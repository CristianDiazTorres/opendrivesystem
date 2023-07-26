#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_mode.h"
#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_purpose.h"
#include "XODR/OpenDRIVE/road/e_direction.h"

/*
    <xs:complexType name="t_road_surface_CRG">
        <xs:annotation>
            <xs:documentation>Data described in OpenCRG is represented by the &lt;CRG&gt; element within the &lt;surface&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="file" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the file containing the CRG data</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sStart" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Start of the application of CRG data
(s-coordinate)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sEnd" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>End of the application of CRG
(s-coordinate)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="orientation" use="required" type="e_direction">
                    <xs:annotation>
                        <xs:documentation>Orientation of the CRG data set relative to the parent &lt;road&gt; element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="mode" use="required" type="e_road_surface_CRG_mode">
                    <xs:annotation>
                        <xs:documentation>Attachment mode for the surface data, see specification.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="purpose" use="optional" type="e_road_surface_CRG_purpose">
                    <xs:annotation>
                        <xs:documentation>Physical purpose of the data contained in the CRG file; if the attribute is missing, data will be interpreted as elevation data.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>s-offset between CRG center line and reference line of the road
(default = 0.0)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="tOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>t-offset between CRG center line and reference line of the road
 (default = 0.0)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-offset between CRG center line and reference line of the road
(default = 0.0)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zScale" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-scale factor for the surface description (default = 1.0) </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Heading offset between CRG center line and reference line of the road (required for mode genuine only, default = 0.0)</xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, file                       , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, sStart                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, sEnd                   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_direction, orientation           , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_surface_CRG_mode, mode      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_surface_CRG_purpose, purpose, OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, sOffset                    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, tOffset                    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffset                    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zScale                     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, hOffset                    , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_surface_CRG : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_surface_CRG)

public:
    double calcDistance(const a_s_t& st) const;
    void updateST(const a_s_t &st);
};

}
