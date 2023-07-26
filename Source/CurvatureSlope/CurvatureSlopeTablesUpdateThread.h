#pragma once

#include "Thread/Main/Thread.h"

namespace _NCurvatureSlope
{

class CurvatureSlopeTablesUpdateThread : public _NThread::Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(CurvatureSlopeTablesUpdateThread, *, )

public:
    QString curvatureSlopeDataPath;

public:
    void setParams(QString curvatureSlopeDataPath);

protected:
    virtual bool onPreLoop();
};

#define CurvatureSlopeTablesUpdateThread_createDefaultInstance                  _NCurvatureSlope::CurvatureSlopeTablesUpdateThread::createDefaultInstance()
#define CurvatureSlopeTablesUpdateThread_getDefaultInstance                     _NCurvatureSlope::CurvatureSlopeTablesUpdateThread::getDefaultInstance()
#define CurvatureSlopeTablesUpdateThread_deleteDefaultInstance                  _NCurvatureSlope::CurvatureSlopeTablesUpdateThread::deleteDefaultInstance()
#define CurvatureSlopeTablesUpdateThread_isDefaultInstanceAlive                 _NCurvatureSlope::CurvatureSlopeTablesUpdateThread::isDefaultInstanceAlive()
#define CurvatureSlopeTablesUpdateThread_stopDefaultInstanceThreadIfAlive       _NCurvatureSlope::CurvatureSlopeTablesUpdateThread::stopDefaultInstanceThreadIfAlive()

}
