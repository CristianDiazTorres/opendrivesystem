#include "GPSTablesUpdateWnd.h"
#include "ui_GPSTablesUpdateWnd.h"
#include "GPS/GPSTablesUpdateThread.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

GPSTablesUpdateWnd::GPSTablesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GPSTablesUpdateWnd)
{
    ui->setupUi(this);
}

GPSTablesUpdateWnd::~GPSTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void GPSTablesUpdateWnd::startAction(QString gpsFilePath)
{
    GPSTablesUpdateThread_createDefaultInstance;

    GPSTablesUpdateThread_getDefaultInstance->setParams(gpsFilePath);

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", GPSTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(GPSTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(GPSTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->gpsPathEdt->setText(gpsFilePath);
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    GPSTablesUpdateThread_getDefaultInstance->restartThread();
}

void GPSTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertGPSLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void GPSTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void GPSTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (GPSTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(GPSTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(GPSTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        GPSTablesUpdateThread_deleteDefaultInstance;
    }
}
