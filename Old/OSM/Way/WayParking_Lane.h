#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:parking:lane

*/

namespace _NOSM
{

#define WayParking_Lane_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayParking_Lane, name, value)

#define WayParking_Lane_MEMBERS(usingType) \
    WayParking_Lane_MEMBER(usingType, PARALLEL      , "parallel") \
    WayParking_Lane_MEMBER(usingType, DIAGONAL      , "diagonal") \
    WayParking_Lane_MEMBER(usingType, PERPENDICULAR , "perpendicular") \
    WayParking_Lane_MEMBER(usingType, MARKED        , "marked") \
    WayParking_Lane_MEMBER(usingType, NO_PARKING    , "no_parking") \
    WayParking_Lane_MEMBER(usingType, NO_STOPPING   , "no_stopping") \
    WayParking_Lane_MEMBER(usingType, FIRE_LANE     , "fire_lane") \
    WayParking_Lane_MEMBER(usingType, NO            , "no") \
    WayParking_Lane_MEMBER(usingType, SEPARATE      , "separate") \
    WayParking_Lane_MEMBER(usingType, ON_STREET     , "on_street") \
    WayParking_Lane_MEMBER(usingType, HALF_ON_KERB  , "half_on_kerb") \
    WayParking_Lane_MEMBER(usingType, ON_KERB       , "on_kerb") \
    WayParking_Lane_MEMBER(usingType, STREET_SIDE   , "street_side") \
    WayParking_Lane_MEMBER(usingType, LAY_BY        , "lay_by") \
    WayParking_Lane_MEMBER(usingType, PAINTED_AREA_ONLY, "painted_area_only") \
    WayParking_Lane_MEMBER(usingType, SHOULDER      , "shoulder") \
    EMPTY_COMMAND

struct WayParking_Lane
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayParking_Lane)
};

}
