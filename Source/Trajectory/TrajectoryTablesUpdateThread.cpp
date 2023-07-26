#include "TrajectoryTablesUpdateThread.h"
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "Common/Main/StringContants.h"
#include "GeoCoordinate/Main/VehiclePos.h"
#include "KalmanFilter.h"

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

namespace _NTrajectory
{

TrajectoryTablesUpdateThread* TrajectoryTablesUpdateThread::defaultInstance = 0;

void TrajectoryTablesUpdateThread::setParams()
{
}

bool TrajectoryTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    DefaultLogger << "========== Calculating trajectory and inserting to pg-database ==========";

    QString lastProcessedGPSId;
    qint64 countToProcess = 0;

    PGDatabaseConnector_getDefaultInstance.getTrajectoryState_LastProcessedGPSValidDataId(lastProcessedGPSId);
    if (lastProcessedGPSId.isEmpty())
        lastProcessedGPSId = "0";

    //qDebug() << "lastProcessedGPSId : " << lastProcessedGPSId;

    PGDatabaseConnector_getDefaultInstance.getGPSValidDataCountToProcessForTrajectory(countToProcess);

    VehiclePos prevPos;
    prevPos.gpsFileId = 0;

    int processedCount = 0;

    KalmanFilter filter;

    while (true)
    {
        //qDebug() << "lastProcessedGPSId : " << lastProcessedGPSId;

        QVector<VehiclePos> records;
        if (!PGDatabaseConnector_getDefaultInstance.getGPSValidDataToProcessForTrajectory(lastProcessedGPSId, records))
        {
            DefaultLogger << "Error while getting gps records from pg-database !!!";
            return false;
        }

        //qDebug() << "records.size():" << records.size();

        if (records.isEmpty())
            break;

        for (VehiclePos& pos : records)
        {
            //qDebug() << "pos.id " << pos.id;

            //pos.updateDerivedProps();
            if (prevPos.gpsFileId == pos.gpsFileId)
            {
                pos.updateAccelFromPrev(prevPos);
            }
            else // if (records.size() > 1)
            {
                //pos.updateAccelFromNext(records[1]);

                filter.intialize(pos.timeSeconds, pos.x(), pos.y(), pos.vx, pos.vy, pos.hdop);
            }

            prevPos = pos;

            const DoubleVec& predicted = filter.predict(pos.timeSeconds, pos.x(), pos.y(), pos.vx, pos.vy, pos.ax, pos.ay);
            VehiclePos newPos;
            newPos.setFromPredictedPos(pos, XY(predicted[0], predicted[1]), predicted[2], predicted[3]);

            //qDebug() << "before insertTrajectoryData : id : " << newPos.id;

            if (!PGDatabaseConnector_getDefaultInstance.insertTrajectoryData(newPos))
            {
                DefaultLogger << "Error while inserting trajectory to pg-database !!!";
                return false;
            }

            lastProcessedGPSId = QString::number(newPos.id);
            if (!PGDatabaseConnector_getDefaultInstance.updateTrajectoryState_LastProcessedGPSValidDataId(lastProcessedGPSId))
            {
                DefaultLogger << "Error while updating status_trajectory !!!";
                return false;
            }
        }

        processedCount += records.size();
        setProgress(100 * processedCount / countToProcess);
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
