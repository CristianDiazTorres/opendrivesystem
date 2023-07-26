#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:turn

*/

namespace _NOSM
{

#define WayTurn_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTurn, name, value)

#define WayTurn_MEMBERS(usingType) \
    WayTurn_MEMBER(usingType, LEFT          ,"left") \
    WayTurn_MEMBER(usingType, SLIGHT_LEFT   ,"slight_left") \
    WayTurn_MEMBER(usingType, SHARP_LEFT    ,"sharp_left") \
    WayTurn_MEMBER(usingType, THROUGH       ,"through") \
    WayTurn_MEMBER(usingType, RIGHT         ,"right") \
    WayTurn_MEMBER(usingType, SLIGHT_RIGHT  ,"slight_right") \
    WayTurn_MEMBER(usingType, SHARP_RIGHT   ,"sharp_right") \
    WayTurn_MEMBER(usingType, LEFT_THROUGH  ,"left;through") \
    WayTurn_MEMBER(usingType, THROUGH_LEFT  ,"through;left") \
    WayTurn_MEMBER(usingType, RIGHT_THROUGH ,"right;through") \
    WayTurn_MEMBER(usingType, THROUGH_RIGHT ,"through;right") \
    WayTurn_MEMBER(usingType, REVERSE       ,"reverse") \
    WayTurn_MEMBER(usingType, MERGE_TO_LEFT ,"merge_to_left") \
    WayTurn_MEMBER(usingType, MERGE_TO_RIGHT,"merge_to_right") \
    WayTurn_MEMBER(usingType, NONE          ,"none") \
    EMPTY_COMMAND

struct WayTurn
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTurn)
};

}
