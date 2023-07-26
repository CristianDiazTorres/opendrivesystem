#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_GANTRY(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_gantry_type_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_camera_mount_A, _SC_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction_highway_A, _SC_toll_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_crane, _SC_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crane_type_A, _SC_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway, _SC_toll_gantry) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_man_made, _SC_gantry))
    {
        od_object.type = _NOD::e_objectType::GANTRY;
        return true;
    }

    return false;
}

}
