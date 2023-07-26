#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_signals_signal_type(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_signals_signal_type) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_type, TRAFFIC_LIGHTS         , _SC_traffic_lights) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_type, CROSSING               , _SC_crossing) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_type, TRAFFIC_CALMING        , _SC_traffic_calming) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_type, TRAFFIC_SIGN           , _SC_traffic_sign) \
    _OD_STRING_ENUM_CONST(usingType, e_road_signals_signal_type, TRAFFIC_SIGNAL         , _SC_traffic_signal) \
    EMPTY_COMMAND

struct e_road_signals_signal_type : public _e_base
{
    _OD_STRING_ENUM_e_road_signals_signal_type(DECLARE)

public:
    e_road_signals_signal_type()
    {
        this->value = 0; // Default value
    }
};
}
