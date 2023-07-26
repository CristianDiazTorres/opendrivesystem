#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/road/e_road_link_elementType.h"
#include "XODR/OpenDRIVE/junction/e_contactPoint.h"
#include "XODR/OpenDRIVE/junction/e_elementDir.h"

/*
    <xs:complexType name="t_road_link_predecessorSuccessor">
        <xs:annotation>
            <xs:documentation>For virtual and regular junctions, different attribute sets shall be used. @contactPoint shall be used for regular junctions; @elementS and @elementDir shall be used for virtual junctions.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="elementId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the linked element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementType" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type of the linked element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="contactPoint" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Contact point of link on the linked element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementS" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Alternative to contactPoint for virtual junctions. Indicates a connection within the predecessor, meaning not at the start or end of the predecessor. Shall only be used for elementType "road"</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementDir" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>To be provided when elementS is used for the connection definition. Indicates the direction on the predecessor from which the road is entered.</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _elementId             , elementId             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_link_elementType, elementType           , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_contactPoint         , contactPoint          , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_grEqZero, elementS   , DOUBLE_INVALID_VALUE  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_elementDir           , elementDir            , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_link_predecessorSuccessor : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_link_predecessorSuccessor)
};

}
