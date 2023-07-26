#include "MainWnd.h"
#include "ui_MainWnd.h"
#include "SetPGDatabaseSettingDlg.h"
#include "SetLocalFilesDatabasePathDlg.h"
#include <QMessageBox>
#include "DB/Main/PGDatabaseConnector.h"
#include "OSM/CountryArea/OSMCountryAreaTablesUpdateThread.h"
#include "_XODRMaker/GPS/NewGPSDataChooseDlg.h"
#include "GPS/GPSTablesUpdateThread.h"
#include "Trajectory/TrajectoryTablesUpdateThread.h"
#include "OSM/Way/OSMWayTablesUpdateThread.h"
#include "OSM/Node/OSMNodeTablesUpdateThread.h"
#include "XODR/Main/XODRTablesUpdateThread.h"
#include "_XODRMaker/CurvatureSlope/NewCurvatureSlopeDataChooseDlg.h"
#include "CurvatureSlope/CurvatureSlopeTablesUpdateThread.h"
#include "_XODRMaker/CountryArea/SetOSMCountryAreaSettingsDlg.h"
#include "XODR/Main/XODRFilesUpdateThread.h"
#include "XODR/Main/JSONFilesUpdateThread.h"
#include "GeoJSON/GeoJSONStagingUploadThread.h"
#include "GeoJSON/GeoJSONApplyingThread.h"
#include "GeoJSON/GeoJSONApplyingTestThread.h"
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

    osmCountryAreaTablesUpdateWndWrapper.setVisible(false);
    osmCountryAreaTablesUpdateWndWrapper.setWidget(&osmCountryAreaTablesUpdateWnd);
    osmCountryAreaTablesUpdateWndWrapper.setWindowTitle(osmCountryAreaTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &osmCountryAreaTablesUpdateWndWrapper);
    osmCountryAreaTablesUpdateWndWrapper.toggleViewAction()->setText("Update OSM Country Area");
    ui->menuWindow->addAction(osmCountryAreaTablesUpdateWndWrapper.toggleViewAction());

    gpsTablesUpdateWndWrapper.setVisible(false);
    gpsTablesUpdateWndWrapper.setWidget(&gpsTablesUpdateWnd);
    gpsTablesUpdateWndWrapper.setWindowTitle(gpsTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &gpsTablesUpdateWndWrapper);
    gpsTablesUpdateWndWrapper.toggleViewAction()->setText("Update GPS");
    ui->menuWindow->addAction(gpsTablesUpdateWndWrapper.toggleViewAction());

    trajectoryTablesUpdateWndWrapper.setVisible(false);
    trajectoryTablesUpdateWndWrapper.setWidget(&trajectoryTablesUpdateWnd);
    trajectoryTablesUpdateWndWrapper.setWindowTitle(trajectoryTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &trajectoryTablesUpdateWndWrapper);
    trajectoryTablesUpdateWndWrapper.toggleViewAction()->setText("Update Trajectory");
    ui->menuWindow->addAction(trajectoryTablesUpdateWndWrapper.toggleViewAction());

    osmWayTablesUpdateWndWrapper.setVisible(false);
    osmWayTablesUpdateWndWrapper.setWidget(&osmWayTablesUpdateWnd);
    osmWayTablesUpdateWndWrapper.setWindowTitle(osmWayTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &osmWayTablesUpdateWndWrapper);
    osmWayTablesUpdateWndWrapper.toggleViewAction()->setText("Update OSM Way");
    ui->menuWindow->addAction(osmWayTablesUpdateWndWrapper.toggleViewAction());

    osmNodeTablesUpdateWndWrapper.setVisible(false);
    osmNodeTablesUpdateWndWrapper.setWidget(&osmNodeTablesUpdateWnd);
    osmNodeTablesUpdateWndWrapper.setWindowTitle(osmNodeTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &osmNodeTablesUpdateWndWrapper);
    osmNodeTablesUpdateWndWrapper.toggleViewAction()->setText("Update OSM Node");
    ui->menuWindow->addAction(osmNodeTablesUpdateWndWrapper.toggleViewAction());

    xodrTablesUpdateWndWrapper.setVisible(false);
    xodrTablesUpdateWndWrapper.setWidget(&xodrTablesUpdateWnd);
    xodrTablesUpdateWndWrapper.setWindowTitle(xodrTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &xodrTablesUpdateWndWrapper);
    xodrTablesUpdateWndWrapper.toggleViewAction()->setText("Update XODR");
    ui->menuWindow->addAction(xodrTablesUpdateWndWrapper.toggleViewAction());

    xodrFilesUpdateWndWrapper.setVisible(false);
    xodrFilesUpdateWndWrapper.setWidget(&xodrFilesUpdateWnd);
    xodrFilesUpdateWndWrapper.setWindowTitle(xodrFilesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &xodrFilesUpdateWndWrapper);
    xodrFilesUpdateWndWrapper.toggleViewAction()->setText("Update XODR Files");
    ui->menuWindow->addAction(xodrFilesUpdateWndWrapper.toggleViewAction());

    jsonFilesUpdateWndWrapper.setVisible(false);
    jsonFilesUpdateWndWrapper.setWidget(&jsonFilesUpdateWnd);
    jsonFilesUpdateWndWrapper.setWindowTitle(jsonFilesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &jsonFilesUpdateWndWrapper);
    jsonFilesUpdateWndWrapper.toggleViewAction()->setText("Update JSON Files");
    ui->menuWindow->addAction(jsonFilesUpdateWndWrapper.toggleViewAction());

    geoJSONStagingUploadWndWrapper.setVisible(false);
    geoJSONStagingUploadWndWrapper.setWidget(&geoJSONStagingUploadWnd);
    geoJSONStagingUploadWndWrapper.setWindowTitle(geoJSONStagingUploadWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &geoJSONStagingUploadWndWrapper);
    geoJSONStagingUploadWndWrapper.toggleViewAction()->setText("Upload GeoJSON Files");
    ui->menuWindow->addAction(geoJSONStagingUploadWndWrapper.toggleViewAction());

    geoJSONApplyingWndWrapper.setVisible(false);
    geoJSONApplyingWndWrapper.setWidget(&geoJSONApplyingWnd);
    geoJSONApplyingWndWrapper.setWindowTitle(geoJSONApplyingWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &geoJSONApplyingWndWrapper);
    geoJSONApplyingWndWrapper.toggleViewAction()->setText("Apply GeoJSON");
    ui->menuWindow->addAction(geoJSONApplyingWndWrapper.toggleViewAction());

    geoJSONApplyingTestWndWrapper.setVisible(false);
    geoJSONApplyingTestWndWrapper.setWidget(&geoJSONApplyingTestWnd);
    geoJSONApplyingTestWndWrapper.setWindowTitle(geoJSONApplyingTestWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &geoJSONApplyingTestWndWrapper);
    geoJSONApplyingTestWndWrapper.toggleViewAction()->setText("Generate GeoJSON Applying Test Files");
    ui->menuWindow->addAction(geoJSONApplyingTestWndWrapper.toggleViewAction());

    curvatureSlopeTablesUpdateWndWrapper.setVisible(false);
    curvatureSlopeTablesUpdateWndWrapper.setWidget(&curvatureSlopeTablesUpdateWnd);
    curvatureSlopeTablesUpdateWndWrapper.setWindowTitle(curvatureSlopeTablesUpdateWnd.windowTitle());
    this->addDockWidget(Qt::RightDockWidgetArea, &curvatureSlopeTablesUpdateWndWrapper);
    curvatureSlopeTablesUpdateWndWrapper.toggleViewAction()->setText("Update Curvature & Slope");
    ui->menuWindow->addAction(curvatureSlopeTablesUpdateWndWrapper.toggleViewAction());
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

