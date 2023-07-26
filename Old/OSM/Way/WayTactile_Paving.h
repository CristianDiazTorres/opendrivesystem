#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:tactile_paving

*/

namespace _NOSM
{

#define WayTactile_Paving_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTactile_Paving, name, value)

#define WayTactile_Paving_MEMBERS(usingType) \
    WayTactile_Paving_MEMBER(usingType, YES , "yes") \
    WayTactile_Paving_MEMBER(usingType, NO , "no") \
    WayTactile_Paving_MEMBER(usingType, CONTRASTED , "contrasted") \
    WayTactile_Paving_MEMBER(usingType, PRIMIITVE , "primitive") \
    WayTactile_Paving_MEMBER(usingType, INCORRECT , "incorrect") \
    EMPTY_COMMAND

struct WayTactile_Paving
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTactile_Paving)
};

}
