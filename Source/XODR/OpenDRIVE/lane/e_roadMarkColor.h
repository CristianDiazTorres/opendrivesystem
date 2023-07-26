#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_roadMarkColor">
        <xs:annotation>
            <xs:documentation>The known keywords for the road mark color information are:</xs:documentation>
        </xs:annotation>
        <xs:restriction base="xs:string">
            <xs:enumeration value="standard">
                <xs:annotation>
                    <xs:documentation>equivalent to "white"</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="blue"/>
            <xs:enumeration value="green"/>
            <xs:enumeration value="red"/>
            <xs:enumeration value="white"/>
            <xs:enumeration value="yellow"/>
            <xs:enumeration value="orange"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_roadMarkColor(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_roadMarkColor) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, STANDARD   , _SC_standard) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, BLUE       , _SC_blue) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, GREEN      , _SC_green) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, RED        , _SC_red) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, WHITE      , _SC_white) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, YELLOW     , _SC_yellow) \
    _OD_STRING_ENUM_CONST(usingType, e_roadMarkColor, ORANGE     , _SC_orange) \
    EMPTY_COMMAND

struct e_roadMarkColor : public _e_base
{
    _OD_STRING_ENUM_e_roadMarkColor(DECLARE)

public:
    e_roadMarkColor()
    {
        this->value = 0; // Default value
    }
};
}
