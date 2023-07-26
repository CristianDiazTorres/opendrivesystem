#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneHeight(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    if (!osmWay.osm.contains(_SC_elevation_lanes_A))
        return;

    _NOD::t_road_lanes_laneSection_lr_lane_height odLaneHeight;
    odLaneHeight.sOffset = 0;
    odLaneHeight.inner = 0;
    odLaneHeight.outer = osmWay.getSplit(_SC_elevation_lanes_A).at(osmLaneIndex).toDouble();
    odLane.height_sequence << odLaneHeight;
}

}
