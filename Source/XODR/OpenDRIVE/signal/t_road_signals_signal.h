#pragma once


#include "XODR/OpenDRIVE/core/e_unit.h"
#include "XODR/OpenDRIVE/core/t_yesNo.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/object/e_orientation.h"
#include "XODR/OpenDRIVE/road/e_countryCode.h"
#include "XODR/OpenDRIVE/signal/e_road_signals_signal_type.h"
#include "XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h"
#include "XODR/OpenDRIVE/signal/t_road_signals_signal_dependency.h"
#include "XODR/OpenDRIVE/signal/t_road_signals_signal_reference.h"
#include "XODR/OpenDRIVE/signal/t_road_signals_signal_positionRoad.h"
#include "XODR/OpenDRIVE/signal/t_road_signals_signal_positionInertial.h"

/*
    <xs:complexType name="t_road_signals_signal">
        <xs:annotation>
            <xs:documentation>Used to provide information about signals along a road. Consists of a main element and an optional lane validity element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="validity" type="t_road_objects_object_laneValidity" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="dependency" type="t_road_signals_signal_dependency" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="reference" type="t_road_signals_signal_reference" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:choice minOccurs="0" maxOccurs="1">
                        <xs:element name="positionRoad" type="t_road_signals_signal_positionRoad" minOccurs="1" maxOccurs="1"/>
                        <xs:element name="positionInertial" type="t_road_signals_signal_positionInertial" minOccurs="1" maxOccurs="1"/>
                    </xs:choice>
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
                        <xs:documentation>Unique ID of the signal within the OpenDRIVE file</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the signal. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dynamic" use="required" type="t_yesNo">
                    <xs:annotation>
                        <xs:documentation>Indicates whether the signal is dynamic or static. Example: traffic light is dynamic</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="orientation" use="required" type="e_orientation">
                    <xs:annotation>
                        <xs:documentation>"+" = valid in positive s- direction
"-" = valid in negative s- direction
"none" = valid in both directions</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z offset from the road to bottom edge of the signal. This represents the vertical clearance of the object. Relative to the reference line.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="country" use="optional" type="e_countryCode">
                    <xs:annotation>
                        <xs:documentation>Country code of the road, see ISO 3166-1, alpha-2 codes.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="countryRevision" use="optional" type="xs:string"/>
                <xs:attribute name="type" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type identifier according to country code
or "-1" / "none". See extra document.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="subtype" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Subtype identifier according to country code or "-1" / "none"</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="value" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Value of the signal, if value is given, unit is mandatory</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="unit" use="optional" type="e_unit">
                    <xs:annotation>
                        <xs:documentation>Unit of @value</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="height" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Height of the signal, measured from bottom edge of the signal</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="width" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Width of the signal</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="text" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Additional text associated with the signal, for example, text on city limit "City\nBadAibling"</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Heading offset of the signal (relative to @orientation, if orientation is equal to "+" or "-")
Heading offset of the signal (relative to reference line, if orientation is equal to "none" )</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="pitch" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Pitch angle of the signal, relative to the inertial system (xy-plane)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roll" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Roll angle of the signal after applying pitch, relative to the inertial system (x''y''-plane) </xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name                            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_yesNo, dynamic, false                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_orientation, orientation         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffset                         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, e_countryCode, country                  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, countryRevision                 , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_signals_signal_type, type   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, subtype                         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, value, DOUBLE_INVALID_VALUE     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_unit, unit                       , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_grEqZero, height, DOUBLE_INVALID_VALUE, OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_grEqZero, width, DOUBLE_INVALID_VALUE , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, text                            , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, hOffset, DOUBLE_INVALID_VALUE   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, pitch, DOUBLE_INVALID_VALUE     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, roll, DOUBLE_INVALID_VALUE      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_objects_object_laneValidity    , validity) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_signals_signal_dependency      , dependency) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_signals_signal_reference       , reference) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_signals_signal_positionRoad    , positionRoad) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_signals_signal_positionInertial, positionInertial) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_signals_signal : public a_s_t
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_signals_signal)
};

}
