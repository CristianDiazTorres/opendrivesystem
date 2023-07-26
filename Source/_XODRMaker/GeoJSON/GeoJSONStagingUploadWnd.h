#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class GeoJSONStagingUploadWnd;
}

class GeoJSONStagingUploadWnd : public QWidget
{
    Q_OBJECT

public:
    explicit GeoJSONStagingUploadWnd(QWidget *parent = 0);
    ~GeoJSONStagingUploadWnd();

public:
    void startAction(QStringList paths);

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::GeoJSONStagingUploadWnd *ui;
};

