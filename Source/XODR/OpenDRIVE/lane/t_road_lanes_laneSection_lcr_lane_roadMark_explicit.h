#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_roadMark_explicit">
        <xs:annotation>
            <xs:documentation>Irregular road markings that cannot be described by repetitive line patterns may be described by individual road marking elements. These explicit definitions also contain &lt;line&gt; elements for the line definition, however, these lines will not be repeated automatically as in repetitive road marking types.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="line" type="t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line, line) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_roadMark_explicit)
};

}
