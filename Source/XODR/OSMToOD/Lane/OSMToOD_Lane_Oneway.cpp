#include "XODR/OSMToOD/OSMToOD.h"
#include "XODR/OpenDRIVE/lane/_t_road_lanes_laneSection_lcr.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLane_Oneway(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);

    // We will place left-side-lanes at left_sequence
    // And right-side-lanes at right_sequence

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

    if (osmWay.isLHT())
        od_lane_section.left_sequence.resize(1);
    else
        od_lane_section.right_sequence.resize(1);

    _NOD::_t_road_lanes_laneSection_lcr& leftRightLane
            = osmWay.isLHT()
            ? (_NOD::_t_road_lanes_laneSection_lcr&)od_lane_section.left_sequence.first()
            : (_NOD::_t_road_lanes_laneSection_lcr&)od_lane_section.right_sequence.first();

    // lanes
    leftRightLane.lane_sequence.reserve(osmWay.laneCount + 2);

    _NOD::_t_road_lanes_laneSection_lcr_lane leftBorder;
    leftBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, leftBorder);
    leftRightLane.lane_sequence << leftBorder;

    for (int k = 0; k < osmWay.laneCount; k++)
    {
        // lane
        _NOD::_t_road_lanes_laneSection_lcr_lane od_lane;
        od_lane.type = _NOD::e_laneType::DRIVING;

        convertLaneAttrSubTags(database_connector, osmWay, k, odRoad, od_lane);
        leftRightLane.lane_sequence << od_lane;
    }

    _NOD::_t_road_lanes_laneSection_lcr_lane rightBorder;
    rightBorder.type = _NOD::e_laneType::BORDER;
    convertLaneRoadMark_Border(database_connector, osmWay, odRoad, rightBorder);
    leftRightLane.lane_sequence << rightBorder;

    leftRightLane.renumberLaneIds(osmWay.isLHT());
}

}
