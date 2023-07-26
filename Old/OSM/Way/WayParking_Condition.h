#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:parking:condition

*/

namespace _NOSM
{

#define WayParking_Condition_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayParking_Condition, name, value)

#define WayParking_Condition_MEMBERS(usingType) \
    WayParking_Condition_MEMBER(usingType, FREE         , "free") \
    WayParking_Condition_MEMBER(usingType, TICKET       , "ticket") \
    WayParking_Condition_MEMBER(usingType, DISC         , "disc") \
    WayParking_Condition_MEMBER(usingType, RESIDENTS    , "residents") \
    WayParking_Condition_MEMBER(usingType, CUSTOMERS    , "customers") \
    WayParking_Condition_MEMBER(usingType, PRIVATE      , "private") \
    EMPTY_COMMAND

struct WayParking_Condition
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayParking_Condition)
};

}
