#include "Thread.h"
#include "Debugger/Main/Logger.h"

namespace _NThread
{

Thread::Thread()
{
    progress = 0;
}

Thread::~Thread()
{
    stopThread();
}

void Thread::restartThread()
{
    stopThread();

    startThread();
}

void Thread::startThread()
{
    onPreStartThread();

    clearStopFlag();

    start();
}

void Thread::stopThread()
{
    onPreStopThread();

    setStopFlag();

    wait();
}

bool Thread::hasToStop()
{
    return forceStop;
}

void Thread::clearStopFlag()
{
    forceStop = false;
}

void Thread::setStopFlag()
{
    forceStop = true;
}

int Thread::getMiliSleepTime()
{
    return miliSleepTime;
}

void Thread::setProgress(int progress)
{
    this->progress = progress;
    emit progressUpdated(progress);
}

void Thread::onRun()
{
    DefaultLogger_NotPGDB << "Before onPreLoop";

    if (onPreLoop())
    {
        DefaultLogger_NotPGDB << "Before Loop";

        while (!hasToStop())
        {
            if (!onLoopBody())
                break;

            onLoopSleep();
        }
    }

    DefaultLogger_NotPGDB << "Before onPostLoop";

    onPostLoop();

    DefaultLogger_NotPGDB << "Before emit postLoopFinished()";

    emit postLoopFinished();
}

void Thread::onLoopSleep()
{
    int miliSleepTime = getMiliSleepTime();
    if (miliSleepTime > 0)
        msleep(miliSleepTime);
}

}
