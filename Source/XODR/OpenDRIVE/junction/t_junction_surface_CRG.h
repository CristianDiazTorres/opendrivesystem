#pragma once

#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_mode.h"
#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_purpose.h"

/*
    <xs:complexType name="t_junction_surface_CRG">
        <xs:annotation>
            <xs:documentation>Data described in OpenCRG are represented by the &lt;CRG&gt; element within the &lt;surface&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="file" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the file containing the CRG data</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="mode" use="required" fixed="global" type="e_road_surface_CRG_mode">
                    <xs:annotation>
                        <xs:documentation>Attachment mode for the surface data.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="purpose" use="optional" type="e_road_surface_CRG_purpose">
                    <xs:annotation>
                        <xs:documentation>Physical purpose of the data contained in the CRG file; if the attribute is missing, data will be interpreted as elevation data.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffset" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z offset between CRG center line and inertial xy-plane
(default = 0.0)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zScale" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z scale factor for the surface description (default = 1.0) </xs:documentation>
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
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                     , file      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_surface_CRG_mode    , mode      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_surface_CRG_purpose , purpose   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double                     , zOffset   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double                     , zScale    , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_junction_surface_CRG : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_surface_CRG)

};

}
