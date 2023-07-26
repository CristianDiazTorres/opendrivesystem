#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/railroad/e_station_platform_segment_side.h"

/*
    <xs:complexType name="t_station_platform_segment">
        <xs:annotation>
            <xs:documentation>Each platform element is valid on one or more track segments. The &lt;segment&gt; element must be specified.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="roadId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the &lt;road&gt; element (track) that accompanies the platform</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sStart" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Minimum s-coordinate on &lt;road&gt; element that has an adjacent platform</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sEnd" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Maximum s-coordiante on &lt;road&gt; element that has an adjacent platform</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="side" use="required" type="e_station_platform_segment_side">
                    <xs:annotation>
                        <xs:documentation>Side of track on which the platform is situated when going from sStart to sEnd. For values see UML Model</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _roadId, roadId                        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, sStart                     , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, sEnd                       , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_station_platform_segment_side, side  , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_station_platform_segment : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_station_platform_segment)

public:
    double calcDistance(const a_s_t& st) const;
    void updateST(const a_s_t &st);
};

}
