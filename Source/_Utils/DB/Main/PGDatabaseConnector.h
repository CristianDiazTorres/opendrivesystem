#pragma once

#include "DB/Internal/Internal.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMutex>
#include "DB/Main/DatabaseConnector.h"
#include "Debugger/Main/LogInfo.h"
#include "GPS/NativeGPSData.h"
#include "Common/Main/DefaultInstance.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"

namespace _NDB
{

#define STR_TO_SQL(str)                             (str.isEmpty() ? " NULL " : " '" + _NCM::preProcessStringForPG(str) + "' ")
#define STR_TO_SQL_WITH_COMMA(str)                  (str.isEmpty() ? " , NULL " : " , '" + _NCM::preProcessStringForPG(str) + "' ")
#define NUM_TO_SQL(num)                             " '" + QString::number(num) + "' "
#define NUM_TO_SQL_WITH_COMMA(num)                  " , '" + QString::number(num) + "' "
#define DBL_TO_SQL(num)                             " '" + _NCM::doubleToStringFullPrecision(num) + "' "
#define DBL_TO_SQL_WITH_COMMA(num)                  " , '" + _NCM::doubleToStringFullPrecision(num) + "' "
#define JSON_TO_SQL(jsonObject, attr)               ((!jsonObject.contains(attr) || jsonObject[attr].toString().isEmpty()) ? " NULL " : " '" + _NCM::preProcessStringForPG(jsonObject[attr].toString()) + "' ")
#define JSON_TO_SQL_WITH_COMMA(jsonObject, attr)    ((!jsonObject.contains(attr) || jsonObject[attr].toString().isEmpty()) ? " , NULL " : " , '" + _NCM::preProcessStringForPG(jsonObject[attr].toString()) + "' ")

class PGDatabaseConnector : public DatabaseConnector
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_DECLARE(PGDatabaseConnector, &, *)

protected:
    struct DatabaseInfo
    {
        QSqlDatabase db;
        bool hasToReconnect;
    };

protected:
    QMutex mutex;
    QMap<QThread*, DatabaseInfo> databasesInfos;

public:
    bool reconnect();

protected:
    inline QSqlDatabase& getCurrentDB();
    inline DatabaseInfo& getCurrentDBInfo();

public slots:
    void onThreadFinished();

protected:
    inline QSqlQuery execQuery(const QString& queryString, _NDebug::LoggingTarget loggingTarget = _NDebug::LD_QDebug_File);
    inline bool isDBOpen();
    inline bool execQueryToAffectOneRow(const QString &queryString, _NDebug::LoggingTarget loggingTarget = _NDebug::LD_QDebug_File);

    template <typename T>
    inline bool getResult_R1C1(const QString& queryString, T& result, _NDebug::LoggingTarget loggingTarget = _NDebug::LD_QDebug_File);

    template <typename T1, typename T2>
    inline bool getResult_R1C2(const QString& queryString, T1& c1Result, T2& c2Result);

    template <typename T1, typename T2, typename T3>
    inline bool getResult_R1C3(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result);

    template <typename T1, typename T2, typename T3, typename T4>
    inline bool getResult_R1C4(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result);

    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    inline bool getResult_R1C5(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result);

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    inline bool getResult_R1C6(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result);

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    inline bool getResult_R1C7(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result, T7& c7Result);

    template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    inline bool getResult_R1C8(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result, T7& c7Result, T8& c8Result);

    template <typename T1, typename T2>
    inline bool getResult_C2(const QString& queryString, QVector<T1>& c1Results, QVector<T2>& c2Results);

public:
    /**********************************************************************/
    /* Logs */
    bool clearLogs();
    bool insertLog(const QString& tableName, const _NDebug::LogInfo& logInfo);
    bool insertGlobalLog(const _NDebug::LogInfo& logInfo);

    /**********************************************************************/
    /* Settings */
    bool clearSettings();

    bool updateSetting(const QString& tableName, const QString& key, const QString& value);
    bool getSettings(const QString& tableName, StringVec& keys, StringVec& vals);
    virtual int getNewID(QString key = _SC_id);

