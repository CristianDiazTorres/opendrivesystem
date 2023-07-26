#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_lanes_laneSection_lr_lane_access_rule">
        <xs:restriction base="xs:string">
            <xs:enumeration value="allow"/>
            <xs:enumeration value="deny"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_lanes_laneSection_lr_lane_access_rule(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_lanes_laneSection_lr_lane_access_rule) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lr_lane_access_rule, ALLOW , _SC_allow) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lr_lane_access_rule, DENY  , _SC_deny) \
    EMPTY_COMMAND

struct e_road_lanes_laneSection_lr_lane_access_rule : public _e_base
{
    _OD_STRING_ENUM_e_road_lanes_laneSection_lr_lane_access_rule(DECLARE)

public:
    e_road_lanes_laneSection_lr_lane_access_rule()
    {
        this->value = 0; // Default value
    }
};
}
