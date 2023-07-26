#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:covered

*/

namespace _NOSM
{

#define WayCovered_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayCovered, name, value)

#define WayCovered_MEMBERS(usingType) \
    WayCovered_MEMBER(usingType, YES                , "yes") \
    WayCovered_MEMBER(usingType, ARCADE             , "arcade") \
    WayCovered_MEMBER(usingType, COLONNADE          , "colonnade") \
    WayCovered_MEMBER(usingType, PARTIAL            , "partial") \
    WayCovered_MEMBER(usingType, BOOTH              , "booth") \
    EMPTY_COMMAND

struct WayCovered
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayCovered)
};

}
