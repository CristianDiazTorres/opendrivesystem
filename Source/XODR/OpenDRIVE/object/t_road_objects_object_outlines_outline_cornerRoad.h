#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_objects_object_outlines_outline_cornerRoad">
        <xs:annotation>
            <xs:documentation>Defines a corner point on the object's outline in road coordinates.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of the corner</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="t" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>t-coordinate of the corner</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dz" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>dz of the corner relative to road reference line</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="height" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of the object at this corner, along the z-axis</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="optional" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>ID of the outline point. Must be unique within one outline</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s_t) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, dz     , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, height , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, _outlinePointId, id, INTEGER_INVALID_VALUE, OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_outlines_outline_cornerRoad : public a_s_t
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_outlines_outline_cornerRoad)
};

}
