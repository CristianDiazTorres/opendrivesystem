#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:traffic_calming

*/

namespace _NOSM
{

#define WayTraffic_Calming_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTraffic_Calming, name, value)

#define WayTraffic_Calming_MEMBERS(usingType) \
    WayTraffic_Calming_MEMBER(usingType, YES          ,"yes") \
    WayTraffic_Calming_MEMBER(usingType, BUMP         ,"bump") \
    WayTraffic_Calming_MEMBER(usingType, HUMP         ,"hump") \
    WayTraffic_Calming_MEMBER(usingType, TABLE        ,"table") \
    WayTraffic_Calming_MEMBER(usingType, CUSHION      ,"cushion") \
    WayTraffic_Calming_MEMBER(usingType, RUMBLE_STRIP ,"rumble_strip") \
    WayTraffic_Calming_MEMBER(usingType, DIP          ,"dip") \
    WayTraffic_Calming_MEMBER(usingType, DOUBLE_DIP   ,"double_dip") \
    WayTraffic_Calming_MEMBER(usingType, DYNAMIC_BUMP ,"dynamic_bump") \
    WayTraffic_Calming_MEMBER(usingType, CHICANE      ,"chicane") \
    WayTraffic_Calming_MEMBER(usingType, CHOKER       ,"choker") \
    WayTraffic_Calming_MEMBER(usingType, ISLAND       ,"island") \
    WayTraffic_Calming_MEMBER(usingType, CHOKED_ISLAND,"choked_island") \
    WayTraffic_Calming_MEMBER(usingType, CHOKED_TABLE ,"choked_table") \
    EMPTY_COMMAND

struct WayTraffic_Calming
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTraffic_Calming)
};

}
