#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_signals_signal_positionRoad">
        <xs:annotation>
            <xs:documentation>Describes the reference point of the physical position road coordinates in cases where it deviates from the logical position. Defines the position on the road.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="roadId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the referenced road</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
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
                <xs:attribute name="zOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z offset from road level to bottom edge of the signal</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hOffset" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Heading offset of the signal (relative to @orientation)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="pitch" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Pitch angle of the signal after applying hOffset, relative to the inertial system (x'y'-plane)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roll" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Roll angle of the signal after applying hOffset and pitch, relative to the inertial system (x''y''-plane)</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _roadId, roadId                        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s_t) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffset                        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, hOffset                        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, pitch, DOUBLE_INVALID_VALUE    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, roll, DOUBLE_INVALID_VALUE     , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_signals_signal_positionRoad : public a_s_t
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_signals_signal_positionRoad)
};

}
