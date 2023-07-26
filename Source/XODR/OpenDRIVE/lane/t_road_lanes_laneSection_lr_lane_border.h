#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset_polynom.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_border">
        <xs:annotation>
            <xs:documentation>Lane borders are another method to describe the width of lanes. Instead of defining the width directly, lane borders describe the outer limits of a lane, independent of the parameters of their inner borders. In this case, inner lanes are defined as lanes which have the same sign for their ID as the lane currently defined, but with a smaller absolute value for their ID.
Especially when road data is derived from automatic measurements, this type of definition is easier than specifying the lane width because it avoids creating many lane sections.
Lane width and lane border elements are mutually exclusive within the same lane group. If both width and lane border elements are present for a lane section in the OpenDRIVE file, the application shall use the information from the &lt;width&gt; elements.
In OpenDRIVE, lane borders are represented by the &lt;border&gt; element within the &lt;lane&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position of the &lt;border&gt; element , relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="a" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a, border position at @s (ds=0)</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_sOffset_polynom) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane_border : public a_sOffset_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_border)
};

}
