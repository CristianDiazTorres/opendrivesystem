#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"

/*
    <xs:complexType name="t_road_objects_object_material">
        <xs:annotation>
            <xs:documentation>Describes the material properties of objects, for example, patches that are part of the road surface but deviate from the standard road material. Supersedes the material specified in the &lt;road material&gt; element and is valid only within the outline of the parent road object.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="surface" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Surface material code, depending on application</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="friction" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Friction value, depending on application</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roughness" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Roughness, for example, for sound and motion systems, depending on application</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_object) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string     , surface   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero , friction  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero , roughness , OPTIONAL) lineEnd \
    EMPTY_COMMAND

// Similar to t_road_lanes_laneSection_lr_lane_material
struct t_road_objects_object_material : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_material)

};

}
