#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_accessRestrictionType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="simulator"/>
            <xs:enumeration value="autonomousTraffic"/>
            <xs:enumeration value="pedestrian"/>
            <xs:enumeration value="passengerCar"/>
            <xs:enumeration value="bus"/>
            <xs:enumeration value="delivery"/>
            <xs:enumeration value="emergency"/>
            <xs:enumeration value="taxi"/>
            <xs:enumeration value="throughTraffic"/>
            <xs:enumeration value="truck"/>
            <xs:enumeration value="bicycle"/>
            <xs:enumeration value="motorcycle"/>
            <xs:enumeration value="none"/>
            <xs:enumeration value="trucks"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_accessRestrictionType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_accessRestrictionType) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, SIMULATOR          , _SC_simulator) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, AUTONOMOUSTRAFFIC  , _SC_autonomousTraffic) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, PEDESTRIAN         , _SC_pedestrian) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, PASSENGERCAR       , _SC_passengerCar) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, BUS                , _SC_bus) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, DELIVERY           , _SC_delivery) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, EMERGENCY          , _SC_emergency) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, TAXI               , _SC_taxi) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, THROUGHTRAFFIC     , _SC_throughTraffic) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, TRUCK              , _SC_truck) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, BICYCLE            , _SC_bicycle) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, MOTORCYCLE         , _SC_motorcycle) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, NONE               , _SC_none) \
    _OD_STRING_ENUM_CONST(usingType, e_accessRestrictionType, TRUCKS             , _SC_trucks) \
    EMPTY_COMMAND

struct e_accessRestrictionType : public _e_base
{
    _OD_STRING_ENUM_e_accessRestrictionType(DECLARE)

public:
    e_accessRestrictionType()
    {
        this->value = 0; // Default value
    }
};
}
