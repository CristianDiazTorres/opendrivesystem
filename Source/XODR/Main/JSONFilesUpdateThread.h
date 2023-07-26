#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NXODR
{

class OpenDRIVEBuilder;
class ExternalSourceProvider;
typedef QVector<ExternalSourceProvider*>     ExternalSourceProviderVec;
class RoadFusor;

class JSONFilesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(JSONFilesUpdateThread, *, )

public:
    void setParams();

protected:
    virtual bool onPreLoop();

};

#define JSONFilesUpdateThread_createDefaultInstance                 _NXODR::JSONFilesUpdateThread::createDefaultInstance()
#define JSONFilesUpdateThread_getDefaultInstance                    _NXODR::JSONFilesUpdateThread::getDefaultInstance()
#define JSONFilesUpdateThread_deleteDefaultInstance                 _NXODR::JSONFilesUpdateThread::deleteDefaultInstance()
#define JSONFilesUpdateThread_isDefaultInstanceAlive                _NXODR::JSONFilesUpdateThread::isDefaultInstanceAlive()
#define JSONFilesUpdateThread_stopDefaultInstanceThreadIfAlive      _NXODR::JSONFilesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
