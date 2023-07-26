#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class JSONFilesUpdateWnd;
}

class JSONFilesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit JSONFilesUpdateWnd(QWidget *parent = 0);
    ~JSONFilesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::JSONFilesUpdateWnd *ui;
};

