#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_tunnelType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="standard"/>
            <xs:enumeration value="underpass">
                <xs:annotation>
                    <xs:documentation>i.e. sides are open for daylight</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_tunnelType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_tunnelType) \
    _OD_STRING_ENUM_CONST(usingType, e_tunnelType, STANDARD    , _SC_standard) \
    _OD_STRING_ENUM_CONST(usingType, e_tunnelType, UNDERPASS   , _SC_underpass) \
    EMPTY_COMMAND

struct e_tunnelType : public _e_base
{
    _OD_STRING_ENUM_e_tunnelType(DECLARE)

public:
    e_tunnelType()
    {
        this->value = 0; // Default value
    }
};
}
