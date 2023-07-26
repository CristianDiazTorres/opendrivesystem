#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:lit

*/

namespace _NOSM
{

#define WayLit_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayLit, name, value)

#define WayLit_MEMBERS(usingType) \
    WayLit_MEMBER(usingType, _24_7          , "24/7") \
    WayLit_MEMBER(usingType, YES            , "yes") \
    WayLit_MEMBER(usingType, AUTOMATIC      , "automatic") \
    WayLit_MEMBER(usingType, DISUSED        , "disused") \
    WayLit_MEMBER(usingType, NO             , "no") \
    WayLit_MEMBER(usingType, SUNSET_SUNRISE , "sunset-sunrise") \
    EMPTY_COMMAND

struct WayLit
{
    // TODO:???
    bool useOperatingTimes;
    String operatingTimes;

    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayLit)
};

}
