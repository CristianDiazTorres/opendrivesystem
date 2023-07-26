
/*
 * This file is part of OSM module and header of RequestAnalyzer submodule.
 *
 * Developed for the OpenStreet Data Management System.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 */

#include "Math/Clipper.h"
#include "OSM/RequestAnalyzer.h"
#include "OSM/OverpassAPI.h"
#include "OSM/PriorKnowledgeProvider.h"
#include "OCS/DatabaseConnector.h"

namespace _NOSM
{
typedef _NMath::Clipper< qreal, RectF, qreal, VehiclePos, PointF >	Clipper1;

WayVec RequestAnalyzer::getNearestRoadsForPath(VehiclePosVec poses, const JsonArray& json_data)
{
    WayVec ways = analyzeOSMRoadResponse(poses, json_data);
    Debug << "    Analyzed OSM Roads : " << ways.size();

    bool notFoundNearestRoadPrev = false;
    for (int i = 0; i < poses.size(); i ++)
    {
        VehiclePos& pos = poses[i];
        int nearestRoadIndex = getNearestRoadIndex(pos, ways);
        if (nearestRoadIndex >= 0)
        {
            notFoundNearestRoadPrev = false;
            ways[nearestRoadIndex].gps_coords << pos;
        }
        else if (notFoundNearestRoadPrev)
        {
            ways.last().gps_coords << pos;
        }
        else if (!notFoundNearestRoadPrev)
        {
            notFoundNearestRoadPrev = true;
            Way way;
            way.width = 12;
            way.lane_count = 2;
            way.gps_coords << pos;
            ways << way;
        }
    }

    for (int i = ways.size() - 1; i >= 0; i --)
    {
        //ways[i].CalculateLength();
        if (!ways[i].isValid())
            ways.removeAt(i);
    }

    Debug << "    Nearested OSM Roads + New Roads : " << ways.size();
    for (Way& way : ways)
        way.calcUpdatedCoord();

    return ways;
}

WayVec RequestAnalyzer::analyzeOSMRoadResponse(VehiclePosVec poses, const JsonArray& json_data)
{
    size_t total_ways = 0;

    for (int i = 0; i < json_data.size(); i++)
    {
        if (json_data[i].isArray())
            total_ways += json_data[i].toArray().size();
    }

    Debug << "========== " << total_ways << " way(s) are analyzed ==========" << ENDL;

    PriorKnowledgeProvider priorKnowledgeProvider;

    WayVec result;
    result.reserve(json_data.size() * 4);

    int way_index = 0;
    for (int i = 0; i < json_data.size(); i++)
    {
        if (!json_data[i].isArray())
            continue;

        JsonArray elements = json_data[i].toArray();

        for (int j = 0; j < elements.size(); j++)
        {
            way_index++;
            Debug << "Way " << way_index << " : ";

            JsonObject wayJson = elements[j].toObject();

            JsonArray geometry = wayJson["geometry"].toArray();

            if (geometry.size() < 2)
                continue;

            VehiclePosVec wayPoses;
            wayPoses.resize(geometry.size());
            for (int k = 0; k < geometry.size(); k ++)
                wayPoses[k].SetFromLatLon(LL(geometry[k]));

            Vector<Vector<PointF> > polys;
            Clipper1::getClippedLineStrips(poses[0].getZoneBound(), wayPoses, polys);
            Debug << "    Clipped sub ways : " << polys.size();

            if (polys.isEmpty())
                continue;

            Debug << "Getting country name by Overpass API...";
            String country = OverpassAPI::GetCountryName(wayPoses[0]); // SLR3
            Debug << country;

            for (Vector<PointF>& poly : polys)
            {
                Way way;

                way.chord_coords.reserve(poly.size());
                for (int k = 0; k < poly.size(); k++)
                {
                    VehiclePos pos;
                    pos.SetByNearPointAndXY(poses[0], poly[k].x(), poly[k].y());
                    pos.UpdateDerivedProps();
                    way.chord_coords << pos;
                }

                JsonObject tags = wayJson["tags"].toObject();

                //====================================================
                if (tags.contains("name"))
                    way.name = tags["name"].toString();

                way.country = country;

                if (tags.contains("highway"))
                    way.highway = tags["highway"].toString();

                // SLR4
                if (tags.contains("width"))
                    way.width = (int)tags["width"].toString().toInt();
                else // TODO: needed ???
                    way.width = priorKnowledgeProvider.GetWayWidth(way.country, way.highway);

                // SLR4
                if (tags.contains("maxspeed"))
                    way.maxspeed = (int)tags["maxspeed"].toString().toInt();
                //else // TODO: needed ?
                //	way.maxspeed = priorKnowledgeProvider.GetMaxSpeed(way.country, way.highway);

                if (tags.contains("maxheight"))
                    way.maxheight = (int)tags["maxheight"].toString().toInt();

                if (tags.contains("maxwidth"))
                    way.maxwidth = (int)tags["maxwidth"].toString().toInt();

                if (tags.contains("maxweight"))
                    way.maxweight = (int)tags["maxweight"].toString().toInt();

                // SLR4
                if (tags.contains("lanes"))
                    way.lane_count = tags["lanes"].toString().toInt();
                else
                    way.lane_count = priorKnowledgeProvider.GetLaneCount(way.country, way.highway);

                if (tags.contains("oneway"))
                    way.oneway = tags["oneway"].toString();

                if (tags.contains("junction"))
                    way.junction = tags["junction"].toString();

                //====================================================
                if (tags.contains("lit"))
                    way.lit = tags["lit"].toString();

                if (tags.contains("smoothness"))
                    way.smoothness = tags["smoothness"].toString();

                if (tags.contains("surface"))
                    way.surface = tags["surface"].toString();

                if (tags.contains("source"))
                    way.source = tags["source"].toString();

                if (tags.contains("source:maxspeed"))
                    way.source_maxspeed = tags["source:maxspeed"].toString();

                //====================================================
                if (tags.contains("access"))
                    way.access = tags["access"].toString();

                if (tags.contains("bicycle"))
                    way.bicycle = tags["bicycle"].toString();

                if (tags.contains("foot"))
                    way.foot = tags["foot"].toString();

                if (tags.contains("footway"))
                    way.footway = tags["footway"].toString();

                //====================================================
                // SLR5
                // TODO: can be center of line segments, but now, center of bound
                // TODO: ??? this may be incorrect
                JsonObject bounds = wayJson["bounds"].toObject();
                way.center_coord = LL((bounds["minlat"].toDouble() + bounds["maxlat"].toDouble()) / 2,
                        (bounds["minlon"].toDouble() + bounds["maxlon"].toDouble()) / 2);

                //====================================================
                way.lanes.resize(way.lane_count);

                for (int k = 0; k < way.lanes.size(); k++)
                {
                    Lane& lane = way.lanes[k];
                    lane.maxspeed = way.maxspeed;
                    lane.width = priorKnowledgeProvider.GetLaneWidth(way.country, way.highway);
                    lane.lateral_offset = 0; // must be calculated later

                    // SLR6
                    lane.driving_direction = POSITIVE;
                    lane.left_marking = priorKnowledgeProvider.GetLeftMarking(way.country, way.highway);
                    lane.right_marking = priorKnowledgeProvider.GetRightMarking(way.country, way.highway);
                    lane.left_marking_color = priorKnowledgeProvider.GetLeftMarkingColor(way.country, way.highway);
                    lane.right_marking_color = priorKnowledgeProvider.GetRightMarkingColor(way.country, way.highway);
                }

                result.push_back(way);
            }
        }
    }

    return result;
}

int RequestAnalyzer::getNearestRoadIndex(VehiclePos& pos, WayVec& ways)
{
    int nearestIndex = -1;
    double minDist = DOUBLE_MAX;
    for (int i = 0; i < ways.size(); i ++)
    {
        double dist = ways[i].GetShortestDistance(pos);
        if (dist < minDist)
        {
            nearestIndex = i;
            minDist = dist;
        }
    }

    return nearestIndex;
}

NodeVec RequestAnalyzer::getWayNodes(const JsonArray& json_data)
{
    NodeVec result;
    result.resize(json_data.size());

    for (int i = 0; i < json_data.size(); i++)
        result[i].ParseFromOSMJson(json_data[i]);

    return result;
}

}
