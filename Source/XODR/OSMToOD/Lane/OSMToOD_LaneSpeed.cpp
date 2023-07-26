#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneSpeed(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    if (!osmWay.osm.contains(_SC_maxspeed_lanes_A))
        return;

    _NOD::t_road_lanes_laneSection_lr_lane_speed odLaneSpeed;
    odLaneSpeed.sOffset = 0;
    odLaneSpeed.max = osmWay.getSplit(_SC_maxspeed_lanes_A).at(osmLaneIndex).toDouble();
    odLaneSpeed.unit = _NOD::e_unitSpeed::KM_H;
    odLane.speed_sequence << odLaneSpeed;
}

}
