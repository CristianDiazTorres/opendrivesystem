#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include "Debugger/Main/LogInfo.h"

namespace Ui {
class OSMCountryAreaTablesUpdateWnd;
}

class OSMCountryAreaTablesUpdateWnd : public QWidget
{
    Q_OBJECT

public:
    explicit OSMCountryAreaTablesUpdateWnd(QWidget *parent = 0);
    ~OSMCountryAreaTablesUpdateWnd();

public:
    void startAction();

public slots:
    void onAddLog(_NDebug::LogInfo logInfo);
    void onProgressUpdated(int progress);
    void onThreadPostLoopFinished();

private:
    Ui::OSMCountryAreaTablesUpdateWnd *ui;
};
