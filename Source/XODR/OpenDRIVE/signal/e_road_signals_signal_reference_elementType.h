#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_signals_signal_reference_elementType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="object"/>
            <xs:enumeration value="signal"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_signals_signal_reference_elementType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_signals_signal_reference_elementType) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_reference_elementType, OBJECT     , _SC_object) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_reference_elementType, SIGNAL_    , _SC_signal) \
    EMPTY_COMMAND

struct e_road_signals_signal_reference_elementType : public _e_base
{
    _OD_STRING_ENUM_e_road_signals_signal_reference_elementType(DECLARE)

public:
    e_road_signals_signal_reference_elementType()
    {
        this->value = 0; // Default value
    }
};
}
