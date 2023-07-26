#pragma once

#include "XODR/OpenDRIVE/core/a_s_t_polynom.h"

/*
    <xs:complexType name="t_road_lateralProfile_shape">
        <xs:annotation>
            <xs:documentation>Defined as the road section's surface relative to the reference plane. There may be several shape definitions at one s-position that have different t-values, thereby describing the curvy shape of the road.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="t" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>t-coordinate of start position </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="a" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a, relative height at @t (dt=0)</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s_t_polynom) lineEnd \
    EMPTY_COMMAND

struct t_road_lateralProfile_shape : public a_s_t_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lateralProfile_shape)
};

}
