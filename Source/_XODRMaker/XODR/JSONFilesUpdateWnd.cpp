#include "JSONFilesUpdateWnd.h"
#include "ui_JSONFilesUpdateWnd.h"
#include "XODR/Main/JSONFilesUpdateThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

JSONFilesUpdateWnd::JSONFilesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JSONFilesUpdateWnd)
{
    ui->setupUi(this);
}

JSONFilesUpdateWnd::~JSONFilesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void JSONFilesUpdateWnd::startAction()
{
    JSONFilesUpdateThread_createDefaultInstance;

    JSONFilesUpdateThread_getDefaultInstance->setParams();

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", JSONFilesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(JSONFilesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(JSONFilesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    JSONFilesUpdateThread_getDefaultInstance->restartThread();
}

void JSONFilesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (false)
    {
        if (logInfo.loggingTarget & _NDebug::LD_PGDB)
            PGDatabaseConnector_getDefaultInstance.insertXODRLog(logInfo);
    }

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void JSONFilesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void JSONFilesUpdateWnd::onThreadPostLoopFinished()
{
    if (JSONFilesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(JSONFilesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(JSONFilesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        JSONFilesUpdateThread_deleteDefaultInstance;
    }
}
