#pragma once

#include "OSM/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NOSM
{

class OSMNodeTablesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(OSMNodeTablesUpdateThread, *, )

protected:
    virtual bool onPreLoop();

};

#define OSMNodeTablesUpdateThread_createDefaultInstance                 _NOSM::OSMNodeTablesUpdateThread::createDefaultInstance()
#define OSMNodeTablesUpdateThread_getDefaultInstance                    _NOSM::OSMNodeTablesUpdateThread::getDefaultInstance()
#define OSMNodeTablesUpdateThread_deleteDefaultInstance                 _NOSM::OSMNodeTablesUpdateThread::deleteDefaultInstance()
#define OSMNodeTablesUpdateThread_isDefaultInstanceAlive                _NOSM::OSMNodeTablesUpdateThread::isDefaultInstanceAlive()
#define OSMNodeTablesUpdateThread_stopDefaultInstanceThreadIfAlive      _NOSM::OSMNodeTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
