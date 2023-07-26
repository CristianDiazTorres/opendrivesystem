#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NXODR
{

class OpenDRIVEBuilder;
class ExternalSourceProvider;
typedef QVector<ExternalSourceProvider*>     ExternalSourceProviderVec;
class RoadFusor;

class XODRTablesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(XODRTablesUpdateThread, *, )

public:
    bool useBasicTables;
    QString gpsFilePath;

public:
    void setParams(bool useBasicTables, QString gpsFilePath = "");

protected:
    virtual bool onPreLoop();
    void processTrajectory(bool useBasicTables
                           , OpenDRIVEBuilder& builder
                           , const VehiclePosVec& trajectory
                           , const VehiclePosVec& splitedMeasurementData
                           , DatabaseConnector& database_connector
                           , ExternalSourceProviderVec& external_source_providers
                           , RoadFusor& road_fusor);
};

#define XODRTablesUpdateThread_createDefaultInstance                _NXODR::XODRTablesUpdateThread::createDefaultInstance()
#define XODRTablesUpdateThread_getDefaultInstance                   _NXODR::XODRTablesUpdateThread::getDefaultInstance()
#define XODRTablesUpdateThread_deleteDefaultInstance                _NXODR::XODRTablesUpdateThread::deleteDefaultInstance()
#define XODRTablesUpdateThread_isDefaultInstanceAlive               _NXODR::XODRTablesUpdateThread::isDefaultInstanceAlive()
#define XODRTablesUpdateThread_stopDefaultInstanceThreadIfAlive     _NXODR::XODRTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
