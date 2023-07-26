#include "JSONFilesUpdateThread.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "DB/Main/LocalFilesDatabaseSettings.h"
#include "Debugger/Main/Logger.h"
#include <QFileInfo>

namespace _NXODR
{

JSONFilesUpdateThread* JSONFilesUpdateThread::defaultInstance = 0;

void JSONFilesUpdateThread::setParams()
{

}

bool JSONFilesUpdateThread::onPreLoop()
{
    setProgress(0);

    if (hasToStop())
        return false;

    QString latestXODRRecordUpdatedTime = LocalFilesDatabaseSettings_getDefaultInstance.getLatestXODRRecordUpdatedTimeForJSONFile();
    qint64 countToProcess = 0;
    if (!PGDatabaseConnector_getDefaultInstance.getXODRRecordCount(countToProcess, latestXODRRecordUpdatedTime))
    {
        DefaultLogger << "Error while getting xodr record count";
        return false;
    }

    for (int i = 0; i < countToProcess; i ++)
    {
        Cell cell;
        if (!PGDatabaseConnector_getDefaultInstance.getXODRCellInfo(latestXODRRecordUpdatedTime, latestXODRRecordUpdatedTime, cell.cellRow, cell.cellCol))
        {
            DefaultLogger << "Error while getting xodr cell info";
            return false;
        }

        _NOD::OpenDRIVE odContent = PGDatabaseConnector_getDefaultInstance.getXODRContent(cell);
        odContent.setParent();
        QString jsonFilePath = QFileInfo(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath() + "/" + odContent.header.name + ".json").absoluteFilePath();

        if (!odContent.writeToJson(jsonFilePath))
            return false;

        setProgress((i + 1) * 100 / countToProcess);

        LocalFilesDatabaseSettings_getDefaultInstance.setLatestXODRRecordUpdatedTimeForJSONFile(latestXODRRecordUpdatedTime);

        if (hasToStop())
            return false;
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
