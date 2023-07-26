#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneWidth(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    _NOD::t_road_lanes_laneSection_lr_lane_width od_lane_width;
    od_lane_width.sOffset = 0;
    od_lane_width.a = osmWay.getSplit(_SC_width_lanes_A).at(osmLaneIndex).toDouble();
    od_lane_width.b = 0;
    od_lane_width.c = 0;
    od_lane_width.d = 0;
    odLane.width_sequence << od_lane_width;
}

}
