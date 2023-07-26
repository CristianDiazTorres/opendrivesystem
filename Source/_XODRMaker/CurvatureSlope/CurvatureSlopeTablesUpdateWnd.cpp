#include "CurvatureSlopeTablesUpdateWnd.h"
#include "ui_CurvatureSlopeTablesUpdateWnd.h"
#include "CurvatureSlope/CurvatureSlopeTablesUpdateThread.h"
#include <QtGlobal>
#include <QScrollBar>
#include <QPlainTextEdit>
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

CurvatureSlopeTablesUpdateWnd::CurvatureSlopeTablesUpdateWnd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CurvatureSlopeTablesUpdateWnd)
{
    ui->setupUi(this);
}

CurvatureSlopeTablesUpdateWnd::~CurvatureSlopeTablesUpdateWnd()
{
    onThreadPostLoopFinished();

    delete ui;
}

void CurvatureSlopeTablesUpdateWnd::startAction(QString gpsFilePath)
{
    CurvatureSlopeTablesUpdateThread_createDefaultInstance;

    CurvatureSlopeTablesUpdateThread_getDefaultInstance->setParams(gpsFilePath);

    _NDebug::Logger::removeSlot("", _NDebug::Logger::ALL_THREADS, "", this, "onAddLog");
    _NDebug::Logger::addSlot("", CurvatureSlopeTablesUpdateThread_getDefaultInstance, "", this, "onAddLog");
    connect(CurvatureSlopeTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
    connect(CurvatureSlopeTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

    ui->pathEdt->setText(gpsFilePath);
    ui->progressBar->setValue(0);
    ui->logEdt->clear();

    CurvatureSlopeTablesUpdateThread_getDefaultInstance->restartThread();
}

void CurvatureSlopeTablesUpdateWnd::onAddLog(_NDebug::LogInfo logInfo)
{
//    if (logInfo.loggingTarget & _NDebug::LD_PGDB)
//        PGDatabaseConnector_getDefaultInstance.insertGPSLog(logInfo);

    bool atEnd = ui->logEdt->verticalScrollBar()->value() == ui->logEdt->verticalScrollBar()->maximum();

    ui->logEdt->insertPlainText(logInfo.fullMessage + '\n');

    if (atEnd)
        ui->logEdt->verticalScrollBar()->setValue(ui->logEdt->verticalScrollBar()->maximum());
}

void CurvatureSlopeTablesUpdateWnd::onProgressUpdated(int progress)
{
    ui->progressBar->setValue(progress);
}

void CurvatureSlopeTablesUpdateWnd::onThreadPostLoopFinished()
{
    if (CurvatureSlopeTablesUpdateThread_isDefaultInstanceAlive)
    {
        disconnect(CurvatureSlopeTablesUpdateThread_getDefaultInstance, SIGNAL(progressUpdated(int)), this, SLOT(onProgressUpdated(int)));
        disconnect(CurvatureSlopeTablesUpdateThread_getDefaultInstance, SIGNAL(postLoopFinished()), this, SLOT(onThreadPostLoopFinished()));

        CurvatureSlopeTablesUpdateThread_deleteDefaultInstance;
    }
}
