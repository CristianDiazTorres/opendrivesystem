#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_station_type">
        <xs:restriction base="xs:string">
            <xs:enumeration value="small"/>
            <xs:enumeration value="medium"/>
            <xs:enumeration value="large"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_station_type(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_station_type) \
    _OD_STRING_ENUM_CONST(usingType, e_station_type, SMALL   , _SC_small) \
    _OD_STRING_ENUM_CONST(usingType, e_station_type, MEDIUM  , _SC_medium) \
    _OD_STRING_ENUM_CONST(usingType, e_station_type, LARGE   , _SC_large) \
    EMPTY_COMMAND

struct e_station_type : public _e_base
{
    _OD_STRING_ENUM_e_station_type(DECLARE)

public:
    e_station_type()
    {
        this->value = 0; // Default value
    }
};
}
