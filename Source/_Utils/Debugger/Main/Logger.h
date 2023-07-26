#pragma once

#include "Debugger/Internal/Internal.h"
#include "Debugger/Main/LogInfo.h"

namespace _NDebug
{

class Logger
{
public:
    static QThread* ALL_THREADS;
    static QString ALL_IDS;

protected:
    LogInfo logInfo;

public:
    Logger(LoggingTarget loggingTarget = LD_All, const QString& id = "");
    virtual ~Logger();

public:
    static void init();
    static void setLoggingEnabled(bool enable);
    static void startLogging();
    static void stopLogging();

public:
    static void addSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName);
    static void removeSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName);
    static void removeSlot(const QString& loggingSlotId);

public:
    Logger& operator<<(const char* text);
    Logger& operator<<(const QString& text);
    Logger& operator<<(const QByteArray& text);
    Logger& operator<<(int value);
    Logger& operator<<(uint value);
#ifndef _WIN32
    Logger& operator<<(size_t value);
#endif
    Logger& operator<<(qint64 value);
    Logger& operator<<(quint64 value);
    Logger& operator<<(double value);

};

#define DefaultLogger               _NDebug::Logger()
#define DefaultLogger_NotPGDB       _NDebug::Logger(_NDebug::LD_NotPGDB)
#define DefaultLogger_QDebug        _NDebug::Logger(_NDebug::LD_QDebug)
#define DefaultLogger_File          _NDebug::Logger(_NDebug::LD_File)

}
