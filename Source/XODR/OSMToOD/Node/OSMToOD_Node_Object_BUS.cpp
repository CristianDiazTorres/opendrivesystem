#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_BUS(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (false)
    {
        od_object.type = _NOD::e_objectType::BUS; // ???
        return true;
    }

    return false;
}

}
