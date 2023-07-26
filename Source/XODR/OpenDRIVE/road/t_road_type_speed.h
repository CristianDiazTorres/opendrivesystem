#pragma once

#include "XODR/OpenDRIVE/core/e_unitSpeed.h"
#include "XODR/OpenDRIVE/road/t_maxSpeed.h"

/*
    <xs:complexType name="t_road_type_speed">
        <xs:annotation>
            <xs:documentation>Defines the default maximum speed allowed in conjunction with the specified road type.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="max" use="required" type="t_maxSpeed">
                    <xs:annotation>
                        <xs:documentation>Maximum allowed speed. Given as string (only "no limit" / "undefined") or numerical value in the respective unit (see attribute unit). If the attribute unit is not specified, m/s is used as default. </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="unit" use="optional" type="e_unitSpeed">
                    <xs:annotation>
                        <xs:documentation>Unit of the attribute max. For values, see chapter "units".</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_maxSpeed , max   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_unitSpeed, unit  , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_type_speed : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_type_speed)
};

}
