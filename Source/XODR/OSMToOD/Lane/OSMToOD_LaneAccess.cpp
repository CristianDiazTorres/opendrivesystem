#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneAccess(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    if (!osmWay.osm.contains(_SC_access_lanes_A))
        return;

    QString value = osmWay.getSplit(_SC_access_lanes_A).at(osmLaneIndex);
    if (value.contains(_SC_yes))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::DENY;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::NONE;
        odLane.access_sequence << odLaneAccess;
        return;
    }

    if (value.contains(_SC_no))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::NONE;
        odLane.access_sequence << odLaneAccess;
        return;
    }

    if (value.contains(_SC_bus))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::BUS;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_psv))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::BUS;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_bicycle))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::BICYCLE;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_motorcar) || value.contains(_SC_motorcycle))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::MOTORCYCLE;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_hgv) || value.contains(_SC_hov))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::TRUCK;
        odLane.access_sequence << odLaneAccess;

        odLaneAccess.restriction = _NOD::e_accessRestrictionType::TRUCKS;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_taxi))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::TAXI;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_emergency))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::EMERGENCY;
        odLane.access_sequence << odLaneAccess;
    }

    if (value.contains(_SC_delivery))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_access odLaneAccess;
        odLaneAccess.rule = _NOD::e_road_lanes_laneSection_lr_lane_access_rule::ALLOW;
        odLaneAccess.restriction = _NOD::e_accessRestrictionType::DELIVERY;
        odLane.access_sequence << odLaneAccess;
    }
}

}
