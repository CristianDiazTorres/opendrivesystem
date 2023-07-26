#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_lanes_laneSection_lcr_lane_roadMark_laneChange">
        <xs:restriction base="xs:string">
            <xs:enumeration value="increase"/>
            <xs:enumeration value="decrease"/>
            <xs:enumeration value="both"/>
            <xs:enumeration value="none"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_lanes_laneSection_lcr_lane_roadMark_laneChange(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange, INCREASE     , _SC_increase) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange, DECREASE     , _SC_decrease) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange, BOTH         , _SC_both) \
    _OD_STRING_ENUM_CONST(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange, NONE         , _SC_none) \
    EMPTY_COMMAND

struct e_road_lanes_laneSection_lcr_lane_roadMark_laneChange : public _e_base
{
    _OD_STRING_ENUM_e_road_lanes_laneSection_lcr_lane_roadMark_laneChange(DECLARE)

public:
    e_road_lanes_laneSection_lcr_lane_roadMark_laneChange()
    {
        this->value = 0; // Default value
    }
};
}
