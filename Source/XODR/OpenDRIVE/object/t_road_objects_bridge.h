#pragma once


#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_bridgeType.h"
#include "XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h"

/*
    <xs:complexType name="t_road_objects_bridge">
        <xs:annotation>
            <xs:documentation>Bridges are modeled as objects in OpenDRIVE. Bridges are valid for the whole cross section of a road unless a lane validity record with further restrictions is provided as child element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="validity" type="t_road_objects_object_laneValidity" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="length" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the bridge (in s-direction)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the bridge. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_bridgeType">
                    <xs:annotation>
                        <xs:documentation>Type of bridge. For values see UML Model.</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, length , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name       , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _bridgeId, id      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_bridgeType, type , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_laneValidity, validity) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_bridge : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_bridge)
};

}
