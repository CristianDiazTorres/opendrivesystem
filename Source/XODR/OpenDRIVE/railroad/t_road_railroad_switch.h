#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/railroad/e_road_railroad_switch_position.h"
#include "XODR/OpenDRIVE/railroad/t_road_railroad_switch_mainTrack.h"
#include "XODR/OpenDRIVE/railroad/t_road_railroad_switch_sideTrack.h"
#include "XODR/OpenDRIVE/railroad/t_road_railroad_switch_partner.h"

/*
    <xs:complexType name="t_road_railroad_switch">
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="mainTrack" type="t_road_railroad_switch_mainTrack" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="sideTrack" type="t_road_railroad_switch_sideTrack" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="partner" type="t_road_railroad_switch_partner" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique name of the switch</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the switch; preferably an integer number, see uint32_t</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="position" use="required" type="e_road_railroad_switch_position">
                    <xs:annotation>
                        <xs:documentation>Either a switch can be operated (dynamic) or it is in a static position. For values see UML Model</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, name                               , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _switchId, id                              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_railroad_switch_position, position  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_road_railroad_switch_mainTrack      , mainTrack) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_road_railroad_switch_sideTrack      , sideTrack) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_railroad_switch_partner        , partner) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_railroad_switch : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_railroad_switch)

};

}
