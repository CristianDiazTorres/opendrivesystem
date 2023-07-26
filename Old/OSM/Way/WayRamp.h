#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:ramp

*/

namespace _NOSM
{

#define WayRamp_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayRamp, name, value)

#define WayRamp_MEMBERS(usingType) \
    WayRamp_MEMBER(usingType, YES, "yes") \
    WayRamp_MEMBER(usingType, SEPARATE, "separate") \
    WayRamp_MEMBER(usingType, NO, "no") \
    EMPTY_COMMAND

struct WayRamp
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayRamp)
};

}
