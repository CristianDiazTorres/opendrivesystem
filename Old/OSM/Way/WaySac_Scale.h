#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:sac_scale

*/

namespace _NOSM
{

#define WaySac_Scale_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WaySac_Scale, name, value)

#define WaySac_Scale_MEMBERS(usingType) \
    WaySac_Scale_MEMBER(usingType, HIKING                   , "hiking") \
    WaySac_Scale_MEMBER(usingType, MOUNTAIN_HIKING          , "mountain_hiking") \
    WaySac_Scale_MEMBER(usingType, DEMANDING_MOUNTAIN_HIKING, "demanding_mountain_hiking") \
    WaySac_Scale_MEMBER(usingType, ALPINE_HIKING            , "alpine_hiking") \
    WaySac_Scale_MEMBER(usingType, DEMANDING_ALPINE_HIKING  , "demanding_alpine_hiking") \
    WaySac_Scale_MEMBER(usingType, DIFFICULT_ALPINE_HIKING  , "difficult_alpine_hiking") \
    EMPTY_COMMAND

struct WaySac_Scale
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WaySac_Scale)
};

}
