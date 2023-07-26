#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:conveying

*/

namespace _NOSM
{

#define WayConveying_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayConveying, name, value)

#define WayConveying_MEMBERS(usingType) \
    WayConveying_MEMBER(usingType, YES              , "yes") \
    WayConveying_MEMBER(usingType, BACKWARD         , "forward") \
    WayConveying_MEMBER(usingType, FORWARD          , "backward") \
    WayConveying_MEMBER(usingType, REVERSIBLE       , "reversible") \
    EMPTY_COMMAND

struct WayConveying
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayConveying)
};

}
