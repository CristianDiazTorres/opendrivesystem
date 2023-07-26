#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_objects_object_outlines_outline_cornerLocal">
        <xs:annotation>
            <xs:documentation>Used to describe complex forms of objects. Defines a corner point on the object outline relative to the object pivot point in local u/v-coordinates. The pivot point and the orientation of the object are given by the s/t/heading arguments of the &lt;object&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="u" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Local u-coordinate of the corner</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="v" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Local v-coordinate of the corner</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="z" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Local z-coordinate of the corner</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="height" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of the object at this corner, along the z-axis</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="optional" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>ID of the outline point. Shall be unique within one outline.</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, u      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, v      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, z      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, height , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, _outlinePointId, id, INTEGER_INVALID_VALUE, OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_outlines_outline_cornerLocal : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_outlines_outline_cornerLocal)

};

}
