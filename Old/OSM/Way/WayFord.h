#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:ford

*/

namespace _NOSM
{

#define WayFord_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayFord, name, value)

#define WayFord_MEMBERS(usingType) \
    WayFord_MEMBER(usingType, YES                   , "yes") \
    WayFord_MEMBER(usingType, STEPPING_STONES       , "stepping_stones") \
    WayFord_MEMBER(usingType, BOAT                  , "boat") \
    EMPTY_COMMAND

struct WayFord
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayFord)
};

}
