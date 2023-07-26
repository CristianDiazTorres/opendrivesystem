#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"
#include "XODR/OpenDRIVE/core/e_unitSpeed.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_speed">
        <xs:annotation>
            <xs:documentation>Defines the maximum allowed speed on a given lane. Each element is valid in direction of the increasing s-coordinate until a new element is defined.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="max" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Maximum allowed speed. If the attribute unit is not specified, m/s is used as default. </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="unit" use="optional" type="e_unitSpeed">
                    <xs:annotation>
                        <xs:documentation>Unit of the attribute max. For values, see UML Model</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero , max  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_unitSpeed, unit , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane_speed : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_speed)
};

}
