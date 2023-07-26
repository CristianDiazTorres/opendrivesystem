#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_include">
        <xs:annotation>
            <xs:documentation>OpenDRIVE allows including external files into the OpenDRIVE file. The processing of the files depends on the application.
Included data is represented by &lt;include&gt; elements. They may be stored at any position in OpenDRIVE.</xs:documentation>
        </xs:annotation>
        <xs:sequence/>
        <xs:attribute name="file" use="required" type="xs:string">
            <xs:annotation>
                <xs:documentation>Location of the file that is to be included</xs:documentation>
            </xs:annotation>
        </xs:attribute>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string        , file   , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_include : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_include)
};

}

