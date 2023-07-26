#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/railroad/t_station_platform_segment.h"

/*
    <xs:complexType name="t_station_platform">
        <xs:annotation>
            <xs:documentation>Each station element must contain at least one platform element. Each platform element must contain at least one reference to a valid track segment.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="segment" type="t_station_platform_segment" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the platform. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name       , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _platformId, id    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_station_platform_segment, segment) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_station_platform : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_station_platform)

};

}
