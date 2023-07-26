#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_roadMarkRule">
        <xs:restriction base="xs:string">
            <xs:enumeration value="no passing"/>
            <xs:enumeration value="caution"/>
            <xs:enumeration value="none"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_roadMarkRule(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_roadMarkRule) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkRule, NO_PASSING  , _SC_no_passing_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkRule, CAUTION     , _SC_caution) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkRule, NONE        , _SC_none) \
    EMPTY_COMMAND

struct e_roadMarkRule : public _e_base
{
    _OD_STRING_ENUM_e_roadMarkRule(DECLARE)

public:
    e_roadMarkRule()
    {
        this->value = 0; // Default value
    }
};
}
