#-------------------------------------------------
#
# Project created by QtCreator 2021-04-11T20:41:28
#
#-------------------------------------------------

QT       += core gui xml network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XODRViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
    INCLUDEPATH += C:/
    LIBS += C:/OSGeo4W64/lib/proj.lib \
        C:/OSGeo4W64/lib/gdal_i.lib
} else {
    INCLUDEPATH += /usr/include/gdal
    LIBS += -lproj -lgdal
}

INCLUDEPATH += ./_Utils

OTHER_FILES += \
    _Utils/DB/pg_dump.sql \
    _Utils/DB/ReadMe.md \
    XODR/OpenDRIVE/xsd/opendrive_16_signal.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_road.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_railroad.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_object.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_lane.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_junction.xsd \
    XODR/OpenDRIVE/xsd/opendrive_16_core.xsd \
    XODR/OpenDRIVE/manual/6.5. Summary of all available coordinate systems.png \
    XODR/OpenDRIVE/manual/6.4. Local coordinate systems.png \
    XODR/OpenDRIVE/manual/6.3. Reference line coordinate systems.png \
    XODR/OpenDRIVE/manual/6.2. Inertial coordinate systems.png \
    XODR/OpenDRIVE/manual/6.1. Coordinate systems overview.png \
    XODR/OpenDRIVE/manual/OpenDRIVE 1.6_files/font-awesome.min.css \
    XODR/OpenDRIVE/manual/OpenDRIVE 1.6.html \
    XODR/OpenDRIVE/manual/OpenDRIVE 1.6_files/MathJax.js.download \
    OSM/Ref/Key_highway - OpenStreetMap Wiki.mhtml \
    OSM/Way/OSMWayTablesUpdateThread.txt \
    OSM/Node/OSMNodeTablesUpdateThread.txt \
    OSM/Ref/ways_vals_highway_width_sorted.txt \
    OSM/Ref/ways_vals_highway_width_compacted.txt \
    OSM/Ref/ways_vals_highway_width.txt \
    OSM/Ref/ways_vals_200_20_shrinked.txt \
    OSM/Ref/ways_vals_200_20.txt \
    OSM/Ref/ways_keys_only.txt \
    OSM/Ref/nodes_vals_200_20.txt \
    OSM/Ref/nodes_keys_only.txt

