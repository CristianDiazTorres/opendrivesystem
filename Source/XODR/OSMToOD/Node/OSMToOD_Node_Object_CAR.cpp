#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_CAR(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_car_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_ruins_car_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_car) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_ruins, _SC_car))
    {
        od_object.type = _NOD::e_objectType::CAR;
        return true;
    }

    return false;
}

}
