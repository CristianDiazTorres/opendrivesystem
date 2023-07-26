#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_unitSlope">
        <xs:restriction base="xs:string">
            <xs:enumeration value="%"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_unitSlope(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_unitSlope) \
    _OD_STRING_ENUM_CONST(usingType, e_unitSlope, PERCENT , "%") \
    EMPTY_COMMAND

struct e_unitSlope : public _e_base
{
    _OD_STRING_ENUM_e_unitSlope(DECLARE)

public:
    e_unitSlope()
    {
        this->value = 0; // Default value
    }
};

}

