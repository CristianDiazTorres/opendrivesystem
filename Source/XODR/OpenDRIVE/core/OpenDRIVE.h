#pragma once

#include "XODR/OpenDRIVE/core/t_header.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/t_road.h"
#include "XODR/OpenDRIVE/signal/t_controller.h"
#include "XODR/OpenDRIVE/junction/t_junction.h"
#include "XODR/OpenDRIVE/junction/t_junctionGroup.h"
#include "XODR/OpenDRIVE/railroad/t_station.h"

/*
    <xs:element name="OpenDRIVE">
        <xs:complexType>
            <xs:sequence>
                <xs:element name="header" type="t_header" minOccurs="1" maxOccurs="1"/>
                <xs:element name="road" type="t_road" minOccurs="1" maxOccurs="unbounded"/>
                <xs:element name="controller" type="t_controller" minOccurs="0" maxOccurs="unbounded"/>
                <xs:element name="junction" type="t_junction" minOccurs="0" maxOccurs="unbounded">
                    <!-- Key Constraints manually added from OpenDRIVE 1.5 -->
                    <xs:key name="k_junction_connectionId">
                        <xs:selector xpath="connection"/>
                        <xs:field xpath="@id"/>
                    </xs:key>
                    <xs:key name="k_junction_controllerId">
                        <xs:selector xpath="junction/controller"/>
                        <xs:field xpath="@id"/>
                    </xs:key>
                    <xs:keyref name="r_junction_connection_master" refer="k_junction_connectionId">
                        <xs:selector xpath="junction/connection"/>
                        <xs:field xpath="@connectionMaster"/>
                    </xs:keyref>
                </xs:element>
                <xs:element name="junctionGroup" type="t_junctionGroup" minOccurs="0" maxOccurs="unbounded"/>
                <xs:element name="station" type="t_station" minOccurs="0" maxOccurs="unbounded"/>
                <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
            </xs:sequence>
        </xs:complexType>

        <!-- Key Constraints manually added from OpenDRIVE 1.5 -->
        <xs:key name="k_roadId">
            <xs:selector xpath="road"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_objects_objectId">
            <xs:selector xpath="road/objects/object"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_objects_objectReferenceId">
            <xs:selector xpath="road/objects/objectReference"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_objects_tunnel">
            <xs:selector xpath="road/objects/tunnel"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_objects_bridge">
            <xs:selector xpath="road/objects/bridge"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_signals_signalId">
            <xs:selector xpath="road/signals/signal"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_railroad_switchId">
            <xs:selector xpath="road/railroad/switch"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_road_railroad_switchName">
            <xs:selector xpath="road/railroad/switch"/>
            <xs:field xpath="@name"/>
        </xs:key>
        <xs:key name="k_controllerId">
            <xs:selector xpath="controller"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_junctionId">
            <xs:selector xpath="junction"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_junctionGroupId">
            <xs:selector xpath="junctionGroup"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_stationId">
            <xs:selector xpath="station"/>
            <xs:field xpath="@id"/>
        </xs:key>
        <xs:key name="k_station_platformId">
            <xs:selector xpath="station/platform"/>
            <xs:field xpath="@id"/>
        </xs:key>

        <xs:keyref name="r_road_link_neighbor" refer="k_roadId">
            <xs:selector xpath="road/link/neighbor"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_road_objects_objectReference" refer="k_road_objects_objectId">
            <xs:selector xpath="road/objects/objectReference"/>
            <xs:field xpath="@outlineId"/>
        </xs:keyref>
        <xs:keyref name="r_road_signals_signal_dependency" refer="k_road_signals_signalId">
            <xs:selector xpath="road/signals/signal/dependency"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_road_signals_signal_positionRoad" refer="k_roadId">
            <xs:selector xpath="road/signals/signal/positionRoad"/>
            <xs:field xpath="@roadId"/>
        </xs:keyref>
        <xs:keyref name="r_road_signals_signalReference" refer="k_road_signals_signalId">
            <xs:selector xpath="road/signals/signalReference"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_road_railroad_switch_mainTrack" refer="k_road_railroad_switchId">
            <xs:selector xpath="road/railroad/switch/mainTrack"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_road_railroad_switch_sideTrack" refer="k_road_railroad_switchId">
            <xs:selector xpath="road/railroad/switch/sideTrack"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_road_railroad_switch_partner" refer="k_road_railroad_switchId">
            <xs:selector xpath="road/railroad/switch/partner"/>
            <xs:field xpath="@id"/>
        </xs:keyref>
        <xs:keyref name="r_controller_control" refer="k_road_signals_signalId">
            <xs:selector xpath="controller/control"/>
            <xs:field xpath="@signalId"/>
        </xs:keyref>
        <xs:keyref name="r_junction_connection_incomingRoad" refer="k_roadId">
            <xs:selector xpath="junction/connection"/>
            <xs:field xpath="@incomingRoad"/>
            <!-- <xs:field xpath="@connectingRoad"/> -->
        </xs:keyref>
        <xs:keyref name="r_junction_connection_connectingRoad" refer="k_roadId">
            <xs:selector xpath="junction/connection"/>
            <!-- <xs:field xpath="@incomingRoad"/> -->
            <xs:field xpath="@connectingRoad"/>
        </xs:keyref>
        <xs:keyref name="r_station_platform_segment" refer="k_roadId">
            <xs:selector xpath="station/platform/segment"/>
            <xs:field xpath="@roadId"/>
        </xs:keyref>

    </xs:element>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_header          , header) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road            , road) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_controller      , controller) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_junction        , junction) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_junctionGroup   , junctionGroup) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_station         , station) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct OpenDRIVE : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_setParent_DEFINE(OpenDRIVE)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(OpenDRIVE)
    _UNIVERSIAL_TYPE_read_write_DEFINE(OpenDRIVE)
    _UNIVERSIAL_TYPE_setTestData_DEFINE(OpenDRIVE)

public:
    bool read(const string& filePath);

    // TODO: ???
    // attributes : xmlns="http://www.opendrive.org"
    bool write(const string& filePath, bool forceToWriteOptionalValues = false);

    void readFromJson(QString json);
    QString writeToJson(bool forceToWriteOptionalValues = false);
    bool writeToJson(const string& filePath, bool forceToWriteOptionalValues = false);

public:
    inline bool isValid() const
    {
        return !road_sequence.isEmpty();
    }

    inline t_cell& getCell()
    {
        for (t_userData& userData : additionalData.userData_sequence)
        {
            if (userData.code == _SC_Cell)
            {
                Q_ASSERT(userData.cell_sequence.size() == 1);
                return userData.cell_sequence[0];
            }
        }

        additionalData.userData_sequence.resize(additionalData.userData_sequence.size() + 1);
        t_userData& userData = additionalData.userData_sequence.last();
        userData.code = _SC_Cell;
        userData.cell_sequence.resize(1);
        return userData.cell_sequence[0];
    }

    inline t_cell getCell() const
    {
        for (const t_userData& userData : additionalData.userData_sequence)
        {
            if (userData.code == _SC_Cell)
            {
                Q_ASSERT(userData.cell_sequence.size() == 1);
                return userData.cell_sequence[0];
            }
        }

        return t_cell();
    }

    inline void init(const Cell& cell)
    {
        header.init(cell);

        const XY &xy = cell.getCellCenterXY();
        t_cell& _cell = getCell();
        _cell.cellRow = cell.cellRow;
        _cell.cellCol = cell.cellCol;
        _cell.centerX = xy.x();
        _cell.centerY = xy.y();
    }

    inline void removeJunctions()
    {
        junction_sequence.clear();
        for (t_road& road : road_sequence)
        {
            if (road.junction != -1)
                road.junction = 0; // We will re-make junction later
        }
    }

    inline void removeRoadLinks()
    {
        for (t_road& road : road_sequence)
            road.link_sequence.clear();
    }

    // @incomplete
    bool setCurvatureSlope(const XY& pos, double curvature, double slope);

    double calcDistance(const LLCoordSysXYCellVec& points, QString tag) const;
    double calcDistance(const LLCoordSysXYCell& point, QString tag) const;
    double calcDistance_road(const LLCoordSysXYCellVec &points) const;
    double calcDistance_road(const LLCoordSysXYCell& point) const;
    double calcDistance_junction(const LLCoordSysXYCellVec &points) const;
    double calcDistance_junction(const LLCoordSysXYCell& point) const;

    bool updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted);
    bool updateGeoJSONData_road(_GeoJSONData& geojsonData, bool& inserted);
    bool updateGeoJSONData_junction(_GeoJSONData& geojsonData, bool& inserted);
};

}

