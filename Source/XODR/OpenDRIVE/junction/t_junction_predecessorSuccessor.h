#pragma once

#include "XODR/OpenDRIVE/core/t_grZero.h"
#include "XODR/OpenDRIVE/road/e_road_link_elementType.h"
#include "XODR/OpenDRIVE/junction/e_elementDir.h"

/*
    <xs:complexType name="t_junction_predecessorSuccessor">
        <xs:annotation>
            <xs:documentation>Provides detailed information about the predecessor / successor road of a virtual connection. Currently, only the @elementType "road" is allowed.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="elementType" use="required" fixed="road" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type of the linked element Currently only "road" is allowed.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the linked element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementS" use="required" type="t_grZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate where the connection meets the preceding / succeding road.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementDir" use="required" type="e_elementDir">
                    <xs:annotation>
                        <xs:documentation>Direction, relative to the s-direction, of the connection on the preceding / succeding road</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT(usingType, e_road_link_elementType    , elementType   , e_road_link_elementType::ROAD , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _elementId                 , elementId                                     , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTR_INIT(usingType, t_grZero                   , elementS      , 0                             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_elementDir               , elementDir                                    , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_junction_predecessorSuccessor : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_predecessorSuccessor)
};

}