    /**********************************************************************/
    /* Data (& Status) */
    bool clearData();

    bool updateState(const QString& tableName, const QString& key, const QString& value);
    bool getState(const QString& tableName, const QString& key, QString& value);

    /**********************************************************************/
    /* OSM Country Area */
    bool insertOSMCountryAreaLog(const _NDebug::LogInfo& logInfo);

    bool clearOSMCountryArea();
    bool clearOSMCountryAreaAndDependencies();

    bool updateOSMCountryAreaDataAndHist(const StringVec &countries
                               , const StringVec &jsons
                               , const StringVec &areas);
    bool getOSMCountryAreaData_NameAsISO3166_1(double lat, double lon, QString& name);

    /**********************************************************************/
    /* GPS */
    bool insertGPSLog(const _NDebug::LogInfo& logInfo);

    bool updateGPSState(const QString& key, const QString& value);
    bool getGPSState(const QString& key, QString& value);

    bool clearGPS();
    bool clearGPSAndDependencies();

    bool insertGPSFileData(const QString& gpsFilePath, qint64& tableId);
    bool insertGPSNativeData(QString gpsFilePath, qint64 gpsFileId, const _NGPS::NativeGPSData& gpsData);
    bool insertGPSValidData(QString gpsFilePath, qint64 gpsFileId, const _NGPS::NativeGPSData& gpsData);

    bool getGPSValidDataCountToProcessForTrajectory(qint64& countToProcess);
    bool getGPSValidDataToProcessForTrajectory(const QString& lastProcessedGPSId, QVector<VehiclePos>& gpsRecords);

    bool getGPSCellsDataCountToProcessForOSMWay(qint64& countToProcess);
    bool getGPSCellsDataToProcessForOSMWay(const QString& lastProcessedCellsId, QVector<qint64>& cellsIds, QVector<Cell>& cells);

    bool getGPSCellsDataCountToProcessForOSMNode(qint64& countToProcess);
    bool getGPSCellsDataToProcessForOSMNode(const QString& lastProcessedCellsId, QVector<qint64>& cellsIds, QVector<Cell>& cells);

    /**********************************************************************/
    /* Trajectory */
    bool insertTrajectoryLog(const _NDebug::LogInfo& logInfo);

    bool updateTrajectoryState(const QString& key, const QString& value);
    bool getTrajectoryState(const QString& key, QString& value);

    bool updateTrajectoryState_LastProcessedGPSValidDataId(const QString& id);
    bool getTrajectoryState_LastProcessedGPSValidDataId(QString& id);

    bool clearTrajectory();
    bool clearTrajectoryAndDependencies();

    bool insertTrajectoryData(const VehiclePos& pos);

    bool getTrajectoryDataCountToProcessForXODR(qint64& countToProcess);
    bool getTrajectoryDataToProcessForXODR(QString& lastProcessedTrajectoryCellsId, QVector<VehiclePos>& trajectoryRecords);

    /**********************************************************************/
    /* OSM Way */
    bool insertOSMWayLog(const _NDebug::LogInfo& logInfo);

    bool updateOSMWayState(const QString& key, const QString& value);
    bool getOSMWayState(const QString& key, QString& value);

    bool updateOSMWayState_LastProcessedGPSCellsDataId(const QString& id);
    bool getOSMWayState_LastProcessedGPSCellsDataId(QString& id);

    bool clearOSMWay();
    bool clearOSMWayAndDependencies();

    bool updateOSMWayDataAndHist(const QString &osmId, QString json, const QString &geom, QJsonObject tags);

    bool getOSMWayDataOnCell(Cell cell, StringVec& jsons);

    /**********************************************************************/
    /* OSM Node */
    bool insertOSMNodeLog(const _NDebug::LogInfo& logInfo);

    bool updateOSMNodeState(const QString& key, const QString& value);
    bool getOSMNodeState(const QString& key, QString& value);

    bool updateOSMNodeState_LastProcessedGPSCellsDataId(const QString& id);
    bool getOSMNodeState_LastProcessedGPSCellsDataId(QString& id);

