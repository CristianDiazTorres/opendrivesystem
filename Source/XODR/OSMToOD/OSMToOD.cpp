#include "XODR/OSMToOD/OSMToOD.h"
#include "XODR/Main/OSMExternalSourceProvider.h"
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "XODR/Main/XODRSettingsOnPGDatabase.h"

namespace _NXODR
{

double OSMToOpenDRIVE::MAX_NODE_ROAD_DISTANCE = 300;

QVector<_NOD::t_road> OSMToOpenDRIVE::buildRoads(
        bool useBasicTables,
        const VehiclePosVec& trajectory,
        ConstMeasurementContent& measurement_content,
        DatabaseConnector& database_connector,
        ConstExternalSourceProviderVec& external_source_providers,
        QVector<_NOSM::Way>& allOSMWays)
{
    DefaultLogger << "OSMToOpenDRIVE::buildRoads";

    Q_UNUSED(trajectory);
    Q_UNUSED(measurement_content);
    Q_UNUSED(database_connector);
    Q_UNUSED(external_source_providers);

    int osmExternalSourceProviderIndex = 0;
    for (; osmExternalSourceProviderIndex < external_source_providers.size(); osmExternalSourceProviderIndex ++)
    {
        ExternalSourceProvider* provider = external_source_providers[osmExternalSourceProviderIndex];
        if (provider->getProviderName() == _SC_OSMExternalSourceProvider)
            break;
    }

    QVector<_NOD::t_road> result;

    if (osmExternalSourceProviderIndex >= external_source_providers.size())
        return result;

    OSMExternalSourceProvider& externalProvider = (OSMExternalSourceProvider&)*external_source_providers[osmExternalSourceProviderIndex];

    QVector<_NOSM::Way> nearestOSMWays;
    externalProvider.getNearestRoadsForPath(useBasicTables, trajectory, allOSMWays, nearestOSMWays);
    if (nearestOSMWays.isEmpty())
        return result;

    result.resize(nearestOSMWays.size());
    for (int i = 0; i < nearestOSMWays.size(); i ++)
    {
        _NOSM::Way& osmWay = nearestOSMWays[i];
        _NOD::t_road& odRoad = result[i];

        if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteGPS())
        {
            _NOD::t_userData odUserData(_SC_gps);
            odUserData.gps_sequence << measurement_content;
            odRoad.additionalData.userData_sequence << odUserData;
        }

        if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteTrajectory())
        {
            _NOD::t_userData odUserData(_SC_trajectory);
            odUserData.trajectory_sequence << trajectory;
            odRoad.additionalData.userData_sequence << odUserData;
        }

        if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteOSM())
        {
            _NOD::t_userData odUserData(_SC_osm);
            odUserData.osm_sequence << osmWay.osm;
            odRoad.additionalData.userData_sequence << odUserData;
        }

        convertRoadAttrSubTags(database_connector, osmWay, odRoad);
        odRoad.init(osmWay.gps_coords_sequence);
        convertLane(database_connector, osmWay, odRoad);
    }

    return result;
}

void OSMToOpenDRIVE::updateOpenDRIVE(
        bool useBasicTables,
        const VehiclePosVec& trajectory,
        ConstMeasurementContent& measurement_content,
        DatabaseConnector& database_connector,
        ConstExternalSourceProviderVec& external_source_providers,
        QVector<_NOD::t_road> &odRoads,
        QVector<_NOSM::Way>& allOSMWays)
{
    Q_UNUSED(trajectory);
    Q_UNUSED(measurement_content);

    DefaultLogger << "    current road count : " << odRoads.size();
    if (odRoads.empty())
        return;

    int osmExternalSourceProviderIndex = 0;
    for (; osmExternalSourceProviderIndex < external_source_providers.size(); osmExternalSourceProviderIndex ++)
    {
        ExternalSourceProvider* provider = external_source_providers[osmExternalSourceProviderIndex];
        if (provider->getProviderName() == _SC_OSMExternalSourceProvider)
            break;
    }

    if (osmExternalSourceProviderIndex >= external_source_providers.size())
        return;

    OSMExternalSourceProvider& externalProvider = (OSMExternalSourceProvider&)*external_source_providers[osmExternalSourceProviderIndex];

    QVector<_NOSM::Node> osm_objects = externalProvider.getNodes(useBasicTables, trajectory[0]);
    convertNodes(database_connector, osm_objects, odRoads);

    const VehiclePos& firstPt = trajectory[0];

    _NOD::OpenDRIVE content;
    content.init(firstPt);
    content.road_sequence = odRoads;

    if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteOSMWay())
    {
        _NOD::t_userData odUserData(_SC_osmWay);
        odUserData.osmWay_sequence << allOSMWays;
        content.additionalData.userData_sequence << odUserData;
    }

    //database_connector.updateCacheOnly(content);
    PGDatabaseConnector_getDefaultInstance.updateXODRContent(firstPt, content);
}

}
