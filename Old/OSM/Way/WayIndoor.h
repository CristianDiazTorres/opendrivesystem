#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:indoor

*/

namespace _NOSM
{

#define WayIndoor_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayIndoor, name, value)

#define WayIndoor_MEMBERS(usingType) \
    WayIndoor_MEMBER(usingType, WALL    , "wall") \
    WayIndoor_MEMBER(usingType, YES     , "yes") \
    EMPTY_COMMAND

struct WayIndoor
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayIndoor)
};

}
