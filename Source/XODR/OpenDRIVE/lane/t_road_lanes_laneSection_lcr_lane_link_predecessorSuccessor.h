#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor">
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="id" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>ID of the preceding / succeeding linked lane</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId, id, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor)

};

}
