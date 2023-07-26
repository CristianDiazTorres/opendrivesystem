#pragma once

#include "XODR/OpenDRIVE/core/a_xy_hdg.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"

/*
    <xs:complexType name="t_header_Offset">
        <xs:annotation>
            <xs:documentation>To avoid large coordinates, an offset of the whole dataset may be applied using the &lt;offset&gt; element. It enables inertial relocation and re-orientation of datasets. The dataset is first translated by @x, @y, and @z. Afterwards, it is rotated by @hdg around the new origin. Rotation around the z-axis should be avoided.In OpenDRIVE, the offset of a database is represented by the &lt;offset&gt; element within the &lt;header&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="x" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Inertial x offset</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="y" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Inertial y offset</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="z" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Inertial z offset</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hdg" use="required" type="xs:float">
                    <xs:annotation>
                        <xs:documentation>Heading offset (rotation around resulting z-axis)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_xy_hdg) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double        , z  , REQUIRED) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_header_Offset : public _OpenDriveElement, public a_xy_hdg
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_header_Offset)
};

}

