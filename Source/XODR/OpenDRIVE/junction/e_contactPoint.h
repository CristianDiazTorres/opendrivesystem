#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_contactPoint">
        <xs:restriction base="xs:string">
            <xs:enumeration value="start"/>
            <xs:enumeration value="end"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_contactPoint(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_contactPoint) \
    _OD_STRING_ENUM_CONST(usingType, e_contactPoint, START   , _SC_start) \
    _OD_STRING_ENUM_CONST(usingType, e_contactPoint, END     , _SC_end) \
    EMPTY_COMMAND

struct e_contactPoint : public _e_base
{
    _OD_STRING_ENUM_e_contactPoint(DECLARE)

public:
    e_contactPoint()
    {
        this->value = 0; // Default value
    }
};
}
