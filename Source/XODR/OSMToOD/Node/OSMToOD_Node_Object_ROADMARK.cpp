#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_ROADMARK(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_roadmark) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_road_mark) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_road_marking) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing_road_marking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_kerb_road_marking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_road_marking_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_enforcement, _SC_road_marking))
    {
        od_object.type = _NOD::e_objectType::ROADMARK;
        return true;
    }

    return false;
}

}
