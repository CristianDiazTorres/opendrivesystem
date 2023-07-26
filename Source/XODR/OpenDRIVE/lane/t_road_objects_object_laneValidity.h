#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_objects_object_laneValidity">
        <xs:annotation>
            <xs:documentation>May replace the default validity with explicit validity information for an object. Multiple validity elements may be defined per object.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="fromLane" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>Minimum ID of the lanes for which the object is valid</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="toLane" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>Maximum ID of the lanes for which the object is valid</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId, fromLane  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _laneId, toLane    , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_laneValidity : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_laneValidity)

};

}
