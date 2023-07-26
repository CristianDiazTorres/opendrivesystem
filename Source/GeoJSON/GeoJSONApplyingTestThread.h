#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NGeoJSON
{

class OpenDRIVEBuilder;
class ExternalSourceProvider;
typedef QVector<ExternalSourceProvider*>     ExternalSourceProviderVec;
class RoadFusor;

class GeoJSONApplyingTestThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(GeoJSONApplyingTestThread, *, )

public:
    void setParams();

protected:
    virtual bool onPreLoop();

};

#define GeoJSONApplyingTestThread_createDefaultInstance                 _NGeoJSON::GeoJSONApplyingTestThread::createDefaultInstance()
#define GeoJSONApplyingTestThread_getDefaultInstance                    _NGeoJSON::GeoJSONApplyingTestThread::getDefaultInstance()
#define GeoJSONApplyingTestThread_deleteDefaultInstance                 _NGeoJSON::GeoJSONApplyingTestThread::deleteDefaultInstance()
#define GeoJSONApplyingTestThread_isDefaultInstanceAlive                _NGeoJSON::GeoJSONApplyingTestThread::isDefaultInstanceAlive()
#define GeoJSONApplyingTestThread_stopDefaultInstanceThreadIfAlive      _NGeoJSON::GeoJSONApplyingTestThread::stopDefaultInstanceThreadIfAlive()

}
