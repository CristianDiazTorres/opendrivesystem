#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/e_laneType.h"
#include "XODR/OpenDRIVE/lane/t_bool_default_false.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_link.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_border.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_width.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_material.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_speed.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_access.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_height.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_rule.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane">
        <xs:annotation>
            <xs:documentation>Lane elements are included in left/center/right elements. Lane elements should represent the lanes from left to right, that is, with descending ID.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="link" type="t_road_lanes_laneSection_lcr_lane_link" minOccurs="0" maxOccurs="1"/>
                    <xs:choice minOccurs="1" maxOccurs="unbounded">
                        <xs:element name="border" type="t_road_lanes_laneSection_lr_lane_border" minOccurs="0" maxOccurs="unbounded"/>
                        <xs:element name="width" type="t_road_lanes_laneSection_lr_lane_width" minOccurs="0" maxOccurs="unbounded"/>
                    </xs:choice>
                    <xs:element name="roadMark" type="t_road_lanes_laneSection_lcr_lane_roadMark" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="material" type="t_road_lanes_laneSection_lr_lane_material" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="speed" type="t_road_lanes_laneSection_lr_lane_speed" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="access" type="t_road_lanes_laneSection_lr_lane_access" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="height" type="t_road_lanes_laneSection_lr_lane_height" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="rule" type="t_road_lanes_laneSection_lr_lane_rule" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="type" use="required" type="e_laneType">
                    <xs:annotation>
                        <xs:documentation>Type of the lane. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="level" use="optional" type="t_bool">
                    <xs:annotation>
                        <xs:documentation>"true" = keep lane on level, that is, do not apply superelevation;
"false" = apply superelevation to this lane (default, also used if attribute level is missing)</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_laneType             , type      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_bool_default_false   , level     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lanes_laneSection_lcr_lane_link    , link) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_border   , border) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_width    , width) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lcr_lane_roadMark, roadMark) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_material , material) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_speed    , speed) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_access   , access) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_height   , height) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneSection_lr_lane_rule     , rule) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_lr_lane : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane)

public:
    void setDefaultValues();

public:
    double getWidth() const
    {
        if (width_sequence.isEmpty())
            return 0;
        return width_sequence.first().a;
    }
};

}
