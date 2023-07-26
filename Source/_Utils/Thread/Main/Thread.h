#pragma once

#include "Thread/Internal/Internal.h"
#include <QThread>
#include "Common/Main/DefaultInstance.h"

#define _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(type, retTypeSymbol, retParamSymbol) \
    _NCM_DEFAULT_INSTANCE_DECLARE(type, retTypeSymbol, retParamSymbol) \
public: \
    static void deleteDefaultInstance() \
    { \
        delete defaultInstance; \
        defaultInstance = 0; \
    } \
 \
    static void deleteDefaultInstanceIfAlive() \
    { \
        if (defaultInstance) \
            deleteDefaultInstance(); \
    } \
\
    static bool isDefaultInstanceAlive() \
    { \
        return defaultInstance != 0; \
    } \
\
    static void stopDefaultInstanceThread() \
    { \
        defaultInstance->stopThread(); \
    } \
\
    static void stopDefaultInstanceThreadIfAlive() \
    { \
        if (defaultInstance) \
            stopDefaultInstanceThread(); \
    }

namespace _NThread
{

class Thread : public QThread
{
    Q_OBJECT

protected:
    int miliSleepTime;
    bool forceStop;
    int progress;

public:
    Thread();
    virtual ~Thread();

public:
    virtual void restartThread();
    virtual void startThread();
    virtual void stopThread();

public:
    virtual bool hasToStop();
    virtual void clearStopFlag();
    virtual void setStopFlag();
    virtual int getMiliSleepTime();
    virtual int getProgress(){ return progress; }
    virtual void setProgress(int progress);

protected:
    virtual void onPreStartThread(){}
    virtual void onPreStopThread(){}

    virtual void run(){ onRun(); }
    virtual void onRun();
    virtual bool onPreLoop(){ return true; } // Go to loop if return TRUE
    virtual bool onLoopBody(){ return false; } // Continue loop if return TRUE
    virtual void onLoopSleep();
    virtual void onPostLoop(){}

signals:
    void postLoopFinished();
    void progressUpdated(int progress);

};

}
