#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_TRAFFICISLAND(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_miniroundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_crossing_island_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing_island_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_crossing_island_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_playground_roundabout_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_playground_roundabout_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction_crossing_A, _SC_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_crossing, _SC_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed_crossing_A, _SC_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_bicycle_parking_position_A, _SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused_playground_A, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_playground, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned_highway_A, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned_highway_A, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction_junction_A, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished_highway_A, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished_junction_A, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused_highway_A, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed_playground_A, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_junction, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_junction, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_traffic_calming, _SC_mini_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_user_defined, _SC_roundabout) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crossing, _SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway, _SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_footway, _SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_landuse, _SC_traffic_island) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_traffic_calming, _SC_traffic_island))
    {
        od_object.type = _NOD::e_objectType::TRAFFICISLAND;
        return true;
    }

    return false;
}

}
