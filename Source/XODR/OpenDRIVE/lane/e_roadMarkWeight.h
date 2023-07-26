#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_roadMarkWeight">
        <xs:restriction base="xs:string">
            <xs:enumeration value="standard"/>
            <xs:enumeration value="bold"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_roadMarkWeight(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_roadMarkWeight) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkWeight, STANDARD , _SC_standard) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkWeight, BOLD     , _SC_bold) \
    EMPTY_COMMAND

struct e_roadMarkWeight : public _e_base
{
    _OD_STRING_ENUM_e_roadMarkWeight(DECLARE)

public:
    e_roadMarkWeight()
    {
        this->value = 0; // Default value
    }
};
}
