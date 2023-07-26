#pragma once

#include "XODR/OpenDRIVE/road/e_paramPoly3_pRange.h"

/*
    <xs:complexType name="t_road_planView_geometry_paramPoly3">
        <xs:annotation>
            <xs:documentation>In OpenDRIVE, parametric cubic curves are represented by &lt;paramPoly3&gt; elements within the &lt;geometry&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="aU" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a for u</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="bU" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter b for u</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="cU" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter c for u</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dU" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter d for u</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="aV" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a for v</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="bV" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter b for v</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="cV" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter c for v</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dV" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter d for v</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="pRange" use="required" type="e_paramPoly3_pRange">
                    <xs:annotation>
                        <xs:documentation>Range of parameter p.
- Case arcLength: p in [0, @length of &lt;geometry&gt;]
- Case normalized: p in [0, 1]</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, aU                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, bU                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, cU                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, dU                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, aV                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, bV                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, cV                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, dV                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_paramPoly3_pRange, pRange, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_planView_geometry_paramPoly3 : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_planView_geometry_paramPoly3)
};

}
