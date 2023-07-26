#include "TrajectoryTablesUpdateWnd.h"
#include "ui_TrajectoryTablesUpdateWnd.h"
#include "Trajectory/TrajectoryTablesUpdateThread.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

TrajectoryTablesUpdateWnd::TrajectoryTablesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrajectoryTablesUpdateWnd)
{
    ui->setupUi(this);
}

TrajectoryTablesUpdateWnd::~TrajectoryTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void TrajectoryTablesUpdateWnd::startAction()
{
    TrajectoryTablesUpdateThread_createDefaultInstance;

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", TrajectoryTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(TrajectoryTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(TrajectoryTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    TrajectoryTablesUpdateThread_getDefaultInstance->restartThread();
}

void TrajectoryTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertTrajectoryLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void TrajectoryTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void TrajectoryTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (TrajectoryTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(TrajectoryTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(TrajectoryTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        TrajectoryTablesUpdateThread_deleteDefaultInstance;
    }
}
