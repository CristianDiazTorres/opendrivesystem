#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/railroad/e_station_type.h"
#include "XODR/OpenDRIVE/railroad/t_station_platform.h"

/*
    <xs:complexType name="t_station">
        <xs:annotation>
            <xs:documentation>Defines stations for tram and railroad applications and for automotive environments. May refer to multiple tracks and is therefore defined on the same level as junctions.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="platform" type="t_station_platform" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique name of the station</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="e_station_type">
                    <xs:annotation>
                        <xs:documentation>Type of station. Free text, depending on the application.
e.g.: small, medium, large</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_railroad) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name           , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _stationId, id         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_station_type, type   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_station_platform, platform) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_station : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_station)
};

}
