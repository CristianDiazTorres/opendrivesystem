#include "XODRFilesUpdateWnd.h"
#include "ui_XODRFilesUpdateWnd.h"
#include "XODR/Main/XODRFilesUpdateThread.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

XODRFilesUpdateWnd::XODRFilesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::XODRFilesUpdateWnd)
{
    ui->setupUi(this);
}

XODRFilesUpdateWnd::~XODRFilesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void XODRFilesUpdateWnd::startAction()
{
    XODRFilesUpdateThread_createDefaultInstance;

    XODRFilesUpdateThread_getDefaultInstance->setParams();

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", XODRFilesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(XODRFilesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(XODRFilesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->dbPathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
    //ui->gpsPathEdt->setText(filePath);
    //ui->continueChkBox->setChecked(continue_);
    //ui->countEdt->setText(QString::number(point_count));
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    XODRFilesUpdateThread_getDefaultInstance->restartThread();
}

void XODRFilesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
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

void XODRFilesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void XODRFilesUpdateWnd::onThreadPostLoopFinished()
{
    if (XODRFilesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(XODRFilesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(XODRFilesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        XODRFilesUpdateThread_deleteDefaultInstance;
    }
}
