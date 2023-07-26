#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:bridge

*/

namespace _NOSM
{

#define WayBridge_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayBridge, name, value)

#define WayBridge_MEMBERS(usingType) \
    WayBridge_MEMBER(usingType, YES                 , "yes") \
    WayBridge_MEMBER(usingType, AQUEDUCT            , "aqueduct") \
    WayBridge_MEMBER(usingType, BOARDWALK           , "boardwalk") \
    WayBridge_MEMBER(usingType, CANTILEVER          , "cantilever") \
    WayBridge_MEMBER(usingType, COVERED             , "covered") \
    WayBridge_MEMBER(usingType, LOW_WATER_CROSSING  , "low_water_crossing") \
    WayBridge_MEMBER(usingType, MOVABLE             , "movable") \
    WayBridge_MEMBER(usingType, TRESTLE             , "trestle") \
    WayBridge_MEMBER(usingType, VIADUCT             , "viaduct") \
    EMPTY_COMMAND

struct WayBridge
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayBridge)
};

}
