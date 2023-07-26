#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_junctionGroup_junctionReference">
        <xs:annotation>
            <xs:documentation>References to existing junction elements.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="junction" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the junction</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionId           , junction        , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_junctionGroup_junctionReference : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junctionGroup_junctionReference)

};

}
