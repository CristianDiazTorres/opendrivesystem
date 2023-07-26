#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class XODRTablesUpdateWnd;
}

class XODRTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit XODRTablesUpdateWnd(QWidget *parent = 0);
    ~XODRTablesUpdateWnd();

public:
    void startAction(bool useBasicTables, QString gpsFilePath = "");

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::XODRTablesUpdateWnd *ui;
};

