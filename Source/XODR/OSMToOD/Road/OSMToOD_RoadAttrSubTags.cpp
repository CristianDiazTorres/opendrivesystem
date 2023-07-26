#include "XODR/OSMToOD/OSMToOD.h"
#include "Debugger/Main/Logger.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertRoadAttrSubTags(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    odRoad.name = osmWay.osm[_SC_name];

    odRoad.id = database_connector.getNewID();
    DefaultLogger << "Creating road with : " <<odRoad.id;

    if (osmWay.osm.contains(_SC_junction))
        odRoad.junction = 0; // Junction, we will make junction object later
    else
        odRoad.junction = -1; // No junction

    if (osmWay.isLHT())
        odRoad.rule = _NOD::e_trafficRule::LHT;
    else
        odRoad.rule = _NOD::e_trafficRule::RHT;

    odRoad.referenceId = osmWay.osm[_SC_id];
    if (osmWay.osm.contains(_SC_junction))
        odRoad.junctionType = osmWay.osm[_SC_junction];

    convertRoadType(database_connector, osmWay, odRoad);
    convertRoadElevationProfile(database_connector, osmWay, odRoad);
}

}
