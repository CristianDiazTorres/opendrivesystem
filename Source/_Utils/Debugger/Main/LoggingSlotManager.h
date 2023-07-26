#pragma once

#include "Debugger/Internal/Internal.h"
#include <QMutex>
#include "Common/Main/DefaultInstance.h"

namespace _NDebug
{

class Logger;
class LoggingThread;

class LoggingSlotManager
{
    friend class Logger;
    friend class LoggingThread;

    _NCM_DEFAULT_INSTANCE_DECLARE(LoggingSlotManager, &, *)

protected:
    struct LoggingSlot
    {
        QString loggingSlotId;

        QThread* loggerThread;
        QString loggerId;

        QObject* loggingReceiver;
        QByteArray slotMethodName;
    };

protected:
    QMutex mutex;
    QVector<LoggingSlot> loggingSlots;

protected:
    void addSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName);
    void removeSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName);
    void removeSlot(const QString& loggingSlotId);
    QVector<LoggingSlot> getSlots();

};

#define LoggingSlotManager_createDefaultInstance        _NDebug::LoggingSlotManager::createDefaultInstance()
#define LoggingSlotManager_getDefaultInstance           _NDebug::LoggingSlotManager::getDefaultInstance()


}
