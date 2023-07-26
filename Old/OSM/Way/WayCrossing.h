#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:crossing

*/

namespace _NOSM
{

#define WayCrossing_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayCrossing, name, value)

#define WayCrossing_MEMBERS(usingType) \
    WayCrossing_MEMBER(usingType, TRAFFIC_SIGNALS   , "traffic_signals") \
    WayCrossing_MEMBER(usingType, UNCONTROLLED      , "uncontrolled") \
    WayCrossing_MEMBER(usingType, NO                , "no") \
    WayCrossing_MEMBER(usingType, UNMARKED          , "unmarked") \
    WayCrossing_MEMBER(usingType, MARKED            , "marked") \
    WayCrossing_MEMBER(usingType, ZEBRA             , "zebra") \
    WayCrossing_MEMBER(usingType, ISLAND            , "island") \
    EMPTY_COMMAND

struct WayCrossing
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayCrossing)
};

}
