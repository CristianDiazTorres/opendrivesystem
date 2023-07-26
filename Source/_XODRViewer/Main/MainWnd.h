#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include "MapWnd.h"
#include "NavigateToLLDlg.h"
#include "NavigateToXYDlg.h"

namespace Ui {
class MainWnd;
}

class MainWnd : public QMainWindow
{
    Q_OBJECT

protected:
    MapWnd mapWindow;
    NavigateToLLDlg navigateToLLDialog;
    NavigateToXYDlg navigateToXYDialog;

    QLabel fullLabel;


public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

private slots:
    void onUpdatedMapStatus();

    void on_actionToLatLon_triggered();
    void on_actionToXY_triggered();

    void on_actionMapWnd_toggled(bool checked);

    void on_actionPGDBSetting_triggered();
    void on_actionLocalFilesDatabasePath_triggered();

private:
    Ui::MainWnd *ui;
};
