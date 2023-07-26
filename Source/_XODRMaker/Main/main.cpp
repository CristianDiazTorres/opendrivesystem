#include "MainWnd.h"
#include <QApplication>
#include <QSqlDatabase>
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include "DB/Main/GlobalSettingsOnPGDatabase.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "DB/Main/LocalFilesDatabaseSettings.h"
#include "GPS/GPSSettingsOnPGDatabase.h"
#include "Trajectory/TrajectorySettingsOnPGDatabase.h"
#include "OSM/CountryArea/OSMCountryAreaSettingsOnPGDatabase.h"
#include "OSM/Way/OSMWaySettingsOnPGDatabase.h"
#include "OSM/Node/OSMNodeSettingsOnPGDatabase.h"
#include "XODR/Main/XODRSettingsOnPGDatabase.h"
#include "SetPGDatabaseSettingDlg.h"
#include "SetLocalFilesDatabasePathDlg.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "OSM/CountryArea/OSMCountryAreaTablesUpdateThread.h"
#include "GPS/GPSTablesUpdateThread.h"
#include "Trajectory/TrajectoryTablesUpdateThread.h"
#include "OSM/Way/OSMWayTablesUpdateThread.h"
#include "OSM/Node/OSMNodeTablesUpdateThread.h"
#include "GeoJSON/GeoJSONStagingUploadThread.h"
#include "GeoJSON/GeoJSONApplyingThread.h"
#include "GeoJSON/GeoJSONApplyingTestThread.h"
#include "XODR/Main/XODRTablesUpdateThread.h"
#include "CurvatureSlope/CurvatureSlopeTablesUpdateThread.h"
#include "XODR/Main/XODRFilesUpdateThread.h"
#include "XODR/Main/JSONFilesUpdateThread.h"

void saveTestData()
{
    _NOD::OpenDRIVE od;
    od.setTestData();
    od.write("C:/_/FullTest.xml", true);
    od.writeToJson("C:/_/FullTest.json", true);
}

void saveGeoJsonTemplateData()
{
    QString path = "C:/_/OpenDRIVESystem/GeoJSONTemplate";

    QJsonObject pointObj;

    {
        QJsonArray arr;
        arr.append(125.6);
        arr.append(10);

        pointObj["type"] = "Point";
        pointObj["coordinates"] = arr;
    }

    QJsonObject lineObj;

    {
        QJsonArray arr, arr1, arr2;
        arr1.append(125.6);
        arr1.append(10);
        arr2.append(125.7);
        arr2.append(10.1);

        arr.append(arr1);
        arr.append(arr2);
        lineObj["type"] = "LineString";
        lineObj["coordinates"] = arr;
    }

    _NOD::t_junction().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_junctionGroup().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_junctionGroup_junctionReference().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_connection().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_connection_laneLink().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_controller().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_predecessorSuccessor().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_priority().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_surface().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_junction_surface_CRG().saveGeoJsonTemplateData(path, pointObj);

    _NOD::t_road_lanes().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneOffset().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_center().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_center_lane().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_link().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark_explicit().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark_sway().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark_type().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark_type_line().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_left().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_left_lane().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_access().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_border().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_height().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_material().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_rule().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_speed().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_lr_lane_width().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_right().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lanes_laneSection_right_lane().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_laneValidity().saveGeoJsonTemplateData(path, pointObj);

    _NOD::t_road_objects().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_bridge().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_objectReference().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_borders().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_borders_border().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_markings().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_markings_marking().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_markings_marking_cornerReference().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_material().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_outlines().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_outlines_outline().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_outlines_outline_cornerLocal().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_outlines_outline_cornerRoad().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_parkingSpace().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_object_repeat().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_objects_tunnel().saveGeoJsonTemplateData(path, pointObj);

    _NOD::t_road_railroad().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_railroad_switch().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_railroad_switch_mainTrack().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_railroad_switch_partner().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_railroad_switch_sideTrack().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_railroad_switch_track().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_station().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_station_platform().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_station_platform_segment().saveGeoJsonTemplateData(path, pointObj);

    _NOD::t_road().saveGeoJsonTemplateData(path, lineObj);
    _NOD::t_road_elevationProfile_elevation().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lateralProfile_shape().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_lateralProfile_superelevation().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_link_predecessorSuccessor().saveGeoJsonTemplateData(path, lineObj);
    _NOD::t_road_planView().saveGeoJsonTemplateData(path, lineObj);
    _NOD::t_road_surface_CRG().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_type().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_type_speed().saveGeoJsonTemplateData(path, pointObj);

    //_NOD::t_controller().saveGeoJsonTemplateData(path, pointObj);
    //_NOD::t_controller_control().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signal().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signalReference().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signal_dependency().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signal_positionInertial().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signal_positionRoad().saveGeoJsonTemplateData(path, pointObj);
    _NOD::t_road_signals_signal_reference().saveGeoJsonTemplateData(path, pointObj);
}

