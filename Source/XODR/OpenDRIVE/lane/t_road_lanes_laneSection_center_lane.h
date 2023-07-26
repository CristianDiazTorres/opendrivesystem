#pragma once

#include "XODR/OpenDRIVE/lane/_t_road_lanes_laneSection_lcr_lane.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_center_lane">
        <xs:annotation>
            <xs:documentation>Lane elements are included in left/center/right elements. Lane elements should represent the lanes from left to right, that is, with descending ID.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="t_road_lanes_laneSection_lr_lane">
                <xs:sequence/>
                <xs:attribute name="id" use="required" fixed="0" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>ID of the lane</xs:documentation>
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
    _UNIVERSIAL_TYPE_BASE_GEO_JSON(usingType, _t_road_lanes_laneSection_lcr_lane) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_center_lane : public _t_road_lanes_laneSection_lcr_lane
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(t_road_lanes_laneSection_center_lane)
    _UNIVERSIAL_TYPE_read_write_DEFINE(t_road_lanes_laneSection_center_lane)
    _UNIVERSIAL_TYPE_setTestData_DEFINE(t_road_lanes_laneSection_center_lane)
    _UNIVERSIAL_TYPE_updateGeoJSONData_DEFINE(t_road_lanes_laneSection_center_lane)
};

}
