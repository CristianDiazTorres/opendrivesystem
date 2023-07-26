#pragma once


#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_orientation.h"
#include "XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h"

/*
    <xs:complexType name="t_road_signals_signalReference">
        <xs:annotation>
            <xs:documentation>Refers to the same, that is, identical signal from multiple roads.
The referenced signals require a unique ID. The &lt;signalReference&gt; element consists of a main element and an optional lane validity element.</xs:documentation>
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
                <xs:attribute name="t" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>t-coordinate</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the referenced signal within the database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="orientation" use="required" type="e_orientation">
                    <xs:annotation>
                        <xs:documentation>"+" = valid in positive s-direction
"-" = valid in negative s-direction
"none" = valid in both directions</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_signal) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s_t) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _signalId, id                           , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_orientation, orientation              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_laneValidity    , validity) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_signals_signalReference : public a_s_t
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_signals_signalReference)
};

}
