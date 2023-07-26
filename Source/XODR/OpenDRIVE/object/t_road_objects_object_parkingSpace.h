#pragma once

#include "XODR/OpenDRIVE/object/e_road_objects_object_parkingSpace_access.h"

/*
    <xs:complexType name="t_road_objects_object_parkingSpace">
        <xs:annotation>
            <xs:documentation>Details for a parking space may be added to the object element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="access" use="required" type="e_road_objects_object_parkingSpace_access">
                    <xs:annotation>
                        <xs:documentation>Access definitions for the parking space. Parking spaces tagged with "women" and "handicapped" are vehicles of type car. For values see UML Model</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="restrictions" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Free text, depending on application</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_objects_object_parkingSpace_access, access  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, restrictions                               , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_parkingSpace : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_parkingSpace)
};

}
