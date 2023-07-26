#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_RAILING(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_handrail) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_railing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_fence, _SC_railing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_fence_type_A, _SC_railing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_barrier, _SC_handrail) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_fence_type, _SC_balustrade))
    {
        od_object.type = _NOD::e_objectType::RAILING;
        return true;
    }

    return false;
}

}
