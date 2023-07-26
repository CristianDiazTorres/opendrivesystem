#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:abutters

*/

namespace _NOSM
{

#define WayAbutters_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayAbutters, name, value)

#define WayAbutters_MEMBERS(usingType) \
    WayAbutters_MEMBER(usingType, COMMERCIAL        , "commercial") \
    WayAbutters_MEMBER(usingType, INDUSTRIAL        , "industrial") \
    WayAbutters_MEMBER(usingType, MIXED             , "mixed") \
    WayAbutters_MEMBER(usingType, RESIDENTIAL       , "residential") \
    WayAbutters_MEMBER(usingType, RETAIL            , "retail") \
    EMPTY_COMMAND

struct WayAbutters
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayAbutters)
};

}
