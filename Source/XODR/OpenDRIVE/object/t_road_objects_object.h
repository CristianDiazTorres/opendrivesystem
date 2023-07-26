#pragma once


#include "XODR/OpenDRIVE/core/t_yesNo.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_objectType.h"
#include "XODR/OpenDRIVE/object/e_orientation.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_repeat.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_outlines.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_material.h"
#include "XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_parkingSpace.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_markings.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_borders.h"

/*
    <xs:complexType name="t_road_objects_object">
        <xs:annotation>
            <xs:documentation>Describes common 3D objects that have a reference to a given road. Objects are items that influence a road by expanding, delimiting, and supplementing its course. The most common examples are parking spaces, crosswalks, and traffic barriers.
There are two ways to describe the bounding box of objects.
    - For an angular object: definition of the width, length and height.
    - For a circular object: definition of the radius and height.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="repeat" type="t_road_objects_object_repeat" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="outline" type="t_road_objects_object_outlines_outline" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="outlines" type="t_road_objects_object_outlines" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="material" type="t_road_objects_object_material" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="validity" type="t_road_objects_object_laneValidity" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="parkingSpace" type="t_road_objects_object_parkingSpace" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="markings" type="t_road_objects_object_markings" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="borders" type="t_road_objects_object_borders" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="t" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>t-coordinate of object's origin</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-offset of object's origin relative to the elevation of the reference line</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="e_objectType">
                    <xs:annotation>
                        <xs:documentation>Type of object. For values, see UML.
For a parking space, the &lt;parkingSpace&gt; element may be used additionally.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="validLength" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Validity of object along s-axis (0.0 for point object)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="orientation" use="optional" type="e_orientation">
                    <xs:annotation>
                        <xs:documentation>"+" = valid in positive s-direction
"-" = valid in negative s-direction
"none" = valid in both directions
(does not affect the heading)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="subtype" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Variant of a type</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dynamic" use="optional" type="t_yesNo">
                    <xs:annotation>
                        <xs:documentation>Indicates whether the object is dynamic or static, default value is "no" (static). Dynamic object cannot change its position.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hdg" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Heading angle of the object relative to road direction</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the object. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="pitch" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Pitch angle relative to the x/y-plane</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roll" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Roll angle relative to the x/y-plane</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="height" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of the object's bounding box. @height is defined in the local coordinate system u/v along the z-axis</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of object's origin</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="length" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Length of the object's bounding box, alternative to @radius.
@length is defined in the local coordinate system u/v along the v-axis</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Width of the object's bounding box, alternative to @radius.
@width is defined in the local coordinate system u/v along the u-axis</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="radius" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>radius of the circular object's bounding box, alternative to @length and @width. @radius is defined in the local coordinate system u/v</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffset           , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_objectType, type        , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, validLength   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_orientation, orientation, OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, subtype           , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_yesNo, dynamic, _SC_no  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, hdg               , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name              , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, pitch             , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _objectId, id             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, roll              , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, height            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, length            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, width             , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, radius            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_repeat          , repeat) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects_object_outlines_outline, outline) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects_object_outlines        , outlines) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_material        , material) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_laneValidity    , validity) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects_object_parkingSpace    , parkingSpace) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects_object_markings        , markings) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects_object_borders         , borders) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object : public a_s_t
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object)
};

}