void createStaticInstances()
{
    PGDatabaseConnector_createDefaultInstance;

    // Settings
    DatabaseSettingsOnLocalSystem_createDefaultInstance;

    GlobalSettingsOnPGDatabase_createDefaultInstance;
    UserSettingsOnPGDatabase_createDefaultInstance;

    GPSSettingsOnPGDatabase_createDefaultInstance;
    TrajectorySettingsOnPGDatabase_createDefaultInstance;
    OSMCountryAreaSettingsOnPGDatabase_createDefaultInstance;
    OSMNodeSettingsOnPGDatabase_createDefaultInstance;
    OSMWaySettingsOnPGDatabase_createDefaultInstance;
    XODRSettingsOnPGDatabase_createDefaultInstance;

    LocalFilesDatabaseSettings_createDefaultInstance;
}

void initStaticInstances()
{
    _NDebug::Logger::init();

    DatabaseSettingsOnLocalSystem_initDefaultInstance;

    if (!DatabaseSettingsOnLocalSystem_getDefaultInstance.isPGSettingsValid() || !PGDatabaseConnector_getDefaultInstance.reconnect())
    {
        SetPGDatabaseSettingDlg dlg;
        dlg.exec();
    }

    GlobalSettingsOnPGDatabase_initDefaultInstance;
    UserSettingsOnPGDatabase_initDefaultInstance;

    GPSSettingsOnPGDatabase_initDefaultInstance;
    TrajectorySettingsOnPGDatabase_initDefaultInstance;
    OSMCountryAreaSettingsOnPGDatabase_initDefaultInstance;
    OSMNodeSettingsOnPGDatabase_initDefaultInstance;
    OSMWaySettingsOnPGDatabase_initDefaultInstance;
    XODRSettingsOnPGDatabase_initDefaultInstance;

    if (UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath().isEmpty())
    {
        QString localFilesDatabasePath = QCoreApplication::applicationDirPath() + "/Database";
        UserSettingsOnPGDatabase_getDefaultInstance.setLocalFilesDatabasePath(localFilesDatabasePath);
        OSMWaySettingsOnPGDatabase_getDefaultInstance.setJsonPath(localFilesDatabasePath + "/OSM");
        OSMNodeSettingsOnPGDatabase_getDefaultInstance.setJsonPath(localFilesDatabasePath + "/OSM");

        SetLocalFilesDatabasePathDlg dlg;
        dlg.exec();
    }

    LocalFilesDatabaseSettings_initDefaultInstance;

    _NDebug::Logger::setLoggingEnabled(true);
    _NDebug::Logger::startLogging();
}

void stopStaticThreads()
{
    _NDebug::Logger::stopLogging();

    GPSTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    TrajectoryTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    OSMCountryAreaTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    OSMNodeTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    OSMWayTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    XODRTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
    XODRFilesUpdateThread_stopDefaultInstanceThreadIfAlive;
    JSONFilesUpdateThread_stopDefaultInstanceThreadIfAlive;
    GeoJSONStagingUploadThread_stopDefaultInstanceThreadIfAlive;
    GeoJSONApplyingThread_stopDefaultInstanceThreadIfAlive;
    GeoJSONApplyingTestThread_stopDefaultInstanceThreadIfAlive;
    CurvatureSlopeTablesUpdateThread_stopDefaultInstanceThreadIfAlive;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    createStaticInstances();



    initStaticInstances();

    MainWnd w;
    w.show();

    int ret = a.exec();

    stopStaticThreads();

    return ret;
}
