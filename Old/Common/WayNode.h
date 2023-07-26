#ifndef __COMMON_WAYNODE_H__
#define __COMMON_WAYNODE_H__

#include "Common/LatLon.h"

namespace Common
{

struct WayNode
{
    LatLon coord;

    QString access;
    QString amenity;
    QString barrier;
    QString bench;
    QString bicycle;
    QString bin;
    QString bollard;
    QString bus;
    QString capacity_parent;
    QString communication_gsm_r;
    QString communication_mobile_phone;
    QString covered;
    QString crossing;
    QString crossing_activation;
    QString crossing_barrier;
    QString crossing_chicane;
    QString crossing_island;
    QString crossing_light;
    QString crossing_saltire;
    QString description;
    QString direction;
    QString direction_east;
    QString direction_south;
    QString emergency;
    QString emergency_telephone_code;
    QString fee;
    QString foot;
    QString highway;
    QString hiking;
    QString horse;
    QString information;
    QString kerb;
    QString lcn;
    QString man_made;
    QString material;
    QString name;
    QString network;
    QString noexit;
    QString noref;
    QString note;
    QString official_name;
    QString old_name;
    QString operator_;
    QString parking;
    QString public_transport;
    QString railway;
    QString railway_derail;
    QString railway_local_operated;
    QString railway_milestone_catenary_mast;
    QString railway_milestone_emergency_brake_override;
    QString railway_position;
    QString railway_position_exact;
    QString railway_radio;
    QString railway_ref;
    QString railway_signal_catenary_mast;
    QString railway_signal_crossing_form;
    QString railway_signal_crossing_distant_form;
    QString railway_signal_direction;
    QString railway_signal_distant;
    QString railway_signal_distant_form;
    QString railway_signal_distant_height;
    QString railway_signal_distant_repeated;
    QString railway_signal_distant_shortened;
    QString railway_signal_distant_states;
    QString railway_signal_electricity;
    QString railway_signal_electricity_form;
    QString railway_signal_electricity_height;
    QString railway_signal_electricity_turn_direction;
    QString railway_signal_electricity_type;
    QString railway_signal_expected_position_height;
    QString railway_signal_main;
    QString railway_signal_main_deactivated;
    QString railway_signal_main_form;
    QString railway_signal_main_function;
    QString railway_signal_main_height;
    QString railway_signal_main_states;
    QString railway_signal_main_substitute_signal;
    QString railway_signal_main_repeated;
    QString railway_signal_main_repeated_form;
    QString railway_signal_minor;
    QString railway_signal_minor_form;
    QString railway_signal_minor_height;
    QString railway_signal_minor_states;
    QString railway_signal_position;
    QString railway_signal_shunting;
    QString railway_signal_shunting_form;
    QString railway_signal_shunting_height;
    QString railway_signal_speed_limit;
    QString railway_signal_speed_limit_form;
    QString railway_signal_speed_limit_height;
    QString railway_signal_speed_limit_speed;
    QString railway_signal_speed_limit_distant;
    QString railway_signal_speed_limit_distant_form;
    QString railway_signal_speed_limit_distant_height;
    QString railway_signal_speed_limit_distant_speed;
    QString railway_signal_station_distant;
    QString railway_signal_station_distant_form;
    QString railway_signal_traversable_type;
    QString railway_signal_whistle;
    QString railway_signal_whistle_form;
    QString railway_signal_wrong_road;
    QString railway_signal_wrong_road_form;
    QString railway_station_category;
    QString railway_switch;
    QString railway_switch_configuration;
    QString railway_switch_electric;
    QString railway_switch_movable_frog;
    QString railway_switch_resetting;
    QString railway_turnout_side;
    QString razed;
    QString ref;
    QString ref_IFOPT;
    QString ref_station;
    QString route_ref;
    QString shelter;
    QString source_date;
    QString supervised;
    QString tactile_paving;
    QString tourism;
    QString tower_type;
    QString traffic_calming;
    QString traffic_sign;
    QString train;
    QString uic_name;
    QString uic_ref;
    QString wheelchair;
    QString wheelchair_description;

public:
    inline void ParseFromOSMJson(QJsonValue json)
    {
        this->coord = LatLon(json);

        QJsonObject obj = json.toObject();
        QJsonObject tags = obj["tags"].toObject();

        if (tags.contains("access"))
            this->access = tags["access"].toString();

        if (tags.contains("amenity"))
            this->amenity = tags["amenity"].toString();

        if (tags.contains("barrier"))
            this->barrier = tags["barrier"].toString();

        if (tags.contains("bench"))
            this->bench = tags["bench"].toString();

        if (tags.contains("bicycle"))
            this->bicycle = tags["bicycle"].toString();

        if (tags.contains("bin"))
            this->bin = tags["bin"].toString();

        if (tags.contains("bollard"))
            this->bollard = tags["bollard"].toString();

        if (tags.contains("bus"))
            this->bus = tags["bus"].toString();

        if (tags.contains("capacity:parent"))
            this->capacity_parent = tags["capacity:parent"].toString();

        if (tags.contains("communication:gsm-r"))
            this->communication_gsm_r = tags["communication:gsm-r"].toString();

        if (tags.contains("communication:mobile_phone"))
            this->communication_mobile_phone = tags["communication:mobile_phone"].toString();

        if (tags.contains("covered"))
            this->covered = tags["covered"].toString();

        if (tags.contains("crossing"))
            this->crossing = tags["crossing"].toString();

        if (tags.contains("crossing:activation"))
            this->crossing_activation = tags["crossing:activation"].toString();

        if (tags.contains("crossing:barrier"))
            this->crossing_barrier = tags["crossing:barrier"].toString();

        if (tags.contains("crossing:chicane"))
            this->crossing_chicane = tags["crossing:chicane"].toString();

        if (tags.contains("crossing:island"))
            this->crossing_island = tags["crossing:island"].toString();

        if (tags.contains("crossing:light"))
            this->crossing_light = tags["crossing:light"].toString();

        if (tags.contains("crossing:saltire"))
            this->crossing_saltire = tags["crossing:saltire"].toString();

        if (tags.contains("description"))
            this->description = tags["description"].toString();

        if (tags.contains("direction"))
            this->direction = tags["direction"].toString();

        if (tags.contains("direction_east"))
            this->direction_east = tags["direction_east"].toString();

        if (tags.contains("direction_south"))
            this->direction_south = tags["direction_south"].toString();

        if (tags.contains("emergency"))
            this->emergency = tags["emergency"].toString();

        if (tags.contains("emergency_telephone_code"))
            this->emergency_telephone_code = tags["emergency_telephone_code"].toString();

        if (tags.contains("fee"))
            this->fee = tags["fee"].toString();

        if (tags.contains("foot"))
            this->foot = tags["foot"].toString();

        if (tags.contains("highway"))
            this->highway = tags["highway"].toString();

        if (tags.contains("hiking"))
            this->hiking = tags["hiking"].toString();

        if (tags.contains("horse"))
            this->horse = tags["horse"].toString();

        if (tags.contains("information"))
            this->information = tags["information"].toString();

        if (tags.contains("kerb"))
            this->kerb = tags["kerb"].toString();

        if (tags.contains("lcn"))
            this->lcn = tags["lcn"].toString();

        if (tags.contains("man_made"))
            this->man_made = tags["man_made"].toString();

        if (tags.contains("material"))
            this->material = tags["material"].toString();

        if (tags.contains("name"))
            this->name = tags["name"].toString();

        if (tags.contains("network"))
            this->network = tags["network"].toString();

        if (tags.contains("noexit"))
            this->noexit = tags["noexit"].toString();

        if (tags.contains("noref"))
            this->noref = tags["noref"].toString();

        if (tags.contains("note"))
            this->note = tags["note"].toString();

        if (tags.contains("official_name"))
            this->official_name = tags["official_name"].toString();

        if (tags.contains("old_name"))
            this->old_name = tags["old_name"].toString();

        if (tags.contains("operator"))
            this->operator_ = tags["operator"].toString();

        if (tags.contains("parking"))
            this->parking = tags["parking"].toString();

        if (tags.contains("public_transport"))
            this->public_transport = tags["public_transport"].toString();

        if (tags.contains("railway"))
            this->railway = tags["railway"].toString();

        if (tags.contains("railway:derail"))
            this->railway_derail = tags["railway:derail"].toString();

        if (tags.contains("railway:local_operated"))
            this->railway_local_operated = tags["railway:local_operated"].toString();

        if (tags.contains("railway:milestone:catenary_mast"))
            this->railway_milestone_catenary_mast = tags["railway:milestone:catenary_mast"].toString();

        if (tags.contains("railway:milestone:emergency_brake_override"))
            this->railway_milestone_emergency_brake_override = tags["railway:milestone:emergency_brake_override"].toString();

        if (tags.contains("railway:position"))
            this->railway_position = tags["railway:position"].toString();

        if (tags.contains("railway:position:exact"))
            this->railway_position_exact = tags["railway:position:exact"].toString();

        if (tags.contains("railway:radio"))
            this->railway_radio = tags["railway:radio"].toString();

        if (tags.contains("railway:ref"))
            this->railway_ref = tags["railway:ref"].toString();

        if (tags.contains("railway:signal:catenary_mast"))
            this->railway_signal_catenary_mast = tags["railway:signal:catenary_mast"].toString();

        if (tags.contains("railway:signal:crossing:form"))
            this->railway_signal_crossing_form = tags["railway:signal:crossing:form"].toString();

        if (tags.contains("railway:signal:crossing_distant:form"))
            this->railway_signal_crossing_distant_form = tags["railway:signal:crossing_distant:form"].toString();

        if (tags.contains("railway:signal:direction"))
            this->railway_signal_direction = tags["railway:signal:direction"].toString();

        if (tags.contains("railway:signal:distant"))
            this->railway_signal_distant = tags["railway:signal:distant"].toString();

        if (tags.contains("railway:signal:distant:form"))
            this->railway_signal_distant_form = tags["railway:signal:distant:form"].toString();

        if (tags.contains("railway:signal:distant:height"))
            this->railway_signal_distant_height = tags["railway:signal:distant:height"].toString();

        if (tags.contains("railway:signal:distant:repeated"))
            this->railway_signal_distant_repeated = tags["railway:signal:distant:repeated"].toString();

        if (tags.contains("railway:signal:distant:shortened"))
            this->railway_signal_distant_shortened = tags["railway:signal:distant:shortened"].toString();

        if (tags.contains("railway:signal:distant:states"))
            this->railway_signal_distant_states = tags["railway:signal:distant:states"].toString();

        if (tags.contains("railway:signal:electricity"))
            this->railway_signal_electricity = tags["railway:signal:electricity"].toString();

        if (tags.contains("railway:signal:electricity:form"))
            this->railway_signal_electricity_form = tags["railway:signal:electricity:form"].toString();

        if (tags.contains("railway:signal:electricity:height"))
            this->railway_signal_electricity_height = tags["railway:signal:electricity:height"].toString();

        if (tags.contains("railway:signal:electricity:turn_direction"))
            this->railway_signal_electricity_turn_direction = tags["railway:signal:electricity:turn_direction"].toString();

        if (tags.contains("railway:signal:electricity:type"))
            this->railway_signal_electricity_type = tags["railway:signal:electricity:type"].toString();

        if (tags.contains("railway:signal:expected_position:height"))
            this->railway_signal_expected_position_height = tags["railway:signal:expected_position:height"].toString();

        if (tags.contains("railway:signal:main"))
            this->railway_signal_main = tags["railway:signal:main"].toString();

        if (tags.contains("railway:signal:main:deactivated"))
            this->railway_signal_main_deactivated = tags["railway:signal:main:deactivated"].toString();

        if (tags.contains("railway:signal:main:form"))
            this->railway_signal_main_form = tags["railway:signal:main:form"].toString();

        if (tags.contains("railway:signal:main:function"))
            this->railway_signal_main_function = tags["railway:signal:main:function"].toString();

        if (tags.contains("railway:signal:main:height"))
            this->railway_signal_main_height = tags["railway:signal:main:height"].toString();

        if (tags.contains("railway:signal:main:states"))
            this->railway_signal_main_states = tags["railway:signal:main:states"].toString();

        if (tags.contains("railway:signal:main:substitute_signal"))
            this->railway_signal_main_substitute_signal = tags["railway:signal:main:substitute_signal"].toString();

        if (tags.contains("railway:signal:main_repeated"))
            this->railway_signal_main_repeated = tags["railway:signal:main_repeated"].toString();

        if (tags.contains("railway:signal:main_repeated:form"))
            this->railway_signal_main_repeated_form = tags["railway:signal:main_repeated:form"].toString();

        if (tags.contains("railway:signal:minor"))
            this->railway_signal_minor = tags["railway:signal:minor"].toString();

        if (tags.contains("railway:signal:minor:form"))
            this->railway_signal_minor_form = tags["railway:signal:minor:form"].toString();

        if (tags.contains("railway:signal:minor:height"))
            this->railway_signal_minor_height = tags["railway:signal:minor:height"].toString();

        if (tags.contains("railway:signal:minor:states"))
            this->railway_signal_minor_states = tags["railway:signal:minor:states"].toString();

        if (tags.contains("railway:signal:position"))
            this->railway_signal_position = tags["railway:signal:position"].toString();

        if (tags.contains("railway:signal:shunting"))
            this->railway_signal_shunting = tags["railway:signal:shunting"].toString();

        if (tags.contains("railway:signal:shunting:form"))
            this->railway_signal_shunting_form = tags["railway:signal:shunting:form"].toString();

        if (tags.contains("railway:signal:shunting:height"))
            this->railway_signal_shunting_height = tags["railway:signal:shunting:height"].toString();

        if (tags.contains("railway:signal:speed_limit"))
            this->railway_signal_speed_limit = tags["railway:signal:speed_limit"].toString();

        if (tags.contains("railway:signal:speed_limit:form"))
            this->railway_signal_speed_limit_form = tags["railway:signal:speed_limit:form"].toString();

        if (tags.contains("railway:signal:speed_limit:height"))
            this->railway_signal_speed_limit_height = tags["railway:signal:speed_limit:height"].toString();

        if (tags.contains("railway:signal:speed_limit:speed"))
            this->railway_signal_speed_limit_speed = tags["railway:signal:speed_limit:speed"].toString();

        if (tags.contains("railway:signal:speed_limit_distant"))
            this->railway_signal_speed_limit_distant = tags["railway:signal:speed_limit_distant"].toString();

        if (tags.contains("railway:signal:speed_limit_distant:form"))
            this->railway_signal_speed_limit_distant_form = tags["railway:signal:speed_limit_distant:form"].toString();

        if (tags.contains("railway:signal:speed_limit_distant:height"))
            this->railway_signal_speed_limit_distant_height = tags["railway:signal:speed_limit_distant:height"].toString();

        if (tags.contains("railway:signal:speed_limit_distant:speed"))
            this->railway_signal_speed_limit_distant_speed = tags["railway:signal:speed_limit_distant:speed"].toString();

        if (tags.contains("railway:signal:station_distant"))
            this->railway_signal_station_distant = tags["railway:signal:station_distant"].toString();

        if (tags.contains("railway:signal:station_distant:form"))
            this->railway_signal_station_distant_form = tags["railway:signal:station_distant:form"].toString();

        if (tags.contains("railway:signal:traversable:type"))
            this->railway_signal_traversable_type = tags["railway:signal:traversable:type"].toString();

        if (tags.contains("railway:signal:whistle"))
            this->railway_signal_whistle = tags["railway:signal:whistle"].toString();

        if (tags.contains("railway:signal:whistle:form"))
            this->railway_signal_whistle_form = tags["railway:signal:whistle:form"].toString();

        if (tags.contains("railway:signal:wrong_road"))
            this->railway_signal_wrong_road = tags["railway:signal:wrong_road"].toString();

        if (tags.contains("railway:signal:wrong_road:form"))
            this->railway_signal_wrong_road_form = tags["railway:signal:wrong_road:form"].toString();

        if (tags.contains("railway:station_category"))
            this->railway_station_category = tags["railway:station_category"].toString();

        if (tags.contains("railway:switch"))
            this->railway_switch = tags["railway:switch"].toString();

        if (tags.contains("railway:switch:configuration"))
            this->railway_switch_configuration = tags["railway:switch:configuration"].toString();

        if (tags.contains("railway:switch:electric"))
            this->railway_switch_electric = tags["railway:switch:electric"].toString();

        if (tags.contains("railway:switch:movable_frog"))
            this->railway_switch_movable_frog = tags["railway:switch:movable_frog"].toString();

        if (tags.contains("railway:switch:resetting"))
            this->railway_switch_resetting = tags["railway:switch:resetting"].toString();

        if (tags.contains("railway:turnout_side"))
            this->railway_turnout_side = tags["railway:turnout_side"].toString();

        if (tags.contains("razed"))
            this->razed = tags["razed"].toString();

        if (tags.contains("ref"))
            this->ref = tags["ref"].toString();

        if (tags.contains("ref:IFOPT"))
            this->ref_IFOPT = tags["ref:IFOPT"].toString();

        if (tags.contains("ref:station"))
            this->ref_station = tags["ref:station"].toString();

        if (tags.contains("route_ref"))
            this->route_ref = tags["route_ref"].toString();

        if (tags.contains("shelter"))
            this->shelter = tags["shelter"].toString();

        if (tags.contains("source:date"))
            this->source_date = tags["source:date"].toString();

        if (tags.contains("supervised"))
            this->supervised = tags["supervised"].toString();

        if (tags.contains("tactile_paving"))
            this->tactile_paving = tags["tactile_paving"].toString();

        if (tags.contains("tourism"))
            this->tourism = tags["tourism"].toString();

        if (tags.contains("tower:type"))
            this->tower_type = tags["tower:type"].toString();

        if (tags.contains("traffic_calming"))
            this->traffic_calming = tags["traffic_calming"].toString();

        if (tags.contains("traffic_sign"))
            this->traffic_sign = tags["traffic_sign"].toString();

        if (tags.contains("train"))
            this->train = tags["train"].toString();

        if (tags.contains("uic_name"))
            this->uic_name = tags["uic_name"].toString();

        if (tags.contains("uic_ref"))
            this->uic_ref = tags["uic_ref"].toString();

        if (tags.contains("wheelchair"))
            this->wheelchair = tags["wheelchair"].toString();

        if (tags.contains("wheelchair:description"))
            this->wheelchair_description = tags["wheelchair:description"].toString();
    }

