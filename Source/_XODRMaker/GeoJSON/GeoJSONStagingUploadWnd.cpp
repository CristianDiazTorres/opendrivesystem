#include "GeoJSONStagingUploadWnd.h"
#include "ui_GeoJSONStagingUploadWnd.h"
#include "GeoJSON/GeoJSONStagingUploadThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

using namespace _NGeoJSON;

GeoJSONStagingUploadWnd::GeoJSONStagingUploadWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GeoJSONStagingUploadWnd)
{
    ui->setupUi(this);
}

GeoJSONStagingUploadWnd::~GeoJSONStagingUploadWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void GeoJSONStagingUploadWnd::startAction(QStringList paths)
{
    GeoJSONStagingUploadThread_createDefaultInstance;

    GeoJSONStagingUploadThread_getDefaultInstance->setParams(paths);

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", GeoJSONStagingUploadThread_getDefaultInstance, "", this, "onAddLog");
    connect(GeoJSONStagingUploadThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(GeoJSONStagingUploadThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    GeoJSONStagingUploadThread_getDefaultInstance->restartThread();
}

void GeoJSONStagingUploadWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (true)
    {
        if (logInfo.loggingTarget & _NDebug::LD_PGDB)
            PGDatabaseConnector_getDefaultInstance.insertGeoJSONStagingLog(logInfo);
    }

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void GeoJSONStagingUploadWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void GeoJSONStagingUploadWnd::onThreadPostLoopFinished()
{
    if (GeoJSONStagingUploadThread_isDefaultInstanceAlive)
    {
        disconnect(GeoJSONStagingUploadThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(GeoJSONStagingUploadThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        GeoJSONStagingUploadThread_deleteDefaultInstance;
    }
}
