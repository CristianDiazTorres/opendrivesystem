#include "OSMNodeTablesUpdateWnd.h"
#include "ui_OSMNodeTablesUpdateWnd.h"
#include "OSM/Node/OSMNodeTablesUpdateThread.h"
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

OSMNodeTablesUpdateWnd::OSMNodeTablesUpdateWnd(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::OSMNodeTablesUpdateWnd)
{
    ui->setupUi(this);
}

OSMNodeTablesUpdateWnd::~OSMNodeTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void OSMNodeTablesUpdateWnd::startAction()
{
    OSMNodeTablesUpdateThread_createDefaultInstance;

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", OSMNodeTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(OSMNodeTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(OSMNodeTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    OSMNodeTablesUpdateThread_getDefaultInstance->restartThread();
}

void OSMNodeTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertOSMNodeLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void OSMNodeTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void OSMNodeTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (OSMNodeTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(OSMNodeTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(OSMNodeTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        OSMNodeTablesUpdateThread_deleteDefaultInstance;
    }
}
