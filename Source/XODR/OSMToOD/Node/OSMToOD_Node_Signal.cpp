#include "XODR/OSMToOD/OSMToOD.h"
#include "XODR/Main/XODRSettingsOnPGDatabase.h"

namespace _NXODR
{

/*
Signals are traffic signs, traffic lights, and specific road marking for the control and regulation of road traffic, as shown in figure 95.

img95
Figure 95. Signals in OpenDRIVE
Signals have different functions and properties:

They are used to control traffic behavior, for example, with speed limits and turn restrictions,
and to alert road traffic about dangerous situations.

They can be static or dynamic.
Static signals, like stop signs, do not change their meaning.
Dynamic signals, like traffic lights, may change their meaning during the simulation.
Their state may be defined in OpenSCENARIO.

Signals shall be placed in relation to a specific road.
The position of the signal is described relative to the road reference line, using the s- and t- coordinates.
Signals shall be positioned in such a way that it is clear to which road or lane they belong and where their validity starts.
Ambiguity about their interpretation shall be avoided.

Traffic rules are different for each country.
The country of the signal is specified in the attribute @country.
When placing signals in OpenDRIVE, country-specific legislation and traffic rules should be considered.
Legislative changes are indicated by the year when the rules come into force.

Height and width of a signal are not required but are recommended for proper representation of the signal.

Road marks, that are not binding to traffic, are not defined as signals, but only as objects.

A signal with the attributes @type and @subtype is only unique in combination with @country and @countryRevision.
*/

bool OSMToOpenDRIVE::convertNode_Signal(DatabaseConnector& database_connector,
                                        _NOSM::Node& osmNode,
                                        const QString& amenity,
                                        const QList<QString>& values,
                                        _NOD::t_road &odRoad)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    _NOD::t_road_signals_signal odSignal;

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_lights) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_camera_mount_A, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_camera_mount_A, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crossing, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crossing, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crossing_1, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_crossing_1, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_intersection, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_intersection, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_level_crossing, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_level_crossing, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_street_cabinet, _SC_light) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_street_cabinet, _SC_lamp) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_light, _SC_traffic_signals))
    {
        //if (osmNode.osm.contains(_SC_traffic_lights))
        //    odSignal.type = QString(_SC_traffic_lights) + ":" + osmNode.osm[_SC_traffic_lights];
        //else
            odSignal.type = _NOD::e_road_signals_signal_type::TRAFFIC_LIGHTS;
    }
    else if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing_1) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_crossing_2) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_level_crossing))
    {
        //if (osmNode.osm.contains(_SC_crossing))
        //    odSignal.type = QString(_SC_crossing) + ":" + osmNode.osm[_SC_crossing];
        //else
            odSignal.type = _NOD::e_road_signals_signal_type::CROSSING;
    }
    else if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_calming) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_area_traffic_calming_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_calming) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_area_highway_A, _SC_traffic_calming) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway, _SC_traffic_calming))
    {
        //if (osmNode.osm.contains(_SC_traffic_calming))
        //    odSignal.type = QString(_SC_traffic_calming) + ":" + osmNode.osm[_SC_traffic_calming];
        //else
            odSignal.type = _NOD::e_road_signals_signal_type::TRAFFIC_CALMING;
    }
    else if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_bollard_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_broken_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_highway_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_left_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_right_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_demolished_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_destroyed_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_disabled_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_location_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_man_made_separate_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_obstacle_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_seasonal_winter_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_sidewalk_left_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_sidewalk_right_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_sidewalk_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_street_cabinet_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_temporarily_gone_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_temporarily_removed_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_waterway_traffic_sign_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_sign_1) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_abandoned, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_bollard, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_broken, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_construction_highway_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway_left_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway_right_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_demolished, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_destroyed, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_disabled, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_disused, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_location, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_man_made_separate_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_obstacle, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_razed, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_seasonal_winter_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_sidewalk, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_sidewalk_left_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_sidewalk_right_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_street_cabinet, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_temporarily_gone_A, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_temporarily_removed, _SC_traffic_sign) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_waterway, _SC_traffic_sign))
    {
         //if (osmNode.osm.contains(_SC_traffic_sign))
         //    odSignal.type = QString(_SC_traffic_sign) + ":" + osmNode.osm[_SC_traffic_sign];
         //else
             odSignal.type = _NOD::e_road_signals_signal_type::TRAFFIC_SIGN;
    }
    else if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_railway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_bicycle_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_demolished_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_highway_traffic_signal_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_construction_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_left_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_right_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_cycleway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_demolished_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_device_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_disabled_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_disused_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_backward_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_backwards_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_bicycle_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_construction_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_disused_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_forward_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_historic_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_1_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_highway_2_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_historic_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_intersection_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_junction_separate_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_junction_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_highway_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_road_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_street_cabinet_traffic_signal_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_street_cabinet_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_control_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_signal) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_traffic_signals_1) ||
         OSMToOpenDRIVE_CONTAINS_KEY(_SC_transport_traffic_signals_A) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_abandoned_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_abandoned_railway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_bicycle, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_construction, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_construction_demolished_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_construction_highway_A, _SC_traffic_signal) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_construction_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway_left_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_cycleway_right_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_demolished_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_device, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_disabled_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_disused, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_disused_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_backward_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_backwards_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_bicycle_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_construction_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_disused_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_forward_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_historic_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_1, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_highway_2, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_historic_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_intersection, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_junction, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_junction_separate_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_razed, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_razed_highway_A, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_road, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_street_cabinet, _SC_traffic_signal) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_street_cabinet, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_traffic_control, _SC_traffic_signals) ||
         OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_transport, _SC_traffic_signals))
    {
        //if (osmNode.osm.contains(_SC_traffic_signals))
        //    odSignal.type = QString(_SC_traffic_signals) + ":" + osmNode.osm[_SC_traffic_signals];
        //else
            odSignal.type = _NOD::e_road_signals_signal_type::TRAFFIC_SIGNAL;
    }
    else
    {
        return false;
    }

    odSignal.id = database_connector.getNewID();
    odSignal.name = osmNode.osm[_SC_name];
    odSignal.zOffset = 0;

    if (!odRoad.type_sequence.isEmpty())
        odSignal.country = odRoad.type_sequence[0].country;

    odRoad.calcST(osmNode.coord, odSignal);

    if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteOSM())
    {
        _NOD::t_userData odUserData(_SC_osm);
        odUserData.osm_sequence << osmNode.osm;
        odSignal.additionalData.userData_sequence << odUserData;
    }

    _NOD::t_road_signals_signal_positionRoad odSignalPositionRoad;
    odSignalPositionRoad.s = odSignal.s;
    odSignalPositionRoad.t = odSignal.t;
    odSignalPositionRoad.roadId = odRoad.id;
    odSignalPositionRoad.hOffset = 0;
    odSignalPositionRoad.zOffset = 0;
    odSignal.positionRoad_sequence << odSignalPositionRoad;

    if (odRoad.signals_sequence.isEmpty())
        odRoad.signals_sequence.resize(1);
    odRoad.signals_sequence[0].signal_sequence << odSignal;

    return true;
}

}
