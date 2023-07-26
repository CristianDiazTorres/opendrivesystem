#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLane_Bidirectional_OneLane(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);

    // We will place left-side-lanes at left_sequence
    // And right-side-lanes at right_sequence
    // But bidirectional-lanes can be placed at any_sequence

    StringVec lanesWidths = osmWay.getSplit(_SC_width_lanes_A).toVector();

    // lane offset
    _NOD::t_road_lanes_laneOffset od_lane_offset;
    od_lane_offset.s = 0;
    od_lane_offset.a = lanesWidths[0].toDouble() / 2;
    od_lane_offset.b = 0;
    od_lane_offset.c = 0;
    od_lane_offset.d = 0;
    odRoad.lanes.laneOffset_sequence << od_lane_offset;

    // lane section
    _NOD::t_road_lanes_laneSection& od_lane_section = odRoad.lanes.laneSection_sequence[0];

    // lanes
    od_lane_section.right_sequence.resize(1);
    od_lane_section.right_sequence[0].lane_sequence.reserve(3);

    _NOD::t_road_lanes_laneSection_right_lane leftBorder;
    leftBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, leftBorder);
    od_lane_section.right_sequence[0].lane_sequence << leftBorder;

    // lane
    _NOD::t_road_lanes_laneSection_right_lane od_lane;
    od_lane.type = _NOD::e_laneType::BIDIRECTIONAL;

    convertLaneAttrSubTags(database_connector, osmWay, 0, odRoad, od_lane);
    od_lane_section.right_sequence[0].lane_sequence << od_lane;

    _NOD::t_road_lanes_laneSection_right_lane rightBorder;
    rightBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, rightBorder);
    od_lane_section.right_sequence[0].lane_sequence << rightBorder;

    od_lane_section.right_sequence[0].renumberLaneIds();
}

}
