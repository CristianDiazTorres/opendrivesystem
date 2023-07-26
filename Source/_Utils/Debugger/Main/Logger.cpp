#include "Logger.h"
#include <QThread>
#include <QDateTime>
#include "Common/Main/String.h"
#include "Common/Main/DateTime.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include "LoggingThread.h"
#include "LoggingSlotManager.h"

namespace _NDebug
{

QThread* Logger::ALL_THREADS = (QThread*)0x09999999;
QString Logger::ALL_IDS = "ALL_IDS";

Logger::Logger(LoggingTarget loggingTarget, const QString& id)
{
    logInfo.loggingTarget = loggingTarget;
    logInfo.thread = QThread::currentThread();
    logInfo.loggerId = id;
}

Logger::~Logger()
{
    logInfo.dateTime = _NCM::getCurrentDateTimeAsPGTimeStampWithTimeZone();
    logInfo.threadId = QString::number((qulonglong)QThread::currentThreadId());

    logInfo.fullMessage += "[DateTime] = " + logInfo.dateTime;
    logInfo.fullMessage += "    [AppUser] = " + DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser();
    logInfo.fullMessage += "    [Thread] = " + logInfo.threadId;
    if (logInfo.loggerId.isEmpty())
        logInfo.fullMessage += "    [LoggerID] = NONE";
    else
        logInfo.fullMessage += "    [LoggerID] = " + logInfo.loggerId;
    logInfo.fullMessage += "    [Message] =" + logInfo.content;

    qDebug() << logInfo.fullMessage;
    //LoggingThread_getDefaultInstance.log(logInfo);
}

void Logger::init()
{
    LoggingSlotManager_createDefaultInstance;
    LoggingThread_createDefaultInstance;
}

void Logger::setLoggingEnabled(bool enable)
{
    LoggingThread_getDefaultInstance.loggingEnabled = enable;
}

void Logger::startLogging()
{
    LoggingThread_getDefaultInstance.startThread();
}

void Logger::stopLogging()
{
    LoggingThread_stopDefaultInstanceThreadIfAlive;
}

void Logger::addSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName)
{
    LoggingSlotManager_getDefaultInstance.addSlot(loggingSlotId, loggerThread, loggerId, loggingReceiver, slotMethodName);
}

void Logger::removeSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName)
{
    LoggingSlotManager_getDefaultInstance.removeSlot(loggingSlotId, loggerThread, loggerId, loggingReceiver, slotMethodName);
}

void Logger::removeSlot(const QString& loggingSlotId)
{
    LoggingSlotManager_getDefaultInstance.removeSlot(loggingSlotId);
}

Logger& Logger::operator<<(const char* text)
{
    logInfo.content += " ";
    logInfo.content += text;
    return *this;
}

Logger& Logger::operator<<(const QString& text)
{
    logInfo.content += " " + text;
    return *this;
}

Logger& Logger::operator<<(const QByteArray& text)
{
    logInfo.content += " " + text;
    return *this;
}

Logger& Logger::operator<<(qint64 value)
{
    logInfo.content += " " + QString::number(value);
    return *this;
}

Logger& Logger::operator<<(quint64 value)
{
    logInfo.content += " " + QString::number(value);
    return *this;
}

Logger& Logger::operator<<(int value)
{
    logInfo.content += " " + QString::number(value);
    return *this;
}

Logger& Logger::operator<<(uint value)
{
    logInfo.content += " " + QString::number(value);
    return *this;
}

#ifndef _WIN32
Logger& Logger::operator<<(size_t value)
{
    logInfo.content += " " + QString::number(value);
    return *this;
}
#endif

Logger& Logger::operator<<(double value)
{
    logInfo.content += " " + _NCM::doubleToStringFullPrecision(value);
    return *this;
}

}
