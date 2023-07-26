#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_outlineFillType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="grass"/>
            <xs:enumeration value="concrete"/>
            <xs:enumeration value="cobble"/>
            <xs:enumeration value="asphalt"/>
            <xs:enumeration value="pavement"/>
            <xs:enumeration value="gravel"/>
            <xs:enumeration value="soil"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_outlineFillType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_outlineFillType) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, GRASS    , _SC_grass) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, CONCRETE , _SC_concrete) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, COBBLE   , _SC_cobble) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, ASPHALT  , _SC_asphalt) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, PAVEMENT , _SC_pavement) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, GRAVEL   , _SC_gravel) \
    _OD_STRING_ENUM_CONST(usingType, e_outlineFillType, SOIL     , _SC_soil) \
    EMPTY_COMMAND

struct e_outlineFillType : public _e_base
{
    _OD_STRING_ENUM_e_outlineFillType(DECLARE)

public:
    e_outlineFillType()
    {
        this->value = 0; // Default value
    }
};
}
