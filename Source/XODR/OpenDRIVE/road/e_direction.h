#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_direction">
        <xs:restriction base="xs:string">
            <xs:enumeration value="same"/>
            <xs:enumeration value="opposite"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_direction(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_direction) \
    _OD_STRING_ENUM_CONST(usingType, e_direction, SAME       , _SC_same) \
    _OD_STRING_ENUM_CONST(usingType, e_direction, OPPOSITE   , _SC_opposite) \
    EMPTY_COMMAND

struct e_direction : public _e_base
{
    _OD_STRING_ENUM_e_direction(DECLARE)

public:
    e_direction()
    {
        this->value = 0; // Default value
    }
};
}
