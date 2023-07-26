#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class OSMNodeTablesUpdateWnd;
}

class OSMNodeTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit OSMNodeTablesUpdateWnd(QWidget *parent = 0);
    ~OSMNodeTablesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::OSMNodeTablesUpdateWnd *ui;
};
