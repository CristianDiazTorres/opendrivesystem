#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertRoadType(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);

    QString highway = osmWay.osm[_SC_highway];

    _NOD::t_road_type od_road_type;
    od_road_type.country = osmWay.osm[_SC_addr_country_A];

    if (highway == _SC_rural ||
        highway == _SC_track)
    {
        od_road_type.type = _NOD::e_roadType::RURAL;
    }
    else if (highway == _SC_motorway ||
        highway == _SC_trunk ||
        highway == _SC_primary ||
        highway == _SC_secondary ||
        highway == _SC_tertiary ||
        highway == _SC_unclassified ||
        highway == _SC_motorway_link ||
        highway == _SC_trunk_link ||
        highway == _SC_primary_link ||
        highway == _SC_secondary_link ||
        highway == _SC_tertiary_link)
    {
        od_road_type.type = _NOD::e_roadType::MOTORWAY;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWN;
    }
    else if (highway == _SC_living_street)
    {
        od_road_type.type = _NOD::e_roadType::LOWSPEED;
    }
    else if (highway == _SC_pedestrian ||
        highway == _SC_footway ||
        highway == _SC_crossing ||
        highway == _SC_bridleway ||
        highway == _SC_steps ||
        highway == _SC_corridor ||
        highway == _SC_path)
    {
        od_road_type.type = _NOD::e_roadType::PEDESTRIAN;
    }
    else if (highway.contains(_SC_bicycle) ||
        highway.contains(_SC_cycleway))
    {
        od_road_type.type = _NOD::e_roadType::BICYCLE;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWNEXPRESSWAY;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWNCOLLECTOR;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWNARTERIAL;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWNPRIVATE;
    }
    else if (highway == _SC_residential)
    {
        od_road_type.type = _NOD::e_roadType::TOWNLOCAL;
    }
    else if (false)
    {
        od_road_type.type = _NOD::e_roadType::TOWNPLAYSTREET;
    }
    else
    {
        od_road_type.type = _NOD::e_roadType::UNKNOWN;
    }

    od_road_type.s = 0;

    convertRoadTypeSpeed(database_connector, osmWay, od_road_type);

    odRoad.type_sequence << od_road_type;
}

}
