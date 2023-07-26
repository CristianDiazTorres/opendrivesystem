#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:tunnel

*/

namespace _NOSM
{

#define WayTunnel_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTunnel, name, value)

#define WayTunnel_MEMBERS(usingType) \
    WayTunnel_MEMBER(usingType, YES                ,"yes") \
    WayTunnel_MEMBER(usingType, BUILDING_PASSAGE   ,"building_passage") \
    WayTunnel_MEMBER(usingType, AVALANCHE_PROTECTOR,"avalanche_protector") \
    WayTunnel_MEMBER(usingType, CULVERT            ,"culvert") \
    WayTunnel_MEMBER(usingType, FLOODED            ,"flooded") \
    EMPTY_COMMAND

struct WayTunnel
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTunnel)
};

}
