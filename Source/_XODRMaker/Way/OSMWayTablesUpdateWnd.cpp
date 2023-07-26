#include "OSMWayTablesUpdateWnd.h"
#include "ui_OSMWayTablesUpdateWnd.h"
#include "OSM/Way/OSMWayTablesUpdateThread.h"
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

OSMWayTablesUpdateWnd::OSMWayTablesUpdateWnd(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::OSMWayTablesUpdateWnd)
{
    ui->setupUi(this);
}

OSMWayTablesUpdateWnd::~OSMWayTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void OSMWayTablesUpdateWnd::startAction()
{
    OSMWayTablesUpdateThread_createDefaultInstance;

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", OSMWayTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(OSMWayTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(OSMWayTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    OSMWayTablesUpdateThread_getDefaultInstance->restartThread();
}

void OSMWayTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertOSMWayLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void OSMWayTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void OSMWayTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (OSMWayTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(OSMWayTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(OSMWayTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        OSMWayTablesUpdateThread_deleteDefaultInstance;
    }
}