void MainWnd::on_actionUpdateOSMCountryArea_triggered()
{
    if (OSMCountryAreaTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    osmCountryAreaTablesUpdateWnd.startAction();

    osmCountryAreaTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearOSMCountryAreaAndDependencies_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMCountryAreaAndDependencies();
}

void MainWnd::on_actionClearOSMCountryArea_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMCountryArea();
}

void MainWnd::on_actionOSMCountryAreaSettings_triggered()
{
    SetOSMCountryAreaSettingsDlg dlg(this);
    dlg.exec();
}

void MainWnd::on_actionUpdateGPSFromFile_triggered()
{
    if (GPSTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    NewGPSDataChooseDlg dlg(this);
    if (!dlg.exec())
        return;

    gpsTablesUpdateWnd.startAction(dlg.getGPSFilePath());

    gpsTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearGPSAndDependencies_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearGPSAndDependencies();
}

void MainWnd::on_actionClearGPS_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearGPS();
}

void MainWnd::on_actionGPSSettings_triggered()
{

}

void MainWnd::on_actionUpdateTrajectory_triggered()
{
    if (TrajectoryTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    trajectoryTablesUpdateWnd.startAction();

    trajectoryTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearTrajectoryAndDependencies_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearTrajectoryAndDependencies();
}

void MainWnd::on_actionClearTrajectory_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearTrajectory();
}

void MainWnd::on_actionTrajectorySettings_triggered()
{

}

void MainWnd::on_actionUpdateOSMWay_triggered()
{
    if (OSMWayTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    osmWayTablesUpdateWnd.startAction();

    osmWayTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearOSMWayAndDependencies_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMWayAndDependencies();
}

void MainWnd::on_actionClearOSMWay_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMWay();
}

void MainWnd::on_actionOSMWaySettings_triggered()
{

}

void MainWnd::on_actionUpdateOSMNode_triggered()
{
    if (OSMNodeTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    osmNodeTablesUpdateWnd.startAction();

    osmNodeTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearOSMNodeAndDependencies_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMNodeAndDependencies();
}

void MainWnd::on_actionClearOSMNode_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearOSMNode();
}

void MainWnd::on_actionOSMNodeSettings_triggered()
{

}

