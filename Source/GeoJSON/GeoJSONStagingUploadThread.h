#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NGeoJSON
{

class GeoJSONStagingUploadThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(GeoJSONStagingUploadThread, *, )

protected:
    QStringList paths;

public:
    void setParams(QStringList paths);

protected:
    virtual bool onPreLoop();
    bool processGeoJSONStagingFile(QString geoJSONStagingFilePath);
};

#define GeoJSONStagingUploadThread_createDefaultInstance                _NGeoJSON::GeoJSONStagingUploadThread::createDefaultInstance()
#define GeoJSONStagingUploadThread_getDefaultInstance                   _NGeoJSON::GeoJSONStagingUploadThread::getDefaultInstance()
#define GeoJSONStagingUploadThread_deleteDefaultInstance                _NGeoJSON::GeoJSONStagingUploadThread::deleteDefaultInstance()
#define GeoJSONStagingUploadThread_isDefaultInstanceAlive               _NGeoJSON::GeoJSONStagingUploadThread::isDefaultInstanceAlive()
#define GeoJSONStagingUploadThread_stopDefaultInstanceThreadIfAlive     _NGeoJSON::GeoJSONStagingUploadThread::stopDefaultInstanceThreadIfAlive()

}
