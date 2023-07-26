#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_railroad_switch_position">
        <xs:restriction base="xs:string">
            <xs:enumeration value="dynamic"/>
            <xs:enumeration value="straight"/>
            <xs:enumeration value="turn"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_railroad_switch_position(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_railroad_switch_position) \
    _OD_STRING_ENUM_CONST(usingType, e_road_railroad_switch_position, DYNAMIC    , _SC_dynamic) \
    _OD_STRING_ENUM_CONST(usingType, e_road_railroad_switch_position, STRAIGHT   , _SC_straight) \
    _OD_STRING_ENUM_CONST(usingType, e_road_railroad_switch_position, TURN       , _SC_turn) \
    EMPTY_COMMAND

struct e_road_railroad_switch_position : public _e_base
{
    _OD_STRING_ENUM_e_road_railroad_switch_position(DECLARE)

public:
    e_road_railroad_switch_position()
    {
        this->value = 0; // Default value
    }
};
}
