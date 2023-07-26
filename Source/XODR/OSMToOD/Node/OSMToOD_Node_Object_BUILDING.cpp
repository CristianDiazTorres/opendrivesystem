#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_BUILDING(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_demolished_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_destroyed_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_historic_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_historic_1_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_historical_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_name_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_ruined_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_ruins_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_seamark_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_temporary_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_addr_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_addr_housename_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_area_building_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_house) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_construction, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_destroyed, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_disused, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_historic, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_historic_1, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_historical, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_ruined, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_ruins, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_seamark, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_temporary, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_accomodation, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_area, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_industrial, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_residential, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_structure, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_type, _SC_building) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_public_transport, _SC_station) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_railway, _SC_station) ||
        amenity == _SC_bank ||
        amenity == _SC_cafe ||
        amenity == _SC_animal_shelter ||
        amenity == _SC_arts_centre ||
        amenity == _SC_casino ||
        amenity == _SC_cinema ||
        amenity == _SC_clinic ||
        amenity == _SC_cloakroom ||
        amenity == _SC_club ||
        amenity == _SC_courthouse ||
        amenity == _SC_culture_center ||
        amenity == _SC_customs ||
        amenity == _SC_dancing_school ||
        amenity == _SC_embassy ||
        amenity == _SC_exhibition_centre ||
        amenity == _SC_garages ||
        amenity == _SC_gym ||
        amenity == _SC_hospice ||
        amenity == _SC_hospital ||
        amenity == _SC_hotel ||
        amenity == _SC_internet_cafe ||
        amenity == _SC_jobcentre ||
        amenity == _SC_karaoke_box ||
        amenity == _SC_kindergarten ||
        amenity == _SC_kiosk ||
        amenity == _SC_library ||
        amenity == _SC_lost_property_office ||
        amenity == _SC_love_hotel ||
        amenity == _SC_marketplace ||
        amenity == _SC_monastery ||
        amenity == _SC_music_school ||
        amenity == _SC_nightclub ||
        amenity == _SC_office ||
        amenity == _SC_post_office ||
        amenity == _SC_prison ||
        amenity == _SC_pub ||
        amenity == _SC_public_building ||
        amenity == _SC_refugee_housing ||
        amenity == _SC_research_institute ||
        amenity == _SC_restaurant ||
        amenity == _SC_school ||
        amenity == _SC_ski_school ||
        amenity == _SC_stripclub ||
        amenity == _SC_studio ||
        amenity == _SC_surf_school ||
        amenity == _SC_theatre ||
        amenity == _SC_university ||
        amenity == _SC_auto_repair_shop_A ||
        amenity == _SC_pub_lottery_A ||
        amenity == _SC_streetfood)
    {
        od_object.type = _NOD::e_objectType::BUILDING;
        return true;
    }

    return false;
}

}
