#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_outlineFillType.h"
#include "XODR/OpenDRIVE/lane/e_laneType.h"
#include "XODR/OpenDRIVE/lane/t_bool_default_true.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline_cornerRoad.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline_cornerLocal.h"

/*
    <xs:complexType name="t_road_objects_object_outlines_outline">
        <xs:annotation>
            <xs:documentation>Defines a series of corner points, including the height of the object relative to the road reference line. For areas, the points should be listed in counter-clockwise order.
An &lt;outline&gt; element shall be followed by one or more &lt;cornerRoad&gt; element or by one or more &lt;cornerLocal&gt; element.

OpenDRIVE 1.4 outline definitions (without &lt;outlines&gt; parent element) shall still be supported.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:choice minOccurs="0" maxOccurs="1">
                        <xs:element name="cornerRoad" type="t_road_objects_object_outlines_outline_cornerRoad" minOccurs="0" maxOccurs="unbounded"/>
                        <xs:element name="cornerLocal" type="t_road_objects_object_outlines_outline_cornerLocal" minOccurs="0" maxOccurs="unbounded"/>
                    </xs:choice>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="id" use="optional" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>ID of the outline. Must be unique within one object.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="fillType" use="optional" type="e_outlineFillType">
                    <xs:annotation>
                        <xs:documentation>Type used to fill the area inside the outline. For values see UML Model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="outer" use="optional" type="t_bool">
                    <xs:annotation>
                        <xs:documentation>Defines if outline is an outer outline of the object.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="closed" use="optional" type="t_bool">
                    <xs:annotation>
                        <xs:documentation>If true, the outline describes an area, not a linear feature.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="laneType" use="optional" type="e_laneType">
                    <xs:annotation>
                        <xs:documentation>Describes the lane type of the outline. For values see UML Model.</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _outlineId, id                 , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_outlineFillType, fillType    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_bool_default_true, outer     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_bool_default_true, closed    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_laneType, laneType           , REQUIRED/*OPTIONAL*/) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_outlines_outline_cornerRoad , cornerRoad) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_outlines_outline_cornerLocal, cornerLocal) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_outlines_outline : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_outlines_outline)

};

}
