#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/t_road_link_predecessorSuccessor.h"

/*
    <xs:complexType name="t_road_link">
        <xs:annotation>
            <xs:documentation>Follows the road header if the road is linked to a successor, a predecessor, or a neighbor. Isolated roads may omit this element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="predecessor" type="t_road_link_predecessorSuccessor" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="successor" type="t_road_link_predecessorSuccessor" minOccurs="0" maxOccurs="1"/>
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
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_link_predecessorSuccessor, predecessor) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_link_predecessorSuccessor, successor) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_link : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_link)
};

}
