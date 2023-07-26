#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_dataQuality_Error">
        <xs:annotation>
            <xs:documentation>The absolute or relative errors of road data are described by &lt;error&gt; elements within the &lt;dataQuality&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:sequence/>
        <xs:attribute name="xyAbsolute" use="required" type="xs:double">
            <xs:annotation>
                <xs:documentation>Absolute error of the road data in x/y direction</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="zAbsolute" use="required" type="xs:double">
            <xs:annotation>
                <xs:documentation>Absolute error of the road data in z direction</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="xyRelative" use="required" type="xs:double">
            <xs:annotation>
                <xs:documentation>Relative error of the road data in x/y direction</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="zRelative" use="required" type="xs:double">
            <xs:annotation>
                <xs:documentation>Relative error of the road data in z direction</xs:documentation>
            </xs:annotation>
        </xs:attribute>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, xyAbsolute , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zAbsolute  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, xyRelative , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zRelative  , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_dataQuality_Error : public _OpenDriveElement
{
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_dataQuality_Error)
};

}

