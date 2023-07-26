#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_junction_connection_laneLink">
        <xs:annotation>
            <xs:documentation>Provides information about the lanes that are linked between an incoming road and a connecting road. It is strongly recommended to provide this element. It is deprecated to omit the &lt;laneLink&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="from" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>ID of the incoming lane</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="to" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>ID of the connection lane</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_junction) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId      , from    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId      , to      , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_junction_connection_laneLink : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_connection_laneLink)

};

}
