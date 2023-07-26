#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_height">
        <xs:annotation>
            <xs:documentation>Lane height shall be defined along the h-coordinate. Lane height may be used to elevate a lane independent from the road elevation. Lane height is used to implement small-scale elevation such as raising pedestrian walkways. Lane height is specified as offset from the road (including elevation, superelevation, shape) in z direction.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="inner" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Inner offset from road level</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="outer" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Outer offset from road level</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, inner, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, outer, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane_height : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_height)
};

}
