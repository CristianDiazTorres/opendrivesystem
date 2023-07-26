#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"
#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

namespace _NGeoJSON
{

class GeoJSONApplyingThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(GeoJSONApplyingThread, *, )

public:
    void setParams();

protected:
    virtual bool onPreLoop();
    bool processStagingData(qint64 stagingNativeDataId, QString filePath, qint64 fileId, QString json);

};

#define GeoJSONApplyingThread_createDefaultInstance                 _NGeoJSON::GeoJSONApplyingThread::createDefaultInstance()
#define GeoJSONApplyingThread_getDefaultInstance                    _NGeoJSON::GeoJSONApplyingThread::getDefaultInstance()
#define GeoJSONApplyingThread_deleteDefaultInstance                 _NGeoJSON::GeoJSONApplyingThread::deleteDefaultInstance()
#define GeoJSONApplyingThread_isDefaultInstanceAlive                _NGeoJSON::GeoJSONApplyingThread::isDefaultInstanceAlive()
#define GeoJSONApplyingThread_stopDefaultInstanceThreadIfAlive      _NGeoJSON::GeoJSONApplyingThread::stopDefaultInstanceThreadIfAlive()

}