    inline QJsonObject ToQJsonObject() const
    {
        QJsonObject obj;

        obj["coord"] = coord.ToQJsonObject();

        if (!this->access.isEmpty())
            obj["access"] = this->access;

        if (!this->amenity.isEmpty())
            obj["amenity"] = this->amenity;

        if (!this->barrier.isEmpty())
            obj["barrier"] = this->barrier;

        if (!this->bench.isEmpty())
            obj["bench"] = this->bench;

        if (!this->bicycle.isEmpty())
            obj["bicycle"] = this->bicycle;

        if (!this->bin.isEmpty())
            obj["bin"] = this->bin;

        if (!this->bollard.isEmpty())
            obj["bollard"] = this->bollard;

        if (!this->bus.isEmpty())
            obj["bus"] = this->bus;

        if (!this->capacity_parent.isEmpty())
            obj["capacity:parent"] = this->capacity_parent;

        if (!this->communication_gsm_r.isEmpty())
            obj["communication:gsm-r"] = this->communication_gsm_r;

        if (!this->communication_mobile_phone.isEmpty())
            obj["communication:mobile_phone"] = this->communication_mobile_phone;

        if (!this->covered.isEmpty())
            obj["covered"] = this->covered;

        if (!this->crossing.isEmpty())
            obj["crossing"] = this->crossing;

        if (!this->crossing_activation.isEmpty())
            obj["crossing:activation"] = this->crossing_activation;

        if (!this->crossing_barrier.isEmpty())
            obj["crossing:barrier"] = this->crossing_barrier;

        if (!this->crossing_chicane.isEmpty())
            obj["crossing:chicane"] = this->crossing_chicane;

        if (!this->crossing_island.isEmpty())
            obj["crossing:island"] = this->crossing_island;

        if (!this->crossing_light.isEmpty())
            obj["crossing:light"] = this->crossing_light;

        if (!this->crossing_saltire.isEmpty())
            obj["crossing:saltire"] = this->crossing_saltire;

        if (!this->description.isEmpty())
            obj["description"] = this->description;

        if (!this->direction.isEmpty())
            obj["direction"] = this->direction;

        if (!this->direction_east.isEmpty())
            obj["direction_east"] = this->direction_east;

        if (!this->direction_south.isEmpty())
            obj["direction_south"] = this->direction_south;

        if (!this->emergency.isEmpty())
            obj["emergency"] = this->emergency;

        if (!this->emergency_telephone_code.isEmpty())
            obj["emergency_telephone_code"] = this->emergency_telephone_code;

        if (!this->fee.isEmpty())
            obj["fee"] = this->fee;

        if (!this->foot.isEmpty())
            obj["foot"] = this->foot;

        if (!this->highway.isEmpty())
            obj["highway"] = this->highway;

        if (!this->hiking.isEmpty())
            obj["hiking"] = this->hiking;

        if (!this->horse.isEmpty())
            obj["horse"] = this->horse;

        if (!this->information.isEmpty())
            obj["information"] = this->information;

        if (!this->kerb.isEmpty())
            obj["kerb"] = this->kerb;

        if (!this->lcn.isEmpty())
            obj["lcn"] = this->lcn;

        if (!this->man_made.isEmpty())
            obj["man_made"] = this->man_made;

        if (!this->material.isEmpty())
            obj["material"] = this->material;

        if (!this->name.isEmpty())
            obj["name"] = this->name;

        if (!this->network.isEmpty())
            obj["network"] = this->network;

        if (!this->noexit.isEmpty())
            obj["noexit"] = this->noexit;

        if (!this->noref.isEmpty())
            obj["noref"] = this->noref;

        if (!this->note.isEmpty())
            obj["note"] = this->note;

        if (!this->official_name.isEmpty())
            obj["official_name"] = this->official_name;

        if (!this->old_name.isEmpty())
            obj["old_name"] = this->old_name;

        if (!this->operator_.isEmpty())
            obj["operator"] = this->operator_;

        if (!this->parking.isEmpty())
            obj["parking"] = this->parking;

        if (!this->public_transport.isEmpty())
            obj["public_transport"] = this->public_transport;

        if (!this->railway.isEmpty())
            obj["railway"] = this->railway;

        if (!this->railway_derail.isEmpty())
            obj["railway:derail"] = this->railway_derail;

        if (!this->railway_local_operated.isEmpty())
            obj["railway:local_operated"] = this->railway_local_operated;

        if (!this->railway_milestone_catenary_mast.isEmpty())
            obj["railway:milestone:catenary_mast"] = this->railway_milestone_catenary_mast;

        if (!this->railway_milestone_emergency_brake_override.isEmpty())
            obj["railway:milestone:emergency_brake_override"] = this->railway_milestone_emergency_brake_override;

        if (!this->railway_position.isEmpty())
            obj["railway:position"] = this->railway_position;

        if (!this->railway_position_exact.isEmpty())
            obj["railway:position:exact"] = this->railway_position_exact;

        if (!this->railway_radio.isEmpty())
            obj["railway:radio"] = this->railway_radio;

        if (!this->railway_ref.isEmpty())
            obj["railway:ref"] = this->railway_ref;

        if (!this->railway_signal_catenary_mast.isEmpty())
            obj["railway:signal:catenary_mast"] = this->railway_signal_catenary_mast;

        if (!this->railway_signal_crossing_form.isEmpty())
            obj["railway:signal:crossing:form"] = this->railway_signal_crossing_form;

        if (!this->railway_signal_crossing_distant_form.isEmpty())
            obj["railway:signal:crossing_distant:form"] = this->railway_signal_crossing_distant_form;

        if (!this->railway_signal_direction.isEmpty())
            obj["railway:signal:direction"] = this->railway_signal_direction;

        if (!this->railway_signal_distant.isEmpty())
            obj["railway:signal:distant"] = this->railway_signal_distant;

        if (!this->railway_signal_distant_form.isEmpty())
            obj["railway:signal:distant:form"] = this->railway_signal_distant_form;

        if (!this->railway_signal_distant_height.isEmpty())
            obj["railway:signal:distant:height"] = this->railway_signal_distant_height;

        if (!this->railway_signal_distant_repeated.isEmpty())
            obj["railway:signal:distant:repeated"] = this->railway_signal_distant_repeated;

        if (!this->railway_signal_distant_shortened.isEmpty())
            obj["railway:signal:distant:shortened"] = this->railway_signal_distant_shortened;

        if (!this->railway_signal_distant_states.isEmpty())
            obj["railway:signal:distant:states"] = this->railway_signal_distant_states;

        if (!this->railway_signal_electricity.isEmpty())
            obj["railway:signal:electricity"] = this->railway_signal_electricity;

        if (!this->railway_signal_electricity_form.isEmpty())
            obj["railway:signal:electricity:form"] = this->railway_signal_electricity_form;

        if (!this->railway_signal_electricity_height.isEmpty())
            obj["railway:signal:electricity:height"] = this->railway_signal_electricity_height;

        if (!this->railway_signal_electricity_turn_direction.isEmpty())
            obj["railway:signal:electricity:turn_direction"] = this->railway_signal_electricity_turn_direction;

        if (!this->railway_signal_electricity_type.isEmpty())
            obj["railway:signal:electricity:type"] = this->railway_signal_electricity_type;

        if (!this->railway_signal_expected_position_height.isEmpty())
            obj["railway:signal:expected_position:height"] = this->railway_signal_expected_position_height;

        if (!this->railway_signal_main.isEmpty())
            obj["railway:signal:main"] = this->railway_signal_main;

        if (!this->railway_signal_main_deactivated.isEmpty())
            obj["railway:signal:main:deactivated"] = this->railway_signal_main_deactivated;

        if (!this->railway_signal_main_form.isEmpty())
            obj["railway:signal:main:form"] = this->railway_signal_main_form;

        if (!this->railway_signal_main_function.isEmpty())
            obj["railway:signal:main:function"] = this->railway_signal_main_function;

        if (!this->railway_signal_main_height.isEmpty())
            obj["railway:signal:main:height"] = this->railway_signal_main_height;

        if (!this->railway_signal_main_states.isEmpty())
            obj["railway:signal:main:states"] = this->railway_signal_main_states;

        if (!this->railway_signal_main_substitute_signal.isEmpty())
            obj["railway:signal:main:substitute_signal"] = this->railway_signal_main_substitute_signal;

        if (!this->railway_signal_main_repeated.isEmpty())
            obj["railway:signal:main_repeated"] = this->railway_signal_main_repeated;

        if (!this->railway_signal_main_repeated_form.isEmpty())
            obj["railway:signal:main_repeated:form"] = this->railway_signal_main_repeated_form;

        if (!this->railway_signal_minor.isEmpty())
            obj["railway:signal:minor"] = this->railway_signal_minor;

        if (!this->railway_signal_minor_form.isEmpty())
            obj["railway:signal:minor:form"] = this->railway_signal_minor_form;

        if (!this->railway_signal_minor_height.isEmpty())
            obj["railway:signal:minor:height"] = this->railway_signal_minor_height;

        if (!this->railway_signal_minor_states.isEmpty())
            obj["railway:signal:minor:states"] = this->railway_signal_minor_states;

        if (!this->railway_signal_position.isEmpty())
            obj["railway:signal:position"] = this->railway_signal_position;

        if (!this->railway_signal_shunting.isEmpty())
            obj["railway:signal:shunting"] = this->railway_signal_shunting;

        if (!this->railway_signal_shunting_form.isEmpty())
            obj["railway:signal:shunting:form"] = this->railway_signal_shunting_form;

        if (!this->railway_signal_shunting_height.isEmpty())
            obj["railway:signal:shunting:height"] = this->railway_signal_shunting_height;

        if (!this->railway_signal_speed_limit.isEmpty())
            obj["railway:signal:speed_limit"] = this->railway_signal_speed_limit;

        if (!this->railway_signal_speed_limit_form.isEmpty())
            obj["railway:signal:speed_limit:form"] = this->railway_signal_speed_limit_form;

        if (!this->railway_signal_speed_limit_height.isEmpty())
            obj["railway:signal:speed_limit:height"] = this->railway_signal_speed_limit_height;

        if (!this->railway_signal_speed_limit_speed.isEmpty())
            obj["railway:signal:speed_limit:speed"] = this->railway_signal_speed_limit_speed;

        if (!this->railway_signal_speed_limit_distant.isEmpty())
            obj["railway:signal:speed_limit_distant"] = this->railway_signal_speed_limit_distant;

        if (!this->railway_signal_speed_limit_distant_form.isEmpty())
            obj["railway:signal:speed_limit_distant:form"] = this->railway_signal_speed_limit_distant_form;

        if (!this->railway_signal_speed_limit_distant_height.isEmpty())
            obj["railway:signal:speed_limit_distant:height"] = this->railway_signal_speed_limit_distant_height;

        if (!this->railway_signal_speed_limit_distant_speed.isEmpty())
            obj["railway:signal:speed_limit_distant:speed"] = this->railway_signal_speed_limit_distant_speed;

        if (!this->railway_signal_station_distant.isEmpty())
            obj["railway:signal:station_distant"] = this->railway_signal_station_distant;

        if (!this->railway_signal_station_distant_form.isEmpty())
            obj["railway:signal:station_distant:form"] = this->railway_signal_station_distant_form;

        if (!this->railway_signal_traversable_type.isEmpty())
            obj["railway:signal:traversable:type"] = this->railway_signal_traversable_type;

        if (!this->railway_signal_whistle.isEmpty())
            obj["railway:signal:whistle"] = this->railway_signal_whistle;

        if (!this->railway_signal_whistle_form.isEmpty())
            obj["railway:signal:whistle:form"] = this->railway_signal_whistle_form;

        if (!this->railway_signal_wrong_road.isEmpty())
            obj["railway:signal:wrong_road"] = this->railway_signal_wrong_road;

        if (!this->railway_signal_wrong_road_form.isEmpty())
            obj["railway:signal:wrong_road:form"] = this->railway_signal_wrong_road_form;

        if (!this->railway_station_category.isEmpty())
            obj["railway:station_category"] = this->railway_station_category;

        if (!this->railway_switch.isEmpty())
            obj["railway:switch"] = this->railway_switch;

        if (!this->railway_switch_configuration.isEmpty())
            obj["railway:switch:configuration"] = this->railway_switch_configuration;

        if (!this->railway_switch_electric.isEmpty())
            obj["railway:switch:electric"] = this->railway_switch_electric;

        if (!this->railway_switch_movable_frog.isEmpty())
            obj["railway:switch:movable_frog"] = this->railway_switch_movable_frog;

        if (!this->railway_switch_resetting.isEmpty())
            obj["railway:switch:resetting"] = this->railway_switch_resetting;

        if (!this->railway_turnout_side.isEmpty())
            obj["railway:turnout_side"] = this->railway_turnout_side;

        if (!this->razed.isEmpty())
            obj["razed"] = this->razed;

        if (!this->ref.isEmpty())
            obj["ref"] = this->ref;

        if (!this->ref_IFOPT.isEmpty())
            obj["ref:IFOPT"] = this->ref_IFOPT;

        if (!this->ref_station.isEmpty())
            obj["ref:station"] = this->ref_station;

        if (!this->route_ref.isEmpty())
            obj["route_ref"] = this->route_ref;

        if (!this->shelter.isEmpty())
            obj["shelter"] = this->shelter;

        if (!this->source_date.isEmpty())
            obj["source:date"] = this->source_date;

        if (!this->supervised.isEmpty())
            obj["supervised"] = this->supervised;

        if (!this->tactile_paving.isEmpty())
            obj["tactile_paving"] = this->tactile_paving;

        if (!this->tourism.isEmpty())
            obj["tourism"] = this->tourism;

        if (!this->tower_type.isEmpty())
            obj["tower:type"] = this->tower_type;

        if (!this->traffic_calming.isEmpty())
            obj["traffic_calming"] = this->traffic_calming;

        if (!this->traffic_sign.isEmpty())
            obj["traffic_sign"] = this->traffic_sign;

        if (!this->train.isEmpty())
            obj["train"] = this->train;

        if (!this->uic_name.isEmpty())
            obj["uic_name"] = this->uic_name;

        if (!this->uic_ref.isEmpty())
            obj["uic_ref"] = this->uic_ref;

        if (!this->wheelchair.isEmpty())
            obj["wheelchair"] = this->wheelchair;

        if (!this->wheelchair_description.isEmpty())
            obj["wheelchair:description"] = this->wheelchair_description;

        return obj;
    }

    inline operator QJsonObject() const
    {
        return ToQJsonObject();
    }
};

typedef CONST WayNode           ConstWayNode;
typedef QVector<WayNode>		WayNodeVec;
typedef CONST WayNodeVec	ConstWayNodeVec;

}

#endif // __COMMON_WAYNODE_H__
