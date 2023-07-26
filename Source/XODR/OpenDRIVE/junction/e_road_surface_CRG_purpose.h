#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_surface_CRG_purpose">
        <xs:restriction base="xs:string">
            <xs:enumeration value="elevation"/>
            <xs:enumeration value="friction"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_surface_CRG_purpose(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_surface_CRG_purpose) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_purpose, ELEVATION   , _SC_elevation) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_purpose, FRICTION    , _SC_friction) \
    EMPTY_COMMAND

struct e_road_surface_CRG_purpose : public _e_base
{
    _OD_STRING_ENUM_e_road_surface_CRG_purpose(DECLARE)

public:
    e_road_surface_CRG_purpose()
    {
        this->value = 0; // Default value
    }
};
}
