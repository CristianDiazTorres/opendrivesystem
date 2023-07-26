#include "GeoJSONApplyingTestWnd.h"
#include "ui_GeoJSONApplyingTestWnd.h"
#include "GeoJSON/GeoJSONApplyingTestThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

using namespace _NGeoJSON;

GeoJSONApplyingTestWnd::GeoJSONApplyingTestWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GeoJSONApplyingTestWnd)
{
    ui->setupUi(this);
}

GeoJSONApplyingTestWnd::~GeoJSONApplyingTestWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void GeoJSONApplyingTestWnd::startAction()
{
    GeoJSONApplyingTestThread_createDefaultInstance;

    GeoJSONApplyingTestThread_getDefaultInstance->setParams();

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", GeoJSONApplyingTestThread_getDefaultInstance, "", this, "onAddLog");
    connect(GeoJSONApplyingTestThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(GeoJSONApplyingTestThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    GeoJSONApplyingTestThread_getDefaultInstance->restartThread();
}

void GeoJSONApplyingTestWnd::onAddLog(_NDebug::LogInfo logInfo)
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

void GeoJSONApplyingTestWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void GeoJSONApplyingTestWnd::onThreadPostLoopFinished()
{
    if (GeoJSONApplyingTestThread_isDefaultInstanceAlive)
    {
        disconnect(GeoJSONApplyingTestThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(GeoJSONApplyingTestThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        GeoJSONApplyingTestThread_deleteDefaultInstance;
    }
}
