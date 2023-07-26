#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/_t_road_lanes_laneSection_lcr_lane.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, _t_road_lanes_laneSection_lcr_lane, lane) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct _t_road_lanes_laneSection_lcr : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_DEFINE(_t_road_lanes_laneSection_lcr)

public:
    void renumberLaneIds(bool left)
    {
        if (left)
        {
            for (int i = 0; i < lane_sequence.size(); i ++)
                lane_sequence[i].id = lane_sequence.size() - i;
        }
        else
        {
            for (int i = 0; i < lane_sequence.size(); i ++)
                lane_sequence[i].id = - (i + 1);
        }
    }
};

}
