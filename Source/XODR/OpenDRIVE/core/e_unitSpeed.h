#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_unitSpeed">
        <xs:restriction base="xs:string">
            <xs:enumeration value="m/s"/>
            <xs:enumeration value="mph"/>
            <xs:enumeration value="km/h"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_unitSpeed(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_unitSpeed) \
    _OD_STRING_ENUM_CONST(usingType, e_unitSpeed, M_S    , _SC_m_s_A) \
    _OD_STRING_ENUM_CONST(usingType, e_unitSpeed, MPH    , _SC_mph) \
    _OD_STRING_ENUM_CONST(usingType, e_unitSpeed, KM_H   , _SC_km_h_A) \
    EMPTY_COMMAND

struct e_unitSpeed : public _e_base
{
    _OD_STRING_ENUM_e_unitSpeed(DECLARE)

public:
    e_unitSpeed()
    {
        this->value = 0; // Default value
    }
};

}

