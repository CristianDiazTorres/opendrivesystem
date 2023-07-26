#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_laneType">
        <xs:annotation>
            <xs:documentation>The lane type is defined per lane. A lane type defines the main purpose of a lane and its corresponding traffic rules. </xs:documentation>
        </xs:annotation>
        <xs:restriction base="xs:string">
            <xs:enumeration value="shoulder">
                <xs:annotation>
                    <xs:documentation>Describes a soft shoulder  at the edge of the road</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="border">
                <xs:annotation>
                    <xs:documentation>Describes a hard border at the edge of the road. has the same height as the drivable lane.</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="driving">
                <xs:annotation>
                    <xs:documentation>"normal" drivable road, which is not one of the other types</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="stop">
                <xs:annotation>
                    <xs:documentation>Hard shoulder on motorways for emergency stops</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="none">
                <xs:annotation>
                    <xs:documentation>"Invisible" lane. This lane is on the most ouside of the road. Its only purpose is for simulation, that there is still opendrive present in case the (human) driver leaves the road. </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="restricted">
                <xs:annotation>
                    <xs:documentation>Lane on which cars should not drive, but have the same height as the drivable lanes. Typically they are separated with lines and often there are additional striped lines on them. </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="parking">
                <xs:annotation>
                    <xs:documentation>Lane with parking spaces</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="median">
                <xs:annotation>
                    <xs:documentation>Lane between driving lanes in oposite directions. Typically used in towns on large roads, to separate the traffic.</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="biking">
                <xs:annotation>
                    <xs:documentation>Lane reserved for Cyclists </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="sidewalk">
                <xs:annotation>
                    <xs:documentation>Lane on which pedestrians can walk savely</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="curb">
                <xs:annotation>
                    <xs:documentation>Lane "curb" is used for curbstones. These have a different height compared to the drivable lanes.</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="exit">
                <xs:annotation>
                    <xs:documentation>Lane Type "exit" is used for the sections which is parallel to the main road (meaning deceleration lanes) </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="entry">
                <xs:annotation>
                    <xs:documentation>Lane Type "entry" is used for the sections which is parallel to the main road (meaning acceleration lanes</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="onRamp">
                <xs:annotation>
                    <xs:documentation>A ramp leading to a motorway from rural/urban roads is an "onRamp". </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="offRamp">
                <xs:annotation>
                    <xs:documentation>A ramp leading away from a motorway and onto rural/urban roads is an "offRamp". </xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="connectingRamp">
                <xs:annotation>
                    <xs:documentation>A ramp connecting two motorways is a "connectingRamp" (e.g. motorway junction)</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="bidirectional">
                <xs:annotation>
                    <xs:documentation>this lane type has two use cases:
a) only driving lane on a narrow road which may be used in both directions;
b) continuous two-way left turn lane on multi-lane roads - US road networks</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="special1"/>
            <xs:enumeration value="special2"/>
            <xs:enumeration value="special3"/>
            <xs:enumeration value="roadWorks"/>
            <xs:enumeration value="tram"/>
            <xs:enumeration value="rail"/>
            <xs:enumeration value="bus"/>
            <xs:enumeration value="taxi"/>
            <xs:enumeration value="HOV">
                <xs:annotation>
                    <xs:documentation>high-occupancy vehicle / carpool vehicle</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="mwyEntry">
                <xs:annotation>
                    <xs:documentation>entry (deprecated)</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="mwyExit">
                <xs:annotation>
                    <xs:documentation>exit (deprecated)</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_laneType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_laneType) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, SHOULDER            , _SC_shoulder) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, BORDER              , _SC_border) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, DRIVING             , _SC_driving) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, STOP                , _SC_stop) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, NONE                , _SC_none) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, RESTRICTED          , _SC_restricted) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, PARKING             , _SC_parking) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, MEDIAN              , _SC_median) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, BIKING              , _SC_biking) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, SIDEWALK            , _SC_sidewalk) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, CURB                , _SC_curb) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, EXIT                , _SC_exit) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, ENTRY               , _SC_entry) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, ONRAMP              , _SC_onRamp) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, OFFRAMP             , _SC_offRamp) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, CONNECTINGRAMP      , _SC_connectingRamp) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, BIDIRECTIONAL       , _SC_bidirectional) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, SPECIAL1            , _SC_special1) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, SPECIAL2            , _SC_special2) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, SPECIAL3            , _SC_special3) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, ROADWORKS           , _SC_roadWorks) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, TRAM                , _SC_tram) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, RAIL                , _SC_rail) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, BUS                 , _SC_bus) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, TAXI                , _SC_taxi) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, HOV                 , _SC_HOV) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, MWYENTRY            , _SC_mwyEntry) \
    _OD_STRING_ENUM_CONST(usingType, e_laneType, MWYEXIT             , _SC_mwyExit) \
    EMPTY_COMMAND

struct e_laneType : public _e_base
{
    _OD_STRING_ENUM_e_laneType(DECLARE)

public:
    e_laneType()
    {
        this->value = 0; // Default value
    }
};
}
