#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:service

*/

namespace _NOSM
{

#define WayService_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayService, name, value)

#define WayService_MEMBERS(usingType) \
    WayService_MEMBER(usingType, PARKING_AISLE   ,"parking_aisle") \
    WayService_MEMBER(usingType, DRIVEWAY        ,"driveway") \
    WayService_MEMBER(usingType, ALLEY           ,"alley") \
    WayService_MEMBER(usingType, EMERGENCY_ACCESS,"emergency_access") \
    WayService_MEMBER(usingType, DRIVE_THROUGH   ,"drive-through") \
    WayService_MEMBER(usingType, YARD            ,"yard") \
    WayService_MEMBER(usingType, SIDING          ,"siding") \
    WayService_MEMBER(usingType, SPUR            ,"spur") \
    WayService_MEMBER(usingType, CROSSOVER       ,"crossover") \
    WayService_MEMBER(usingType, TOURISM         ,"tourism") \
    WayService_MEMBER(usingType, NIGHT           ,"night") \
    WayService_MEMBER(usingType, CAR_SHUTTLE     ,"car_shuttle") \
    WayService_MEMBER(usingType, CAR	         ,"car	") \
    WayService_MEMBER(usingType, COMMUTER        ,"commuter") \
    WayService_MEMBER(usingType, REGIONAL        ,"regional") \
    WayService_MEMBER(usingType, LONG_DISTANCE   ,"long_distance") \
    WayService_MEMBER(usingType, HIGH_SPEED      ,"high_speed") \
    WayService_MEMBER(usingType, DEALER          ,"dealer") \
    WayService_MEMBER(usingType, REPAIR          ,"repair") \
    WayService_MEMBER(usingType, TYRES           ,"tyres") \
    WayService_MEMBER(usingType, FUEL            ,"fuel") \
    WayService_MEMBER(usingType, PARTS           ,"parts") \
    WayService_MEMBER(usingType, OIL             ,"oil") \
    WayService_MEMBER(usingType, IRRIGATION      ,"irrigation") \
    WayService_MEMBER(usingType, WATER_POWER     ,"water_power") \
    EMPTY_COMMAND

struct WayService
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayService)
};

}
