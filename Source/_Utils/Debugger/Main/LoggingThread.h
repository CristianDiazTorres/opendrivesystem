#pragma once

#include "Debugger/Internal/Internal.h"
#include "Thread/Main/Thread.h"
#include <QMutex>
#include "Debugger/Main/LogInfo.h"

namespace _NDebug
{

class Logger;

class LoggingThread : public Thread
{
    friend class Logger;

    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(LoggingThread, &, *)

protected:
    bool loggingEnabled;
    QMutex mutex;
    QList<LogInfo> logInfos;

public:
    LoggingThread();

protected:
    void log(const LogInfo& logInfo);
    void processLog(const LogInfo& logInfo);

protected:
    virtual bool onLoopBody();
    virtual int getMiliSleepTime();

};

#define LoggingThread_createDefaultInstance                     _NDebug::LoggingThread::createDefaultInstance()
#define LoggingThread_getDefaultInstance                        _NDebug::LoggingThread::getDefaultInstance()
#define LoggingThread_deleteDefaultInstance                     _NDebug::LoggingThread::deleteDefaultInstance()
#define LoggingThread_isDefaultInstanceAlive                    _NDebug::LoggingThread::isDefaultInstanceAlive()
#define LoggingThread_stopDefaultInstanceThreadIfAlive          _NDebug::LoggingThread::stopDefaultInstanceThreadIfAlive()

}
