#include "XODRTablesUpdateThread.h"
#include "OSM/OSM.h"
#include "XODR/Main/FileReader.h"
#include "XODR/Main/RoadFusor.h"
#include "DB/Main/LocalFilesDatabaseConnector.h"
#include "XODR/OSMToOD/OSMToOD.h"
#include "XODR/Main/OSMExternalSourceProvider.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "Trajectory/EgoTrajectoryCreator.h"
#include "Trajectory/TrajectorySpliter.h"

using namespace _NTrajectory;

namespace _NXODR
{

XODRTablesUpdateThread* XODRTablesUpdateThread::defaultInstance = 0;

void XODRTablesUpdateThread::setParams(bool useBasicTables, QString gpsFilePath)
{
    this->useBasicTables = useBasicTables;
    this->gpsFilePath = gpsFilePath;
}

bool XODRTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    LocalFilesDatabaseConnector local_files_database_connector;
    DatabaseConnector& database_connector = local_files_database_connector;

    //int start = 0;
    //if (!database_connector.setGPSFilePath(filePath, continue_, point_count, start))
    //    return false;

    if (hasToStop())
        return false;

    QString lastProcessedTrajectoryCellsId;
    qint64 countToProcess = 0;

    MeasurementContent measurement_content;
    VehiclePosVec trajectory;
    VehiclePosVecVec trajectories, splitedMeasurementData;

    if (useBasicTables)
    {
        PGDatabaseConnector_getDefaultInstance.getXODRState_LastProcessedTrajectorySequentialCellsDataId(lastProcessedTrajectoryCellsId);
        if (lastProcessedTrajectoryCellsId.isEmpty())
            lastProcessedTrajectoryCellsId = "0";

        PGDatabaseConnector_getDefaultInstance.getTrajectoryDataCountToProcessForXODR(countToProcess);
    }
    else
    {
        measurement_content = FileReader<MeasurementContent>().read(gpsFilePath);

        if (hasToStop())
            return false;

        trajectory = EgoTrajectoryCreator().computeTrajectory(measurement_content);

        if (hasToStop())
            return false;

        TrajectorySpliter().split(trajectory, measurement_content, trajectories, splitedMeasurementData);

        for (int i = 0; i < trajectories.size(); i++)
            countToProcess += trajectories[i].size();
    }

    if (countToProcess <= 0)
    {
        DefaultLogger << "Nothing to process !!!";
        return false;
    }

    OSMExternalSourceProvider osm_external_source_provider;
    ExternalSourceProviderVec external_source_providers;
    external_source_providers.push_back(&osm_external_source_provider);

    OSMToOpenDRIVE osmToOpenDRIVE;
    OpenDRIVEBuilder& builder = osmToOpenDRIVE;

    RoadFusor road_fusor;

    qint64 processedCount = 0;
    int i = -1;

    while (true)
    {
        QVector<VehiclePos> records;
        QVector<VehiclePos> measurementData;
        if (useBasicTables)
        {
            if (!PGDatabaseConnector_getDefaultInstance.getTrajectoryDataToProcessForXODR(lastProcessedTrajectoryCellsId, records))
            {
                DefaultLogger << "Error while getting trajectory records from pg-database !!!";
                return false;
            }

            measurementData = records;
        }
        else
        {
            if (++ i >= trajectories.size())
                break;

            records = trajectories[i];
            measurementData = splitedMeasurementData[i];
        }

        if (records.isEmpty())
            break;

        processTrajectory(useBasicTables, builder, records, measurementData, database_connector, external_source_providers, road_fusor);

        if (useBasicTables)
        {
            if (!PGDatabaseConnector_getDefaultInstance.updateXODRState_LastProcessedTrajectorySequentialCellsDataId(lastProcessedTrajectoryCellsId))
            {
                DefaultLogger << "Error while updating status_ocs !!!";
                return false;
            }

            processedCount += records.size();
        }
        else
        {
            processedCount += trajectories[i].size();
        }

        setProgress(processedCount * 100 / countToProcess);

        if (hasToStop())
            return false;
    }

    return false;
}



void XODRTablesUpdateThread::processTrajectory(bool useBasicTables
                                             , OpenDRIVEBuilder& builder
                                             , const VehiclePosVec& trajectory
                                             , const VehiclePosVec& splitedMeasurementData
                                             , DatabaseConnector& database_connector
                                             , ExternalSourceProviderVec& external_source_providers
                                             , RoadFusor& road_fusor)
{
    const VehiclePos& firstPt = trajectory[0];

    DefaultLogger << "Current OpenDRIVE : " << firstPt.getName();

    DefaultLogger << "Loading old content ============";

    //_NOD::OpenDRIVE old_content = database_connector.get(trajectory[0]);
    _NOD::OpenDRIVE old_content = PGDatabaseConnector_getDefaultInstance.getXODRContent(trajectory[0]);
    old_content.setParent();

    if (hasToStop())
        return;

    const QVector<_NOD::t_road>& old_roads = old_content.road_sequence;

    QVector<_NOSM::Way> allOSMWays;
    QVector<_NOD::t_road> new_roads = builder.buildRoads(useBasicTables, trajectory, splitedMeasurementData, database_connector, external_source_providers, allOSMWays);

    if (hasToStop())
        return;

    new_roads = road_fusor.fuse(old_roads, new_roads);

    if (hasToStop())
        return;

    DefaultLogger << "Updating new content ============";

    builder.updateOpenDRIVE(useBasicTables, trajectory, splitedMeasurementData, database_connector, external_source_providers, new_roads, allOSMWays);

    if (hasToStop())
        return;

    // TODO:???!!! Temporary code
    //database_connector.updateDBFromCache();

    if (hasToStop())
        return;

    DefaultLogger << "Updating neighbours ============";

    builder.updateJunctionLink(database_connector, firstPt);

    if (hasToStop())
        return;

    for (int i = 0; i < _NGC::DirectionCount; i ++)
    {
        builder.updateNeighbor(database_connector, firstPt, (CardinalDirection)i);

        if (hasToStop())
            return;
    }

    if (hasToStop())
        return;

    DefaultLogger << "Writing to database ============";

    //database_connector.updateDBFromCache();
}

}
