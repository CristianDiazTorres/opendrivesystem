#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class TrajectoryTablesUpdateWnd;
}

class TrajectoryTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit TrajectoryTablesUpdateWnd(QWidget *parent = 0);
    ~TrajectoryTablesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::TrajectoryTablesUpdateWnd *ui;
};

