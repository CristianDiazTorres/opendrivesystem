#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertRoadElevationProfile(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmWay);
    Q_UNUSED(odRoad);

    double elevation = osmWay.osm[_SC_elevation].toInt();
    if (elevation <= 0)
        return;

    _NOD::t_road_elevationProfile_elevation odElevation;
    odElevation.s = 0;
    odElevation.a = elevation;
    odElevation.b = 0;
    odElevation.c = 0;
    odElevation.d = 0;

    odRoad.elevationProfile_sequence.resize(1);
    odRoad.elevationProfile_sequence[0].elevation_sequence << odElevation;
}

}
