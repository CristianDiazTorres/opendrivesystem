#include "XODRTablesUpdateWnd.h"
#include "ui_XODRTablesUpdateWnd.h"
#include "XODR/Main/XODRTablesUpdateThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

XODRTablesUpdateWnd::XODRTablesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XODRTablesUpdateWnd)
{
    ui->setupUi(this);
}

XODRTablesUpdateWnd::~XODRTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void XODRTablesUpdateWnd::startAction(bool useBasicTables, QString gpsFilePath)
{
    XODRTablesUpdateThread_createDefaultInstance;

    XODRTablesUpdateThread_getDefaultInstance->setParams(useBasicTables, gpsFilePath);

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", XODRTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(XODRTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(XODRTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    XODRTablesUpdateThread_getDefaultInstance->restartThread();
}

void XODRTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
        PGDatabaseConnector_getDefaultInstance.insertXODRLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void XODRTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void XODRTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (XODRTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(XODRTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(XODRTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        XODRTablesUpdateThread_deleteDefaultInstance;
    }
}
