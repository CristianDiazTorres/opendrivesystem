#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:kerb

*/

namespace _NOSM
{

#define WayKerb_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayKerb, name, value)

#define WayKerb_MEMBERS(usingType) \
    WayKerb_MEMBER(usingType, RAISED    , "raised") \
    WayKerb_MEMBER(usingType, LOWERED   , "lowered") \
    WayKerb_MEMBER(usingType, FLUSH     , "flush") \
    WayKerb_MEMBER(usingType, ROLLED    , "rolled") \
    WayKerb_MEMBER(usingType, YES       , "yes") \
    WayKerb_MEMBER(usingType, NO        , "no") \
    EMPTY_COMMAND

struct WayKerb
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayKerb)
};

}
