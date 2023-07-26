#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:crossing_ref

*/

namespace _NOSM
{

#define WayCrossing_Ref_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayCrossing_Ref, name, value)

#define WayCrossing_Ref_MEMBERS(usingType) \
    WayCrossing_Ref_MEMBER(usingType, ZEBRA         , "zebra") \
    WayCrossing_Ref_MEMBER(usingType, PELICAN       , "pelica") \
    WayCrossing_Ref_MEMBER(usingType, TOUCAN        , "toucan") \
    WayCrossing_Ref_MEMBER(usingType, TIGER         , "tiger") \
    WayCrossing_Ref_MEMBER(usingType, PEGASUS       , "pegasus") \
    WayCrossing_Ref_MEMBER(usingType, PUFFIN        , "puffin") \
    WayCrossing_Ref_MEMBER(usingType, PXO           , "pxo") \
    EMPTY_COMMAND

struct WayCrossing_Ref
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayCrossing_Ref)
};

}
