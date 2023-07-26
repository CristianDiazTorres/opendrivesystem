#include "CurvatureSlopeTablesUpdateThread.h"
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "Common/Main/StringContants.h"
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"
#include "DB/Main/LocalFilesDatabaseConnector.h"

/*
for (int i = 0; i < result.size(); i ++)
{
    result[i].updateDerivedProps();
    if (i != 0)
        result[i].updateAccelFromPrev(result[i - 1]);
}

if (result.size() > 1)
    result.front().updateAccelFromNext(result[1]);
*/

namespace _NCurvatureSlope
{

CurvatureSlopeTablesUpdateThread* CurvatureSlopeTablesUpdateThread::defaultInstance = 0;

void CurvatureSlopeTablesUpdateThread::setParams(QString curvatureSlopeDataPath)
{
    this->curvatureSlopeDataPath = curvatureSlopeDataPath;
}

// @incomplete
bool CurvatureSlopeTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    DefaultLogger << "========== Reading data from json files ==========";

    QDir dir(curvatureSlopeDataPath);
    QStringList filters; filters << "*.json";
    QVector<QFileInfo> files = dir.entryInfoList(filters).toVector();

    LocalFilesDatabaseConnector local_files_database_connector;

    for (int i = 0; i < files.size(); i ++)
    {
        //qDebug() << files[i].filePath();
        QFile file(files[i].filePath());
        file.open(QIODevice::ReadOnly);

        QByteArray data = file.readAll();
        //qDebug() << data.size();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        //qDebug() << doc.isArray();
        //qDebug() << doc.isObject();
        QJsonObject root = doc.object();
        double lat = root["GPS_SWIFT"].toObject()["Latitude"].toDouble();
        double lon = root["GPS_SWIFT"].toObject()["Longitude"].toDouble();
        double curvature = 1 / root["Road_Curvature"].toObject()["Radius"].toDouble();
        double verticalSlope = root["Slope"].toObject()["Slope_Vertical"].toDouble();

        LLCoordSysXYCell pos;
        pos.setFromLL(LL(lat, lon));
        _NOD::OpenDRIVE odContent = local_files_database_connector.getXODRContent(pos);
        odContent.setParent();
        odContent.setCurvatureSlope(pos, curvature, verticalSlope);
        local_files_database_connector.updateXODRContent(pos, odContent);

        setProgress(100 * (i + 1) / files.size());
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
