#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_lr_lane_material">
        <xs:annotation>
            <xs:documentation>Stores information about the material of lanes. Each element is valid until a new element is defined. If multiple elements are defined, they must be listed in increasing order.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="sOffset" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, relative to the position of the preceding &lt;laneSection&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="surface" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Surface material code, depending on application</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="friction" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Friction coefficient</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roughness" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Roughness, for example, for sound and motion systems</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string     , surface   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero , friction  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero , roughness , OPTIONAL) lineEnd \
    EMPTY_COMMAND

// Similar to t_road_objects_object_material
struct t_road_lanes_laneSection_lr_lane_material : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes_laneSection_lr_lane_material)
};

}
