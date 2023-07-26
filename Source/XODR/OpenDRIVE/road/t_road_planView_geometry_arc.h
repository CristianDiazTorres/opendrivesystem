#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_road_planView_geometry_arc">
        <xs:annotation>
            <xs:documentation>An arc describes a road reference line with constant curvature. In OpenDRIVE, an arc is represented by an &lt;arc&gt; element within the &lt;geometry&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="curvature" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Constant curvature throughout the element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

/*
    2.3.6. Curvature
    For curvature indications, the following convention applies:

        Positive curvature: left curve (counter-clockwise motion)

        Negative curvature: right curve (clockwise motion)

    Curvature == 1/radius
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, curvature, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_road_planView_geometry_arc : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_planView_geometry_arc)
};

}
