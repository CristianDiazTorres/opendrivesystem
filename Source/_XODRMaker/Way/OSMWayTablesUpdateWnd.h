#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class OSMWayTablesUpdateWnd;
}

class OSMWayTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit OSMWayTablesUpdateWnd(QWidget *parent = 0);
    ~OSMWayTablesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::OSMWayTablesUpdateWnd *ui;
};
