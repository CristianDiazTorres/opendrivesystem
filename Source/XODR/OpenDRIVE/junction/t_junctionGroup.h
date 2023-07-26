#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/junction/t_junctionGroup_junctionReference.h"
#include "XODR/OpenDRIVE/junction/e_junctionGroup_type.h"

/*
    <xs:complexType name="t_junctionGroup">
        <xs:annotation>
            <xs:documentation>Two or more junctions may be grouped in junction groups to indicate that these junctions belong to the same roundabout.
The &lt;junctionGroup&gt; element is split into a header element and a series of member elements.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="junctionReference" type="t_junctionGroup_junctionReference" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the junction group. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_junctionGroup_type">
                    <xs:annotation>
                        <xs:documentation>Type of junction group
For values see UML Model</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                     , name      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionGroupId           , id        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_junctionGroup_type       , type      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_junctionGroup_junctionReference , junctionReference) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_junctionGroup : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junctionGroup)
};

}
