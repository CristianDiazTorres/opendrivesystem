#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_trafficRule">
        <xs:restriction base="xs:string">
            <xs:enumeration value="RHT"/>
            <xs:enumeration value="LHT"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_trafficRule(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_trafficRule) \
    _OD_STRING_ENUM_CONST(usingType, e_trafficRule, RHT  , _SC_RHT) \
    _OD_STRING_ENUM_CONST(usingType, e_trafficRule, LHT  , _SC_LHT) \
    EMPTY_COMMAND

struct e_trafficRule : public _e_base
{
    _OD_STRING_ENUM_e_trafficRule(DECLARE)

public:
    e_trafficRule()
    {
        this->value = 0; // Default value
    }
};
}
