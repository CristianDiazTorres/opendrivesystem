#pragma once

#include "XODR/OpenDRIVE/core/a_polynom.h"

/*
    <xs:complexType name="t_road_planView_geometry_poly3">
        <xs:annotation>
            <xs:documentation>
In OpenDRIVE, a cubic polynom is represented by a &lt;poly3&gt; element within the &lt;geometry&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="a" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="b" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter b</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="c" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter c</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="d" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter d</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_polynom) lineEnd \
    EMPTY_COMMAND

struct t_road_planView_geometry_poly3 : public _OpenDriveElement, public a_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_planView_geometry_poly3)
};

}
