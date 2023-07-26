#include "OCSM/RoadBuilder.h"
#include <QDateTime>

namespace OCSM
{

	OpenDRIVE::OpenDRIVE RoadBuilder::Build(Common::ConstVehiclePosVec& rlr,
		Common::ConstVehiclePosVec& trajectory,
		ConstMeasurementContent& measurement_content,
        DatabaseConnector& database_connector,
		ConstExternalSourceProviderVec& external_source_providers)
	{
        Q_UNUSED(rlr);
        Q_UNUSED(measurement_content);

		MyCout << "========== Building OpenDRIVE content ==========" << MyEndl;

		if (external_source_providers.isEmpty())
		{
			MyCout << "No content" << MyEndl;
			return OpenDRIVE::OpenDRIVE();
		}

        const ExternalSourceProvider& external_source_provider = *(external_source_providers[0]);
        OSMM::ConstRoadVec& osmm_roads = external_source_provider.GetSavedData();

		OpenDRIVE::OpenDRIVE result;
        makeHeader(database_connector, database_connector.GetName(trajectory[0]), result.header);

        // Roads
        result.road_sequence.resize(osmm_roads.size());

		for (int i = 0; i < osmm_roads.size(); i++)
		{
            // Road
            OSMM::ConstRoad& osmm_road = osmm_roads[i];
            OpenDRIVE::t_road& od_road = result.road_sequence[i];

            // Convert road-attr
            convertRoadAttr(database_connector, osmm_road, od_road);

            // Convert road-type
            convertRoadType(database_connector, osmm_road, od_road);

            // Convert geometry
            convertGeometry(database_connector, osmm_road, od_road);

            // Convert lane
            convertLane(database_connector, osmm_road, od_road);

            // Convert way-nodes
            convertWayNodes(database_connector, osmm_road, od_road);
		}

		return result;
	}

    void RoadBuilder::makeHeader(DatabaseConnector& database_connector, const QString& name, OpenDRIVE::t_header& header)
    {
        Q_UNUSED(database_connector);

        header.revMajor = 1;
        header.revMinor = 6;
        header.name = name;
        header.version = "1.0";
        header.date = OpenDRIVE::_date::currentDateTimeUtc();
        header.north = - SQUARE_GRID_AREA_SIZE;
        header.south = SQUARE_GRID_AREA_SIZE;
        header.east = - SQUARE_GRID_AREA_SIZE;
        header.west = SQUARE_GRID_AREA_SIZE;
    }

    void RoadBuilder::convertRoadAttr(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road)
    {
        od_road.name = osmm_road.name;
        od_road.length = osmm_road.length;
        od_road.id = database_connector.GetNewRoadID();
        od_road.junction = -1;
        od_road.rule = OpenDRIVE::e_trafficRule::RHT;
    }

    void RoadBuilder::convertRoadType(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road)
    {
        Q_UNUSED(database_connector);

        OpenDRIVE::t_road_type od_road_type;
        od_road_type.country = osmm_road.country;
        od_road_type.type = OpenDRIVE::e_roadType::TOWN;
        od_road_type.s = 0;
        od_road.type_sequence << od_road_type;
    }

    void RoadBuilder::convertGeometry(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road)
    {
        Q_UNUSED(database_connector);

        for (OSMM::ConstLaneSection& osmm_lane_section : osmm_road.lane_sections)
        {
            for (Common::ConstVehiclePos& pos : osmm_lane_section.chord_coords)
            {
                // line
                OpenDRIVE::t_road_planView_geometry od_geom;
                od_geom.s = 0;
                od_geom.x = pos.x;
                od_geom.y = pos.y;
                od_geom.hdg = pos.heading; // In radians
                od_geom.length = pos.length;

                od_road.planView.geometry_sequence << od_geom;
            }
        }
    }

    void RoadBuilder::convertLane(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road)
    {
        Q_UNUSED(database_connector);

        od_road.lanes.laneSection_sequence.resize(osmm_road.lane_sections.size());

        for (int j = 0; j < osmm_road.lane_sections.size(); j++)
        {
            // lane section
            OSMM::ConstLaneSection& osmm_lane_section = osmm_road.lane_sections[j];

            // lane section
            OpenDRIVE::t_road_lanes_laneSection& od_lane_section = od_road.lanes.laneSection_sequence[j];
            od_lane_section.s = osmm_road.width;

            // lanes
            od_lane_section.right_sequence.resize(1);
            od_lane_section.right_sequence[0].lane_sequence.resize(osmm_lane_section.lanes.size());

            for (int k = 0; k < osmm_lane_section.lanes.size(); k++)
            {
                // lane
                OSMM::ConstLane& osmm_lane = osmm_lane_section.lanes[k];

                OpenDRIVE::t_road_lanes_laneSection_right_lane& od_lane = od_lane_section.right_sequence[0].lane_sequence[k];
                od_lane.id = osmm_lane.id;
                od_lane.type = OpenDRIVE::e_laneType::DRIVING;

                OpenDRIVE::t_road_lanes_laneSection_lr_lane_width od_lane_width;
                od_lane_width.sOffset = 0;
                od_lane_width.a = 0;
                od_lane_width.b = osmm_lane.width;
                od_lane_width.c = 0;
                od_lane_width.d = 0;
                od_lane.width_sequence << od_lane_width;
            }
        }
    }

    void RoadBuilder::convertWayNodes(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road)
    {
        Q_UNUSED(database_connector);

        for (int j = 0; j < osmm_road.lane_sections.size(); j++)
        {
            // lane section
            OSMM::ConstLaneSection& osmm_lane_section = osmm_road.lane_sections[j];

            // way nodes
            for (Common::ConstWayNode& wayNode : osmm_lane_section.way_nodes)
            {
                OpenDRIVE::t_road_objects_object od_object;

                if (!wayNode.barrier.isEmpty() ||
                    !wayNode.crossing_barrier.isEmpty())
                {
                    od_object.type = OpenDRIVE::e_objectType::BARRIER;
                }
                else if (!wayNode.parking.isEmpty())
                {
                    od_object.type = OpenDRIVE::e_objectType::PARKINGSPACE;
                }
                else if (!wayNode.crossing_island.isEmpty())
                {
                    od_object.type = OpenDRIVE::e_objectType::TRAFFICISLAND;
                }
                else if (!wayNode.foot.isEmpty() &&
                    !wayNode.crossing.isEmpty())
                {
                    od_object.type = OpenDRIVE::e_objectType::CROSSWALK;
                }
                else if (!wayNode.traffic_sign.isEmpty())
                {
                    od_object.type = OpenDRIVE::e_objectType::ROADMARK;
                }
                else
                    continue;

                od_object.name = wayNode.name;
                if (od_road.objects_sequence.isEmpty())
                    od_road.objects_sequence.resize(1);
                od_road.objects_sequence[0].object_sequence << od_object;
            }
        }
    }
}