    bool clearOSMNode();
    bool clearOSMNodeAndDependencies();

    bool updateOSMNodeDataAndHist(const QString &osmId, QString json, const QString &geom, QJsonObject tags);

    bool getOSMNodeDataOnCell(Cell cell, StringVec& jsons);

    /**********************************************************************/
    /* GeoJSON Staging */
    bool insertGeoJSONStagingLog(const _NDebug::LogInfo& logInfo);

    bool updateGeoJSONStagingState(const QString& key, const QString& value);
    bool getGeoJSONStagingState(const QString& key, QString& value);

    bool clearGeoJSONStaging();
    bool clearGeoJSONStagingAndDependencies();

    bool insertGeoJSONStagingFileData(const QString& geoJSONStagingFilePath, qint64& tableId);
    bool insertGeoJSONStagingNativeData(QString geoJSONStagingFilePath, qint64 geoJSONStagingFileId, QString geom, QString tag, QString json);

    bool getGeoJSONStagingNativeDataCountToProcessForApplying(qint64& countToProcess);
    bool getGeoJSONStagingNativeData(const QString& lastProcessedGeoJSONStagingNativeDataId
                                     , QVector<qint64>& ids
                                     , StringVec& filePaths
                                     , QVector<qint64>& fileIds
                                     , StringVec& jsons);

    /**********************************************************************/
    /* GeoJSON Applying */
    bool insertGeoJSONApplyingLog(const _NDebug::LogInfo& logInfo);

    bool updateGeoJSONApplyingState(const QString& key, const QString& value);
    bool getGeoJSONApplyingState(const QString& key, QString& value);

    bool updateGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(const QString& id);
    bool getGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(QString& id);

    bool clearGeoJSONApplying();
    bool clearGeoJSONApplyingAndDependencies();

    bool insertGeoJSONApplyingData(qint64 nativeDataId
                                   , QString filePath
                                   , qint64 fileId
                                   , QString tag
                                   , QString json
                                   , QString operation
                                   , qint64 histIdBefore
                                   , QString contentBefore
                                   , qint64 histIdAfter
                                   , QString contentAfter);

    bool getGeoJSONApplyingRecordCount(qint64& countToProcess, const QString& latestGeoJSONApplyingRecordUpdatedTime);
    bool getGeoJSONApplyingRecord(const QString& prevGeoJSONApplyingRecordUpdatedTime
                                  , QString& curGeoJSONApplyingRecordUpdatedTime
                                  , qint64& id
                                  , QString& geoJSONStagingFilePath
                                  , QString& tag
                                  , QString& json
                                  , QString& operation
                                  , QString& contentBefore
                                  , QString& contentAfter);

    /**********************************************************************/
    /* XODR */
    bool insertXODRLog(const _NDebug::LogInfo& logInfo);

    bool updateXODRState(const QString& key, const QString& value);
    bool getXODRState(const QString& key, QString& value);

    bool updateXODRState_LastProcessedTrajectorySequentialCellsDataId(const QString& id);
    bool getXODRState_LastProcessedTrajectorySequentialCellsDataId(QString& id);

    bool clearXODR();
    bool updateXODRDataAndHist(int cellRow, int cellCol, QString json);
    bool updateXODRContent(const Cell& cell, _NOD::OpenDRIVE& odContent);
    bool getXODRData(int cellRow, int cellCol, QString& json);
    _NOD::OpenDRIVE getXODRContent(const Cell& cell);
    bool getXODRRecordCount(qint64& count, const QString& latestXODRRecordUpdatedTime);
    bool getXODRCellInfo(const QString& prevXODRRecordUpdatedTime, QString& curXODRRecordUpdatedTime, int& cellRow, int& cellCol);
    bool getLatestXODRHistId(qint64& id, int cellRow, int cellCol);

};

#define PGDatabaseConnector_createDefaultInstance   _NDB::PGDatabaseConnector::createDefaultInstance()
#define PGDatabaseConnector_getDefaultInstance      _NDB::PGDatabaseConnector::getDefaultInstance()

}

#include "PGDatabaseConnector.inl"