HEADERS += \
    _Utils/UniversialType/Main/UniversialType.h \
    _Utils/GeoCoordinate/Main/Cell.h \
    _Utils/GeoCoordinate/Main/LL.h \
    _Utils/GeoCoordinate/GeoCoordinate.h \
    _Utils/DB/DB.h \
    _Utils/DB/Internal/Internal.h \
    _Utils/Common/Internal/Internal.h \
    _Utils/DB/Main/SettingsOnPGDatabase.h \
    _Utils/DB/Main/PGDatabaseConnector.h \
    _Utils/Debugger/Main/Logger.h \
    _Utils/GeoCoordinate/Main/VehiclePos.h \
    _Utils/Common/Common.h \
    _Utils/Network/Main/HttpRequest.h \
    _Utils/Common/Main/DefaultInstance.h \
    _Utils/Debugger/Main/LoggingThread.h \
    _Utils/Thread/Main/Thread.h \
    _Utils/DB/Main/UserSettingsOnPGDatabase.h \
    _Utils/DB/Main/LocalFilesDatabaseSettings.h \
    _Utils/SettingsOnLocalSystem/Main/SettingsOnLocalSystem.h \
    _Utils/DB/Main/DatabaseSettingsOnLocalSystem.h \
    _Utils/DB/Main/GlobalSettingsOnPGDatabase.h \
    _Utils/Debugger/Main/LoggingSlotManager.h \
    _Utils/Common/Main/File.h \
    _Utils/Common/Main/DateTime.h \
    _Utils/GeoCoordinate/Main/CoordSysXYCell.h \
    _Utils/GeoCoordinate/Main/CoordSysCell.h \
    _Utils/GeoCoordinate/Main/CoordSys.h \
    _Utils/GeoCoordinate/Main/XYCell.h \
    _Utils/GeoCoordinate/Main/CoordSysXY.h \
    _Utils/GeoCoordinate/Main/LLCoordSysXYCell.h \
    _Utils/Math/Math.h \
    _Utils/UniversialType/Main/StringPairs.h \
    _Utils/Math/Main/XY.h \
    _Utils/Common/Main/Vector.h \
    _Utils/DB/Main/DatabaseConnector.h \
    _Utils/DB/Main/LocalFilesDatabaseConnector.h \
    _Utils/Math/Internal/Internal.h \
    _Utils/UniversialType/UniversialType.h \
    _Utils/UniversialType/Internal/Internal.h \
    _Utils/XML/XML.h \
    _Utils/XML/Main/XmlElement.h \
    _Utils/GeoCoordinate/Main/CardinalDirection.h \
    _Utils/Common/Main/StringContants.h \
    _Utils/Common/Main/String.h \
    _Utils/Debugger/Debugger.h \
    _Utils/Debugger/Main/LoggingTarget.h \
    _Utils/Math/Main/ClipperXY.h \
    _Utils/Math/Main/ClipperLL.h \
    _Utils/Math/Main/Clipper.h \
    _Utils/Math/Main/ClipperMacros.h \
    _Utils/XML/Main/XmlUtils_p.h \
    _Utils/XML/Main/XmlStream_p.h \
    _Utils/XML/Main/XmlStream.h \
    _Utils/XML/Internal/Internal.h \
    _Utils/Thread/Thread.h \
    _Utils/Thread/Internal/Internal.h \
    _Utils/SettingsOnLocalSystem/SettingsOnLocalSystem.h \
    _Utils/SettingsOnLocalSystem/Internal/Internal.h \
    _Utils/Network/Network.h \
    _Utils/Network/Internal/Internal.h \
    _Utils/Math/Main/QMatrix4x4D.h \
    _Utils/GeoCoordinate/Internal/Internal.h \
    _Utils/Debugger/Main/LogInfo.h \
    _Utils/Debugger/Internal/Internal.h \
    _Utils/Common/Main/JsonArray.h \
    _Utils/Common/Internal/Compile.h \
    XODR/OpenDRIVE/core/_OpenDriveElement.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_sway.h \
    XODR/OpenDRIVE/road/t_road_elevationProfile_elevation.h \
    XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline_cornerRoad.h \
    XODR/OpenDRIVE/object/t_road_objects_object_repeat.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_border.h \
    XODR/OpenDRIVE/road/t_road_lateralProfile_shape.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark.h \
    XODR/OpenDRIVE/road/t_road_lateralProfile_superelevation.h \
    XODR/OpenDRIVE/signal/t_road_signals_signalReference.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_access.h \
    XODR/OpenDRIVE/object/t_road_objects_bridge.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line.h \
    XODR/OpenDRIVE/signal/t_road_signals_signal_positionRoad.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_material.h \
    XODR/OpenDRIVE/object/t_road_objects_tunnel.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_rule.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_width.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_speed.h \
    XODR/OpenDRIVE/object/t_road_objects_objectReference.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane_height.h \
    XODR/OpenDRIVE/object/t_road_objects_object.h \
    XODR/OpenDRIVE/signal/t_road_signals_signal.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneOffset.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_type_line.h \
    XODR/OpenDRIVE/railroad/t_road_railroad_switch_track.h \
    XODR/OpenDRIVE/road/t_road_type.h \
    XODR/OpenDRIVE/road/t_road_surface_CRG.h \
    XODR/OpenDRIVE/object/t_road_objects_object_markings_marking.h \
    XODR/OpenDRIVE/railroad/t_station_platform_segment.h \
    XODR/OpenDRIVE/junction/t_junction_connection.h \
    XODR/OpenDRIVE/junction/t_junction_connection_laneLink.h \
    XODR/OpenDRIVE/junction/t_junction_controller.h \
    XODR/OpenDRIVE/junction/t_junction_priority.h \
    XODR/OpenDRIVE/junction/t_junction_surface_CRG.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor.h \
    XODR/OpenDRIVE/lane/t_road_objects_object_laneValidity.h \
    XODR/OpenDRIVE/object/t_road_objects_object_borders_border.h \
    XODR/OpenDRIVE/object/t_road_objects_object_markings_marking_cornerReference.h \
    XODR/OpenDRIVE/object/t_road_objects_object_material.h \
    XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline.h \
    XODR/OpenDRIVE/object/t_road_objects_object_outlines_outline_cornerLocal.h \
    XODR/OpenDRIVE/railroad/t_road_railroad_switch.h \
    XODR/OpenDRIVE/railroad/t_station_platform.h \
    XODR/OpenDRIVE/road/t_road_planView.h \
    XODR/OpenDRIVE/signal/t_controller_control.h \
    XODR/OpenDRIVE/signal/t_road_signals_signal_dependency.h \
    XODR/OpenDRIVE/signal/t_road_signals_signal_reference.h \
    XODR/OpenDRIVE/junction/t_junctionGroup_junctionReference.h \
    XODR/OpenDRIVE/core/a_sOffset.h \
    XODR/OpenDRIVE/core/a_s.h \
    XODR/OpenDRIVE/core/a_ds.h \
    XODR/OpenDRIVE/core/a_s_t.h \
    XODR/OpenDRIVE/core/a_sOffset_tOffset.h \
    XODR/OpenDRIVE/core/t_cell.h \
    XODR/OpenDRIVE/core/t_dataQuality.h \
    XODR/OpenDRIVE/core/t_dataQuality_Error.h \
    XODR/OpenDRIVE/core/t_dataQuality_RawData.h \
    XODR/OpenDRIVE/core/t_header.h \
    XODR/OpenDRIVE/core/t_header_Offset.h \
    XODR/OpenDRIVE/core/t_include.h \
    XODR/OpenDRIVE/road/t_road_link_predecessorSuccessor.h \
    XODR/OpenDRIVE/core/t_header_GeoReference.h \
    XODR/OpenDRIVE/internal/_internal.h \
    XODR/OpenDRIVE/core/OpenDRIVE.h \
    XODR/OpenDRIVE/core/e_unitMass.h \
    XODR/OpenDRIVE/core/e_unit.h \
    XODR/OpenDRIVE/road/e_countryCode.h \
    XODR/OpenDRIVE/signal/e_road_signals_signal_reference_elementType.h \
    XODR/OpenDRIVE/core/_stringEnum.h \
    XODR/OpenDRIVE/core/e_dataQuality_RawData_Source.h \
    XODR/OpenDRIVE/road/e_countryCode_deprecated.h \
    XODR/OpenDRIVE/core/e_unitSlope.h \
    XODR/OpenDRIVE/junction/e_contactPoint.h \
    XODR/OpenDRIVE/object/e_borderType.h \
    XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lcr_lane_roadMark_laneChange.h \
    XODR/OpenDRIVE/core/e_dataQuality_RawData_PostProcessing.h \
    XODR/OpenDRIVE/object/e_outlineFillType.h \
    XODR/OpenDRIVE/railroad/e_station_type.h \
    XODR/OpenDRIVE/road/e_direction.h \
    XODR/OpenDRIVE/object/e_tunnelType.h \
    XODR/OpenDRIVE/lane/e_roadMarkRule.h \
    XODR/OpenDRIVE/lane/e_accessRestrictionType.h \
    XODR/OpenDRIVE/object/e_bridgeType.h \
    XODR/OpenDRIVE/signal/e_road_signals_signal_type.h \
    XODR/OpenDRIVE/junction/e_road_surface_CRG_purpose.h \
    XODR/OpenDRIVE/lane/e_roadMarkType.h \
    XODR/OpenDRIVE/railroad/e_station_platform_segment_side.h \
    XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lr_lane_access_rule.h \
    XODR/OpenDRIVE/road/e_paramPoly3_pRange.h \
    XODR/OpenDRIVE/lane/e_laneType.h \
    XODR/OpenDRIVE/object/e_sideType.h \
    XODR/OpenDRIVE/road/e_countryCode_iso3166alpha2.h \
    XODR/OpenDRIVE/railroad/e_road_railroad_switch_position.h \
    XODR/OpenDRIVE/road/e_roadType.h \
    XODR/OpenDRIVE/object/e_road_objects_object_parkingSpace_access.h \
    XODR/OpenDRIVE/object/e_objectType.h \
    XODR/OpenDRIVE/road/e_countryCode_iso3166alpha3_deprecated.h \
    XODR/OpenDRIVE/road/e_trafficRule.h \
    XODR/OpenDRIVE/core/e_unitSpeed.h \
    XODR/OpenDRIVE/junction/e_elementDir.h \
    XODR/OpenDRIVE/core/e_unitDistance.h \
    XODR/OpenDRIVE/road/e_road_link_elementType.h \
    XODR/OpenDRIVE/lane/e_roadMarkColor.h \
    XODR/OpenDRIVE/junction/e_road_surface_CRG_mode.h \
    XODR/OpenDRIVE/road/e_maxSpeedString.h \
    XODR/OpenDRIVE/object/e_orientation.h \
    XODR/OpenDRIVE/lane/e_roadMarkWeight.h \
    XODR/OpenDRIVE/junction/e_junctionGroup_type.h \
    XODR/OpenDRIVE/junction/e_junction_type.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_center.h \
    XODR/OpenDRIVE/road/t_road_link.h \
    XODR/OpenDRIVE/junction/t_junctionGroup.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane.h \
    XODR/OpenDRIVE/junction/t_junction_surface.h \
    XODR/OpenDRIVE/object/t_road_objects.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_explicit.h \
    XODR/OpenDRIVE/object/t_road_objects_object_outlines.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_left.h \
    XODR/OpenDRIVE/road/t_road_elevationProfile.h \
    XODR/OpenDRIVE/road/t_road_lateralProfile.h \
    XODR/OpenDRIVE/railroad/t_road_railroad.h \
    XODR/OpenDRIVE/road/t_road.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_link.h \
    XODR/OpenDRIVE/lane/t_road_lanes.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lcr_lane_roadMark_type.h \
    XODR/OpenDRIVE/object/t_road_objects_object_markings.h \
    XODR/OpenDRIVE/railroad/t_station.h \
    XODR/OpenDRIVE/lane/_t_road_lanes_laneSection_lcr.h \
    XODR/OpenDRIVE/core/g_additionalData.h \
    XODR/OpenDRIVE/junction/t_junction.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_right.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry.h \
    XODR/OpenDRIVE/road/t_road_surface.h \
    XODR/OpenDRIVE/railroad/t_road_railroad_switch_partner.h \
    XODR/OpenDRIVE/signal/t_controller.h \
    XODR/OpenDRIVE/signal/t_road_signals.h \
    XODR/OpenDRIVE/object/t_road_objects_object_borders.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry_arc.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_right_lane.h \
    XODR/OpenDRIVE/railroad/t_road_railroad_switch_mainTrack.h \
    XODR/OpenDRIVE/object/t_road_objects_object_parkingSpace.h \
    XODR/OpenDRIVE/core/a_polynom.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry_poly3.h \
    XODR/OpenDRIVE/lane/_t_road_lanes_laneSection_lcr_lane.h \
    XODR/OpenDRIVE/road/t_road_type_speed.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_left_lane.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry_paramPoly3.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry_line.h \
    XODR/OpenDRIVE/signal/t_road_signals_signal_positionInertial.h \
    XODR/OpenDRIVE/junction/t_junction_predecessorSuccessor.h \
    XODR/OpenDRIVE/core/t_userData.h \
    XODR/OpenDRIVE/road/t_road_planView_geometry_spiral.h \
    XODR/OpenDRIVE/railroad/t_road_railroad_switch_sideTrack.h \
    XODR/OpenDRIVE/core/a_ds_polynom.h \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection_center_lane.h \
    XODR/OpenDRIVE/core/a_s_t_polynom.h \
    XODR/OpenDRIVE/core/a_xy_hdg.h \
    XODR/OpenDRIVE/core/a_s_polynom.h \
    XODR/OpenDRIVE/core/a_sOffset_polynom.h \
    XODR/OpenDRIVE/road/t_maxSpeed.h \
    XODR/OpenDRIVE/core/_date.h \
    XODR/OpenDRIVE/core/_double.h \
    XODR/OpenDRIVE/core/t_yesNo.h \
    XODR/OpenDRIVE/core/t_grZero.h \
    XODR/OpenDRIVE/lane/t_bool_default_false.h \
    XODR/OpenDRIVE/lane/t_bool_default_true.h \
    XODR/OpenDRIVE/core/_integer.h \
    XODR/OpenDRIVE/core/t_grEqZero.h \
    XODR/OpenDRIVE/core/t_zeroOne.h \
    _XODRViewer/Main/MainWnd.h \
    _XODRViewer/Main/NavigateToXYDlg.h \
    _XODRViewer/Main/MapWnd.h \
    _XODRViewer/Main/SetLocalFilesDatabasePathDlg.h \
    _XODRViewer/Main/NavigateToLLDlg.h \
    _XODRViewer/Main/SetPGDatabaseSettingDlg.h \
    _XODRViewer/Internal/Internal.h \
    OSM/Node/Node.h \
    OSM/Way/Way.h \
    OSM/Main/RequestAnalyzer.h \
    OSM/CountryArea/OSMCountryAreaSettingsOnPGDatabase.h \
    OSM/Way/OSMWayTablesUpdateThread.h \
    OSM/Node/OSMNodeTablesUpdateThread.h \
    OSM/CountryArea/OSMCountryAreaTablesUpdateThread.h \
    OSM/Way/OSMWaySettingsOnPGDatabase.h \
    OSM/Node/OSMNodeSettingsOnPGDatabase.h \
    OSM/Internal/Internal.h \
    OSM/OSM.h \
    OSM/Main/RequestLauncher.h \
    OSM/Main/ResultGenerator.h \
    OSM/Main/OverpassAPI.h \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__RHT.h \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__LHT.h \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__Base.h \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider_AU.h \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider.h \
    OSM/Main/RequestStatus.h \
    OSM/Main/PolygonAPI.h \
    OSM/TileImage/OSMTileImageAPI.h \
    OSM/TileImage/OSMTileImageDownloader.h \
    OSM/TileImage/OSMTileImageParam.h \
    _Utils/Common/Main/Cacher.h

