#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:bus_bay

*/

namespace _NOSM
{

#define WayBus_Bay_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayBus_Bay, name, value)

#define WayBus_Bay_MEMBERS(usingType) \
    WayBus_Bay_MEMBER(usingType, BOTH               , "both") \
    WayBus_Bay_MEMBER(usingType, RIGHT              , "right") \
    WayBus_Bay_MEMBER(usingType, LEFT               , "left") \
    EMPTY_COMMAND

struct WayBus_Bay
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayBus_Bay)
};

}
