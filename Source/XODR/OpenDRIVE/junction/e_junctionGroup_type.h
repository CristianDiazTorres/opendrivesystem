#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_junctionGroup_type">
        <xs:restriction base="xs:string">
            <xs:enumeration value="roundabout"/>
            <xs:enumeration value="unknown"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_junctionGroup_type(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_junctionGroup_type) \
    _OD_STRING_ENUM_CONST(usingType, e_junctionGroup_type, ROUNDABOUT    , _SC_roundabout) \
    _OD_STRING_ENUM_CONST(usingType, e_junctionGroup_type, UNKNOWN       , _SC_unknown) \
    EMPTY_COMMAND

struct e_junctionGroup_type : public _e_base
{
    _OD_STRING_ENUM_e_junctionGroup_type(DECLARE)

public:
    e_junctionGroup_type()
    {
        this->value = 0; // Default value
    }
};
}
