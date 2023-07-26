#include "GPSTablesUpdateThread.h"
#include "Debugger/Main/Logger.h"
#include "GPS/NativeGPSData.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "Common/Main/StringContants.h"

/*
for (int i = 0; i < result.size(); i ++)
{
    result[i].updateDerivedProps();
    if (i != 0)
        result[i].updateAccelFromPrev(result[i - 1]);
}

if (result.size() > 1)
    result.front().updateAccelFromNext(result[1]);
*/

namespace _NGPS
{

GPSTablesUpdateThread* GPSTablesUpdateThread::defaultInstance = 0;

void GPSTablesUpdateThread::setParams(QString gpsFilePath)
{
    this->gpsFilePath = gpsFilePath;
}

bool GPSTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    DefaultLogger << "========== Reading data from csv file and inserting to pg-database ==========";

    // Open csv file
    QFile fin(gpsFilePath);
    if (!fin.open(QIODevice::ReadOnly))
        return false;

    // Insert gps file info to pg-database
    qint64 gpsFileId = 0;
    if (!PGDatabaseConnector_getDefaultInstance.insertGPSFileData(gpsFilePath, gpsFileId))
        return false;

    // Read field names and parse
    QString line = QString::fromUtf8(fin.readLine());
    setProgress(100 * fin.pos() / fin.size());

    StringVec fieldNames = line.split(",").toVector();
    for (QString& fieldName : fieldNames)
        fieldName = fieldName.trimmed();

    // Read lines
    NativeGPSData lastMergedPos;
    while (!fin.atEnd())
    {
        // Read line
        line = QString::fromUtf8(fin.readLine().trimmed());
        line += ',';

        // Parse line
        NativeGPSData pos, mergedPos;

        int fieldIndex = 0;
        int prevPos = 0;
        bool invalidRow = false;

        // Parse fields
        while (true)
        {
            int curPos = line.indexOf(',', prevPos);
            if (curPos == -1)
                break;

            QString fieldName = fieldNames[fieldIndex];
            pos[fieldName] = line.mid(prevPos, curPos - prevPos).trimmed();

            if (pos[fieldName].isEmpty())
            {
                if (fieldName == _SC_Lat__deg__A || fieldName == _SC_Lon__deg__A)
                {
                    invalidRow = true;
                }
                else
                {
                    mergedPos[fieldName] = lastMergedPos[fieldName];
                }
            }
            else
            {
                mergedPos[fieldName] = pos[fieldName];
            }

            fieldIndex ++;
            prevPos = curPos + 1;
        }

        // Insert native gps data to pg-database
        if (!PGDatabaseConnector_getDefaultInstance.insertGPSNativeData(gpsFilePath, gpsFileId, pos))
        {
            DefaultLogger << "Error while inserting to pg-database !!!";
            return false;
        }

        if (!invalidRow)
        {
            // Insert merged gps data to pg-database
            if (mergedPos[_SC_UTC_Date_A] != lastMergedPos[_SC_UTC_Date_A]
                || mergedPos[_SC_UTC_Time_A] != lastMergedPos[_SC_UTC_Time_A])
            {
                if (!lastMergedPos[_SC_UTC_Date_A].isEmpty() && !lastMergedPos[_SC_UTC_Time_A].isEmpty())
                {
                    if (!PGDatabaseConnector_getDefaultInstance.insertGPSValidData(gpsFilePath, gpsFileId, lastMergedPos))
                    {
                        DefaultLogger << "Error while inserting to pg-database !!!";
                        return false;
                    }
                }
            }

            lastMergedPos = mergedPos;
        }

        setProgress(100 * fin.pos() / fin.size());
    }

    // Insert final merged gps data to pg-database
    if (!lastMergedPos[_SC_UTC_Date_A].isEmpty() && !lastMergedPos[_SC_UTC_Time_A].isEmpty())
    {
        if (!PGDatabaseConnector_getDefaultInstance.insertGPSValidData(gpsFilePath, gpsFileId, lastMergedPos))
        {
            DefaultLogger << "Error while inserting to pg-database !!!";
            return false;
        }
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
