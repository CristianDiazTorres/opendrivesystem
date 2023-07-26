#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_countryCode_deprecated">
        <xs:restriction base="xs:string">
            <xs:enumeration value="OpenDRIVE"/>
            <xs:enumeration value="Austria"/>
            <xs:enumeration value="Brazil"/>
            <xs:enumeration value="China"/>
            <xs:enumeration value="France"/>
            <xs:enumeration value="Germany"/>
            <xs:enumeration value="Italy"/>
            <xs:enumeration value="Switzerland"/>
            <xs:enumeration value="USA"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_countryCode_deprecated(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_countryCode_deprecated) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, OPENDRIVE     , _SC_OpenDRIVE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, AUSTRIA       , _SC_Austria) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, BRAZIL        , _SC_Brazil) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, CHINA         , _SC_China) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, FRANCE        , _SC_France) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, GERMANY       , _SC_Germany) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, ITALY         , _SC_Italy) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, SWITZERLAND   , _SC_Switzerland) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_deprecated, USA           , _SC_USA) \
    EMPTY_COMMAND

struct e_countryCode_deprecated : public _e_base
{
    _OD_STRING_ENUM_e_countryCode_deprecated(DECLARE)

public:
    e_countryCode_deprecated()
    {
        this->value = 0; // Default value
    }
};
}
