
/*
 * This file is part of OSMM module and header of RequestAnalyzer submodule.
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

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "OSMM/RequestAnalyzer.h"
#include "Common/OverpassAPI.h"
#include "OSMM/PriorKnowledgeProvider.h"
#include "OCSM/DatabaseConnector.h"

namespace OSMM
{

	/**
	* Process JSON data.
	*
	* @param json_data contains JSON object array.
	* @return array of road description
	*
	* @exceptsafe This function does not throw exceptions.
	*/
	RoadVec RequestAnalyzer::Process(ConstRequest& request, ConstQJsonArray& json_data)
	{
		size_t total_ways = 0;

		for (int i = 0; i < json_data.size(); i++)
		{
            if (json_data[i].isArray())
                total_ways += json_data[i].toArray().size();
		}

		MyCout << "========== " << total_ways << " way(s) are analyzed ==========" << MyEndl;

		PriorKnowledgeProvider priorKnowledgeProvider;

		RoadVec result;
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
                MyCout << "Way " << way_index << " : ";

				QJsonObject way = elements[j].toObject();

                Road road;

                road.pos = request.poses[i];

                QJsonArray geometry = way["geometry"].toArray();

				Common::LatLon coord(geometry[0]);

				QJsonObject tags = way["tags"].toObject();

				//====================================================
                if (tags.contains("name"))
                    road.name = tags["name"].toString();

                MyCout << "Getting country name by Overpass API...";
                road.country = Common::OverpassAPI::GetCountryName(coord); // SLR3
                MyCout << road.country;

                if (tags.contains("highway"))
                    road.highway = tags["highway"].toString();

				// SLR4
                if (tags.contains("width"))
                    road.width = (int)tags["width"].toString().toInt();
				//else // TODO: needed ?
                //	road.width = priorKnowledgeProvider.GetWayWidth(road.country, road.highway);

				// SLR4
                if (tags.contains("maxspeed"))
                    road.maxspeed = (int)tags["maxspeed"].toString().toInt();
				//else // TODO: needed ?
                //	road.maxspeed = priorKnowledgeProvider.GetMaxSpeed(road.country, road.highway);

                if (tags.contains("maxheight"))
                    road.maxheight = (int)tags["maxheight"].toString().toInt();

                if (tags.contains("maxwidth"))
                    road.maxwidth = (int)tags["maxwidth"].toString().toInt();

                if (tags.contains("maxweight"))
                    road.maxweight = (int)tags["maxweight"].toString().toInt();

				// SLR4
                if (tags.contains("lanes"))
                    road.lane_count = tags["lanes"].toString().toInt();
				else
                    road.lane_count = priorKnowledgeProvider.GetLaneCount(road.country, road.highway);

                if (tags.contains("oneway"))
                    road.oneway = tags["oneway"].toString();

                if (tags.contains("junction"))
                    road.junction = tags["junction"].toString();

				//====================================================
                if (tags.contains("lit"))
                    road.lit = tags["lit"].toString();

                if (tags.contains("smoothness"))
                    road.smoothness = tags["smoothness"].toString();

                if (tags.contains("surface"))
                    road.surface = tags["surface"].toString();

                if (tags.contains("source"))
                    road.source = tags["source"].toString();

                if (tags.contains("source:maxspeed"))
                    road.source_maxspeed = tags["source:maxspeed"].toString();

				//====================================================
                if (tags.contains("access"))
                    road.access = tags["access"].toString();

                if (tags.contains("bicycle"))
                    road.bicycle = tags["bicycle"].toString();

                if (tags.contains("foot"))
                    road.foot = tags["foot"].toString();

                if (tags.contains("footway"))
                    road.footway = tags["footway"].toString();

				//====================================================
				// SLR5
				// TODO: can be center of line segments, but now, center of bound
				QJsonObject bounds = way["bounds"].toObject();
                road.center_coord = Common::LatLon((bounds["minlat"].toDouble() + bounds["maxlat"].toDouble()) / 2,
                    (bounds["minlon"].toDouble() + bounds["maxlon"].toDouble()) / 2);

				//====================================================
                road.lane_sections.resize(1);

                LaneSection& lane_section = road.lane_sections[0];
                lane_section.lanes.resize(road.lane_count);

                for (int k = 0; k < lane_section.lanes.size(); k++)
				{
					Lane& lane = lane_section.lanes[k];
                    lane.id = request.database_connector->GetNewLaneID();
					lane.previous_id = -1;
					lane.next_id = -1;
                    lane.maxspeed = road.maxspeed;
                    lane.width = priorKnowledgeProvider.GetLaneWidth(road.country, road.highway);
					lane.lateral_offset = 0; // must be calculated later

					// SLR6
					lane.driving_direction = POSITIVE;
                    lane.left_marking = priorKnowledgeProvider.GetLeftMarking(road.country, road.highway);
                    lane.right_marking = priorKnowledgeProvider.GetRightMarking(road.country, road.highway);
                    lane.left_marking_color = priorKnowledgeProvider.GetLeftMarkingColor(road.country, road.highway);
                    lane.right_marking_color = priorKnowledgeProvider.GetRightMarkingColor(road.country, road.highway);
				}

				Common::VehiclePosVec& chord_coords = lane_section.chord_coords;
				chord_coords.resize(geometry.size());

                for (int k = 0; k < geometry.size(); k++)
				{
					Common::VehiclePos& pos = chord_coords[k];
					pos.coord = Common::LatLon(geometry[k]);
                    pos.heading = road.pos.heading; // In radians
                    pos.UpdateDerivedProps();
				}

                for (int k = 0; k < chord_coords.size() - 1; k++)
                    chord_coords[k].UpdateLengthFromNext(chord_coords[k + 1]);
                chord_coords.last().length = 0;

				//====================================================
                MyCout << "Getting nodes around way by Overpass API...";
                QJsonValue way_nodes_json = Common::OverpassAPI::GetNodesData(chord_coords);
                if (!way_nodes_json.toArray().isEmpty())
				{
                    QJsonArray node_elements = way_nodes_json.toArray();
					MyCout << node_elements.size() << " nodes around ways" << MyEndl;

					lane_section.way_nodes.resize(node_elements.size());

                    for (int k = 0; k < node_elements.size(); k++)
						lane_section.way_nodes[k].ParseFromOSMJson(node_elements[k]);
				}
				else
				{
					MyCout << "No node around way" << MyEndl;
				}

                road.CalculateLength();
                result.push_back(road);
			}
		}

		return result;
	}

	RoadVec RequestAnalyzer::Process2(ConstRequest& request, ConstQJsonArray& json_data)
	{
		size_t total_ways = 0;

		for (int i = 0; i < json_data.size(); i++)
		{
            if (json_data[i].isArray())
                total_ways += json_data[i].toArray().size();
		}

		MyCout << "========== " << total_ways << " way(s) are analyzed ==========" << MyEndl;

		PriorKnowledgeProvider priorKnowledgeProvider;

		RoadVec result;
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
                MyCout << "Way " << way_index << " : ";

				QJsonObject way = elements[j].toObject();

                Road road;

                road.pos = request.poses[i];

                QJsonArray geometry = way["geometry"].toArray();

				Common::LatLon coord(geometry[0]);

				QJsonObject tags = way["tags"].toObject();

				//====================================================
                if (tags.contains("name"))
                    road.name = tags["name"].toString();

                MyCout << "Getting country name by Overpass API...";
                road.country = Common::OverpassAPI::GetCountryName(coord); // SLR3
                MyCout << road.country;

                if (tags.contains("highway"))
                    road.highway = tags["highway"].toString();

				// SLR4
                if (tags.contains("width"))
                    road.width = (int)tags["width"].toString().toInt();
				//else // TODO: needed ?
                //	road.width = priorKnowledgeProvider.GetWayWidth(road.country, road.highway);

				// SLR4
                if (tags.contains("maxspeed"))
                    road.maxspeed = (int)tags["maxspeed"].toString().toInt();
				//else // TODO: needed ?
                //	road.maxspeed = priorKnowledgeProvider.GetMaxSpeed(road.country, road.highway);

                if (tags.contains("maxheight"))
                    road.maxheight = (int)tags["maxheight"].toString().toInt();

                if (tags.contains("maxwidth"))
                    road.maxwidth = (int)tags["maxwidth"].toString().toInt();

                if (tags.contains("maxweight"))
                    road.maxweight = (int)tags["maxweight"].toString().toInt();

				// SLR4
                if (tags.contains("lanes"))
                    road.lane_count = tags["lanes"].toString().toInt();
				else
                    road.lane_count = priorKnowledgeProvider.GetLaneCount(road.country, road.highway);

                if (tags.contains("oneway"))
                    road.oneway = tags["oneway"].toString();

                if (tags.contains("junction"))
                    road.junction = tags["junction"].toString();

				//====================================================
                if (tags.contains("lit"))
                    road.lit = tags["lit"].toString();

                if (tags.contains("smoothness"))
                    road.smoothness = tags["smoothness"].toString();

                if (tags.contains("surface"))
                    road.surface = tags["surface"].toString();

                if (tags.contains("source"))
                    road.source = tags["source"].toString();

                if (tags.contains("source:maxspeed"))
                    road.source_maxspeed = tags["source:maxspeed"].toString();

				//====================================================
                if (tags.contains("access"))
                    road.access = tags["access"].toString();

                if (tags.contains("bicycle"))
                    road.bicycle = tags["bicycle"].toString();

                if (tags.contains("foot"))
                    road.foot = tags["foot"].toString();

                if (tags.contains("footway"))
                    road.footway = tags["footway"].toString();

				//====================================================
				// SLR5
				// TODO: can be center of line segments, but now, center of bound
				QJsonObject bounds = way["bounds"].toObject();
                road.center_coord = Common::LatLon((bounds["minlat"].toDouble() + bounds["maxlat"].toDouble()) / 2,
                    (bounds["minlon"].toDouble() + bounds["maxlon"].toDouble()) / 2);

				//====================================================
                road.lane_sections.resize(1);

                LaneSection& lane_section = road.lane_sections[0];
                lane_section.lanes.resize(road.lane_count);

                for (int k = 0; k < lane_section.lanes.size(); k++)
				{
					Lane& lane = lane_section.lanes[k];
                    lane.id = request.database_connector->GetNewLaneID();
					lane.previous_id = -1;
					lane.next_id = -1;
                    lane.maxspeed = road.maxspeed;
                    lane.width = priorKnowledgeProvider.GetLaneWidth(road.country, road.highway);
					lane.lateral_offset = 0; // must be calculated later

					// SLR6
					lane.driving_direction = POSITIVE;
                    lane.left_marking = priorKnowledgeProvider.GetLeftMarking(road.country, road.highway);
                    lane.right_marking = priorKnowledgeProvider.GetRightMarking(road.country, road.highway);
                    lane.left_marking_color = priorKnowledgeProvider.GetLeftMarkingColor(road.country, road.highway);
                    lane.right_marking_color = priorKnowledgeProvider.GetRightMarkingColor(road.country, road.highway);
				}

				Common::VehiclePosVec& chord_coords = lane_section.chord_coords;
				chord_coords.resize(geometry.size());

                for (int k = 0; k < geometry.size(); k++)
				{
					Common::VehiclePos& pos = chord_coords[k];
					pos.coord = Common::LatLon(geometry[k]);
                    pos.heading = road.pos.heading; // In radians
                    pos.UpdateDerivedProps();
				}

                for (int k = 0; k < chord_coords.size() - 1; k++)
                    chord_coords[k].UpdateLengthFromNext(chord_coords[k + 1]);
                chord_coords.last().length = 0;

				//====================================================
                MyCout << "Getting nodes around way by Overpass API...";
                QJsonValue way_nodes_json = Common::OverpassAPI::GetNodesData(chord_coords);
                if (!way_nodes_json.toArray().isEmpty())
				{
                    QJsonArray node_elements = way_nodes_json.toArray();
                    MyCout << node_elements.size() << " nodes around ways" << MyEndl;

					lane_section.way_nodes.resize(node_elements.size());

                    for (int k = 0; k < node_elements.size(); k++)
						lane_section.way_nodes[k].ParseFromOSMJson(node_elements[k]);
				}
				else
				{
                    MyCout << "No node around way" << MyEndl;
				}

                road.CalculateLength();
                result.push_back(road);
			}
		}

		return result;
	}

}
