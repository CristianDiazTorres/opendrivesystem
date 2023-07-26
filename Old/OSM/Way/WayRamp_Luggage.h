#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:ramp

*/

namespace _NOSM
{

#define WayRamp_Luggage_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayRamp_Luggage, name, value)

#define WayRamp_Luggage_MEMBERS(usingType) \
    WayRamp_Luggage_MEMBER(usingType, YES, "yes") \
    WayRamp_Luggage_MEMBER(usingType, AUTOMATIC, "automatic") \
    WayRamp_Luggage_MEMBER(usingType, MANUAL, "manual") \
    WayRamp_Luggage_MEMBER(usingType, NO, "no") \
    EMPTY_COMMAND

struct WayRamp_Luggage
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayRamp_Luggage)
};

}
