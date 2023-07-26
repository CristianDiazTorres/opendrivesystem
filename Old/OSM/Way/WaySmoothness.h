#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:smoothness

*/

namespace _NOSM
{

#define WaySmoothness_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WaySmoothness, name, value)

#define WaySmoothness_MEMBERS(usingType) \
    WaySmoothness_MEMBER(usingType, EXCELLENT    , "excellent") \
    WaySmoothness_MEMBER(usingType, GOOD         , "good") \
    WaySmoothness_MEMBER(usingType, INTERMEDIATE , "intermediate") \
    WaySmoothness_MEMBER(usingType, BAD          , "bad") \
    WaySmoothness_MEMBER(usingType, VERY_BAD     , "very_bad") \
    WaySmoothness_MEMBER(usingType, HORRIBLE     , "horrible") \
    WaySmoothness_MEMBER(usingType, VERY_HORRIBLE, "very_horrible") \
    WaySmoothness_MEMBER(usingType, IMPASSABLE   , "impassable") \
    EMPTY_COMMAND

struct WaySmoothness
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WaySmoothness)
};

}
