#pragma once

#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId             , id      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_BASE_GEO_JSON(usingType, t_road_lanes_laneSection_lr_lane) lineEnd \
    EMPTY_COMMAND

struct _t_road_lanes_laneSection_lcr_lane : public t_road_lanes_laneSection_lr_lane
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(_t_road_lanes_laneSection_lcr_lane)
    _UNIVERSIAL_TYPE_read_write_DEFINE(_t_road_lanes_laneSection_lcr_lane)
    _UNIVERSIAL_TYPE_setTestData_DEFINE(_t_road_lanes_laneSection_lcr_lane)
    _UNIVERSIAL_TYPE_updateGeoJSONData_DEFINE(_t_road_lanes_laneSection_lcr_lane)

public:
    _t_road_lanes_laneSection_lcr_lane(){}

    _t_road_lanes_laneSection_lcr_lane(_laneId laneId) : id(laneId){}
};

}
