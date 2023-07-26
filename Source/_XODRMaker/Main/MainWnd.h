#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include "MapWnd.h"
#include "_XODRMaker/CountryArea/OSMCountryAreaTablesUpdateWnd.h"
#include "_XODRMaker/GPS/GPSTablesUpdateWnd.h"
#include "_XODRMaker/Trajectory/TrajectoryTablesUpdateWnd.h"
#include "_XODRMaker/Way/OSMWayTablesUpdateWnd.h"
#include "_XODRMaker/Node/OSMNodeTablesUpdateWnd.h"
#include "_XODRMaker/XODR/XODRTablesUpdateWnd.h"
#include "_XODRMaker/XODR/XODRFilesUpdateWnd.h"
#include "_XODRMaker/XODR/JSONFilesUpdateWnd.h"
#include "_XODRMaker/GeoJSON/GeoJSONStagingUploadWnd.h"
#include "_XODRMaker/GeoJSON/GeoJSONApplyingWnd.h"
#include "_XODRMaker/GeoJSON/GeoJSONApplyingTestWnd.h"
#include "_XODRMaker/CurvatureSlope/CurvatureSlopeTablesUpdateWnd.h"
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

    QDockWidget osmCountryAreaTablesUpdateWndWrapper;
    OSMCountryAreaTablesUpdateWnd osmCountryAreaTablesUpdateWnd;

    QDockWidget gpsTablesUpdateWndWrapper;
    GPSTablesUpdateWnd gpsTablesUpdateWnd;

    QDockWidget trajectoryTablesUpdateWndWrapper;
    TrajectoryTablesUpdateWnd trajectoryTablesUpdateWnd;

    QDockWidget osmWayTablesUpdateWndWrapper;
    OSMWayTablesUpdateWnd osmWayTablesUpdateWnd;

    QDockWidget osmNodeTablesUpdateWndWrapper;
    OSMNodeTablesUpdateWnd osmNodeTablesUpdateWnd;

    QDockWidget xodrTablesUpdateWndWrapper;
    XODRTablesUpdateWnd xodrTablesUpdateWnd;

    QDockWidget xodrFilesUpdateWndWrapper;
    XODRFilesUpdateWnd xodrFilesUpdateWnd;

    QDockWidget geoJSONStagingUploadWndWrapper;
    GeoJSONStagingUploadWnd geoJSONStagingUploadWnd;

    QDockWidget geoJSONApplyingWndWrapper;
    GeoJSONApplyingWnd geoJSONApplyingWnd;

    QDockWidget geoJSONApplyingTestWndWrapper;
    GeoJSONApplyingTestWnd geoJSONApplyingTestWnd;

    QDockWidget jsonFilesUpdateWndWrapper;
    JSONFilesUpdateWnd jsonFilesUpdateWnd;

    QDockWidget curvatureSlopeTablesUpdateWndWrapper;
    CurvatureSlopeTablesUpdateWnd curvatureSlopeTablesUpdateWnd;

    QLabel fullLabel;


public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

private slots:
    void onUpdatedMapStatus();

    void on_actionUpdateOSMCountryArea_triggered();
    void on_actionClearOSMCountryAreaAndDependencies_triggered();
    void on_actionClearOSMCountryArea_triggered();
    void on_actionOSMCountryAreaSettings_triggered();

    void on_actionUpdateGPSFromFile_triggered();
    void on_actionClearGPSAndDependencies_triggered();
    void on_actionClearGPS_triggered();
    void on_actionGPSSettings_triggered();

    void on_actionUpdateTrajectory_triggered();
    void on_actionClearTrajectoryAndDependencies_triggered();
    void on_actionClearTrajectory_triggered();
    void on_actionTrajectorySettings_triggered();

    void on_actionUpdateOSMWay_triggered();
    void on_actionClearOSMWayAndDependencies_triggered();
    void on_actionClearOSMWay_triggered();
    void on_actionOSMWaySettings_triggered();

    void on_actionUpdateOSMNode_triggered();
    void on_actionClearOSMNodeAndDependencies_triggered();
    void on_actionClearOSMNode_triggered();
    void on_actionOSMNodeSettings_triggered();

    void on_actionUpdateXODRTablesUsingBasicTables_triggered();
    void on_actionUpdateXODRTablesDirectlyUsingGPSFile_triggered();
    void on_actionUpdateXODRFilesFromTable_triggered();
    void on_actionUpdateJSONFromTable_triggered();
    void on_actionClearXODR_triggered();
    void on_actionXODRSettings_triggered();

    void on_actionUploadGeoJSONFiles_triggered();
    void on_actionUploadGeoJSONFolders_triggered();
    void on_actionClearGeoJSONStaging_triggered();
    void on_actionApplyGeoJSON_triggered();
    void on_actionClearGeoJSONApplying_triggered();
    void on_actionGenerateGeoJSONApplyingTestFiles_triggered();

    void on_actionUpdateCurvatureSlope_triggered();

    void on_actionToLatLon_triggered();
    void on_actionToXY_triggered();

    void on_actionMapWnd_toggled(bool checked);

    void on_actionPGDBSetting_triggered();
    void on_actionLocalFilesDatabasePath_triggered();

private:
    Ui::MainWnd *ui;
};
