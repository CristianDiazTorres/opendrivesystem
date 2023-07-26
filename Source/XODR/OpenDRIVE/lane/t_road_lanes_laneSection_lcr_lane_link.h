#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_link">
        <xs:annotation>
            <xs:documentation>For links between lanes with an identical reference line, the lane predecessor and successor information provide the IDs of lanes on the preceding or following lane section. This element may only be omitted, if lanes end at a junction or have no physical link.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="predecessor" type="t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="successor" type="t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor" minOccurs="0" maxOccurs="unbounded"/>
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
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor, predecessor) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor, successor) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_link : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_link)
};

}
