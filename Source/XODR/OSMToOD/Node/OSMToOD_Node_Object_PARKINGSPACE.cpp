#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_PARKINGSPACE(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_park) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking_1) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking_position) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking_slots) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking_space) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_parking_zone) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_demolished_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_zone_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_bicycle_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_motorcycle_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_zone, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_amenity, _SC_park) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_amenity_1, _SC_park) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_amenity_2, _SC_park) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned_amenity_A, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_bicycle, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_building, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction_amenity_A, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished_amenity_A, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_motorcycle, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_old_amenity_A, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_old_amenity, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed_amenity_A, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_service_vehicle_parking_A, _SC_yes) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_services, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_site, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_training, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_transport, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_transportation, _SC_parking) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_use, _SC_private_parking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_user_defined_other, _SC_parking))
    {
        od_object.type = _NOD::e_objectType::PARKINGSPACE;
        return true;
    }

    return false;
}

}
