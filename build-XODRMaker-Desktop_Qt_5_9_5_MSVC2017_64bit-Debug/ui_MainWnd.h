/********************************************************************************
** Form generated from reading UI file 'MainWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWND_H
#define UI_MAINWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWnd
{
public:
    QAction *actionMapWnd;
    QAction *actionUpdateXODRTablesUsingBasicTables;
    QAction *actionLocalFilesDatabasePath;
    QAction *actionGPSDataLayer;
    QAction *actionTrajectoryLayer;
    QAction *actionOSMWayLayer;
    QAction *actionOpenDRIVERoadLayer;
    QAction *actionToLatLon;
    QAction *actionToXY;
    QAction *actionPGDBSetting;
    QAction *actionUpdateOSMCountryArea;
    QAction *actionUpdateGPSFromFile;
    QAction *actionUpdateCurvatureSlope;
    QAction *actionUpdateTrajectory;
    QAction *actionOSMSettings;
    QAction *actionUpdateOSMNode;
    QAction *actionClearOSMCountryAreaAndDependencies;
    QAction *actionClearOSMCountryArea;
    QAction *actionOSMCountryAreaSettings;
    QAction *actionClearGPSAndDependencies;
    QAction *actionClearGPS;
    QAction *actionGPSSettings;
    QAction *actionClearTrajectoryAndDependencies;
    QAction *actionClearTrajectory;
    QAction *actionTrajectorySettings;
    QAction *actionUpdateOSMWay;
    QAction *actionClearOSMWayAndDependencies;
    QAction *actionClearOSMWay;
    QAction *actionOSMWaySettings;
    QAction *actionClearOSMNodeAndDependencies;
    QAction *actionClearOSMNode;
    QAction *actionOSMNodeSettings;
    QAction *actionClearXODR;
    QAction *actionXODRSettings;
    QAction *actionUpdateXODRTablesDirectlyUsingGPSFile;
    QAction *actionUpdateXODRFilesFromTable;
    QAction *actionUpdateJSONFromTable;
    QAction *actionUploadGeoJSONFiles;
    QAction *actionClearGeoJSONStaging;
    QAction *actionUploadGeoJSONFolders;
    QAction *actionApplyGeoJSON;
    QAction *actionClearGeoJSONApplying;
    QAction *actionGenerateGeoJSONApplyingTestFiles;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuWindow;
    QMenu *menuSetting;
    QMenu *menuView;
    QMenu *menuNavigate;
    QMenu *menuCountryArea;
    QMenu *menuOSMCountryArea;
    QMenu *menuGPS;
    QMenu *menuTrajectory;
    QMenu *menuWay;
    QMenu *menuOSMWay;
    QMenu *menuNode;
    QMenu *menuOSMNode;
    QMenu *menuXODR;
    QMenu *menuCurvatureSlope;
    QMenu *menuGeoJSON_Staging;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWnd)
    {
        if (MainWnd->objectName().isEmpty())
            MainWnd->setObjectName(QStringLiteral("MainWnd"));
        MainWnd->resize(907, 524);
        actionMapWnd = new QAction(MainWnd);
        actionMapWnd->setObjectName(QStringLiteral("actionMapWnd"));
        actionMapWnd->setCheckable(true);
        actionMapWnd->setChecked(true);
        actionUpdateXODRTablesUsingBasicTables = new QAction(MainWnd);
        actionUpdateXODRTablesUsingBasicTables->setObjectName(QStringLiteral("actionUpdateXODRTablesUsingBasicTables"));
        actionLocalFilesDatabasePath = new QAction(MainWnd);
        actionLocalFilesDatabasePath->setObjectName(QStringLiteral("actionLocalFilesDatabasePath"));
        actionGPSDataLayer = new QAction(MainWnd);
        actionGPSDataLayer->setObjectName(QStringLiteral("actionGPSDataLayer"));
        actionGPSDataLayer->setCheckable(true);
        actionGPSDataLayer->setChecked(true);
        actionTrajectoryLayer = new QAction(MainWnd);
        actionTrajectoryLayer->setObjectName(QStringLiteral("actionTrajectoryLayer"));
        actionTrajectoryLayer->setCheckable(true);
        actionTrajectoryLayer->setChecked(true);
        actionOSMWayLayer = new QAction(MainWnd);
        actionOSMWayLayer->setObjectName(QStringLiteral("actionOSMWayLayer"));
        actionOSMWayLayer->setCheckable(true);
        actionOSMWayLayer->setChecked(true);
        actionOpenDRIVERoadLayer = new QAction(MainWnd);
        actionOpenDRIVERoadLayer->setObjectName(QStringLiteral("actionOpenDRIVERoadLayer"));
        actionOpenDRIVERoadLayer->setCheckable(true);
        actionOpenDRIVERoadLayer->setChecked(true);
        actionToLatLon = new QAction(MainWnd);
        actionToLatLon->setObjectName(QStringLiteral("actionToLatLon"));
        actionToXY = new QAction(MainWnd);
        actionToXY->setObjectName(QStringLiteral("actionToXY"));
        actionPGDBSetting = new QAction(MainWnd);
        actionPGDBSetting->setObjectName(QStringLiteral("actionPGDBSetting"));
        actionUpdateOSMCountryArea = new QAction(MainWnd);
        actionUpdateOSMCountryArea->setObjectName(QStringLiteral("actionUpdateOSMCountryArea"));
        actionUpdateGPSFromFile = new QAction(MainWnd);
        actionUpdateGPSFromFile->setObjectName(QStringLiteral("actionUpdateGPSFromFile"));
        actionUpdateCurvatureSlope = new QAction(MainWnd);
        actionUpdateCurvatureSlope->setObjectName(QStringLiteral("actionUpdateCurvatureSlope"));
        actionUpdateTrajectory = new QAction(MainWnd);
        actionUpdateTrajectory->setObjectName(QStringLiteral("actionUpdateTrajectory"));
        actionOSMSettings = new QAction(MainWnd);
        actionOSMSettings->setObjectName(QStringLiteral("actionOSMSettings"));
        actionUpdateOSMNode = new QAction(MainWnd);
        actionUpdateOSMNode->setObjectName(QStringLiteral("actionUpdateOSMNode"));
        actionClearOSMCountryAreaAndDependencies = new QAction(MainWnd);
        actionClearOSMCountryAreaAndDependencies->setObjectName(QStringLiteral("actionClearOSMCountryAreaAndDependencies"));
        actionClearOSMCountryArea = new QAction(MainWnd);
        actionClearOSMCountryArea->setObjectName(QStringLiteral("actionClearOSMCountryArea"));
        actionOSMCountryAreaSettings = new QAction(MainWnd);
        actionOSMCountryAreaSettings->setObjectName(QStringLiteral("actionOSMCountryAreaSettings"));
        actionClearGPSAndDependencies = new QAction(MainWnd);
        actionClearGPSAndDependencies->setObjectName(QStringLiteral("actionClearGPSAndDependencies"));
        actionClearGPS = new QAction(MainWnd);
        actionClearGPS->setObjectName(QStringLiteral("actionClearGPS"));
        actionGPSSettings = new QAction(MainWnd);
        actionGPSSettings->setObjectName(QStringLiteral("actionGPSSettings"));
        actionClearTrajectoryAndDependencies = new QAction(MainWnd);
        actionClearTrajectoryAndDependencies->setObjectName(QStringLiteral("actionClearTrajectoryAndDependencies"));
        actionClearTrajectory = new QAction(MainWnd);
        actionClearTrajectory->setObjectName(QStringLiteral("actionClearTrajectory"));
        actionTrajectorySettings = new QAction(MainWnd);
        actionTrajectorySettings->setObjectName(QStringLiteral("actionTrajectorySettings"));
        actionUpdateOSMWay = new QAction(MainWnd);
        actionUpdateOSMWay->setObjectName(QStringLiteral("actionUpdateOSMWay"));
        actionClearOSMWayAndDependencies = new QAction(MainWnd);
        actionClearOSMWayAndDependencies->setObjectName(QStringLiteral("actionClearOSMWayAndDependencies"));
        actionClearOSMWay = new QAction(MainWnd);
        actionClearOSMWay->setObjectName(QStringLiteral("actionClearOSMWay"));
        actionOSMWaySettings = new QAction(MainWnd);
        actionOSMWaySettings->setObjectName(QStringLiteral("actionOSMWaySettings"));
        actionClearOSMNodeAndDependencies = new QAction(MainWnd);
        actionClearOSMNodeAndDependencies->setObjectName(QStringLiteral("actionClearOSMNodeAndDependencies"));
        actionClearOSMNode = new QAction(MainWnd);
        actionClearOSMNode->setObjectName(QStringLiteral("actionClearOSMNode"));
        actionOSMNodeSettings = new QAction(MainWnd);
        actionOSMNodeSettings->setObjectName(QStringLiteral("actionOSMNodeSettings"));
        actionClearXODR = new QAction(MainWnd);
        actionClearXODR->setObjectName(QStringLiteral("actionClearXODR"));
        actionXODRSettings = new QAction(MainWnd);
        actionXODRSettings->setObjectName(QStringLiteral("actionXODRSettings"));
        actionUpdateXODRTablesDirectlyUsingGPSFile = new QAction(MainWnd);
        actionUpdateXODRTablesDirectlyUsingGPSFile->setObjectName(QStringLiteral("actionUpdateXODRTablesDirectlyUsingGPSFile"));
        actionUpdateXODRFilesFromTable = new QAction(MainWnd);
        actionUpdateXODRFilesFromTable->setObjectName(QStringLiteral("actionUpdateXODRFilesFromTable"));
        actionUpdateJSONFromTable = new QAction(MainWnd);
        actionUpdateJSONFromTable->setObjectName(QStringLiteral("actionUpdateJSONFromTable"));
        actionUpdateJSONFromTable->setEnabled(false);
        actionUploadGeoJSONFiles = new QAction(MainWnd);
        actionUploadGeoJSONFiles->setObjectName(QStringLiteral("actionUploadGeoJSONFiles"));
        actionClearGeoJSONStaging = new QAction(MainWnd);
        actionClearGeoJSONStaging->setObjectName(QStringLiteral("actionClearGeoJSONStaging"));
        actionUploadGeoJSONFolders = new QAction(MainWnd);
        actionUploadGeoJSONFolders->setObjectName(QStringLiteral("actionUploadGeoJSONFolders"));
        actionApplyGeoJSON = new QAction(MainWnd);
        actionApplyGeoJSON->setObjectName(QStringLiteral("actionApplyGeoJSON"));
        actionClearGeoJSONApplying = new QAction(MainWnd);
        actionClearGeoJSONApplying->setObjectName(QStringLiteral("actionClearGeoJSONApplying"));
        actionGenerateGeoJSONApplyingTestFiles = new QAction(MainWnd);
        actionGenerateGeoJSONApplyingTestFiles->setObjectName(QStringLiteral("actionGenerateGeoJSONApplyingTestFiles"));
        centralWidget = new QWidget(MainWnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWnd->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWnd);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 907, 21));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuNavigate = new QMenu(menuBar);
        menuNavigate->setObjectName(QStringLiteral("menuNavigate"));
        menuCountryArea = new QMenu(menuBar);
        menuCountryArea->setObjectName(QStringLiteral("menuCountryArea"));
        menuOSMCountryArea = new QMenu(menuCountryArea);
        menuOSMCountryArea->setObjectName(QStringLiteral("menuOSMCountryArea"));
        menuGPS = new QMenu(menuBar);
        menuGPS->setObjectName(QStringLiteral("menuGPS"));
        menuTrajectory = new QMenu(menuBar);
        menuTrajectory->setObjectName(QStringLiteral("menuTrajectory"));
        menuWay = new QMenu(menuBar);
        menuWay->setObjectName(QStringLiteral("menuWay"));
        menuOSMWay = new QMenu(menuWay);
        menuOSMWay->setObjectName(QStringLiteral("menuOSMWay"));
        menuNode = new QMenu(menuBar);
        menuNode->setObjectName(QStringLiteral("menuNode"));
        menuOSMNode = new QMenu(menuNode);
        menuOSMNode->setObjectName(QStringLiteral("menuOSMNode"));
        menuXODR = new QMenu(menuBar);
        menuXODR->setObjectName(QStringLiteral("menuXODR"));
        menuCurvatureSlope = new QMenu(menuBar);
        menuCurvatureSlope->setObjectName(QStringLiteral("menuCurvatureSlope"));
        menuGeoJSON_Staging = new QMenu(menuBar);
        menuGeoJSON_Staging->setObjectName(QStringLiteral("menuGeoJSON_Staging"));
        MainWnd->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWnd);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWnd->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWnd);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWnd->setStatusBar(statusBar);

        menuBar->addAction(menuCountryArea->menuAction());
        menuBar->addAction(menuGPS->menuAction());
        menuBar->addAction(menuTrajectory->menuAction());
        menuBar->addAction(menuWay->menuAction());
        menuBar->addAction(menuNode->menuAction());
        menuBar->addAction(menuXODR->menuAction());
        menuBar->addAction(menuGeoJSON_Staging->menuAction());
        menuBar->addAction(menuCurvatureSlope->menuAction());
        menuBar->addAction(menuNavigate->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuWindow->addAction(actionMapWnd);
        menuSetting->addAction(actionPGDBSetting);
        menuSetting->addAction(actionLocalFilesDatabasePath);
        menuView->addAction(actionGPSDataLayer);
        menuView->addAction(actionTrajectoryLayer);
        menuView->addAction(actionOSMWayLayer);
        menuView->addAction(actionOpenDRIVERoadLayer);
        menuNavigate->addAction(actionToLatLon);
        menuNavigate->addAction(actionToXY);
        menuCountryArea->addAction(menuOSMCountryArea->menuAction());
        menuOSMCountryArea->addAction(actionUpdateOSMCountryArea);
        menuOSMCountryArea->addAction(actionClearOSMCountryAreaAndDependencies);
        menuOSMCountryArea->addAction(actionClearOSMCountryArea);
        menuOSMCountryArea->addAction(actionOSMCountryAreaSettings);
        menuGPS->addAction(actionUpdateGPSFromFile);
        menuGPS->addAction(actionClearGPSAndDependencies);
        menuGPS->addAction(actionClearGPS);
        menuGPS->addAction(actionGPSSettings);
        menuTrajectory->addAction(actionUpdateTrajectory);
        menuTrajectory->addAction(actionClearTrajectoryAndDependencies);
        menuTrajectory->addAction(actionClearTrajectory);
        menuTrajectory->addAction(actionTrajectorySettings);
        menuWay->addAction(menuOSMWay->menuAction());
        menuOSMWay->addAction(actionUpdateOSMWay);
        menuOSMWay->addAction(actionClearOSMWayAndDependencies);
        menuOSMWay->addAction(actionClearOSMWay);
        menuOSMWay->addAction(actionOSMWaySettings);
        menuNode->addAction(menuOSMNode->menuAction());
        menuOSMNode->addAction(actionUpdateOSMNode);
        menuOSMNode->addAction(actionClearOSMNodeAndDependencies);
        menuOSMNode->addAction(actionClearOSMNode);
        menuOSMNode->addAction(actionOSMNodeSettings);
        menuXODR->addAction(actionUpdateXODRTablesUsingBasicTables);
        menuXODR->addAction(actionUpdateXODRTablesDirectlyUsingGPSFile);
        menuXODR->addAction(actionUpdateXODRFilesFromTable);
        menuXODR->addAction(actionUpdateJSONFromTable);
        menuXODR->addAction(actionClearXODR);
        menuXODR->addAction(actionXODRSettings);
        menuCurvatureSlope->addAction(actionUpdateCurvatureSlope);
        menuGeoJSON_Staging->addAction(actionUploadGeoJSONFiles);
        menuGeoJSON_Staging->addAction(actionUploadGeoJSONFolders);
        menuGeoJSON_Staging->addAction(actionClearGeoJSONStaging);
        menuGeoJSON_Staging->addAction(actionApplyGeoJSON);
        menuGeoJSON_Staging->addAction(actionClearGeoJSONApplying);
        menuGeoJSON_Staging->addAction(actionGenerateGeoJSONApplyingTestFiles);

        retranslateUi(MainWnd);

        QMetaObject::connectSlotsByName(MainWnd);
    } // setupUi

    void retranslateUi(QMainWindow *MainWnd)
    {
        MainWnd->setWindowTitle(QApplication::translate("MainWnd", "OpenDRIVE System", Q_NULLPTR));
        actionMapWnd->setText(QApplication::translate("MainWnd", "Map Window", Q_NULLPTR));
        actionUpdateXODRTablesUsingBasicTables->setText(QApplication::translate("MainWnd", "Update table using basic tables", Q_NULLPTR));
        actionLocalFilesDatabasePath->setText(QApplication::translate("MainWnd", "Local Files Database Path", Q_NULLPTR));
        actionGPSDataLayer->setText(QApplication::translate("MainWnd", "GPS Data Layer", Q_NULLPTR));
        actionTrajectoryLayer->setText(QApplication::translate("MainWnd", "Trajectory Layer", Q_NULLPTR));
        actionOSMWayLayer->setText(QApplication::translate("MainWnd", "OSM Way Layer", Q_NULLPTR));
        actionOpenDRIVERoadLayer->setText(QApplication::translate("MainWnd", "OpenDRIVE Road Layer", Q_NULLPTR));
        actionToLatLon->setText(QApplication::translate("MainWnd", "To Lat Lon", Q_NULLPTR));
        actionToXY->setText(QApplication::translate("MainWnd", "To X Y", Q_NULLPTR));
        actionPGDBSetting->setText(QApplication::translate("MainWnd", "PostgreSQL Database Setting", Q_NULLPTR));
        actionUpdateOSMCountryArea->setText(QApplication::translate("MainWnd", "Update", Q_NULLPTR));
        actionUpdateGPSFromFile->setText(QApplication::translate("MainWnd", "Update from file", Q_NULLPTR));
        actionUpdateCurvatureSlope->setText(QApplication::translate("MainWnd", "Update from file", Q_NULLPTR));
        actionUpdateTrajectory->setText(QApplication::translate("MainWnd", "Update", Q_NULLPTR));
        actionOSMSettings->setText(QApplication::translate("MainWnd", "OSM Settings", Q_NULLPTR));
        actionUpdateOSMNode->setText(QApplication::translate("MainWnd", "Update", Q_NULLPTR));
        actionClearOSMCountryAreaAndDependencies->setText(QApplication::translate("MainWnd", "Clear this and dependencies", Q_NULLPTR));
        actionClearOSMCountryArea->setText(QApplication::translate("MainWnd", "Clear only this", Q_NULLPTR));
        actionOSMCountryAreaSettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionClearGPSAndDependencies->setText(QApplication::translate("MainWnd", "Clear this and dependencies", Q_NULLPTR));
        actionClearGPS->setText(QApplication::translate("MainWnd", "Clear only this", Q_NULLPTR));
        actionGPSSettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionClearTrajectoryAndDependencies->setText(QApplication::translate("MainWnd", "Clear this and dependencies", Q_NULLPTR));
        actionClearTrajectory->setText(QApplication::translate("MainWnd", "Clear only this", Q_NULLPTR));
        actionTrajectorySettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionUpdateOSMWay->setText(QApplication::translate("MainWnd", "Update", Q_NULLPTR));
        actionClearOSMWayAndDependencies->setText(QApplication::translate("MainWnd", "Clear this and dependencies", Q_NULLPTR));
        actionClearOSMWay->setText(QApplication::translate("MainWnd", "Clear only this", Q_NULLPTR));
        actionOSMWaySettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionClearOSMNodeAndDependencies->setText(QApplication::translate("MainWnd", "Clear this and dependencies", Q_NULLPTR));
        actionClearOSMNode->setText(QApplication::translate("MainWnd", "Clear only this", Q_NULLPTR));
        actionOSMNodeSettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionClearXODR->setText(QApplication::translate("MainWnd", "Clear", Q_NULLPTR));
        actionXODRSettings->setText(QApplication::translate("MainWnd", "Settings", Q_NULLPTR));
        actionUpdateXODRTablesDirectlyUsingGPSFile->setText(QApplication::translate("MainWnd", "Update table directly using gps file", Q_NULLPTR));
        actionUpdateXODRFilesFromTable->setText(QApplication::translate("MainWnd", "Update files from table", Q_NULLPTR));
        actionUpdateJSONFromTable->setText(QApplication::translate("MainWnd", "Update json from table", Q_NULLPTR));
        actionUploadGeoJSONFiles->setText(QApplication::translate("MainWnd", "Upload GeoJSON files", Q_NULLPTR));
        actionClearGeoJSONStaging->setText(QApplication::translate("MainWnd", "Clear GeoJSON Staging", Q_NULLPTR));
        actionUploadGeoJSONFolders->setText(QApplication::translate("MainWnd", "Upload GeoJSON folders", Q_NULLPTR));
        actionApplyGeoJSON->setText(QApplication::translate("MainWnd", "Apply GeoJSON", Q_NULLPTR));
        actionClearGeoJSONApplying->setText(QApplication::translate("MainWnd", "Clear GeoJSON Applying", Q_NULLPTR));
        actionGenerateGeoJSONApplyingTestFiles->setText(QApplication::translate("MainWnd", "Generate GeoJSON Applying Test Files", Q_NULLPTR));
        menuWindow->setTitle(QApplication::translate("MainWnd", "Window", Q_NULLPTR));
        menuSetting->setTitle(QApplication::translate("MainWnd", "Setting", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWnd", "View", Q_NULLPTR));
        menuNavigate->setTitle(QApplication::translate("MainWnd", "Navigate", Q_NULLPTR));
        menuCountryArea->setTitle(QApplication::translate("MainWnd", "Country Area", Q_NULLPTR));
        menuOSMCountryArea->setTitle(QApplication::translate("MainWnd", "OSM", Q_NULLPTR));
        menuGPS->setTitle(QApplication::translate("MainWnd", "GPS", Q_NULLPTR));
        menuTrajectory->setTitle(QApplication::translate("MainWnd", "Trajectory", Q_NULLPTR));
        menuWay->setTitle(QApplication::translate("MainWnd", "Way", Q_NULLPTR));
        menuOSMWay->setTitle(QApplication::translate("MainWnd", "OSM", Q_NULLPTR));
        menuNode->setTitle(QApplication::translate("MainWnd", "Node", Q_NULLPTR));
        menuOSMNode->setTitle(QApplication::translate("MainWnd", "OSM", Q_NULLPTR));
        menuXODR->setTitle(QApplication::translate("MainWnd", "XODR", Q_NULLPTR));
        menuCurvatureSlope->setTitle(QApplication::translate("MainWnd", "Curvature && Slope", Q_NULLPTR));
        menuGeoJSON_Staging->setTitle(QApplication::translate("MainWnd", "GeoJSON", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWnd: public Ui_MainWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWND_H
