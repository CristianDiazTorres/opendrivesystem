#include "DB/Main/LocalFilesDatabaseConnector.h"
#include <QFileInfo>
#include <QDir>
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "Debugger/Main/Logger.h"

namespace _NDB
{

QString LocalFilesDatabaseConnector::getFilePath(const Cell& zoneCell)
{
    return getFilePath(zoneCell.getName());
}

QString LocalFilesDatabaseConnector::getFilePath(const QString& name)
{
    return QFileInfo(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath() + "/" + name + ".xodr").absoluteFilePath();
}

bool LocalFilesDatabaseConnector::setGPSFilePath(QString& filePath, bool continue_, int count, int& start)
{
    if (filePath.isEmpty())
    {
        DefaultLogger << "GPS file path is empty !";
        return false;
    }

    filePath = QFileInfo(filePath).absoluteFilePath();
    if (filePath.isEmpty())
    {
        DefaultLogger << "GPS file path is invalid !";
        return false;
    }

    if (!continue_)
    {
        DefaultLogger << "'continue' flag was not set, new GPS file path would be used.";
        DefaultLogger << "Start : 0 , Count : " << count;
        UserSettingsOnPGDatabase_getDefaultInstance.setValue(_SC_gpsFilePath, filePath);
        UserSettingsOnPGDatabase_getDefaultInstance.setValue(_SC_count, count);
        start = 0;
        return true;
    }

    QString oldFilePath = UserSettingsOnPGDatabase_getDefaultInstance.getValue(_SC_gpsFilePath);
    if (oldFilePath.isEmpty())
    {
        DefaultLogger << "'continue' flag was set, but old GPS file path is empty !";
        return false;
    }

    if (filePath != oldFilePath)
    {
        DefaultLogger << "'continue' flag was set, new/old GPS file paths are different !";
        DefaultLogger << "Old GPS file path : " << oldFilePath;
        return false;
    }

    start = UserSettingsOnPGDatabase_getDefaultInstance.getValue(_SC_count, 0).toInt();
    UserSettingsOnPGDatabase_getDefaultInstance.getValue(_SC_count, start + count);
    DefaultLogger << "'continue' flag was set.";
    DefaultLogger << "Start : " << start << " , Count : " << count;
    return true;
}

bool LocalFilesDatabaseConnector::updateXODRContent(const Cell& cell, _NOD::OpenDRIVE& odContent)
{
    odContent.header.version = QString::number(odContent.header.version.toDouble() + 0.001);

    odContents.update(cell, odContent);

    QString filePath = getFilePath(odContent.header.name);
    if (odContent.write(filePath))
    {
        DefaultLogger << "Saving succeeded: " << filePath;
        return true;
    }
    else
    {
        DefaultLogger << "Saving failed: " << filePath;
        DefaultLogger << "Critical Error !!! Check your disk space & permission ";
        return false;
    }
}

_NOD::OpenDRIVE LocalFilesDatabaseConnector::getXODRContent(const Cell& cell)
{
    if (odContents.exists(cell))
        return odContents.getContent(cell);

    _NOD::OpenDRIVE odContent;
    QString name = cell.getName();
    if (!odContent.read(getFilePath(name)))
        odContent.init(cell);

    odContents.update(cell, odContent);
    return odContent;
}

int LocalFilesDatabaseConnector::getNewID(QString key)
{
    // ????????????!!!!!!!!!
    int id = UserSettingsOnPGDatabase_getDefaultInstance.getValue(key, 0).toInt() + 1;
    UserSettingsOnPGDatabase_getDefaultInstance.setValue(key, id);
    return id;
}

}
