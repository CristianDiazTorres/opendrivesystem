#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class CurvatureSlopeTablesUpdateWnd;
}

class CurvatureSlopeTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit CurvatureSlopeTablesUpdateWnd(QWidget *parent = 0);
    ~CurvatureSlopeTablesUpdateWnd();

public:
    void startAction(QString gpsFilePath);

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::CurvatureSlopeTablesUpdateWnd *ui;
};

