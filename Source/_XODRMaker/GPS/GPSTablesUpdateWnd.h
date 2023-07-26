#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class GPSTablesUpdateWnd;
}

class GPSTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit GPSTablesUpdateWnd(QWidget *parent = 0);
    ~GPSTablesUpdateWnd();

public:
    void startAction(QString gpsFilePath);

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::GPSTablesUpdateWnd *ui;
};

