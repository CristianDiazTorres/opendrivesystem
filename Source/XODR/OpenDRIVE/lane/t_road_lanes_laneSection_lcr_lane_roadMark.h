#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkType.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkWeight.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkColor.h"
#include "XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lcr_lane_roadMark_laneChange.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_sway.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_type.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_explicit.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_roadMark">
        <xs:annotation>
            <xs:documentation>Defines the style of the line at the outer border of a lane. The style of the center line that separates left and right lanes is determined by the road mark element for the center lane.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="sway" type="t_road_lanes_laneSection_lcr_lane_roadMark_sway" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="type" type="t_road_lanes_laneSection_lcr_lane_roadMark_type" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="explicit" type="t_road_lanes_laneSection_lcr_lane_roadMark_explicit" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position of the &lt;roadMark&gt; element, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_roadMarkType">
                    <xs:annotation>
                        <xs:documentation>Type of the road mark. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="weight" use="optional" type="e_roadMarkWeight">
                    <xs:annotation>
                        <xs:documentation>Weight of the road mark. This attribute is optional if detailed definition is given below. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="color" use="required" type="e_roadMarkColor">
                    <xs:annotation>
                        <xs:documentation>Color of the road mark. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="material" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Material of the road mark. Identifiers to be defined by the user, use "standard" as default value.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Width of the road mark. This attribute is optional if detailed definition is given by &lt;line&gt; element. </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="laneChange" use="optional" type="e_road_lanes_laneSection_lcr_lane_roadMark_laneChange">
                    <xs:annotation>
                        <xs:documentation>Allows a lane change in the indicated direction, taking into account that lanes are numbered in ascending order from right to left. If the attribute is missing, "both" is used as default. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="height" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of road mark above the road, i.e. thickness of the road mark.</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_sOffset) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkType, type                                               , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkWeight, weight                                           , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkColor, color                                             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, material                                                   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_grEqZero, width, DOUBLE_INVALID_VALUE                            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange, laneChange  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, height, DOUBLE_INVALID_VALUE                               , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lcr_lane_roadMark_sway       , sway) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lanes_laneSection_lcr_lane_roadMark_type       , type) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lanes_laneSection_lcr_lane_roadMark_explicit   , explicit) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_roadMark : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_roadMark)
};

}
