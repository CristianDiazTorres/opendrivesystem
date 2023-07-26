#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_sideType.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkWeight.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkColor.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_markings_marking_cornerReference.h"

/*
    <xs:complexType name="t_road_objects_object_markings_marking">
        <xs:annotation>
            <xs:documentation>Specifies a marking that is either attached to one side of the object bounding box or referencing outline points.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="cornerReference" type="t_road_objects_object_markings_marking_cornerReference" minOccurs="2" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="side" use="required" type="e_sideType">
                    <xs:annotation>
                        <xs:documentation>Side of the bounding box described in &lt;object&gt; element in the local coordinate system u/v. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="weight" use="optional" type="e_roadMarkWeight">
                    <xs:annotation>
                        <xs:documentation>Optical "weight" of the marking. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Width of the marking.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="color" use="required" type="e_roadMarkColor">
                    <xs:annotation>
                        <xs:documentation>Color of the marking. For values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffset" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Height of road mark above the road, i.e. thickness of the road mark</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="spaceLength" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the gap between the visible parts</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="lineLength" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Length of the visible part</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="startOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Lateral offset in u-direction from start of bounding box side where the first marking starts</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="stopOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Lateral offset in u-direction from end of bounding box side where the marking ends</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_sideType, side          , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkWeight, weight  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, width             , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadMarkColor, color    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, zOffset       , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, spaceLength   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, lineLength        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, startOffset       , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, stopOffset        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 2, x, t_road_objects_object_markings_marking_cornerReference, cornerReference) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_markings_marking : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_markings_marking)

public:
    double calcDistance(const a_s_t& st) const;
    void updateST(const a_s_t &st);
};

}
