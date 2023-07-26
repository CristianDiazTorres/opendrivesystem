#pragma once

#include "XODR/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NXODR
{

class OpenDRIVEBuilder;
class ExternalSourceProvider;
typedef QVector<ExternalSourceProvider*>     ExternalSourceProviderVec;
class RoadFusor;

class XODRFilesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(XODRFilesUpdateThread, *, )

public:
    void setParams();

protected:
    virtual bool onPreLoop();

};

#define XODRFilesUpdateThread_createDefaultInstance                 _NXODR::XODRFilesUpdateThread::createDefaultInstance()
#define XODRFilesUpdateThread_getDefaultInstance                    _NXODR::XODRFilesUpdateThread::getDefaultInstance()
#define XODRFilesUpdateThread_deleteDefaultInstance                 _NXODR::XODRFilesUpdateThread::deleteDefaultInstance()
#define XODRFilesUpdateThread_isDefaultInstanceAlive                _NXODR::XODRFilesUpdateThread::isDefaultInstanceAlive()
#define XODRFilesUpdateThread_stopDefaultInstanceThreadIfAlive      _NXODR::XODRFilesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
