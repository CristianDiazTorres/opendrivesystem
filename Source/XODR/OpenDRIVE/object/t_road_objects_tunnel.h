#pragma once


#include "XODR/OpenDRIVE/core/t_zeroOne.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_tunnelType.h"
#include "XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h"

/*
    <xs:complexType name="t_road_objects_tunnel">
        <xs:annotation>
            <xs:documentation>Tunnels are modeled as objects in OpenDRIVE. Tunnels apply to the entire cross section of the road within the given range unless a lane validity element with further restrictions is provided as child element.</xs:documentation>
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
                        <xs:documentation>Length of the tunnel (in s-direction)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the tunnel. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_tunnelType">
                    <xs:annotation>
                        <xs:documentation>Type of tunnel. For values see UML Model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="lighting" use="optional" type="t_zeroOne">
                    <xs:annotation>
                        <xs:documentation>Degree of artificial tunnel lighting. Depends on the application.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="daylight" use="optional" type="t_zeroOne">
                    <xs:annotation>
                        <xs:documentation>Degree of daylight intruding the tunnel. Depends on the application.</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, length     , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name           , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _tunnelId, id          , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_tunnelType, type     , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_zeroOne, lighting    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_zeroOne, daylight    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_laneValidity    , validity) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_tunnel : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_tunnel)
};

}
