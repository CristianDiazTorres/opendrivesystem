#include "MainWnd.h"
#include <QApplication>
#include <QSqlDatabase>
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include "DB/Main/GlobalSettingsOnPGDatabase.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "DB/Main/LocalFilesDatabaseSettings.h"
#include "SetPGDatabaseSettingDlg.h"
#include "SetLocalFilesDatabasePathDlg.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "OSM/TileImage/OSMTileImageDownloader.h"

void createStaticInstances()
{
    PGDatabaseConnector_createDefaultInstance;

    // Settings
    DatabaseSettingsOnLocalSystem_createDefaultInstance;

    GlobalSettingsOnPGDatabase_createDefaultInstance;
    UserSettingsOnPGDatabase_createDefaultInstance;

    LocalFilesDatabaseSettings_createDefaultInstance;

    OSMTileImageDownloader_createDefaultInstance;
}

void initStaticInstances()
{
    _NDebug::Logger::init();

    DatabaseSettingsOnLocalSystem_initDefaultInstance;

    if (!DatabaseSettingsOnLocalSystem_getDefaultInstance.isPGSettingsValid() || !PGDatabaseConnector_getDefaultInstance.reconnect())
    {
        SetPGDatabaseSettingDlg dlg;
        dlg.exec();
    }

    GlobalSettingsOnPGDatabase_initDefaultInstance;
    UserSettingsOnPGDatabase_initDefaultInstance;

    if (UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath().isEmpty())
    {
        QString localFilesDatabasePath = QCoreApplication::applicationDirPath() + "/Database";
        UserSettingsOnPGDatabase_getDefaultInstance.setLocalFilesDatabasePath(localFilesDatabasePath);

        SetLocalFilesDatabasePathDlg dlg;
        dlg.exec();
    }

    LocalFilesDatabaseSettings_initDefaultInstance;

    OSMTileImageDownloader_getDefaultInstance->startThread();

    _NDebug::Logger::setLoggingEnabled(true);
    _NDebug::Logger::startLogging();
}

void stopStaticThreads()
{
    OSMTileImageDownloader_stopDefaultInstanceThreadIfAlive;

    _NDebug::Logger::stopLogging();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<_NOSM::OSMTileImageParam>("_NOSM::OSMTileImageParam");

    createStaticInstances();

    initStaticInstances();

    MainWnd w;
    w.show();

    int ret = a.exec();

    stopStaticThreads();

    return ret;
}
