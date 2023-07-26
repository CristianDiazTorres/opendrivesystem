#include "OSMCountryAreaTablesUpdateWnd.h"
#include "ui_OSMCountryAreaTablesUpdateWnd.h"
#include "OSM/CountryArea/OSMCountryAreaTablesUpdateThread.h"
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

OSMCountryAreaTablesUpdateWnd::OSMCountryAreaTablesUpdateWnd(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::OSMCountryAreaTablesUpdateWnd)
{
    ui->setupUi(this);
}

OSMCountryAreaTablesUpdateWnd::~OSMCountryAreaTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void OSMCountryAreaTablesUpdateWnd::startAction()
{
    OSMCountryAreaTablesUpdateThread_createDefaultInstance;

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", OSMCountryAreaTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(OSMCountryAreaTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(OSMCountryAreaTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    OSMCountryAreaTablesUpdateThread_getDefaultInstance->restartThread();
}

void OSMCountryAreaTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertOSMCountryAreaLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void OSMCountryAreaTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void OSMCountryAreaTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (OSMCountryAreaTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(OSMCountryAreaTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(OSMCountryAreaTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        OSMCountryAreaTablesUpdateThread_deleteDefaultInstance;
    }
}
