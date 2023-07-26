#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:busway

*/

namespace _NOSM
{

#define WayBusway_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayBusway, name, value)

#define WayBusway_MEMBERS(usingType) \
    WayBusway_MEMBER(usingType, LANE               , "alane") \
    WayBusway_MEMBER(usingType, OPPOSITE_LANE      , "aopposite_lane") \
    EMPTY_COMMAND

struct WayBusway
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayBusway)
};

}
