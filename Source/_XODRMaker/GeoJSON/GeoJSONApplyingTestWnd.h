#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class GeoJSONApplyingTestWnd;
}

class GeoJSONApplyingTestWnd : public QWidget
{
    Q_OBJECT

public:
    explicit GeoJSONApplyingTestWnd(QWidget *parent = 0);
    ~GeoJSONApplyingTestWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::GeoJSONApplyingTestWnd *ui;
};

