#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_bridgeType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="concrete"/>
            <xs:enumeration value="steel"/>
            <xs:enumeration value="brick"/>
            <xs:enumeration value="wood"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_bridgeType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_bridgeType) \
    _OD_STRING_ENUM_CONST(usingType, e_bridgeType, CONCRETE , _SC_concrete) \
    _OD_STRING_ENUM_CONST(usingType, e_bridgeType, STEEL    , _SC_steel) \
    _OD_STRING_ENUM_CONST(usingType, e_bridgeType, BRICK    , _SC_brick) \
    _OD_STRING_ENUM_CONST(usingType, e_bridgeType, WOOD     , _SC_wood) \
    EMPTY_COMMAND

struct e_bridgeType : public _e_base
{
    _OD_STRING_ENUM_e_bridgeType(DECLARE)

public:
    e_bridgeType()
    {
        this->value = 0; // Default value
    }
};
}
