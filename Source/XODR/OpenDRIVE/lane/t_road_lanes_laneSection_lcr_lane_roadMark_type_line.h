#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset_tOffset.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkRule.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkColor.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_roadMark_type_line">
        <xs:annotation>
            <xs:documentation>A road mark may consist of one or more elements. Multiple elements are usually positioned side-by-side. A line definition is valid for a given length of the lane and will be repeated automatically.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="length" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Length of the visible part</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="space" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the gap between the visible parts</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="tOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Lateral offset from the lane border.
If &lt;sway&gt; element is present, the lateral offset follows the sway.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Initial longitudinal offset of the line definition from the start of the road mark definition</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="rule" use="optional" type="e_roadMarkRule">
                    <xs:annotation>
                        <xs:documentation>Rule that must be observed when passing the line from inside, for example, from the lane with the lower absolute ID to the lane with the higher absolute ID. For values see UML Model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Line width</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="color" use="optional" type="e_roadMarkColor">
                    <xs:annotation>
                        <xs:documentation>Line color. If given, this attribute supersedes the definition in the &lt;roadMark&gt; element. For values see UML Model.</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, length         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, space      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_sOffset_tOffset) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkRule, rule   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, width          , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkColor, color , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_roadMark_type_line : public a_sOffset_tOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_roadMark_type_line)
};

}
