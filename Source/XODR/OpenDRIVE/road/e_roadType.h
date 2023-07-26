#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_roadType">
        <xs:annotation>
            <xs:documentation>The known keywords for the road type information are:</xs:documentation>
        </xs:annotation>
        <xs:restriction base="xs:string">
            <xs:enumeration value="unknown"/>
            <xs:enumeration value="rural"/>
            <xs:enumeration value="motorway"/>
            <xs:enumeration value="town"/>
            <xs:enumeration value="lowSpeed">
                <xs:annotation>
                    <xs:documentation>In Germany, lowSpeed is equivalent to a 30km/h zone</xs:documentation>
                </xs:annotation>
            </xs:enumeration>
            <xs:enumeration value="pedestrian"/>
            <xs:enumeration value="bicycle"/>
            <xs:enumeration value="townExpressway"/>
            <xs:enumeration value="townCollector"/>
            <xs:enumeration value="townArterial"/>
            <xs:enumeration value="townPrivate"/>
            <xs:enumeration value="townLocal"/>
            <xs:enumeration value="townPlayStreet"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_roadType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_roadType) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, UNKNOWN         , _SC_unknown) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, RURAL           , _SC_rural) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, MOTORWAY        , _SC_motorway) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWN            , _SC_town) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, LOWSPEED        , _SC_lowSpeed) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, PEDESTRIAN      , _SC_pedestrian) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, BICYCLE         , _SC_bicycle) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNEXPRESSWAY  , _SC_townExpressway) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNCOLLECTOR   , _SC_townCollector) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNARTERIAL    , _SC_townArterial) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNPRIVATE     , _SC_townPrivate) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNLOCAL       , _SC_townLocal) \
    _OD_STRING_ENUM_CONST(usingType, e_roadType, TOWNPLAYSTREET  , _SC_townPlayStreet) \
    EMPTY_COMMAND

struct e_roadType : public _e_base
{
    _OD_STRING_ENUM_e_roadType(DECLARE)

public:
    e_roadType()
    {
        this->value = 0; // Default value
    }
};
}
