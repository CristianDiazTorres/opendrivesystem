#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_maxSpeedString">
        <xs:restriction base="xs:string">
            <xs:enumeration value="no limit"/>
            <xs:enumeration value="undefined"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_maxSpeedString(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_maxSpeedString) \
    _OD_STRING_ENUM_CONST(usingType, e_maxSpeedString, NO_LIMIT  , _SC_no_limit_A) \
    _OD_STRING_ENUM_CONST(usingType, e_maxSpeedString, UNDEFINED , _SC_undefined) \
    EMPTY_COMMAND

struct e_maxSpeedString : public _e_base
{
    _OD_STRING_ENUM_e_maxSpeedString(DECLARE)

public:
    e_maxSpeedString()
    {
        this->value = 0; // Default value
    }
};
}
