
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

#include "Math/Main/ClipperLL.h"
#include "OSM/Main/RequestAnalyzer.h"
#include "OSM/Main/OverpassAPI.h"
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider.h"
#include "OSM/Way/Way.h"
#include "DB/Main/PGDatabaseConnector.h"

namespace _NOSM
{
typedef _NMath::Clipper< qreal, QRectF, double, LLCoordSysXYCell, LL >	Clipper1;

void RequestAnalyzer::getNearestRoadsForPath(VehiclePosVec poses, const QJsonArray& json_data, WayVec& allOSMWays, WayVec& nearestWays)
{
    allOSMWays = analyzeOSMRoadResponse(poses, json_data);
    DefaultLogger_File << "    Analyzed OSM Roads : " << allOSMWays.size();

    nearestWays = allOSMWays;

    PriorKnowledgeProvider priorKnowledgeProvider;

    bool newRoadWasAdded = false;
    for (int i = 0; i < poses.size(); i ++)
    {
        VehiclePos& pos = poses[i];
        double distance = 0;
        int nearestRoadIndex = _NMath::getNearestIndex(pos, nearestWays, distance);
        if (nearestRoadIndex >= 0)
        {
            newRoadWasAdded = false;
            nearestWays[nearestRoadIndex].gps_coords_sequence << pos;
        }
        else if (newRoadWasAdded)
        {
            nearestWays.last().gps_coords_sequence << pos;
        }
        else if (!newRoadWasAdded)
        {
            newRoadWasAdded = true;

            Way way;

            // Will not use
            //DefaultLogger_File << "Getting country name by Overpass API...";
            //way.osm[_SC_addr_country_A] = OverpassAPI::getCountryName(pos); // SLR3

            // Will use our database
            PGDatabaseConnector_getDefaultInstance.getOSMCountryAreaData_NameAsISO3166_1(pos.lat, pos.lon, way.osm[_SC_addr_country_A]);

            DefaultLogger_File << way.osm["addr:country"];

            priorKnowledgeProvider.fillWayAttrs(way);

            way.chord_coords_sequence << pos;
            way.gps_coords_sequence << pos;
            nearestWays << way;
        }
    }

    for (int i = nearestWays.size() - 1; i >= 0; i --)
    {
        //ways[i].calculateLength();
        if (!nearestWays[i].isValid())
            nearestWays.removeAt(i);
    }

    DefaultLogger_File << "    Nearested OSM Roads + New Roads : " << nearestWays.size();
    for (Way& way : nearestWays)
        way.calcUpdatedCoord();
}

void RequestAnalyzer::getNearestRoadsForPath(VehiclePosVec poses, const StringVec& json_data, WayVec& allOSMWays, WayVec& nearestWays)
{
    allOSMWays = analyzeOSMRoadResponse(poses, json_data);
    DefaultLogger_File << "    Analyzed OSM Roads : " << allOSMWays.size();

    nearestWays = allOSMWays;

    PriorKnowledgeProvider priorKnowledgeProvider;

    bool newRoadWasAdded = false;
    for (int i = 0; i < poses.size(); i ++)
    {
        VehiclePos& pos = poses[i];
        double distance = 0;
        int nearestRoadIndex = _NMath::getNearestIndex(pos, nearestWays, distance);
        if (nearestRoadIndex >= 0)
        {
            newRoadWasAdded = false;
            nearestWays[nearestRoadIndex].gps_coords_sequence << pos;
        }
        else if (newRoadWasAdded)
        {
            nearestWays.last().gps_coords_sequence << pos;
        }
        else if (!newRoadWasAdded)
        {
            newRoadWasAdded = true;

            Way way;

            // Will not use
            //DefaultLogger_File << "Getting country name by Overpass API...";
            //way.osm[_SC_addr_country_A] = OverpassAPI::getCountryName(pos); // SLR3

            // Will use our database
            PGDatabaseConnector_getDefaultInstance.getOSMCountryAreaData_NameAsISO3166_1(pos.lat, pos.lon, way.osm[_SC_addr_country_A]);

            DefaultLogger_File << way.osm["addr:country"];

            priorKnowledgeProvider.fillWayAttrs(way);

            way.chord_coords_sequence << pos;
            way.gps_coords_sequence << pos;
            nearestWays << way;
        }
    }

    for (int i = nearestWays.size() - 1; i >= 0; i --)
    {
        //ways[i].calculateLength();
        if (!nearestWays[i].isValid())
            nearestWays.removeAt(i);
    }

    DefaultLogger_File << "    Nearested OSM Roads + New Roads : " << nearestWays.size();
    for (Way& way : nearestWays)
        way.calcUpdatedCoord();
}

WayVec RequestAnalyzer::analyzeOSMRoadResponse(VehiclePosVec poses, const QJsonArray& json_data)
{
    size_t total_ways = 0;

    for (int i = 0; i < json_data.size(); i++)
    {
        if (json_data[i].isArray())
            total_ways += json_data[i].toArray().size();
    }

    DefaultLogger_File << "========== " << total_ways << " way(s) are analyzed ==========";

    PriorKnowledgeProvider priorKnowledgeProvider;

    WayVec result;
    result.reserve(json_data.size() * 4);

    int way_index = 0;
    for (int i = 0; i < json_data.size(); i++)
    {
        if (!json_data[i].isArray())
            continue;

        QJsonArray elements = json_data[i].toArray();

        for (int j = 0; j < elements.size(); j++)
        {
            way_index++;
            DefaultLogger_File << "Way " << way_index << " : ";

            QJsonObject wayJson = elements[j].toObject();

            QJsonArray geometry = wayJson[_SC_geometry].toArray();

            DefaultLogger_File << "geometry.size():" << geometry.size();

            if (geometry.size() < 2)
                continue;

            LLCoordSysXYCellVec wayPoses;
            wayPoses.resize(geometry.size());
            for (int k = 0; k < geometry.size(); k ++)
                wayPoses[k].setFromLL(LL(geometry[k]));

            //for (const LLCoordSysXYCell& pos : wayPoses)
            //    DefaultLogger_File << pos.x() << "," << pos.y();

            //DefaultLogger_File << "Bound:"
            //      << poses[0].getCellBoundInMeters().left() << " "
            //      << poses[0].getCellBoundInMeters().top() <<  " "
            //      << poses[0].getCellBoundInMeters().right() <<  " "
            //      << poses[0].getCellBoundInMeters().bottom();

            LLVecVec polys;
            Clipper1::getClippedLineStrips(poses[0].getCellBoundInDegrees(), wayPoses, polys);
            DefaultLogger_File << "    Clipped sub ways : " << polys.size();

            if (polys.isEmpty())
                continue;

            // Will not use
            //DefaultLogger_File << "Getting country name by Overpass API...";
            //QString country = OverpassAPI::getCountryName(wayPoses[0]); // SLR3

            // Will use our database
            QString country;
            PGDatabaseConnector_getDefaultInstance.getOSMCountryAreaData_NameAsISO3166_1(wayPoses[0].lat, wayPoses[0].lon, country);
            DefaultLogger_File << country;

            DefaultLogger_File << "polys.size(): " << polys.size();

            for (LLVec& poly : polys)
            {
                Way way;
                way.parseFromOSMJson(wayJson);

                DefaultLogger_File << "poly.size(): " << poly.size();

                way.chord_coords_sequence.reserve(poly.size());
                for (int k = 0; k < poly.size(); k++)
                {
                    VehiclePos pos;
                    pos.setFromLL(poly[k]);
                    pos.updateDerivedProps();
                    way.chord_coords_sequence << pos;
                }

                if (way.osm[_SC_addr_country_A].isEmpty())
                    way.osm[_SC_addr_country_A] = country;

                priorKnowledgeProvider.fillWayAttrs(way);

                DefaultLogger_File << "way.id : " << way.osm[_SC_id];
                DefaultLogger_File << "way.laneCount : " << way.laneCount;
                DefaultLogger_File << "way.leftLaneCount : " << way.leftLaneCount;
                DefaultLogger_File << "way.forwardLaneCount : " << way.forwardLaneCount;
                DefaultLogger_File << "way.bidirectionalLaneCount : " << way.bidirectionalLaneCount;
                DefaultLogger_File << "way.rightLaneCount : " << way.rightLaneCount;
                DefaultLogger_File << "way.backwardLaneCount : " << way.backwardLaneCount;

                //====================================================
                // SLR5
                // TODO: can be center of line segments, but now, center of bound
                // TODO: ??? this may be incorrect
                QJsonObject bounds = wayJson[_SC_bounds].toObject();
                way.center_coord = LL((bounds[_SC_minlat].toDouble() + bounds[_SC_maxlat].toDouble()) / 2,
                        (bounds[_SC_minlon].toDouble() + bounds[_SC_maxlon].toDouble()) / 2);

                //====================================================

                result.push_back(way);
            }
        }
    }

    return result;
}

WayVec RequestAnalyzer::analyzeOSMRoadResponse(VehiclePosVec poses, const StringVec& json_data)
{
    DefaultLogger_File << "========== " << json_data.size() << " way(s) are analyzed ==========";

    PriorKnowledgeProvider priorKnowledgeProvider;

    WayVec result;
    result.reserve(json_data.size() * 4);

    for (int j = 0; j < json_data.size(); j++)
    {
        DefaultLogger_File << "Way " << j << " : ";

        //qDebug() << json_data[j];

        QJsonObject wayJson = QJsonDocument::fromJson(json_data[j].toUtf8()).object();

        QJsonArray geometry = wayJson[_SC_geometry].toArray();

        DefaultLogger_File << "geometry.size():" << geometry.size();

        if (geometry.size() < 2)
            continue;

        LLCoordSysXYCellVec wayPoses;
        wayPoses.resize(geometry.size());
        for (int k = 0; k < geometry.size(); k ++)
            wayPoses[k].setFromLL(LL(geometry[k]));

        //for (const LLCoordSysXYCell& pos : wayPoses)
        //    DefaultLogger_File << pos.x() << "," << pos.y();

        //DefaultLogger_File << "Bound:"
        //      << poses[0].getCellBoundInMeters().left() << " "
        //      << poses[0].getCellBoundInMeters().top() <<  " "
        //      << poses[0].getCellBoundInMeters().right() <<  " "
        //      << poses[0].getCellBoundInMeters().bottom();

        LLVecVec polys;
        Clipper1::getClippedLineStrips(poses[0].getCellBoundInDegrees(), wayPoses, polys);
        DefaultLogger_File << "    Clipped sub ways : " << polys.size();

        if (polys.isEmpty())
            continue;

        // Will not use
        //DefaultLogger_File << "Getting country name by Overpass API...";
        //QString country = OverpassAPI::getCountryName(wayPoses[0]); // SLR3

        // Will use our database
        QString country;
        PGDatabaseConnector_getDefaultInstance.getOSMCountryAreaData_NameAsISO3166_1(wayPoses[0].lat, wayPoses[0].lon, country);
        DefaultLogger_File << country;

        DefaultLogger_File << "polys.size(): " << polys.size();

        for (LLVec& poly : polys)
        {
            Way way;
            way.parseFromOSMJson(wayJson);

            DefaultLogger_File << "poly.size(): " << poly.size();

            way.chord_coords_sequence.reserve(poly.size());
            for (int k = 0; k < poly.size(); k++)
            {
                VehiclePos pos;
                pos.setFromLL(poly[k]);
                pos.updateDerivedProps();
                way.chord_coords_sequence << pos;
            }

            if (way.osm[_SC_addr_country_A].isEmpty())
                way.osm[_SC_addr_country_A] = country;

            priorKnowledgeProvider.fillWayAttrs(way);

            DefaultLogger_File << "way.id : " << way.osm[_SC_id];
            DefaultLogger_File << "way.laneCount : " << way.laneCount;
            DefaultLogger_File << "way.leftLaneCount : " << way.leftLaneCount;
            DefaultLogger_File << "way.forwardLaneCount : " << way.forwardLaneCount;
            DefaultLogger_File << "way.bidirectionalLaneCount : " << way.bidirectionalLaneCount;
            DefaultLogger_File << "way.rightLaneCount : " << way.rightLaneCount;
            DefaultLogger_File << "way.backwardLaneCount : " << way.backwardLaneCount;

            //====================================================
            // SLR5
            // TODO: can be center of line segments, but now, center of bound
            // TODO: ??? this may be incorrect
            QJsonObject bounds = wayJson[_SC_bounds].toObject();
            way.center_coord = LL((bounds[_SC_minlat].toDouble() + bounds[_SC_maxlat].toDouble()) / 2,
                    (bounds[_SC_minlon].toDouble() + bounds[_SC_maxlon].toDouble()) / 2);

            //====================================================

            result.push_back(way);
        }
    }


    return result;
}

NodeVec RequestAnalyzer::getWayNodes(const QJsonArray& json_data)
{
    NodeVec result;
    result.resize(json_data.size());

    for (int i = 0; i < json_data.size(); i++)
        result[i].parseFromOSMJson(json_data[i].toObject());

    return result;
}

NodeVec RequestAnalyzer::getWayNodes(const StringVec& json_data)
{
    NodeVec result;
    result.resize(json_data.size());

    for (int i = 0; i < json_data.size(); i++)
        result[i].parseFromOSMJson(QJsonDocument::fromJson(json_data[i].toUtf8()).object());

    return result;
}

}
