#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_VEGETATION(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_vegetation) ||
        values.contains(_SC_vegetation))
    {
        od_object.type = _NOD::e_objectType::VEGETATION;
        return true;
    }

    return false;
}

}
