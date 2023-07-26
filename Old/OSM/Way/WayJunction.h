#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:junction

*/

namespace _NOSM
{

#define WayJunction_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayJunction, name, value)

#define WayJunction_MEMBERS(usingType) \
    WayJunction_MEMBER(usingType, ROUNDABOUT    , "roundabout") \
    WayJunction_MEMBER(usingType, CIRCULAR      , "circular") \
    WayJunction_MEMBER(usingType, JUGHANDLE     , "jughandle") \
    WayJunction_MEMBER(usingType, FILTER        , "filter") \
    WayJunction_MEMBER(usingType, YES           , "yes") \
    EMPTY_COMMAND

struct WayJunction
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayJunction)
};

}
