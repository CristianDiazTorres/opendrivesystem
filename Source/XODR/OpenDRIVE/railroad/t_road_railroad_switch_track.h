#pragma once


#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/junction/e_elementDir.h"

/*
    <xs:complexType name="t_road_railroad_switch_mainTrack">
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the main track, that is, the &lt;road&gt; element. Must be consistent with parent containing this &lt;railroad&gt; element.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of the switch, that is, the point where main track and side track meet</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="dir" use="required" type="e_elementDir">
                    <xs:annotation>
                        <xs:documentation>direction, relative to the s-direction, on the main track for entering the side track via the switch</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_railroad) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _trackId, id       , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_elementDir, dir  , REQUIRED) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_railroad_switch_track : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_railroad_switch_track)
};

}
