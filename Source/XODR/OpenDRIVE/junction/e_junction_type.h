#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_junction_type">
        <xs:restriction base="xs:string">
            <xs:enumeration value="default"/>
            <xs:enumeration value="virtual"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_junction_type(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_junction_type) \
    _OD_STRING_ENUM_CONST(usingType, e_junction_type, DEFAULT , _SC_default) \
    _OD_STRING_ENUM_CONST(usingType, e_junction_type, VIRTUAL , _SC_virtual) \
    EMPTY_COMMAND

struct e_junction_type : public _e_base
{
    _OD_STRING_ENUM_e_junction_type(DECLARE)

public:
    e_junction_type()
    {
        this->value = 0; // Default value
    }
};
}
