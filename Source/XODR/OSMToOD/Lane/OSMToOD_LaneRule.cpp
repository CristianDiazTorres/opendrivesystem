#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneRule(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    if (osmWay.osm.contains(_SC_car_pooling_lanes_A))
    {
        if (osmWay.getSplit(_SC_car_pooling_lanes_A).at(osmLaneIndex) == _SC_yes)
        {
            _NOD::t_road_lanes_laneSection_lr_lane_rule odLaneRule;
            odLaneRule.sOffset = 0;
            odLaneRule.value = _SC_car_pool_A;
            odLane.rule_sequence << odLaneRule;
            return;
        }
    }

    if (osmWay.osm.contains(_SC_parking_lanes_A))
    {
        QString value = osmWay.getSplit(_SC_parking_lanes_A).at(osmLaneIndex);
        if (value == _SC_no_stopping)
        {
            _NOD::t_road_lanes_laneSection_lr_lane_rule odLaneRule;
            odLaneRule.sOffset = 0;
            odLaneRule.value = _SC_no_stopping_at_any_time_A;
            odLane.rule_sequence << odLaneRule;
            return;
        }

        if (value == _SC_no_parking)
        {
            _NOD::t_road_lanes_laneSection_lr_lane_rule odLaneRule;
            odLaneRule.sOffset = 0;
            odLaneRule.value = _SC_disabled_parking_A;
            odLane.rule_sequence << odLaneRule;
            return;
        }
    }
}

}
