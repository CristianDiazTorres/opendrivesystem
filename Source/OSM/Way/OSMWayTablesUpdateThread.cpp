#include "OSM/Way/OSMWayTablesUpdateThread.h"
#include "OSM/Main/OverpassAPI.h"
#include "OSM/Main/PolygonAPI.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "GeoCoordinate/Main/Cell.h"

namespace _NOSM
{

OSMWayTablesUpdateThread* OSMWayTablesUpdateThread::defaultInstance = 0;

bool OSMWayTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    DefaultLogger << "========== Updating OSM Way ==========";

    QString lastProcessedCellsId;
    qint64 countToProcess = 0;

    PGDatabaseConnector_getDefaultInstance.getOSMWayState_LastProcessedGPSCellsDataId(lastProcessedCellsId);
    if (lastProcessedCellsId.isEmpty())
        lastProcessedCellsId = "0";

    //qDebug() << "lastProcessedCellsId : " << lastProcessedCellsId;

    PGDatabaseConnector_getDefaultInstance.getGPSCellsDataCountToProcessForOSMWay(countToProcess);

    int processedCount = 0;

    while (true)
    {
        //qDebug() << "lastProcessedCellsId : " << lastProcessedCellsId;

        QVector<qint64> cellsIds;
        QVector<Cell> cells;
        if (!PGDatabaseConnector_getDefaultInstance.getGPSCellsDataToProcessForOSMWay(lastProcessedCellsId, cellsIds, cells))
        {
            DefaultLogger << "Error while getting cells from pg-database !!!";
            return false;
        }

        //qDebug() << "records.size():" << cellsIds.size();

        if (cellsIds.isEmpty())
            break;

        for (int i = 0; i < cellsIds.size(); i ++)
        {
            qint64 cellId = cellsIds[i];
            Cell& cell = cells[i];
            LL cellCenter = cell.getCellCenterLL();

            QJsonValue jsonValue = OverpassAPI::getWaysData(cellCenter.lat, cellCenter.lon, Cell::SQUARE_CELL_SIZE * 100000);
            if (jsonValue.isArray())
            {
                QJsonArray elements = jsonValue.toArray();

                for (int j = 0; j < elements.size(); j ++)
                {
                    QJsonObject jsonObject = elements[j].toObject();
                    QString osmId = QString::number((qint64)jsonObject[_SC_id].toDouble());
                    QString json = QJsonDocument(jsonObject).toJson();

                    QJsonArray geomArray = jsonObject[_SC_geometry].toArray();
                    QString geomStr;
                    if (!geomArray.isEmpty())
                    {
                        geomStr = "LINESTRING(";
                        for (int k = 0; k < geomArray.size(); k ++)
                        {
                            QJsonObject geom = geomArray[k].toObject();

                            if (k != 0)
                                geomStr += ",";

                            LL ll(geomArray[k]);
                            geomStr += _NCM::doubleToStringFullPrecision(ll.lon) + " " + _NCM::doubleToStringFullPrecision(ll.lat);
                        }
                        geomStr += ")";
                    }

                    QJsonObject tags = jsonObject[_SC_tags].toObject();
                    PGDatabaseConnector_getDefaultInstance.updateOSMWayDataAndHist(osmId, json, geomStr, tags);
                }
            }

            if (!PGDatabaseConnector_getDefaultInstance.updateOSMWayState_LastProcessedGPSCellsDataId(QString::number(cellId)))
            {
                DefaultLogger << "Error while updating status_osm !!!";
                return false;
            }
        }

        lastProcessedCellsId = QString::number(cellsIds.last());

        processedCount += cellsIds.size();
        setProgress(100 * processedCount / countToProcess);
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
