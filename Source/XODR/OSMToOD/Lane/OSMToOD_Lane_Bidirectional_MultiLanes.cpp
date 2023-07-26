#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLane_Bidirectional_MultiLanes(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);

    // We will place left-side-lanes at left_sequence
    // And right-side-lanes at right_sequence

    // lane section
    _NOD::t_road_lanes_laneSection& od_lane_section = odRoad.lanes.laneSection_sequence[0];
    convertLaneRoadMark_Center(database_connector, osmWay, odRoad, od_lane_section.center.lane_sequence[0]);

    // TODO: Ignore odd case

    // TODO: ???!!! Need to consider bidirectionalLaneCount ???!!!

    od_lane_section.left_sequence.resize(1);
    od_lane_section.left_sequence[0].lane_sequence.reserve(osmWay.leftLaneCount + 1);

    _NOD::t_road_lanes_laneSection_left_lane leftBorder;
    leftBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, leftBorder);
    od_lane_section.left_sequence[0].lane_sequence << leftBorder;

    StringVec lanesWidths = osmWay.getSplit(_SC_width_lanes_A).toVector();

    for (int k = 0; k < osmWay.leftLaneCount; k++)
    {
        // lane
        _NOD::t_road_lanes_laneSection_left_lane od_lane;
        od_lane.type = _NOD::e_laneType::DRIVING;

        convertLaneAttrSubTags(database_connector, osmWay, k, odRoad, od_lane);
        od_lane_section.left_sequence[0].lane_sequence << od_lane;
    }

    od_lane_section.right_sequence.resize(1);
    od_lane_section.right_sequence[0].lane_sequence.reserve(osmWay.rightLaneCount + 1);

    for (int k = osmWay.leftLaneCount; k < osmWay.leftLaneCount + osmWay.rightLaneCount; k++)
    {
        // lane
        _NOD::t_road_lanes_laneSection_right_lane od_lane;
        od_lane.type = _NOD::e_laneType::DRIVING;

        convertLaneAttrSubTags(database_connector, osmWay, k, odRoad, od_lane);
        od_lane_section.right_sequence[0].lane_sequence << od_lane;
    }

    _NOD::t_road_lanes_laneSection_right_lane rightBorder;
    rightBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, rightBorder);
    od_lane_section.right_sequence[0].lane_sequence << rightBorder;

    od_lane_section.left_sequence[0].renumberLaneIds();
    od_lane_section.right_sequence[0].renumberLaneIds();
}

}
