#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class GeoJSONApplyingWnd;
}

class GeoJSONApplyingWnd : public QWidget
{
    Q_OBJECT

public:
    explicit GeoJSONApplyingWnd(QWidget *parent = 0);
    ~GeoJSONApplyingWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::GeoJSONApplyingWnd *ui;
};