SOURCES += \
    _Utils/GeoCoordinate/Main/Cell.cpp \
    _Utils/GeoCoordinate/Main/LL.cpp \
    _Utils/GeoCoordinate/GeoCoordinate.cpp \
    _Utils/DB/Main/PGDatabaseConnector_OSMWay.cpp \
    _Utils/DB/Main/PGDatabaseConnector_OSMNode.cpp \
    _Utils/DB/Main/PGDatabaseConnector_Settings.cpp \
    _Utils/DB/Main/PGDatabaseConnector_GeoJSONStaging.cpp \
    _Utils/DB/Main/SettingsOnPGDatabase.cpp \
    _Utils/GeoCoordinate/Main/VehiclePos.cpp \
    _Utils/Debugger/Main/Logger.cpp \
    _Utils/DB/Main/PGDatabaseConnector_GPS.cpp \
    _Utils/DB/Main/PGDatabaseConnector_Trajectory.cpp \
    _Utils/DB/Main/PGDatabaseConnector_XODR.cpp \
    _Utils/DB/Main/PGDatabaseConnector_GeoJSONApplying.cpp \
    _Utils/DB/Main/LocalFilesDatabaseConnector.cpp \
    _Utils/DB/Main/PGDatabaseConnector_OSMCountryArea.cpp \
    _Utils/DB/Main/PGDatabaseConnector.inl \
    _Utils/Debugger/Main/LoggingThread.cpp \
    _Utils/SettingsOnLocalSystem/Main/SettingsOnLocalSystem.cpp \
    _Utils/DB/Main/UserSettingsOnPGDatabase.cpp \
    _Utils/DB/Main/LocalFilesDatabaseSettings.cpp \
    _Utils/DB/Main/PGDatabaseConnector_Logs.cpp \
    _Utils/DB/Main/PGDatabaseConnector_Data_Status.cpp \
    _Utils/DB/Main/GlobalSettingsOnPGDatabase.cpp \
    _Utils/DB/Main/PGDatabaseConnector.cpp \
    _Utils/Thread/Main/Thread.cpp \
    _Utils/GeoCoordinate/Main/LLCoordSysXYCell.cpp \
    _Utils/DB/Main/DatabaseSettingsOnLocalSystem.cpp \
    _Utils/Debugger/Main/LoggingSlotManager.cpp \
    _Utils/XML/Main/XmlUtils.cpp \
    _Utils/XML/Main/XmlStream.cpp \
    _Utils/XML/Main/XmlElement.cpp \
    _Utils/Math/Math.cpp \
    _Utils/Math/Main/QMatrix4x4D.cpp \
    _Utils/GeoCoordinate/Main/XYCell.cpp \
    _Utils/GeoCoordinate/Main/CoordSys.cpp \
    _Utils/GeoCoordinate/Main/CoordSysXYCell.cpp \
    _Utils/GeoCoordinate/Main/CoordSysXY.cpp \
    _Utils/GeoCoordinate/Main/CoordSysCell.cpp \
    _Utils/DB/Main/DatabaseConnector.cpp \
    XODR/OpenDRIVE/object/t_road_objects_object_markings_marking.cpp \
    XODR/OpenDRIVE/railroad/t_station_platform_segment.cpp \
    XODR/OpenDRIVE/road/t_road_surface_CRG.cpp \
    XODR/OpenDRIVE/core/a_s_t.cpp \
    XODR/OpenDRIVE/core/a_s.cpp \
    XODR/OpenDRIVE/core/a_sOffset_tOffset.cpp \
    XODR/OpenDRIVE/core/a_ds.cpp \
    XODR/OpenDRIVE/core/a_sOffset.cpp \
    XODR/OpenDRIVE/core/t_header.cpp \
    XODR/OpenDRIVE/core/OpenDRIVE.cpp \
    XODR/OpenDRIVE/core/_OpenDriveElement.cpp \
    XODR/OpenDRIVE/signal/_signal.cpp \
    XODR/OpenDRIVE/road/t_road_planView.cpp \
    XODR/OpenDRIVE/road/t_road_planView_geometry.cpp \
    XODR/OpenDRIVE/road/t_road.cpp \
    XODR/OpenDRIVE/road/_road.cpp \
    XODR/OpenDRIVE/railroad/_railroad.cpp \
    XODR/OpenDRIVE/object/_object.cpp \
    XODR/OpenDRIVE/lane/t_road_lanes_laneSection.cpp \
    XODR/OpenDRIVE/lane/_lane.cpp \
    XODR/OpenDRIVE/junction/_junction.cpp \
    XODR/OpenDRIVE/core/t_userData.cpp \
    XODR/OpenDRIVE/core/_core.cpp \
    XODR/OpenDRIVE/core/_date.cpp \
    _XODRViewer/Main/MainWnd.cpp \
    _XODRViewer/Main/MapWnd.cpp \
    _XODRViewer/Main/main.cpp \
    _XODRViewer/Main/SetLocalFilesDatabasePathDlg.cpp \
    _XODRViewer/Main/SetPGDatabaseSettingDlg.cpp \
    _XODRViewer/Main/NavigateToXYDlg.cpp \
    _XODRViewer/Main/NavigateToLLDlg.cpp \
    OSM/Main/RequestAnalyzer.cpp \
    OSM/Way/Way.cpp \
    OSM/OSM.cpp \
    OSM/Node/OSMNodeTablesUpdateThread.cpp \
    OSM/Way/OSMWayTablesUpdateThread.cpp \
    OSM/Main/RequestLauncher.cpp \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__Base.cpp \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__LHT.cpp \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__RHT.cpp \
    OSM/Way/Way_Oneway.cpp \
    OSM/CountryArea/OSMCountryAreaSettingsOnPGDatabase.cpp \
    OSM/Main/OverpassAPI.cpp \
    OSM/CountryArea/OSMCountryAreaTablesUpdateThread.cpp \
    OSM/Main/ResultGenerator.cpp \
    OSM/Node/OSMNodeSettingsOnPGDatabase.cpp \
    OSM/Way/OSMWaySettingsOnPGDatabase.cpp \
    OSM/Way/Way_RoadMark.cpp \
    OSM/Way/Way_LanesWidth.cpp \
    OSM/Way/Way_LaneCount2.cpp \
    OSM/Way/Way_LaneCount1.cpp \
    OSM/Way/Way_Junction.cpp \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider_AU.cpp \
    OSM/PriorKnowledgeProvider/PriorKnowledgeProvider.cpp \
    OSM/Node/Node.cpp \
    OSM/TileImage/OSMTileImageAPI.cpp \
    OSM/TileImage/OSMTileImageDownloader.cpp \
    _XODRViewer/Main/MapWnd_OSM.cpp

FORMS += \
    _XODRViewer/Main/MainWnd.ui \
    _XODRViewer/Main/SetPGDatabaseSettingDlg.ui \
    _XODRViewer/Main/SetLocalFilesDatabasePathDlg.ui \
    _XODRViewer/Main/NavigateToXYDlg.ui \
    _XODRViewer/Main/NavigateToLLDlg.ui \
    _XODRViewer/Main/MapWnd.ui
