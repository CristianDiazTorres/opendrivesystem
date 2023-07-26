#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_CROSSWALK(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_crosswalk) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_demolished_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_historic_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_crossing_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_footway, _SC_crosswalk) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_bicycle, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_railway, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_historic, _SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed, _SC_crossing))
    {
        od_object.type = _NOD::e_objectType::CROSSWALK;
        return true;
    }

    return false;
}

}
