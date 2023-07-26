#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:wheelchair

*/

namespace _NOSM
{

#define WayWheelchair_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayWheelchair, name, value)

#define WayWheelchair_MEMBERS(usingType) \
    WayWheelchair_MEMBER(usingType, YES, "yes") \
    WayWheelchair_MEMBER(usingType, LIMITED, "limited") \
    WayWheelchair_MEMBER(usingType, NO, "no") \
    WayWheelchair_MEMBER(usingType, DESIGNATED, "designated") \
    EMPTY_COMMAND

struct WayWheelchair
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayWheelchair)
};

}
