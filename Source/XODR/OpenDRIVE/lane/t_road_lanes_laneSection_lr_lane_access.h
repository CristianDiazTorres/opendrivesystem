#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"
#include "XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lr_lane_access_rule.h"
#include "XODR/OpenDRIVE/lane/e_accessRestrictionType.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_access">
        <xs:annotation>
            <xs:documentation>Defines access restrictions for certain types of road users.
Each element is valid in direction of the increasing s co-ordinate until a new element is defined. If multiple elements are defined, they must be listed in increasing order.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="rule" use="optional" type="e_road_lanes_laneSection_lr_lane_access_rule">
                    <xs:annotation>
                        <xs:documentation>Specifies whether the participant given in the attribute @restriction is allowed or denied access to the given lane</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="restriction" use="required" type="e_accessRestrictionType">
                    <xs:annotation>
                        <xs:documentation>Identifier of the participant to whom the restriction applies. For values, see UML Model</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_lanes_laneSection_lr_lane_access_rule   , rule          , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_accessRestrictionType                        , restriction   , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane_access : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_access)
};

}
