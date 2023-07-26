#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_bool_default_true.h"
#include "XODR/OpenDRIVE/object/e_borderType.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object_markings_marking_cornerReference.h"

/*
    <xs:complexType name="t_road_objects_object_borders_border">
        <xs:annotation>
            <xs:documentation>Specifies a border along certain outline points.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="cornerReference" type="t_road_objects_object_markings_marking_cornerReference" minOccurs="2" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="width" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Border width</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_borderType">
                    <xs:annotation>
                        <xs:documentation>Appearance of border. For values see UML Model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="outlineId" use="required" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>ID of the outline to use</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="useCompleteOutline" use="optional" type="t_bool">
                    <xs:annotation>
                        <xs:documentation>Use all outline points for border. "true" is used as default.</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero         , width             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_borderType       , type              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _outlineId         , outlineId         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_bool_default_true, useCompleteOutline, OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 2, x, t_road_objects_object_markings_marking_cornerReference, cornerReference) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_borders_border : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_borders_border)

};

}
