#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:footway

*/

namespace _NOSM
{

#define WayFootway_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayFootway, name, value)

#define WayFootway_MEMBERS(usingType) \
    WayFootway_MEMBER(usingType, ACCESS_AISLE           , "access_aisle") \
    WayFootway_MEMBER(usingType, CROSSING               , "crossing") \
    WayFootway_MEMBER(usingType, SIDEWALK               , "sidewalk") \
    WayFootway_MEMBER(usingType, BOTH                   , "both") \
    WayFootway_MEMBER(usingType, RIGHT                  , "right") \
    WayFootway_MEMBER(usingType, LEFT                   , "left") \
    WayFootway_MEMBER(usingType, NONE                   , "none") \
    EMPTY_COMMAND

struct WayFootway
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayFootway)
};

}
