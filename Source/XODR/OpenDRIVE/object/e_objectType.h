#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_objectType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="none">
                <xs:annotation>
                    <xs:documentation>i.e. unknown</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="obstacle">
                <xs:annotation>
                    <xs:documentation>for anything that is not further categorized</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="car">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="pole"/>
            <xs:enumeration value="tree"/>
            <xs:enumeration value="vegetation"/>
            <xs:enumeration value="barrier"/>
            <xs:enumeration value="building"/>
            <xs:enumeration value="parkingSpace"/>
            <xs:enumeration value="patch"/>
            <xs:enumeration value="railing"/>
            <xs:enumeration value="trafficIsland"/>
            <xs:enumeration value="crosswalk"/>
            <xs:enumeration value="streetLamp"/>
            <xs:enumeration value="gantry"/>
            <xs:enumeration value="soundBarrier"/>
            <xs:enumeration value="van">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="bus">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="trailer">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="bike">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="motorbike">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="tram">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="train">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="pedestrian">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="wind">
                <xs:annotation>
                    <xs:documentation>deprecated</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="roadMark"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_objectType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_objectType) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, NONE              , _SC_none) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, OBSTACLE          , _SC_obstacle) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, CAR               , _SC_car) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, POLE              , _SC_pole) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, TREE              , _SC_tree) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, VEGETATION        , _SC_vegetation) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, BARRIER           , _SC_barrier) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, BUILDING          , _SC_building) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, PARKINGSPACE      , _SC_parkingSpace) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, PATCH             , _SC_patch) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, RAILING           , _SC_railing) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, TRAFFICISLAND     , _SC_trafficIsland) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, CROSSWALK         , _SC_crosswalk) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, STREETLAMP        , _SC_streetLamp) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, GANTRY            , _SC_gantry) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, SOUNDBARRIER      , _SC_soundBarrier) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, VAN               , _SC_van) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, BUS               , _SC_bus) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, TRAILER           , _SC_trailer) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, BIKE              , _SC_bike) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, MOTORBIKE         , _SC_motorbike) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, TRAM              , _SC_tram) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, TRAIN             , _SC_train) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, PEDESTRIAN        , _SC_pedestrian) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, WIND              , _SC_wind) \
    _OD_STRING_ENUM_CONST(usingType, e_objectType, ROADMARK          , _SC_roadMark) \
    EMPTY_COMMAND

struct e_objectType : public _e_base
{
    _OD_STRING_ENUM_e_objectType(DECLARE)

public:
    e_objectType()
    {
        this->value = 0; // Default value
    }
};
}
