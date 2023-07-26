#include "LoggingSlotManager.h"
#include "Logger.h"
#include <QDebug>

namespace _NDebug
{

LoggingSlotManager* LoggingSlotManager::defaultInstance = 0;

void LoggingSlotManager::addSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName)
{
    LoggingSlot loggingSlot;
    loggingSlot.loggingSlotId = loggingSlotId;
    loggingSlot.loggerThread = loggerThread;
    loggingSlot.loggerId = loggerId;
    loggingSlot.loggingReceiver = loggingReceiver;
    loggingSlot.slotMethodName = slotMethodName;

    qDebug() << "LoggingSlotManager::addSlot before lock";
    mutex.lock();
    qDebug() << "LoggingSlotManager::addSlot after lock";

    loggingSlots << loggingSlot;

    qDebug() << "LoggingSlotManager::addSlot before unlock";
    mutex.unlock();
    qDebug() << "LoggingSlotManager::addSlot after unlock";
}

void LoggingSlotManager::removeSlot(const QString& loggingSlotId, QThread* loggerThread, const QString& loggerId, QObject* loggingReceiver, const QByteArray& slotMethodName)
{
    qDebug() << "LoggingSlotManager::removeSlot1 before lock";
    mutex.lock();
    qDebug() << "LoggingSlotManager::removeSlot1 after lock";

    for (int i = loggingSlots.size() - 1; i >= 0; i --)
    {
        const LoggingSlot& loggingSlot = loggingSlots[i];
        if (loggingSlot.loggingSlotId == loggingSlotId
            && (loggerThread == Logger::ALL_THREADS || loggingSlot.loggerThread == loggerThread)
            && loggingSlot.loggerId == loggerId
            && loggingSlot.loggingReceiver == loggingReceiver
            && loggingSlot.slotMethodName == slotMethodName)
        {
            loggingSlots.remove(i);
        }
    }

    qDebug() << "LoggingSlotManager::removeSlot1 before unlock";
    mutex.unlock();
    qDebug() << "LoggingSlotManager::removeSlot1 after unlock";
}

void LoggingSlotManager::removeSlot(const QString& loggingSlotId)
{
    qDebug() << "LoggingSlotManager::removeSlot2 before lock";
    mutex.lock();
    qDebug() << "LoggingSlotManager::removeSlot2 after lock";

    for (int i = loggingSlots.size() - 1; i >= 0; i --)
    {
        const LoggingSlot& loggingSlot = loggingSlots[i];
        if (loggingSlot.loggingSlotId == loggingSlotId)
        {
            loggingSlots.remove(i);
        }
    }

    qDebug() << "LoggingSlotManager::removeSlot2 before unlock";
    mutex.unlock();
    qDebug() << "LoggingSlotManager::removeSlot2 after unlock";
}

QVector<LoggingSlotManager::LoggingSlot> LoggingSlotManager::getSlots()
{
    qDebug() << "LoggingSlotManager::getSlots before lock";
    mutex.lock();
    qDebug() << "LoggingSlotManager::getSlots after lock";

    QVector<LoggingSlot> copiedLoggingSlots = loggingSlots;

    qDebug() << "LoggingSlotManager::getSlots before unlock";
    mutex.unlock();
    qDebug() << "LoggingSlotManager::getSlots after unlock";

    return copiedLoggingSlots;
}

}
