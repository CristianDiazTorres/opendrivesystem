#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_planView_geometry_spiral">
        <xs:annotation>
            <xs:documentation>In OpenDRIVE, a spiral is represented by a &lt;spiral&gt; element within the &lt;geometry&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="curvStart" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Curvature at the start of the element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="curvEnd" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Curvature at the end of the element</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, curvStart  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, curvEnd    , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_planView_geometry_spiral : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_planView_geometry_spiral)
};

}
