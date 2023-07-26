#pragma once

#include "Thread/Main/Thread.h"

namespace _NTrajectory
{

class TrajectoryTablesUpdateThread : public _NThread::Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(TrajectoryTablesUpdateThread, *, )

public:
    void setParams();

protected:
    virtual bool onPreLoop();
};

#define TrajectoryTablesUpdateThread_createDefaultInstance                  _NTrajectory::TrajectoryTablesUpdateThread::createDefaultInstance()
#define TrajectoryTablesUpdateThread_getDefaultInstance                     _NTrajectory::TrajectoryTablesUpdateThread::getDefaultInstance()
#define TrajectoryTablesUpdateThread_deleteDefaultInstance                  _NTrajectory::TrajectoryTablesUpdateThread::deleteDefaultInstance()
#define TrajectoryTablesUpdateThread_isDefaultInstanceAlive                 _NTrajectory::TrajectoryTablesUpdateThread::isDefaultInstanceAlive()
#define TrajectoryTablesUpdateThread_stopDefaultInstanceThreadIfAlive       _NTrajectory::TrajectoryTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
