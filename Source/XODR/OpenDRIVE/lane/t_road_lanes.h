#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneOffset.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection.h"

/*
    <xs:complexType name="t_road_lanes">
        <xs:annotation>
            <xs:documentation>Contains a series of lane section elements that define the characteristics of the road cross sections with respect to the lanes along the reference line.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="laneOffset" type="t_road_lanes_laneOffset" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="laneSection" type="t_road_lanes_laneSection" minOccurs="1" maxOccurs="unbounded">
                        <!-- Key Constraints manually added from OpenDRIVE 1.5 -->
                        <xs:key name="k_road_lanes_laneSection_laneId">
                            <xs:selector xpath="/lane"/>
                            <xs:field xpath="@id"/>
                        </xs:key>
                    </xs:element>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/
// NOTE: "*/lane" instead of "/lane"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_lanes_laneOffset       , laneOffset) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_lanes_laneSection      , laneSection) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_lanes)

public:
    double getLength() const;
    double getLaneSectionEndS(double s) const;
};

}
