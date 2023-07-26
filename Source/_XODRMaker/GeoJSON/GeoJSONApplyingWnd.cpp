#include "GeoJSONApplyingWnd.h"
#include "ui_GeoJSONApplyingWnd.h"
#include "GeoJSON/GeoJSONApplyingThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

using namespace _NGeoJSON;

GeoJSONApplyingWnd::GeoJSONApplyingWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GeoJSONApplyingWnd)
{
    ui->setupUi(this);
}

GeoJSONApplyingWnd::~GeoJSONApplyingWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void GeoJSONApplyingWnd::startAction()
{
    GeoJSONApplyingThread_createDefaultInstance;

    GeoJSONApplyingThread_getDefaultInstance->setParams();

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", GeoJSONApplyingThread_getDefaultInstance, "", this, "onAddLog");
    connect(GeoJSONApplyingThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(GeoJSONApplyingThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    GeoJSONApplyingThread_getDefaultInstance->restartThread();
}

void GeoJSONApplyingWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (true)
    {
        if (logInfo.loggingTarget & _NDebug::LD_PGDB)
            PGDatabaseConnector_getDefaultInstance.insertGeoJSONApplyingLog(logInfo);
    }

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void GeoJSONApplyingWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void GeoJSONApplyingWnd::onThreadPostLoopFinished()
{
    if (GeoJSONApplyingThread_isDefaultInstanceAlive)
    {
        disconnect(GeoJSONApplyingThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(GeoJSONApplyingThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        GeoJSONApplyingThread_deleteDefaultInstance;
    }
}
