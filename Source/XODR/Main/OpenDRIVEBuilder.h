
#pragma once

#include "XODR/Main/MeasurementContent.h"
#include "DB/Main/DatabaseConnector.h"
#include "XODR/Main/ExternalSourceProvider.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"

namespace _NXODR
{

class OpenDRIVEBuilder
{
public:

    /**
     * @return QVector<_NOD::t_road>
     * @param trajectory
     * @param measurement_content
     */
    virtual QVector<_NOD::t_road> buildRoads(
            bool useBasicTables,
            const VehiclePosVec& trajectory,
            ConstMeasurementContent& measurement_content,
            DatabaseConnector& database_connector,
            ConstExternalSourceProviderVec& external_source_providers,
            QVector<_NOSM::Way>& allOSMWays) = 0;

    virtual void updateOpenDRIVE(
            bool useBasicTables,
            const VehiclePosVec& trajectory,
            ConstMeasurementContent& measurement_content,
            DatabaseConnector& database_connector,
            ConstExternalSourceProviderVec& external_source_providers,
            QVector<_NOD::t_road> &odRoads,
            QVector<_NOSM::Way>& allOSMWays) = 0;

public:
    void updateNeighbor(DatabaseConnector& databaseConnector,
                        const VehiclePos& pos,
                        CardinalDirection direction);
    void updateJunctionLink(DatabaseConnector& databaseConnector,
                            const LLCoordSysXYCell& pos);

};

}

