#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:access

*/

namespace _NOSM
{

#define WayAccess_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayAccess, name, value)

#define WayAccess_MEMBERS(usingType) \
    WayAccess_MEMBER(usingType, YES                 , "yes") \
    WayAccess_MEMBER(usingType, NO                  , "no") \
    WayAccess_MEMBER(usingType, PRIVATE             , "private") \
    WayAccess_MEMBER(usingType, PERMISSIVE          , "permissive") \
    WayAccess_MEMBER(usingType, PERMIT              , "permit") \
    WayAccess_MEMBER(usingType, DESTINATION         , "destination") \
    WayAccess_MEMBER(usingType, DELIVERY            , "delivery") \
    WayAccess_MEMBER(usingType, CUSTOMERS           , "customers") \
    WayAccess_MEMBER(usingType, DESIGNATED          , "designated") \
    WayAccess_MEMBER(usingType, USE_SIDEPATH        , "use_sidepath") \
    WayAccess_MEMBER(usingType, DISMOUNT            , "dismount") \
    WayAccess_MEMBER(usingType, AGRICULTURAL        , "agricultural") \
    WayAccess_MEMBER(usingType, FORESTRY            , "forestry") \
    WayAccess_MEMBER(usingType, DISCOURAGED         , "discouraged") \
    WayAccess_MEMBER(usingType, UNKNOWN             , "unknown") \
    EMPTY_COMMAND

struct WayAccess
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayAccess)
};

}
