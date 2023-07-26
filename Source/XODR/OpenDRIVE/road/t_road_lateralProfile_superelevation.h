#pragma once

#include "XODR/OpenDRIVE/core/a_s_polynom.h"

/*
<xs:complexType name="t_road_lateralProfile_superelevation">
        <xs:annotation>
            <xs:documentation>Defined as the road section's roll angle around the s-axis. Elements must be defined in increasing order along the reference line. The parameters of an element are valid until the next element starts or the road reference line ends. Per default, the superelevation of a road is zero.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="a" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a, superelevation at @s (ds=0)</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s_polynom) lineEnd \
    EMPTY_COMMAND

struct t_road_lateralProfile_superelevation : public a_s_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lateralProfile_superelevation)
};

}
