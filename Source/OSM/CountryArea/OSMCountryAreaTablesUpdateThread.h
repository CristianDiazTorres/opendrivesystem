#pragma once

#include "OSM/Internal/Internal.h"
#include "Thread/Main/Thread.h"

namespace _NOSM
{

class OSMCountryAreaTablesUpdateThread : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(OSMCountryAreaTablesUpdateThread, *, )

protected:
    virtual bool onPreLoop();

};

#define OSMCountryAreaTablesUpdateThread_createDefaultInstance                  _NOSM::OSMCountryAreaTablesUpdateThread::createDefaultInstance()
#define OSMCountryAreaTablesUpdateThread_getDefaultInstance                     _NOSM::OSMCountryAreaTablesUpdateThread::getDefaultInstance()
#define OSMCountryAreaTablesUpdateThread_deleteDefaultInstance                  _NOSM::OSMCountryAreaTablesUpdateThread::deleteDefaultInstance()
#define OSMCountryAreaTablesUpdateThread_isDefaultInstanceAlive                 _NOSM::OSMCountryAreaTablesUpdateThread::isDefaultInstanceAlive()
#define OSMCountryAreaTablesUpdateThread_stopDefaultInstanceThreadIfAlive       _NOSM::OSMCountryAreaTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
