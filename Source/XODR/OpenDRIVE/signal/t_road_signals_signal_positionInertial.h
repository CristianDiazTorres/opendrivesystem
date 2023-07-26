#pragma once

#include "XODR/OpenDRIVE/core/a_xy_hdg.h"
#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_signals_signal_positionInertial">
        <xs:annotation>
            <xs:documentation>Describes the reference point of the physical position in inertial coordinates in cases where it deviates from the logical position. Defines the inertial position.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="x" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>x-coordinate</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="y" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>y-coordinate</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="z" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-coordinate</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hdg" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Heading of the signal, relative to the inertial system</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="pitch" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Pitch angle of the signal after applying heading, relative to the inertial system (x'y'-plane)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="roll" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Roll angle of the signal after applying heading and pitch, relative to the inertial system (x''y''-plane)</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_xy_hdg) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, z                              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, pitch, DOUBLE_INVALID_VALUE    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, double, roll, DOUBLE_INVALID_VALUE     , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_signals_signal_positionInertial : public _OpenDriveElement, public a_xy_hdg
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_signals_signal_positionInertial)
};

}
