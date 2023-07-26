#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:overtaking

*/

namespace _NOSM
{

#define WayOvertaking_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayOvertaking, name, value)

#define WayOvertaking_MEMBERS(usingType) \
    WayOvertaking_MEMBER(usingType, NO          , "no") \
    WayOvertaking_MEMBER(usingType, CAUTION     , "caution") \
    WayOvertaking_MEMBER(usingType, BOTH        , "both") \
    WayOvertaking_MEMBER(usingType, YES         , "yes") \
    WayOvertaking_MEMBER(usingType, FORWARD     , "forward") \
    WayOvertaking_MEMBER(usingType, BACKWARD    , "backward") \
    EMPTY_COMMAND

struct WayOvertaking
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayOvertaking)
};

}
