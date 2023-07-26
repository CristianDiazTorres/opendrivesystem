#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_objects_object_markings_marking_cornerReference">
        <xs:annotation>
            <xs:documentation>Specifies a point by referencing an existing outline point.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="id" use="required" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>Index of outline point</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_object) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _outlinePointId, id, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_markings_marking_cornerReference : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_markings_marking_cornerReference)

};

}
