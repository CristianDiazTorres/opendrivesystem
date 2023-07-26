#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:embedded_rails

*/

namespace _NOSM
{

#define WayEmbedded_Rails_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayEmbedded_Rails, name, value)

#define WayEmbedded_Rails_MEMBERS(usingType) \
    WayEmbedded_Rails_MEMBER(usingType, ABANDONED       , "abandoned") \
    WayEmbedded_Rails_MEMBER(usingType, CONSTRUCTION    , "construction") \
    WayEmbedded_Rails_MEMBER(usingType, DISUSED         , "disused") \
    WayEmbedded_Rails_MEMBER(usingType, FUNICULAR       , "funicular") \
    WayEmbedded_Rails_MEMBER(usingType, LIGHT_RAIL      , "light_rail") \
    WayEmbedded_Rails_MEMBER(usingType, MINIATURE       , "miniature") \
    WayEmbedded_Rails_MEMBER(usingType, NARROW_GAUGE    , "narrow_gauge") \
    WayEmbedded_Rails_MEMBER(usingType, RAIL            , "rail") \
    WayEmbedded_Rails_MEMBER(usingType, TRAM            , "tram") \
    WayEmbedded_Rails_MEMBER(usingType, YES             , "yes") \
    EMPTY_COMMAND

struct WayEmbedded_Rails
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayEmbedded_Rails)
};

}
