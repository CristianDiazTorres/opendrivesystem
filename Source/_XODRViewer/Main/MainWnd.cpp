#include "MainWnd.h"
#include "ui_MainWnd.h"
#include "SetPGDatabaseSettingDlg.h"
#include "SetLocalFilesDatabasePathDlg.h"
#include <QMessageBox>
#include "DB/Main/PGDatabaseConnector.h"
#include <QFileDialog>

MainWnd::MainWnd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWnd)
{
    ui->setupUi(this);

    this->setCentralWidget(&mapWindow);
    connect(&mapWindow, SIGNAL(updateStatus()), this, SLOT(onUpdatedMapStatus()));
    connect(ui->actionGPSDataLayer, SIGNAL(toggled(bool)), &mapWindow, SLOT(onShowGPSLayer(bool)));
    connect(ui->actionTrajectoryLayer, SIGNAL(toggled(bool)), &mapWindow, SLOT(onShowTrajectoryLayer(bool)));
    connect(ui->actionOSMWayLayer, SIGNAL(toggled(bool)), &mapWindow, SLOT(onShowOSMWayLayer(bool)));
    connect(ui->actionOpenDRIVERoadLayer, SIGNAL(toggled(bool)), &mapWindow, SLOT(onShowOpenDRIVERoadLayer(bool)));

    connect(&navigateToLLDialog, SIGNAL(doNavigate(double,double)), &mapWindow, SLOT(onDoNaviate(double,double)));
    navigateToLLDialog.setVisible(false);

    connect(&navigateToXYDialog, SIGNAL(doNavigate(double,double)), &mapWindow, SLOT(onDoNaviate(double,double)));
    navigateToXYDialog.setVisible(false);

    //fullLabel.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //fullLabel.setReadOnly(true);
    this->statusBar()->addPermanentWidget(&fullLabel);
}

MainWnd::~MainWnd()
{
    delete ui;
}

void MainWnd::onUpdatedMapStatus()
{
    QString text;
    text.sprintf(" Size: (%d, %d px)"
                 ", Center: (%.1f, %.1f meters)"
                 ", Bound: (%.1f, %.1f, %.1f, %.1f meters)"
                 ", Center Cell: (%d, %d)"
                 ", Mouse: (%.1f, %.1f px)"
                 ", (%.1f, %.1f meters)"
                 ", Cell: (%d, %d)"
                 " "
                 , mapWindow.width(), mapWindow.height()
                 , mapWindow.centerPos.x(), mapWindow.centerPos.y()
                 , mapWindow.boundInMeter.left(), mapWindow.boundInMeter.top(), mapWindow.boundInMeter.right(), mapWindow.boundInMeter.bottom()
                 , mapWindow.centerPos.cellRow, mapWindow.centerPos.cellCol
                 , mapWindow.curPosInPx.x(), mapWindow.curPosInPx.y()
                 , mapWindow.curPos.x(), mapWindow.curPos.y()
                 , mapWindow.curPos.cellRow, mapWindow.curPos.cellCol);
    fullLabel.setText(text);
}

void MainWnd::on_actionToLatLon_triggered()
{
    navigateToXYDialog.hide();
    navigateToLLDialog.show();
}

void MainWnd::on_actionToXY_triggered()
{
    navigateToLLDialog.hide();
    navigateToXYDialog.setCurCenterPos(mapWindow.centerPos);
    navigateToXYDialog.show();
}

void MainWnd::on_actionMapWnd_toggled(bool checked)
{
    mapWindow.setVisible(checked);
}

void MainWnd::on_actionPGDBSetting_triggered()
{
    SetPGDatabaseSettingDlg dlg(this);
    dlg.exec();
}

void MainWnd::on_actionLocalFilesDatabasePath_triggered()
{
    SetLocalFilesDatabasePathDlg dlg(this);
    dlg.exec();
}


