#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

/*

https://wiki.openstreetmap.org/wiki/Key:highway

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dmotorway
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dtrunk
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dprimary
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dsecondary
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dtertiary
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dunclassified
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dresidential

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dmotorway_link
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dtrunk_link
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dprimary_link
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dsecondary_link
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dtertiary_link

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dliving_street
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dservice
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dpedestrian
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dtrack
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dbus_guideway
https://wiki.openstreetmap.org/wiki/Tag:highway%3Descape
https://wiki.openstreetmap.org/wiki/Tag:highway%3Draceway
https://wiki.openstreetmap.org/wiki/Tag:highway%3Droad

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dfootway
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dbridleway
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dsteps
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dcorridor
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dpath

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dcycleway

https://wiki.openstreetmap.org/wiki/Tag:highway%3Dproposed
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dconstruction

https://wiki.openstreetmap.org/wiki/Tag:highway%3Delevator
https://wiki.openstreetmap.org/wiki/Tag:highway%3Demergency_bay
https://wiki.openstreetmap.org/wiki/Tag:highway%3Dplatform

*/

namespace _NOSM
{

#define WayHighway_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayHighway, name, value)

#define WayHighway_MEMBERS(usingType) \
    WayHighway_MEMBER(usingType, MOTORWAY           , "motorway") \
    WayHighway_MEMBER(usingType, TRUNK              , "trunk") \
    WayHighway_MEMBER(usingType, PRIMARY            , "primary") \
    WayHighway_MEMBER(usingType, SECONDARY          , "secondary") \
    WayHighway_MEMBER(usingType, TERTIARY           , "tertiary") \
    WayHighway_MEMBER(usingType, UNCLASSIFIED       , "unclassified") \
    WayHighway_MEMBER(usingType, RESIDENTIAL        , "residential") \
    WayHighway_MEMBER(usingType, MOTORWAY_LINK      , "motorway_link") \
    WayHighway_MEMBER(usingType, TRUNK_LINK         , "trunk_link") \
    WayHighway_MEMBER(usingType, PRIMARY_LINK       , "primary_link") \
    WayHighway_MEMBER(usingType, SECONDARY_LINK     , "secondary_link") \
    WayHighway_MEMBER(usingType, TERTIARY_LINK      , "tertiary_link") \
    WayHighway_MEMBER(usingType, LIVING_STREET      , "living_street") \
    WayHighway_MEMBER(usingType, SERVICE            , "service") \
    WayHighway_MEMBER(usingType, PEDESTRIAN         , "pedestrian") \
    WayHighway_MEMBER(usingType, TRACK              , "track") \
    WayHighway_MEMBER(usingType, BUS_GUIDEWAY       , "bus_guideway") \
    WayHighway_MEMBER(usingType, ESCAPE             , "escape") \
    WayHighway_MEMBER(usingType, RACEWAY            , "raceway") \
    WayHighway_MEMBER(usingType, ROAD               , "road") \
    WayHighway_MEMBER(usingType, FOOTWAY            , "footway") \
    WayHighway_MEMBER(usingType, BRIDLEWAY          , "bridleway") \
    WayHighway_MEMBER(usingType, STEPS              , "steps") \
    WayHighway_MEMBER(usingType, CORRIDOR           , "corridor") \
    WayHighway_MEMBER(usingType, PATH               , "path") \
    WayHighway_MEMBER(usingType, CYCLEWAY           , "cycleway") \
    WayHighway_MEMBER(usingType, PROPOSED           , "proposed") \
    WayHighway_MEMBER(usingType, CONSTRUCTION       , "construction") \
    WayHighway_MEMBER(usingType, ELEVATOR           , "elevator") \
    WayHighway_MEMBER(usingType, EMERGENCY_BAY      , "emergency_bay") \
    WayHighway_MEMBER(usingType, PLATFORM           , "platform") \
    EMPTY_COMMAND

struct WayHighway
{
    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayHighway)
};

}
