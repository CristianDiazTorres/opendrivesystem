#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:sidewalk

*/

namespace _NOSM
{

#define WaySidewalk_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WaySidewalk, name, value)

#define WaySidewalk_MEMBERS(usingType) \
    WaySidewalk_MEMBER(usingType, BOTH    ,"both") \
    WaySidewalk_MEMBER(usingType, RIGHT   ,"right") \
    WaySidewalk_MEMBER(usingType, LEFT    ,"left") \
    WaySidewalk_MEMBER(usingType, NONE    ,"none") \
    WaySidewalk_MEMBER(usingType, NO      ,"no") \
    WaySidewalk_MEMBER(usingType, YES     ,"yes") \
    WaySidewalk_MEMBER(usingType, SEPARATE,"separate") \
    EMPTY_COMMAND

struct WaySidewalk
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WaySidewalk)
};

}
