#pragma once

#include "Thread/Main/Thread.h"

namespace _NGPS
{

class GPSTablesUpdateThread : public _NThread::Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(GPSTablesUpdateThread, *, )

public:
    QString gpsFilePath;

public:
    void setParams(QString gpsFilePath);

protected:
    virtual bool onPreLoop();
};

#define GPSTablesUpdateThread_createDefaultInstance                 _NGPS::GPSTablesUpdateThread::createDefaultInstance()
#define GPSTablesUpdateThread_getDefaultInstance                    _NGPS::GPSTablesUpdateThread::getDefaultInstance()
#define GPSTablesUpdateThread_deleteDefaultInstance                 _NGPS::GPSTablesUpdateThread::deleteDefaultInstance()
#define GPSTablesUpdateThread_isDefaultInstanceAlive                _NGPS::GPSTablesUpdateThread::isDefaultInstanceAlive()
#define GPSTablesUpdateThread_stopDefaultInstanceThreadIfAlive      _NGPS::GPSTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
