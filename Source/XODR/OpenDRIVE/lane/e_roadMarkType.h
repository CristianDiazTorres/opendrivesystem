#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_roadMarkType">
        <xs:annotation>
            <xs:documentation>The known keywords for the simplified road mark type information are:</xs:documentation>
        </xs:annotation>
        <xs:restriction base="xs:string">
            <xs:enumeration value="none"/>
            <xs:enumeration value="solid"/>
            <xs:enumeration value="broken"/>
            <xs:enumeration value="solid solid">
                <xs:annotation>
                    <xs:documentation>for double solid line</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="solid broken">
                <xs:annotation>
                    <xs:documentation>from inside to outside, exception: center lane - from left to right</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="broken solid">
                <xs:annotation>
                    <xs:documentation>from inside to outside, exception: center lane - from left to right</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="broken broken">
                <xs:annotation>
                    <xs:documentation>from inside to outside, exception: center lane - from left to right</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="botts dots"/>
            <xs:enumeration value="grass">
                <xs:annotation>
                    <xs:documentation>meaning a grass edge</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="curb"/>
            <xs:enumeration value="custom">
                <xs:annotation>
                    <xs:documentation>if detailed description is given in child tags</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="edge">
                <xs:annotation>
                    <xs:documentation>describing the limit of usable space on a road</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_roadMarkType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_roadMarkType) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, NONE            , _SC_none) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, SOLID           , _SC_solid) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, BROKEN          , _SC_broken) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, SOLID_SOLID     , _SC_solid_solid_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, SOLID_BROKEN    , _SC_solid_broken_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, BROKEN_SOLID    , _SC_broken_solid_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, BROKEN_BROKEN   , _SC_broken_broken_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, BOTTS_DOTS      , _SC_botts_dots_A) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, GRASS           , _SC_grass) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, CURB            , _SC_curb) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, CUSTOM          , _SC_custom) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkType, EDGE            , _SC_edge) \
    EMPTY_COMMAND

struct e_roadMarkType : public _e_base
{
    _OD_STRING_ENUM_e_roadMarkType(DECLARE)

public:
    e_roadMarkType()
    {
        this->value = 0; // Default value
    }
};
}
