#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_sideType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="left"/>
            <xs:enumeration value="right"/>
            <xs:enumeration value="front"/>
            <xs:enumeration value="rear"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_sideType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_sideType) \
    _OD_STRING_ENUM_CONST(usingType, e_sideType, LEFT    , _SC_left) \
    _OD_STRING_ENUM_CONST(usingType, e_sideType, RIGHT   , _SC_right) \
    _OD_STRING_ENUM_CONST(usingType, e_sideType, FRONT   , _SC_front) \
    _OD_STRING_ENUM_CONST(usingType, e_sideType, REAR    , _SC_rear) \
    EMPTY_COMMAND

struct e_sideType : public _e_base
{
    _OD_STRING_ENUM_e_sideType(DECLARE)

public:
    e_sideType()
    {
        this->value = 0; // Default value
    }
};
}
