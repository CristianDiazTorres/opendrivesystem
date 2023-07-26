#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/t_road_objects_object.h"
#include "XODR/OpenDRIVE/object/t_road_objects_objectReference.h"
#include "XODR/OpenDRIVE/object/t_road_objects_tunnel.h"
#include "XODR/OpenDRIVE/object/t_road_objects_bridge.h"

/*
    <xs:complexType name="t_road_objects">
        <xs:annotation>
            <xs:documentation>Container for all objects along a road.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="object" type="t_road_objects_object" minOccurs="0" maxOccurs="unbounded">
                        <!-- Key Constraints manually added from OpenDRIVE 1.5 -->
                        <xs:key name="k_road_objects_object_outlineId">
                            <xs:selector xpath="outlines/outline"/>
                            <xs:field xpath="@id"/>
                        </xs:key>
                        <!--xs:keyref name="r_road_objects_object_outline_cornerRoad" refer="k_road_objects_object_outlineId">
                            <xs:selector xpath="outlines/outline/cornerRoad"/>
                            <xs:field xpath="@id"/>
                        </xs:keyref>
                        <xs:keyref name="r_road_objects_object_outline_cornerLocal" refer="k_road_objects_object_outlineId">
                            <xs:selector xpath="outlines/outline/cornerLocal"/>
                            <xs:field xpath="@id"/>
                        </xs:keyref-->
                        <xs:keyref name="r_road_objects_object_borders_border" refer="k_road_objects_object_outlineId">
                            <xs:selector xpath="borders/border"/>
                            <xs:field xpath="@outlineId"/>
                        </xs:keyref>
                    </xs:element>
                    <xs:element name="objectReference" type="t_road_objects_objectReference" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="tunnel" type="t_road_objects_tunnel" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="bridge" type="t_road_objects_bridge" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_object) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object         , object) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_objectReference, objectReference) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_tunnel         , tunnel) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_bridge         , bridge) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects)
};

}
