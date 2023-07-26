#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>

namespace _NDB
{

PGDatabaseConnector* PGDatabaseConnector::defaultInstance = 0;

bool PGDatabaseConnector::reconnect()
{
    qDebug() << "PGDatabaseConnector::reconnect before lock";
    mutex.lock();
    qDebug() << "PGDatabaseConnector::reconnect after lock";

    // Just set reconnection flag for all threads databases
    for (DatabaseInfo& dbInfo : databasesInfos)
        dbInfo.hasToReconnect = true;

    qDebug() << "PGDatabaseConnector::reconnect before unlock";
    mutex.unlock();
    qDebug() << "PGDatabaseConnector::reconnect after unlock";

    // Open current database, maybe main thread database
    return isDBOpen();
}

void PGDatabaseConnector::onThreadFinished()
{
    QThread* thread = (QThread*)sender();

    QSqlDatabase db;

    qDebug() << "PGDatabaseConnector::onThreadFinished before lock";
    mutex.lock();
    qDebug() << "PGDatabaseConnector::onThreadFinished after lock";

    // Remove database info from map
    db = databasesInfos.take(thread).db;

    qDebug() << "PGDatabaseConnector::onThreadFinished before unlock";
    mutex.unlock();
    qDebug() << "PGDatabaseConnector::onThreadFinished after unlock";

    // Close database
    db.close();
}

}
