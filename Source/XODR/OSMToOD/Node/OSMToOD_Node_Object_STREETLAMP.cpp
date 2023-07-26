#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_STREETLAMP(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_streetlamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_streetlamp_ref_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_streetlight) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_street_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_street_lamp_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_light, _SC_street_lamp_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_light_type_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_lamp_type_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_lamp_type, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_lamp_type, _SC_street_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_pole, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_amenity, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway, _SC_street_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_highway_1, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_historic_highway_A, _SC_street_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_lit, _SC_street_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_street_furniture, _SC_lamppost))
    {
        od_object.type = _NOD::e_objectType::STREETLAMP;
        return true;
    }

    return false;
}

}
