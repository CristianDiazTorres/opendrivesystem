#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_POLE(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (//values.contains(_SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_pole_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_fence_pole_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_pole_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_ref_pole_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_type_pole_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_fence, _SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed, _SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_ref, _SC_pole) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_type, _SC_pole))
    {
        od_object.type = _NOD::e_objectType::POLE;
        return true;
    }

    return false;
}

}
