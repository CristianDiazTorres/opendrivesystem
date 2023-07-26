#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_paramPoly3_pRange">
        <xs:restriction base="xs:string">
            <xs:enumeration value="arcLength"/>
            <xs:enumeration value="normalized"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_paramPoly3_pRange(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_paramPoly3_pRange) \
    _OD_STRING_ENUM_CONST(usingType, e_paramPoly3_pRange, ARCLENGTH  , _SC_arcLength) \
    _OD_STRING_ENUM_CONST(usingType, e_paramPoly3_pRange, NORMALIZED , _SC_normalized) \
    EMPTY_COMMAND

struct e_paramPoly3_pRange : public _e_base
{
    _OD_STRING_ENUM_e_paramPoly3_pRange(DECLARE)

public:
    e_paramPoly3_pRange()
    {
        this->value = 0; // Default value
    }
};
}
