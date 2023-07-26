#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:tracktype

*/

namespace _NOSM
{

#define WayTracktype_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTracktype, name, value)

#define WayTracktype_MEMBERS(usingType) \
    WayTracktype_MEMBER(usingType, GRADE1, "grade1") \
    WayTracktype_MEMBER(usingType, GRADE2, "grade2") \
    WayTracktype_MEMBER(usingType, GRADE3, "grade3") \
    WayTracktype_MEMBER(usingType, GRADE4, "grade4") \
    WayTracktype_MEMBER(usingType, GRADE5, "grade5") \
    EMPTY_COMMAND

struct WayTracktype
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTracktype)
};

}
