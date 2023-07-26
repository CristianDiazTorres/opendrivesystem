#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_station_platform_segment_side">
        <xs:restriction base="xs:string">
            <xs:enumeration value="left"/>
            <xs:enumeration value="right"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_station_platform_segment_side(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_station_platform_segment_side) \
    _OD_STRING_ENUM_CONST(usingType, e_station_platform_segment_side, LEFT   , _SC_left) \
    _OD_STRING_ENUM_CONST(usingType, e_station_platform_segment_side, RIGHT  , _SC_right) \
    EMPTY_COMMAND

struct e_station_platform_segment_side : public _e_base
{
    _OD_STRING_ENUM_e_station_platform_segment_side(DECLARE)

public:
    e_station_platform_segment_side()
    {
        this->value = 0; // Default value
    }
};
}
