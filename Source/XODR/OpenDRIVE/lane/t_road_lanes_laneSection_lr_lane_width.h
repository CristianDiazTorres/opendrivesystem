#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset_polynom.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_width">
        <xs:annotation>
            <xs:documentation>The width of a lane is defined along the t-coordinate. The width of a lane may change within a lane section.
Lane width and lane border elements are mutually exclusive within the same lane group. If both width and lane border elements are present for a lane section in the OpenDRIVE file, the application must use the information from the &lt;width&gt; elements.
In OpenDRIVE, lane width is described by the &lt;width&gt; element within the &lt;lane&gt; element. </xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position of the &lt;width&gt; element, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="a" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Polynom parameter a, width at @s (ds=0)</xs:documentation>
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

struct t_road_lanes_laneSection_lr_lane_width : public a_sOffset_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_width)
};

}
