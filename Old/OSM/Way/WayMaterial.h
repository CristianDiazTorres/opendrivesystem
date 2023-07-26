#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:material

*/

namespace _NOSM
{

#define WayMaterial_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayMaterial, name, value)

#define WayMaterial_MEMBERS(usingType) \
    WayMaterial_MEMBER(usingType, WOOD                  , "wood") \
    WayMaterial_MEMBER(usingType, PALM_LEAVES           , "palm_leaves") \
    WayMaterial_MEMBER(usingType, BAMBOO                , "bamboo") \
    WayMaterial_MEMBER(usingType, METAL                 , "metal") \
    WayMaterial_MEMBER(usingType, BRASS                 , "brass") \
    WayMaterial_MEMBER(usingType, BRONZE                , "bronze") \
    WayMaterial_MEMBER(usingType, STEEL                 , "steel") \
    WayMaterial_MEMBER(usingType, CONCRETE              , "concrete") \
    WayMaterial_MEMBER(usingType, REINFORCED_CONCRETE   , "reinforced_concrete") \
    WayMaterial_MEMBER(usingType, STONE                 , "stone") \
    WayMaterial_MEMBER(usingType, GRANITE               , "granite") \
    WayMaterial_MEMBER(usingType, SANDSTONE             , "sandstone") \
    WayMaterial_MEMBER(usingType, MASONRY               , "masonry") \
    WayMaterial_MEMBER(usingType, BRICK                 , "brick") \
    WayMaterial_MEMBER(usingType, SILICATEBRICK         , "silicatebrick") \
    WayMaterial_MEMBER(usingType, ADOBE                 , "adobe") \
    WayMaterial_MEMBER(usingType, PLASTIC               , "plastic") \
    WayMaterial_MEMBER(usingType, SOIL                  , "soil") \
    WayMaterial_MEMBER(usingType, RAMMED_EARTH          , "rammed_earth") \
    WayMaterial_MEMBER(usingType, GLASS                 , "glass") \
    WayMaterial_MEMBER(usingType, ANDESITE              , "andesite") \
    EMPTY_COMMAND

struct WayMaterial
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayMaterial)
};

}
