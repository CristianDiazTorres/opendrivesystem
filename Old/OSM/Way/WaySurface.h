#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:surface

*/

namespace _NOSM
{

#define WaySurface_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WaySurface, name, value)

#define WaySurface_MEMBERS(usingType) \
    WaySurface_MEMBER(usingType, PAVED                          , "paved") \
    WaySurface_MEMBER(usingType, ASPHALT                        , "asphalt") \
    WaySurface_MEMBER(usingType, CONCRETE                       , "concrete") \
    WaySurface_MEMBER(usingType, CONCRETE_LANES                 , "concrete:lanes") \
    WaySurface_MEMBER(usingType, CONCRETE_PLATES                , "concrete:plates") \
    WaySurface_MEMBER(usingType, PAVING_STONES                  , "paving_stones") \
    WaySurface_MEMBER(usingType, SETT                           , "sett") \
    WaySurface_MEMBER(usingType, UNHEWN_COBBLESTONE             , "unhewn_cobblestone") \
    WaySurface_MEMBER(usingType, COBBLESTONE                    , "cobblestone") \
    WaySurface_MEMBER(usingType, COBBLESTONE_FLATTENED          , "cobblestone:flattened") \
    WaySurface_MEMBER(usingType, METAL                          , "metal") \
    WaySurface_MEMBER(usingType, WOOD                           , "wood") \
    WaySurface_MEMBER(usingType, STEPPING_STONES                , "stepping_stones") \
    WaySurface_MEMBER(usingType, UNPAVED                        , "unpaved") \
    WaySurface_MEMBER(usingType, COMPACTED                      , "compacted") \
    WaySurface_MEMBER(usingType, FINE_GRAVEL                    , "fine_gravel") \
    WaySurface_MEMBER(usingType, GRAVEL                         , "gravel") \
    WaySurface_MEMBER(usingType, ROCK                           , "rock") \
    WaySurface_MEMBER(usingType, PEBBLESTONE                    , "pebblestone") \
    WaySurface_MEMBER(usingType, GROUND                         , "ground") \
    WaySurface_MEMBER(usingType, DIRT                           , "dirt") \
    WaySurface_MEMBER(usingType, EARTH                          , "earth") \
    WaySurface_MEMBER(usingType, GRASS                          , "grass") \
    WaySurface_MEMBER(usingType, GRASS_PAVER                    , "grass_paver") \
    WaySurface_MEMBER(usingType, MUD                            , "mud") \
    WaySurface_MEMBER(usingType, SAND                           , "sand") \
    WaySurface_MEMBER(usingType, WOODCHIPS                      , "woodchips") \
    WaySurface_MEMBER(usingType, SNOW                           , "snow") \
    WaySurface_MEMBER(usingType, ICE                            , "ice") \
    WaySurface_MEMBER(usingType, SALT                           , "salt") \
    WaySurface_MEMBER(usingType, CLAY                           , "clay") \
    WaySurface_MEMBER(usingType, TARTAN                         , "tartan") \
    WaySurface_MEMBER(usingType, ARTIFICIAL_TURF                , "artificial_turf") \
    WaySurface_MEMBER(usingType, ACRYLIC                        , "acrylic") \
    WaySurface_MEMBER(usingType, METAL_GRID                     , "metal_grid") \
    WaySurface_MEMBER(usingType, CARPET                         , "carpet") \
    EMPTY_COMMAND

struct WaySurface
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WaySurface)
};

}
