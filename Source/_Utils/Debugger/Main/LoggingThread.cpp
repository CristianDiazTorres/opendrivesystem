#include "LoggingThread.h"
#include "Logger.h"
#include "LoggingSlotManager.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>

namespace _NDebug
{

static QFile s_logFile;

LoggingThread* LoggingThread::defaultInstance = 0;

LoggingThread::LoggingThread()
    : loggingEnabled(false)
{
}

void LoggingThread::log(const LogInfo& logInfo)
{
    //qDebug() << "LoggingThread::log before lock";
    mutex.lock();
    //qDebug() << "LoggingThread::log after lock";

    logInfos << logInfo;

    //qDebug() << "LoggingThread::log before unlock";
    mutex.unlock();
    //qDebug() << "LoggingThread::log after unlock";
}

void LoggingThread::processLog(const LogInfo &logInfo)
{
    if (logInfo.loggingTarget & LD_QDebug)
         qDebug() << logInfo.fullMessage;

    if (logInfo.loggingTarget & LD_File)
    {
        if (!s_logFile.isOpen())
        {
            QString path = UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath() + "/Log";
            QDir().mkpath(path);
            s_logFile.setFileName(path + "/Global.log");
            s_logFile.open(QIODevice::Append);
            s_logFile.seek(s_logFile.size());
        }

        s_logFile.write(logInfo.fullMessage.toUtf8());
        s_logFile.write("\r\n");
        s_logFile.flush();
    }

    if (logInfo.loggingTarget & LD_Slot)
    {
        QVector<LoggingSlotManager::LoggingSlot> loggingSlots = LoggingSlotManager_getDefaultInstance.getSlots();

        for (const LoggingSlotManager::LoggingSlot& loggingSlot : loggingSlots)
        {
            if ((loggingSlot.loggerThread == Logger::ALL_THREADS || loggingSlot.loggerThread == logInfo.thread)
                && (loggingSlot.loggerId == Logger::ALL_IDS || loggingSlot.loggerId == logInfo.loggerId))
            {
                QMetaObject::invokeMethod(loggingSlot.loggingReceiver
                                          , loggingSlot.slotMethodName
                                          , Q_ARG(_NDebug::LogInfo, logInfo));
            }
        }
    }

    if (logInfo.loggingTarget & LD_PGDB)
    {
        PGDatabaseConnector_getDefaultInstance.insertGlobalLog(logInfo);
    }
}

bool LoggingThread::onLoopBody()
{
    if (!loggingEnabled)
        return true;

    QList<LogInfo> copiedLogInfos;

    //qDebug() << "LoggingThread::onLoopBody before lock";
    mutex.lock();
    //qDebug() << "LoggingThread::onLoopBody after lock";

    for (int i = qMin(logInfos.size(), 20) - 1; i >= 0; i --)
        copiedLogInfos << logInfos.takeFirst();

    //qDebug() << "LoggingThread::onLoopBody before unlock";
    mutex.unlock();
    //qDebug() << "LoggingThread::onLoopBody after unlock";

    for (const LogInfo& logInfo : copiedLogInfos)
    {
        if (!hasToStop())
            processLog(logInfo);
    }

    return true;
}

int LoggingThread::getMiliSleepTime()
{
    QString timeStr = UserSettingsOnPGDatabase_getDefaultInstance.getLoggingMiliSleepTime();
    if (timeStr.isEmpty())
        return (miliSleepTime = 100);

    return (miliSleepTime = timeStr.toInt());
}

}
