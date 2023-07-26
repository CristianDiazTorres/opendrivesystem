#include "GeoJSONApplyingThread.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "Debugger/Main/Logger.h"
#include <QFileInfo>
#include <QDir>

namespace _NGeoJSON
{

GeoJSONApplyingThread* GeoJSONApplyingThread::defaultInstance = 0;

void GeoJSONApplyingThread::setParams()
{
}

bool GeoJSONApplyingThread::onPreLoop()
{
    setProgress(0);

    if (hasToStop())
        return false;

    qint64 countToProcess;
    if (!PGDatabaseConnector_getDefaultInstance.getGeoJSONStagingNativeDataCountToProcessForApplying(countToProcess))
    {
        qDebug() << "getGeoJSONStagingNativeDataCountToProcessForApplying Error !!!";
        return false;
    }

    if (countToProcess == 0)
    {
        qDebug() << "countToProcess = 0";
        DefaultLogger << "Finished !!!";
        setProgress(100);
        return false;
    }

    QString lastProcessedId;
    if (!PGDatabaseConnector_getDefaultInstance.getGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(lastProcessedId))
    {
        qDebug() << "getGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId Error !!!";
        return false;
    }

    if (lastProcessedId.isEmpty())
        lastProcessedId = "0";

    qint64 processedCount = 0;

    while (true)
    {
        QVector<qint64> stagingNativeDataIds, fileIds;
        StringVec filePaths, jsons;

        if (!PGDatabaseConnector_getDefaultInstance.getGeoJSONStagingNativeData(lastProcessedId, stagingNativeDataIds, filePaths, fileIds, jsons))
        {
            qDebug() << "getGeoJSONStagingNativeData Error !!!";
            return false;
        }

        if (stagingNativeDataIds.isEmpty())
            break;

        for (int i = 0; i < stagingNativeDataIds.size(); i ++)
        {
            if (!processStagingData(stagingNativeDataIds[i], filePaths[i], fileIds[i], jsons[i]))
            {
                qDebug() << "processStagingData Error !!!";
                return false;
            }

            lastProcessedId = QString::number(stagingNativeDataIds[i]);

            if (!PGDatabaseConnector_getDefaultInstance.updateGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(lastProcessedId))
            {
                qDebug() << "updateGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId Error !!!";
                return false;
            }

            processedCount ++;

            setProgress(processedCount * 100 / countToProcess);
        }
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}


void getNearestContent(const LLCoordSysXYCell& point, const QString& tag, _NOD::OpenDRIVE& contentBefore, _NOD::OpenDRIVE& contentAfter, Cell& cell)
{
    QVector<_NOD::OpenDRIVE> contents(9);
    for (int i = 0; i < CardinalDirection::DirectionCount; i ++)
    {
        Cell neighbourCell;
        neighbourCell.setFromCoordDirection(point, (CardinalDirection)i);
        contents[i] = PGDatabaseConnector_getDefaultInstance.getXODRContent(neighbourCell);
        contents[i].setParent();
    }

    contents.last() = PGDatabaseConnector_getDefaultInstance.getXODRContent(point);
    contents.last().setParent();

    double minDist = 0;
    int index = _NMath::getNearestIndex(point, contents, tag, minDist);
    if (minDist > 20)
        index = contents.size() - 1;

    contentAfter = contentBefore = contents[index];
    cell = contentBefore.getCell();
}

void getNearestContent(const LLCoordSysXYCellVec& points, const QString& tag, _NOD::OpenDRIVE& contentBefore, _NOD::OpenDRIVE& contentAfter, Cell& cell)
{
    const LLCoordSysXYCell& firstPt = points.first();

    QVector<_NOD::OpenDRIVE> contents(9);
    for (int i = 0; i < CardinalDirection::DirectionCount; i ++)
    {
        Cell neighbourCell;
        neighbourCell.setFromCoordDirection(firstPt, (CardinalDirection)i);
        contents[i] = PGDatabaseConnector_getDefaultInstance.getXODRContent(neighbourCell);
        contents[i].setParent();
    }

    contents.last() = PGDatabaseConnector_getDefaultInstance.getXODRContent(firstPt);
    contents.last().setParent();

    double minDist = 0;
    int index = _NMath::getNearestIndex(points, contents, tag, minDist);
    if (minDist > 1)
        index = contents.size() - 1;

    contentAfter = contentBefore = contents[index];
    cell = contentBefore.getCell();
}

bool GeoJSONApplyingThread::processStagingData(qint64 stagingNativeDataId, QString filePath, qint64 fileId, QString json)
{
    QJsonObject jsonObj = QJsonDocument::fromJson(json.toUtf8()).object();
    QJsonObject geomObj = jsonObj["geometry"].toObject();
    QString geomType = geomObj["type"].toString().toLower();
    QJsonArray coordinates = geomObj["coordinates"].toArray();

    _NOD::_GeoJSONData geojsonData;
    geojsonData.propsObj = jsonObj["properties"].toObject();
    if (geojsonData.propsObj.contains("condition_properties"))
        geojsonData.condPropsObj = geojsonData.propsObj.take("condition_properties").toObject();
    geojsonData.geojsonVersion = geojsonData.propsObj.take("geojson_vesion").toString();
    geojsonData.updateST = geojsonData.propsObj.take("update_st").toBool();
    geojsonData.tag = geojsonData.propsObj.take("tag").toString();
    geojsonData.operCommand = geojsonData.propsObj.take("operation_command").toString();
    geojsonData.operType = geojsonData.propsObj.take("operation_type").toString();

    qDebug() << "tag : " << geojsonData.tag;

    if (geomType == "point")
    {
        geojsonData.isLine = false;
    }
    else if (geomType == "linestring")
    {
        geojsonData.isLine = true;
    }
    else
    {
        return true;
    }

    _NOD::OpenDRIVE contentBefore, contentAfter;
    Cell cell;

    if (geojsonData.isLine)
    {
        geojsonData.points.resize(coordinates.size());
        for (int i = 0; i < coordinates.size(); i ++)
            geojsonData.points[i].setFromLL(LL(coordinates[i].toArray()));
        geojsonData.point = geojsonData.points.first();

        getNearestContent(geojsonData.points, geojsonData.tag, contentBefore, contentAfter, cell);
    }
    else
    {
        geojsonData.point.setFromLL(LL(coordinates));
        getNearestContent(geojsonData.point, geojsonData.tag, contentBefore, contentAfter, cell);
    }

    qint64 histIdBefore = 0, histIdAfter = 0;
    PGDatabaseConnector_getDefaultInstance.getLatestXODRHistId(histIdBefore, cell.cellRow, cell.cellCol);

    QString operation;
    bool inserted = false;
    if (contentAfter.updateGeoJSONData(geojsonData, inserted))
    {
        operation = inserted ? "insert" : "update";
        PGDatabaseConnector_getDefaultInstance.updateXODRContent(cell, contentAfter);
    }
    else
    {
        operation = "none";
    }

    PGDatabaseConnector_getDefaultInstance.getLatestXODRHistId(histIdAfter, cell.cellRow, cell.cellCol);

    PGDatabaseConnector_getDefaultInstance.insertGeoJSONApplyingData(stagingNativeDataId
                                                         , filePath
                                                         , fileId
                                                         , geojsonData.tag
                                                         , json
                                                         , operation
                                                         , histIdBefore
                                                         , contentBefore.writeToJson()
                                                         , histIdAfter
                                                         , contentAfter.writeToJson());

    return true;
}

}
