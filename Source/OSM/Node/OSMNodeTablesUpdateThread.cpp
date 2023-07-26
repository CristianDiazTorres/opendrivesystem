#include "OSM/Node/OSMNodeTablesUpdateThread.h"
#include "OSM/Main/OverpassAPI.h"
#include "OSM/Main/PolygonAPI.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "GeoCoordinate/Main/Cell.h"

namespace _NOSM
{

OSMNodeTablesUpdateThread* OSMNodeTablesUpdateThread::defaultInstance = 0;

bool OSMNodeTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    DefaultLogger << "========== Updating OSM Node ==========";

    QString lastProcessedCellsId;
    qint64 countToProcess = 0;

    PGDatabaseConnector_getDefaultInstance.getOSMNodeState_LastProcessedGPSCellsDataId(lastProcessedCellsId);
    if (lastProcessedCellsId.isEmpty())
        lastProcessedCellsId = "0";

    //qDebug() << "lastProcessedCellsId : " << lastProcessedCellsId;

    PGDatabaseConnector_getDefaultInstance.getGPSCellsDataCountToProcessForOSMNode(countToProcess);

    int processedCount = 0;

    while (true)
    {
        //qDebug() << "lastProcessedCellsId : " << lastProcessedCellsId;

        QVector<qint64> cellsIds;
        QVector<Cell> cells;
        if (!PGDatabaseConnector_getDefaultInstance.getGPSCellsDataToProcessForOSMNode(lastProcessedCellsId, cellsIds, cells))
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

            QJsonValue jsonValue = OverpassAPI::getNodesData(cellCenter.lat, cellCenter.lon, Cell::SQUARE_CELL_SIZE * 100000);
            if (jsonValue.isArray())
            {
                QJsonArray elements = jsonValue.toArray();

                for (int j = 0; j < elements.size(); j ++)
                {
                    QJsonObject jsonObject = elements[j].toObject();
                    LL ll(jsonObject);
                    QString osmId = QString::number((qint64)jsonObject[_SC_id].toDouble());
                    QString json = QJsonDocument(jsonObject).toJson();

                    QString geomStr = "POINT(" + _NCM::doubleToStringFullPrecision(ll.lon) + " " + _NCM::doubleToStringFullPrecision(ll.lat) + ")";

                    QJsonObject tags = jsonObject[_SC_tags].toObject();
                    PGDatabaseConnector_getDefaultInstance.updateOSMNodeDataAndHist(osmId, json, geomStr, tags);
                }
            }

            if (!PGDatabaseConnector_getDefaultInstance.updateOSMNodeState_LastProcessedGPSCellsDataId(QString::number(cellId)))
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
