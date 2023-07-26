#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_unitMass">
        <xs:restriction base="xs:string">
            <xs:enumeration value="kg"/>
            <xs:enumeration value="t"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_unitMass(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_unitMass) \
    _OD_STRING_ENUM_CONST(usingType, e_unitMass, KG  , _SC_kg) \
    _OD_STRING_ENUM_CONST(usingType, e_unitMass, T   , _SC_t) \
    EMPTY_COMMAND

struct e_unitMass : public _e_base
{
    _OD_STRING_ENUM_e_unitMass(DECLARE)

public:
    e_unitMass()
    {
        this->value = 0; // Default value
    }
};

}

