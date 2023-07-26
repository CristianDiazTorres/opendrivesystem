#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_orientation">
        <xs:restriction base="xs:string">
            <xs:enumeration value="+"/>
            <xs:enumeration value="-"/>
            <xs:enumeration value="none"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_orientation(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_orientation) \
    _OD_STRING_ENUM_CONST(usingType, e_orientation, PLUS     , "+") \
    _OD_STRING_ENUM_CONST(usingType, e_orientation, MINUS    , "-") \
    _OD_STRING_ENUM_CONST(usingType, e_orientation, NONE     , _SC_none) \
    EMPTY_COMMAND

struct e_orientation : public _e_base
{
    _OD_STRING_ENUM_e_orientation(DECLARE)

public:
    e_orientation()
    {
        this->value = 0; // Default value
    }
};
}
