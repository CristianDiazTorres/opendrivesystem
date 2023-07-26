#pragma once

#include "XODR/OpenDRIVE/junction/e_junction_type.h"
#include "XODR/OpenDRIVE/junction/t_junction_predecessorSuccessor.h"
#include "XODR/OpenDRIVE/junction/t_junction_connection_laneLink.h"
#include "XODR/OpenDRIVE/junction/e_contactPoint.h"

/*
    <xs:complexType name="t_junction_connection">
        <xs:annotation>
            <xs:documentation>Provides information about a single connection within a junction.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="predecessor" type="t_junction_predecessorSuccessor" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="successor" type="t_junction_predecessorSuccessor" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="laneLink" type="t_junction_connection_laneLink" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within the junction</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="e_junction_type">
                    <xs:annotation>
                        <xs:documentation>Type of the connection, regular connections are type "default"
mandatory attribute for virtual connections</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="incomingRoad" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the incoming road</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="connectingRoad" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the connecting road</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="contactPoint" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Contact point on the connecting road. For values, see UML Model</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

/* Changed e_junction_type from optional to required */
#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_junction) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionConnectionId      , id                    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_junction_type            , type                  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, _roadId, incomingRoad      , INTEGER_INVALID_VALUE , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, _roadId, connectingRoad    , INTEGER_INVALID_VALUE , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_contactPoint             , contactPoint          , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_junction_predecessorSuccessor       , predecessor) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_junction_predecessorSuccessor       , successor) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_junction_connection_laneLink        , laneLink) lineEnd \
    EMPTY_COMMAND

struct t_junction_connection : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_connection)

};

}
