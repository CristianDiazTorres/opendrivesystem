#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_unitDistance">
        <xs:restriction base="xs:string">
            <xs:enumeration value="m"/>
            <xs:enumeration value="km"/>
            <xs:enumeration value="ft"/>
            <xs:enumeration value="mile"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_unitDistance(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_unitDistance) \
    _OD_STRING_ENUM_CONST(usingType, e_unitDistance, M       , _SC_m) \
    _OD_STRING_ENUM_CONST(usingType, e_unitDistance, KM      , _SC_km) \
    _OD_STRING_ENUM_CONST(usingType, e_unitDistance, FT      , _SC_ft) \
    _OD_STRING_ENUM_CONST(usingType, e_unitDistance, MILE    , _SC_mile) \
    EMPTY_COMMAND

struct e_unitDistance : public _e_base
{
    _OD_STRING_ENUM_e_unitDistance(DECLARE)

public:
    e_unitDistance()
    {
        this->value = 0; // Default value
    }
};

}

