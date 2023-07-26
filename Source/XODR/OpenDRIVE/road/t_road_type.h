#pragma once


#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/e_roadType.h"
#include "XODR/OpenDRIVE/road/e_countryCode.h"
#include "XODR/OpenDRIVE/road/t_road_type_speed.h"

/*
    <xs:complexType name="t_road_type">
        <xs:annotation>
            <xs:documentation>A road type element is valid for the entire cross section of a road. It is valid until a new road type element is provided or until the road ends.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="speed" type="t_road_type_speed" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="required" type="e_roadType">
                    <xs:annotation>
                        <xs:documentation>For supported types, for values see UML model.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="country" use="optional" type="e_countryCode">
                    <xs:annotation>
                        <xs:documentation>Country code of the road, see ISO 3166-1, alpha-2 codes.</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_roadType     , type      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, e_countryCode  , country   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_type_speed     , speed) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_type : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_type)

};

}
