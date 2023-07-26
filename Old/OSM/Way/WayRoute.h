#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:route

*/

namespace _NOSM
{

#define WayRoute_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayRoute, name, value)

#define WayRoute_MEMBERS(usingType) \
    WayRoute_MEMBER(usingType, BUS           , "bus") \
    WayRoute_MEMBER(usingType, TROLLEYBUS    , "trolleybus") \
    WayRoute_MEMBER(usingType, MINIBUS       , "minibus") \
    WayRoute_MEMBER(usingType, SHARE_TAXI    , "share_taxi") \
    WayRoute_MEMBER(usingType, TRAIN         , "train") \
    WayRoute_MEMBER(usingType, LIGHT_RAIL    , "light_rail") \
    WayRoute_MEMBER(usingType, SUBWAY        , "subway") \
    WayRoute_MEMBER(usingType, TRAM          , "tram") \
    WayRoute_MEMBER(usingType, MONORAIL      , "monorail") \
    WayRoute_MEMBER(usingType, FERRY         , "ferry") \
    WayRoute_MEMBER(usingType, ROAD          , "road") \
    WayRoute_MEMBER(usingType, DETOUR        , "detour") \
    WayRoute_MEMBER(usingType, EVACUATION    , "evacuation") \
    WayRoute_MEMBER(usingType, RAILWAY       , "railway") \
    WayRoute_MEMBER(usingType, TRACKS        , "tracks") \
    WayRoute_MEMBER(usingType, SNOWMOBILE    , "snowmobile") \
    WayRoute_MEMBER(usingType, HIKING        , "hiking") \
    WayRoute_MEMBER(usingType, FOOT          , "foot") \
    WayRoute_MEMBER(usingType, NORDIC_WALKING, "nordic_walking") \
    WayRoute_MEMBER(usingType, RUNNING       , "running") \
    WayRoute_MEMBER(usingType, FITNESS_TRAIL , "fitness_trail") \
    WayRoute_MEMBER(usingType, INLINE_SKATES , "inline_skates") \
    WayRoute_MEMBER(usingType, BICYCLE       , "bicycle") \
    WayRoute_MEMBER(usingType, MTB           , "mtb") \
    WayRoute_MEMBER(usingType, HORSE         , "horse") \
    WayRoute_MEMBER(usingType, TRANSHUMANCE  , "transhumance") \
    WayRoute_MEMBER(usingType, PISTE         , "piste") \
    WayRoute_MEMBER(usingType, SKI           , "ski") \
    /*WayRoute_MEMBER(usingType, FERRY         , "ferry")*/ \
    WayRoute_MEMBER(usingType, WATERWAY      , "waterway") \
    WayRoute_MEMBER(usingType, BOAT          , "boat") \
    WayRoute_MEMBER(usingType, MOTORBOAT     , "motorboat") \
    WayRoute_MEMBER(usingType, CANOE         , "canoe") \
    WayRoute_MEMBER(usingType, POWER         , "power") \
    WayRoute_MEMBER(usingType, PIPELINE      , "pipeline") \
    EMPTY_COMMAND

struct WayRoute
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayRoute)
};

}
