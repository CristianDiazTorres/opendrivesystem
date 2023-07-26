#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_junction_priority">
        <xs:annotation>
            <xs:documentation>If an incoming road is linked to an outgoing road with multiple connection roads to represent several possible lane connections, then one of these connections may be prioritized. Assigning a priority is only required if the application is unable to derive priorities from signals before or inside a junction or from the lanes leading to a junction. At least one attribute must be given.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="high" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the prioritized connecting road</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="low" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the connecting road with lower priority</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _roadId      , high    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _roadId      , low     , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_junction_priority : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_priority)

};

}
