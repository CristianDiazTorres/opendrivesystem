#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class XODRFilesUpdateWnd;
}

class XODRFilesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit XODRFilesUpdateWnd(QWidget *parent = 0);
    ~XODRFilesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::XODRFilesUpdateWnd *ui;
};

