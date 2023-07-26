#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:priority_road

*/

namespace _NOSM
{

#define WayPriority_Road_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayPriority_Road, name, value)

#define WayPriority_Road_MEMBERS(usingType) \
    WayPriority_Road_MEMBER(usingType, DESIGNATED, "designated") \
    WayPriority_Road_MEMBER(usingType, YES_UNPOSTED, "yes_unposted") \
    WayPriority_Road_MEMBER(usingType, END, "end") \
    EMPTY_COMMAND

struct WayPriority_Road
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayPriority_Road)
};

}
