#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:cycleway

*/

namespace _NOSM
{

#define WayCycleway_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayCycleway, name, value)

#define WayCycleway_MEMBERS(usingType) \
    WayCycleway_MEMBER(usingType, LANE                  , "lane") \
    WayCycleway_MEMBER(usingType, OPPOSITE_LANE         , "opposite_lane") \
    WayCycleway_MEMBER(usingType, OPPOSITE              , "opposite") \
    WayCycleway_MEMBER(usingType, SHARED_LANE           , "shared_lane") \
    WayCycleway_MEMBER(usingType, SHARE_BUSWAY          , "share_busway") \
    WayCycleway_MEMBER(usingType, OPPOSITE_SHARE_BUSWAY , "opposite_share_busway") \
    WayCycleway_MEMBER(usingType, SHARED                , "shared") \
    WayCycleway_MEMBER(usingType, TRACK                 , "track") \
    WayCycleway_MEMBER(usingType, OPPOSITE_TRACK        , "opposite_track") \
    WayCycleway_MEMBER(usingType, ASL                   , "asl") \
    WayCycleway_MEMBER(usingType, SHOULDER              , "shoulder") \
    WayCycleway_MEMBER(usingType, SEPARATE              , "separate") \
    WayCycleway_MEMBER(usingType, NO                    , "no") \
    WayCycleway_MEMBER(usingType, CROSSING              , "crossing") \
    EMPTY_COMMAND

struct WayCycleway
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayCycleway)
};

}
