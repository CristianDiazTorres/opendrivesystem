#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_surface_CRG_mode">
        <xs:restriction base="xs:string">
            <xs:enumeration value="attached"/>
            <xs:enumeration value="attached0"/>
            <xs:enumeration value="genuine"/>
            <xs:enumeration value="global"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_surface_CRG_mode(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_surface_CRG_mode) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_mode, ATTACHED   , _SC_attached) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_mode, ATTACHED0  , _SC_attached0) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_mode, GENUINE    , _SC_genuine) \
    _OD_STRING_ENUM_CONST(usingType, e_road_surface_CRG_mode, GLOBAL     , _SC_global) \
    EMPTY_COMMAND

struct e_road_surface_CRG_mode : public _e_base
{
    _OD_STRING_ENUM_e_road_surface_CRG_mode(DECLARE)

public:
    e_road_surface_CRG_mode()
    {
        this->value = 0; // Default value
    }
};
}
