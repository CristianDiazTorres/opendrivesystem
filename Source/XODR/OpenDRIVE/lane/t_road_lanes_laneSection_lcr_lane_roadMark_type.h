#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_type_line.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_roadMark_type">
        <xs:annotation>
            <xs:documentation>Each type definition shall contain one or more line definitions with additional information about the lines that the road mark is composed of.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="line" type="t_road_lanes_laneSection_lcr_lane_roadMark_type_line" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the road mark type. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Accumulated width of the road mark. In case of several &lt;line&gt; elements this @width is the sum of all @width of &lt;line&gt; elements and spaces in between, necessary to form the road mark. This attribute supersedes the definition in the &lt;roadMark&gt; element.</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, width, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_lanes_laneSection_lcr_lane_roadMark_type_line   , line) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_roadMark_type : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_roadMark_type)
};

}