void MainWnd::on_actionUpdateXODRTablesUsingBasicTables_triggered()
{
    if (XODRTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    xodrTablesUpdateWnd.startAction(true);

    xodrTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionUpdateXODRTablesDirectlyUsingGPSFile_triggered()
{
    if (XODRTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    NewGPSDataChooseDlg dlg(this);
    if (!dlg.exec())
        return;

    xodrTablesUpdateWnd.startAction(false, dlg.getGPSFilePath());

    xodrTablesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionUpdateXODRFilesFromTable_triggered()
{
    if (XODRFilesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    xodrFilesUpdateWnd.startAction();

    xodrFilesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionUpdateJSONFromTable_triggered()
{
    if (JSONFilesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    jsonFilesUpdateWnd.startAction();

    jsonFilesUpdateWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearXODR_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearXODR();
}

void MainWnd::on_actionXODRSettings_triggered()
{

}

void MainWnd::on_actionUploadGeoJSONFiles_triggered()
{
    if (GeoJSONStagingUploadThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptOpen);
    fileDlg.setFileMode(QFileDialog::ExistingFiles);

    if (!fileDlg.exec())
        return;

    if (fileDlg.selectedFiles().isEmpty())
        return;

    geoJSONStagingUploadWnd.startAction(fileDlg.selectedFiles());

    geoJSONStagingUploadWndWrapper.setVisible(true);
}

void MainWnd::on_actionUploadGeoJSONFolders_triggered()
{
    if (GeoJSONStagingUploadThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptOpen);
    fileDlg.setFileMode(QFileDialog::Directory);

    if (!fileDlg.exec())
        return;

    if (fileDlg.selectedFiles().isEmpty())
        return;

    geoJSONStagingUploadWnd.startAction(fileDlg.selectedFiles());

    geoJSONStagingUploadWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearGeoJSONStaging_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearGeoJSONStaging();
}

void MainWnd::on_actionApplyGeoJSON_triggered()
{
    if (GeoJSONApplyingThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    geoJSONApplyingWnd.startAction();

    geoJSONApplyingWndWrapper.setVisible(true);
}

void MainWnd::on_actionClearGeoJSONApplying_triggered()
{
    PGDatabaseConnector_getDefaultInstance.clearGeoJSONApplying();
}

void MainWnd::on_actionGenerateGeoJSONApplyingTestFiles_triggered()
{
    if (GeoJSONApplyingTestThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    geoJSONApplyingTestWnd.startAction();

    geoJSONApplyingTestWndWrapper.setVisible(true);
}

void MainWnd::on_actionUpdateCurvatureSlope_triggered()
{
    if (CurvatureSlopeTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    NewCurvatureSlopeDataChooseDlg dlg(this);
    if (!dlg.exec())
        return;

    curvatureSlopeTablesUpdateWnd.startAction(dlg.getCurvatureSlopeDataPath());

    curvatureSlopeTablesUpdateWndWrapper.setVisible(true);
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
    if (OSMCountryAreaTablesUpdateThread_isDefaultInstanceAlive
        || GPSTablesUpdateThread_isDefaultInstanceAlive
        || TrajectoryTablesUpdateThread_isDefaultInstanceAlive
        || OSMWayTablesUpdateThread_isDefaultInstanceAlive
        || OSMNodeTablesUpdateThread_isDefaultInstanceAlive
        || XODRTablesUpdateThread_isDefaultInstanceAlive
        || XODRFilesUpdateThread_isDefaultInstanceAlive
        || JSONFilesUpdateThread_isDefaultInstanceAlive
        || GeoJSONStagingUploadThread_isDefaultInstanceAlive
        || GeoJSONApplyingThread_isDefaultInstanceAlive
        || GeoJSONApplyingTestThread_isDefaultInstanceAlive
        || CurvatureSlopeTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    SetPGDatabaseSettingDlg dlg(this);
    dlg.exec();
}

void MainWnd::on_actionLocalFilesDatabasePath_triggered()
{
    if (OSMCountryAreaTablesUpdateThread_isDefaultInstanceAlive
        || GPSTablesUpdateThread_isDefaultInstanceAlive
        || TrajectoryTablesUpdateThread_isDefaultInstanceAlive
        || OSMWayTablesUpdateThread_isDefaultInstanceAlive
        || OSMNodeTablesUpdateThread_isDefaultInstanceAlive
        || XODRTablesUpdateThread_isDefaultInstanceAlive
        || XODRFilesUpdateThread_isDefaultInstanceAlive
        || JSONFilesUpdateThread_isDefaultInstanceAlive
        || GeoJSONStagingUploadThread_isDefaultInstanceAlive
        || GeoJSONApplyingThread_isDefaultInstanceAlive
        || GeoJSONApplyingTestThread_isDefaultInstanceAlive
        || CurvatureSlopeTablesUpdateThread_isDefaultInstanceAlive)
    {
        QMessageBox::warning(this, "Warning", "There is a running thread");
        return;
    }

    SetLocalFilesDatabasePathDlg dlg(this);
    dlg.exec();
}


