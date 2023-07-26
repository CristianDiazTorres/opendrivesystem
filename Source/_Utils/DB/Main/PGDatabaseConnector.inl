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

inline QSqlDatabase& PGDatabaseConnector::getCurrentDB()
{
    DatabaseInfo& dbInfo = getCurrentDBInfo();
    QSqlDatabase& db = dbInfo.db;

    // Reconnect if flag was set
    if (dbInfo.hasToReconnect)
    {
        db.close();

        db.setHostName(DatabaseSettingsOnLocalSystem_getDefaultInstance.getHost());
        db.setPort(DatabaseSettingsOnLocalSystem_getDefaultInstance.getPort().toInt());
        db.setDatabaseName(DatabaseSettingsOnLocalSystem_getDefaultInstance.getDBName());
        db.setUserName(DatabaseSettingsOnLocalSystem_getDefaultInstance.getDBUser());
        db.setPassword(DatabaseSettingsOnLocalSystem_getDefaultInstance.getPassword());
        if (!db.open())
            return db;

        // Clear flag
        dbInfo.hasToReconnect = false;
    }

    return db;
}

inline PGDatabaseConnector::DatabaseInfo& PGDatabaseConnector::getCurrentDBInfo()
{
    QThread* thread = QThread::currentThread();

    //qDebug() << "PGDatabaseConnector::getCurrentDBInfo before lock";
    mutex.lock();
    //qDebug() << "PGDatabaseConnector::getCurrentDBInfo after lock";

    // Current database info for current thread
    bool existed = databasesInfos.contains(thread);
    DatabaseInfo& dbInfo = databasesInfos[thread];

    //qDebug() << "PGDatabaseConnector::getCurrentDBInfo before unlock";
    mutex.unlock();
    //qDebug() << "PGDatabaseConnector::getCurrentDBInfo after unlock";

    // Create new database
    if (!existed)
    {
        dbInfo.db = QSqlDatabase::addDatabase("QPSQL", QString::number((qint64)QThread::currentThreadId()));
        dbInfo.hasToReconnect = true;
        connect(thread, SIGNAL(finished()), this, SLOT(onThreadFinished()));
    }

    return dbInfo;
}

inline QSqlQuery PGDatabaseConnector::execQuery(const QString& queryString, _NDebug::LoggingTarget loggingTarget)
{
    if (!isDBOpen())
    {
        DefaultLogger_NotPGDB << "Database connection error !!!";
        return QSqlQuery();
    }

    _NDebug::Logger(loggingTarget) << "Running SQL query : " << queryString;

    QSqlQuery sqlQuery = getCurrentDB().exec(queryString);
    QSqlError sqlError = sqlQuery.lastError();

    static QString errorStrings[] = {
        "NoError",
        "ConnectionError",
        "StatementError",
        "TransactionError",
        "UnknownError"
    };

    if (sqlError.type() != QSqlError::NoError)
    {
        _NDebug::Logger(loggingTarget) << "SQL Error Status : "
                                      << "Type : " << errorStrings[(int)sqlError.type()]
                                      << "NativeErrorCode : " << sqlError.nativeErrorCode()
                                      << "DriverText : " << sqlError.driverText()
                                      << "DatabaseText : " << sqlError.databaseText()
                                      << "Text : " << sqlError.text();
    }

    return sqlQuery;
}

inline bool PGDatabaseConnector::isDBOpen()
{
    if (!getCurrentDB().isOpen())
    {
        qDebug() << "*** DB Open failed !!!";
        return false;
    }
    return true;
}

inline bool PGDatabaseConnector::execQueryToAffectOneRow(const QString &queryString, _NDebug::LoggingTarget loggingTarget)
{
    if (!isDBOpen())
        return false;

    return execQuery(queryString, loggingTarget).numRowsAffected() == 1;
}

template <typename T>
inline bool PGDatabaseConnector::getResult_R1C1(const QString& queryString, T& result, _NDebug::LoggingTarget loggingTarget)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString, loggingTarget);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    result = sqlQuery.value(0).value<T>();
    return true;
}

template <typename T1, typename T2>
inline bool PGDatabaseConnector::getResult_R1C2(const QString& queryString, T1& c1Result, T2& c2Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    return true;
}

template <typename T1, typename T2, typename T3>
inline bool PGDatabaseConnector::getResult_R1C3(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    return true;
}

template <typename T1, typename T2, typename T3, typename T4>
inline bool PGDatabaseConnector::getResult_R1C4(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    c4Result = sqlQuery.value(3).value<T4>();
    return true;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
inline bool PGDatabaseConnector::getResult_R1C5(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    c4Result = sqlQuery.value(3).value<T4>();
    c5Result = sqlQuery.value(4).value<T5>();
    return true;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
inline bool PGDatabaseConnector::getResult_R1C6(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    c4Result = sqlQuery.value(3).value<T4>();
    c5Result = sqlQuery.value(4).value<T5>();
    c6Result = sqlQuery.value(5).value<T6>();
    return true;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
inline bool PGDatabaseConnector::getResult_R1C7(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result, T7& c7Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    c4Result = sqlQuery.value(3).value<T4>();
    c5Result = sqlQuery.value(4).value<T5>();
    c6Result = sqlQuery.value(5).value<T6>();
    c7Result = sqlQuery.value(6).value<T7>();
    return true;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
inline bool PGDatabaseConnector::getResult_R1C8(const QString& queryString, T1& c1Result, T2& c2Result, T3& c3Result, T4& c4Result, T5& c5Result, T6& c6Result, T7& c7Result, T8& c8Result)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Result = sqlQuery.value(0).value<T1>();
    c2Result = sqlQuery.value(1).value<T2>();
    c3Result = sqlQuery.value(2).value<T3>();
    c4Result = sqlQuery.value(3).value<T4>();
    c5Result = sqlQuery.value(4).value<T5>();
    c6Result = sqlQuery.value(5).value<T6>();
    c7Result = sqlQuery.value(6).value<T7>();
    c8Result = sqlQuery.value(7).value<T8>();
    return true;
}

template <typename T1, typename T2>
inline bool PGDatabaseConnector::getResult_C2(const QString& queryString, QVector<T1>& c1Results, QVector<T2>& c2Results)
{
    if (!isDBOpen())
        return false;

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    c1Results.reserve(sqlQuery.size());
    c2Results.reserve(sqlQuery.size());

    do
    {
        c1Results << sqlQuery.value(0).value<T1>();
        c2Results << sqlQuery.value(1).value<T2>();
    }
    while(sqlQuery.next());

    return true;
}

}
