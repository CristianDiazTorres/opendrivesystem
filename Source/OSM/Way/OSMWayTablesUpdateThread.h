#pragma once

#include "OSM/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NOSM
{

class OSMWayTablesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(OSMWayTablesUpdateThread, *, )

protected:
    virtual bool onPreLoop();

};

#define OSMWayTablesUpdateThread_createDefaultInstance                  _NOSM::OSMWayTablesUpdateThread::createDefaultInstance()
#define OSMWayTablesUpdateThread_getDefaultInstance                     _NOSM::OSMWayTablesUpdateThread::getDefaultInstance()
#define OSMWayTablesUpdateThread_deleteDefaultInstance                  _NOSM::OSMWayTablesUpdateThread::deleteDefaultInstance()
#define OSMWayTablesUpdateThread_isDefaultInstanceAlive                 _NOSM::OSMWayTablesUpdateThread::isDefaultInstanceAlive()
#define OSMWayTablesUpdateThread_stopDefaultInstanceThreadIfAlive       _NOSM::OSMWayTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
