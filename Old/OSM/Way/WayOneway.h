#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:oneway

*/

namespace _NOSM
{

#define WayOneway_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayOneway, name, value)

#define WayOneway_MEMBERS(usingType) \
    WayOneway_MEMBER(usingType, YES         , "yes") /* (discouraged alternatives: "true", "1") */ \
    WayOneway_MEMBER(usingType, TRUE        , "true") \
    WayOneway_MEMBER(usingType, _1          , "1") \
    WayOneway_MEMBER(usingType, NO          , "no") /* (discouraged alternatives: "false", "0") */ \
    WayOneway_MEMBER(usingType, FALSE       , "false") \
    WayOneway_MEMBER(usingType, _0          , "0") \
    WayOneway_MEMBER(usingType, __1         , "-1") /* (discouraged alternative: "reverse") */ \
    WayOneway_MEMBER(usingType, REVERSE     , "reverse") \
    WayOneway_MEMBER(usingType, REVERSIBLE  , "reversible") \
    WayOneway_MEMBER(usingType, ALTERNATING , "alternating") \
    EMPTY_COMMAND

struct WayOneway
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayOneway)
};

}
