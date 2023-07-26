#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/railroad/t_road_railroad_switch.h"

/*
    <xs:complexType name="t_road_railroad">
        <xs:annotation>
            <xs:documentation>Container for all railroad definitions that shall be applied along a road.
The available set of railroad elements is currently limited to the definition of switches. All other entries shall be covered with the existing elements, for example, track definition by &lt;road&gt;, signal definition by &lt;signal&gt;, etc. Railroad-specific elements are defined against the background of streetcar applications.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="switch" type="t_road_railroad_switch" minOccurs="0" maxOccurs="unbounded"/>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_railroad) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_railroad_switch, switch) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_railroad : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_railroad)
};

}
