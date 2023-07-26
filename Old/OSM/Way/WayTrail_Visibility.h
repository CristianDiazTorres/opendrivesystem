#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:trail_visibility

*/

namespace _NOSM
{

#define WayTrail_Visibility_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTrail_Visibility, name, value)

#define WayTrail_Visibility_MEMBERS(usingType) \
    WayTrail_Visibility_MEMBER(usingType, EXCELLENT   ,"excellent") \
    WayTrail_Visibility_MEMBER(usingType, GOOD        ,"good") \
    WayTrail_Visibility_MEMBER(usingType, INTERMEDIATE,"intermediate") \
    WayTrail_Visibility_MEMBER(usingType, BAD         ,"bad") \
    WayTrail_Visibility_MEMBER(usingType, HORRIBLE    ,"horrible") \
    WayTrail_Visibility_MEMBER(usingType, NO          ,"no") \
    EMPTY_COMMAND

struct WayTrail_Visibility
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTrail_Visibility)
};

}
