#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_borderType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="concrete"/>
            <xs:enumeration value="curb"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_borderType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_borderType) \
    _OD_STRING_ENUM_CONST(usingType, e_borderType, CONCRETE , _SC_concrete) \
    _OD_STRING_ENUM_CONST(usingType, e_borderType, CURB     , _SC_curb) \
    EMPTY_COMMAND

struct e_borderType : public _e_base
{
    _OD_STRING_ENUM_e_borderType(DECLARE)

public:
    e_borderType()
    {
        this->value = 0; // Default value
    }
};
}
