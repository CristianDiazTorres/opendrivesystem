#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_rule">
        <xs:annotation>
            <xs:documentation>Used to add rules that are not covered by any of the other lane attributes that are described in this specification.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="value" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Free text; currently recommended values are
"no stopping at any time"
"disabled parking"
"car pool"</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, value, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane_rule : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_rule)
};

}
