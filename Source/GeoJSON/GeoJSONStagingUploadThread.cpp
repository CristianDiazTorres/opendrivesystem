#include "GeoJSONStagingUploadThread.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "Debugger/Main/Logger.h"
#include <QFileInfo>
#include <QDir>

namespace _NGeoJSON
{

GeoJSONStagingUploadThread* GeoJSONStagingUploadThread::defaultInstance = 0;

void GeoJSONStagingUploadThread::setParams(QStringList paths)
{
    this->paths = paths;
}

bool GeoJSONStagingUploadThread::onPreLoop()
{
    setProgress(0);

    if (hasToStop())
        return false;

    QVector<QFileInfo> files;
    for (QString path : paths)
    {
        QFileInfo pathInfo(path);
        if (!pathInfo.exists())
            continue;

        if (pathInfo.isDir())
        {
            QStringList filters;
            filters << "*.geojson";
            files.append(QDir(path).entryInfoList(filters, QDir::Files).toVector());
        }
        else if (pathInfo.isFile())
        {
            files << pathInfo;
        }
        else
        {
            continue;
        }
    }

    qDebug() << "files.size(): " << files.size();
    for (int i = 0; i < files.size(); i ++)
    {
        QFileInfo& fi = files[i];
        QString filePath = fi.absoluteFilePath();

        if (!processGeoJSONStagingFile(filePath))
        {
            qDebug() << "processGeoJSONStagingFile Error !!!";
            return false;
        }

        setProgress((i + 1) * 100 / files.size());

        if (hasToStop())
            return false;
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

bool GeoJSONStagingUploadThread::processGeoJSONStagingFile(QString geoJSONStagingFilePath)
{
    qint64 geoJSONStagingFileId = 0;

    if (!PGDatabaseConnector_getDefaultInstance.insertGeoJSONStagingFileData(geoJSONStagingFilePath, geoJSONStagingFileId))
    {
        qDebug() << "insertGeoJSONStagingFileData Error !!!";
        return false;
    }

    QFile file(geoJSONStagingFilePath);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonArray features = QJsonDocument::fromJson(data).object()["features"].toArray();
    for (int i = 0; i < features.size(); i ++)
    {
        QJsonObject feature = features[i].toObject();

        QJsonObject geomObj = feature["geometry"].toObject();
        QString type = geomObj["type"].toString().toLower();
        QJsonArray coordinates = geomObj["coordinates"].toArray();

        QJsonObject properties = feature["properties"].toObject();
        QString tag = properties.take("tag").toString();

        QString geomString;
        if (type == "point")
        {
            geomString = "POINT("
                    + _NCM::doubleToStringFullPrecision(coordinates[0].toDouble())
                    + " "
                    + _NCM::doubleToStringFullPrecision(coordinates[1].toDouble())
                    + ")";
        }
        else if (type == "linestring")
        {
            geomString = "LINESTRING(";
            for (int j = 0; j < coordinates.size(); j ++)
            {
                if (j != 0)
                    geomString += ",";

                QJsonArray point = coordinates[j].toArray();
                geomString += _NCM::doubleToStringFullPrecision(point[0].toDouble())
                        + " "
                        + _NCM::doubleToStringFullPrecision(point[1].toDouble());
            }
            geomString += ")";
        }
        else
        {
            continue;
        }

        QString jsonStr = QJsonDocument(feature).toJson();

        if (!PGDatabaseConnector_getDefaultInstance.insertGeoJSONStagingNativeData(geoJSONStagingFilePath, geoJSONStagingFileId, geomString, tag, jsonStr))
        {
            qDebug() << "insertGeoJSONStagingNativeData Error !!!";
            return false;
        }
    }

    return true;
}

}
