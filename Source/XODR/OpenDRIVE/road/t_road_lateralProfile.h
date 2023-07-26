#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/t_road_lateralProfile_superelevation.h"
#include "XODR/OpenDRIVE/road/t_road_lateralProfile_shape.h"

/*
    <xs:complexType name="t_road_lateralProfile">
        <xs:annotation>
            <xs:documentation>Contains a series of superelevation elements that define the characteristics of the road surface's banking along the reference line.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="superelevation" type="t_road_lateralProfile_superelevation" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="shape" type="t_road_lateralProfile_shape" minOccurs="0" maxOccurs="unbounded"/>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lateralProfile_superelevation, superelevation) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lateralProfile_shape, shape) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lateralProfile : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lateralProfile)
};

}
