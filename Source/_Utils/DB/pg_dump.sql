--
-- PostgreSQL database dump
--

-- Dumped from database version 12.7
-- Dumped by pg_dump version 12.7

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: sc_dt_gc; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_gc;


--
-- Name: sc_dt_global; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_global;


--
-- Name: sc_dt_math; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_math;


--
-- Name: sc_dt_od_core; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_core;


--
-- Name: sc_dt_od_junction; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_junction;


--
-- Name: sc_dt_od_lane; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_lane;


--
-- Name: sc_dt_od_object; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_object;


--
-- Name: sc_dt_od_railroad; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_railroad;


--
-- Name: sc_dt_od_road; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_road;


--
-- Name: sc_dt_od_signal; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_od_signal;


--
-- Name: sc_dt_osm; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_dt_osm;


--
-- Name: sc_ods; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA sc_ods;


--
-- Name: postgis; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS postgis WITH SCHEMA public;


--
-- Name: CardinalDirection; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."CardinalDirection" AS ENUM (
    'North',
    'South',
    'East',
    'West',
    'NorthEast',
    'NorthWest',
    'SouthEast',
    'SouthWest'
);


--
-- Name: integer; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global."integer" AS bigint;


--
-- Name: Cell; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."Cell" AS (
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer"
);


--
-- Name: CoordSys; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."CoordSys" AS (
	"coordSysId" sc_dt_global."integer"
);


--
-- Name: CoordSysCell; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."CoordSysCell" AS (
	"coordSysId" sc_dt_global."integer",
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer"
);


--
-- Name: double; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global.double AS double precision;


--
-- Name: CoordSysXY; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."CoordSysXY" AS (
	"coordSysId" sc_dt_global."integer",
	x sc_dt_global.double,
	y sc_dt_global.double
);


--
-- Name: CoordSysXYCell; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."CoordSysXYCell" AS (
	"coordSysId" sc_dt_global."integer",
	x sc_dt_global.double,
	y sc_dt_global.double,
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer"
);


--
-- Name: LL; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."LL" AS (
	lat sc_dt_global.double,
	lon sc_dt_global.double
);


--
-- Name: LLCoordSysXYCell; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."LLCoordSysXYCell" AS (
	lat sc_dt_global.double,
	lon sc_dt_global.double,
	"coordSysId" sc_dt_global."integer",
	x sc_dt_global.double,
	y sc_dt_global.double,
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer"
);


--
-- Name: string; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global.string AS text;


--
-- Name: VehiclePos; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."VehiclePos" AS (
	lat sc_dt_global.double,
	lon sc_dt_global.double,
	"coordSysId" sc_dt_global."integer",
	x sc_dt_global.double,
	y sc_dt_global.double,
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer",
	id sc_dt_global."integer",
	"gpsFileId" sc_dt_global."integer",
	"gpsTow" sc_dt_global.double,
	date sc_dt_global.string,
	"time" sc_dt_global.string,
	sog sc_dt_global.double,
	roll sc_dt_global.double,
	pitch sc_dt_global.double,
	heading sc_dt_global.double,
	hdop sc_dt_global.double,
	ehpe sc_dt_global.double,
	evpe sc_dt_global.double,
	"timeSeconds" sc_dt_global.double,
	vx sc_dt_global.double,
	vy sc_dt_global.double,
	ax sc_dt_global.double,
	ay sc_dt_global.double
);


--
-- Name: XYCell; Type: TYPE; Schema: sc_dt_gc; Owner: -
--

CREATE TYPE sc_dt_gc."XYCell" AS (
	x sc_dt_global.double,
	y sc_dt_global.double,
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer"
);


--
-- Name: StringPairs; Type: TYPE; Schema: sc_dt_global; Owner: -
--

CREATE TYPE sc_dt_global."StringPairs" AS (
	keys sc_dt_global.string[],
	"values" sc_dt_global.string[]
);


--
-- Name: datetime; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global.datetime AS timestamp with time zone;


--
-- Name: int; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global."int" AS integer;


--
-- Name: int64; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global.int64 AS bigint;


--
-- Name: qstring; Type: DOMAIN; Schema: sc_dt_global; Owner: -
--

CREATE DOMAIN sc_dt_global.qstring AS text;


--
-- Name: XY; Type: TYPE; Schema: sc_dt_math; Owner: -
--

CREATE TYPE sc_dt_math."XY" AS (
	x sc_dt_global.double,
	y sc_dt_global.double
);


--
-- Name: _bridgeId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_bridgeId" AS sc_dt_global."integer";


--
-- Name: _controllerId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_controllerId" AS sc_dt_global."integer";


--
-- Name: _elementId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_elementId" AS sc_dt_global."integer";


--
-- Name: _junctionConnectionId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_junctionConnectionId" AS sc_dt_global."integer";


--
-- Name: _junctionControllerId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_junctionControllerId" AS sc_dt_global."integer";


--
-- Name: _junctionGroupId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_junctionGroupId" AS sc_dt_global."integer";


--
-- Name: _junctionId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_junctionId" AS sc_dt_global."integer";


--
-- Name: _laneId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_laneId" AS sc_dt_global."integer";


--
-- Name: _nonNegativeInteger; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_nonNegativeInteger" AS sc_dt_global."integer";


--
-- Name: _objectId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_objectId" AS sc_dt_global."integer";


--
-- Name: _outlineId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_outlineId" AS sc_dt_global."integer";


--
-- Name: _outlinePointId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_outlinePointId" AS sc_dt_global."integer";


--
-- Name: _platformId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_platformId" AS sc_dt_global."integer";


--
-- Name: _roadId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_roadId" AS sc_dt_global."integer";


--
-- Name: _signalId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_signalId" AS sc_dt_global."integer";


--
-- Name: _stationId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_stationId" AS sc_dt_global."integer";


--
-- Name: _switchId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_switchId" AS sc_dt_global."integer";


--
-- Name: _trackId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_trackId" AS sc_dt_global."integer";


--
-- Name: _tunnelId; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_tunnelId" AS sc_dt_global."integer";


--
-- Name: e_dataQuality_RawData_PostProcessing; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_dataQuality_RawData_PostProcessing" AS ENUM (
    'raw',
    'cleaned',
    'processed',
    'fused'
);


--
-- Name: e_dataQuality_RawData_Source; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_dataQuality_RawData_Source" AS ENUM (
    'sensor',
    'cadaster',
    'custom'
);


--
-- Name: e_unit; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.e_unit AS ENUM (
    'm',
    'km',
    'ft',
    'mile',
    'm/s',
    'mph',
    'km/h',
    'kg',
    't',
    '%'
);


--
-- Name: e_unitSpeed; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_unitSpeed" AS ENUM (
    'm/s',
    'mph',
    'km/h'
);


--
-- Name: t_cell; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.t_cell AS (
	"cellRow" sc_dt_global."integer",
	"cellCol" sc_dt_global."integer",
	"centerX" sc_dt_global.double,
	"centerY" sc_dt_global.double
);


--
-- Name: t_dataQuality_Error; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_dataQuality_Error" AS (
	"xyAbsolute" sc_dt_global.double,
	"zAbsolute" sc_dt_global.double,
	"xyRelative" sc_dt_global.double,
	"zRelative" sc_dt_global.double
);


--
-- Name: t_dataQuality_RawData; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_dataQuality_RawData" AS (
	date sc_dt_global.datetime,
	source sc_dt_od_core."e_dataQuality_RawData_Source",
	"sourceComment" sc_dt_global.string,
	"postProcessing" sc_dt_od_core."e_dataQuality_RawData_PostProcessing",
	"postProcessingComment" sc_dt_global.string
);


--
-- Name: t_dataQuality; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_dataQuality" AS (
	error_sequence sc_dt_od_core."t_dataQuality_Error"[],
	"rawData_sequence" sc_dt_od_core."t_dataQuality_RawData"[]
);


--
-- Name: t_grEqZero; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."t_grEqZero" AS sc_dt_global.double;


--
-- Name: t_grZero; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."t_grZero" AS sc_dt_global.double;


--
-- Name: t_include; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.t_include AS (
	file sc_dt_global.string
);


--
-- Name: Way; Type: TYPE; Schema: sc_dt_osm; Owner: -
--

CREATE TYPE sc_dt_osm."Way" AS (
	"laneCount" sc_dt_global."int",
	"leftLaneCount" sc_dt_global."int",
	"forwardLaneCount" sc_dt_global."int",
	"bidirectionalLaneCount" sc_dt_global."int",
	"rightLaneCount" sc_dt_global."int",
	"backwardLaneCount" sc_dt_global."int",
	chord_length sc_dt_global.double,
	gps_length sc_dt_global.double,
	updated_length sc_dt_global.double,
	osm sc_dt_global."StringPairs",
	center_coord sc_dt_gc."LL",
	chord_coords_sequence sc_dt_gc."VehiclePos"[],
	gps_coords_sequence sc_dt_gc."VehiclePos"[],
	updated_coords_sequence sc_dt_gc."VehiclePos"[]
);


--
-- Name: t_userData; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_userData" AS (
	code sc_dt_global.string,
	value sc_dt_global.string,
	cell_sequence sc_dt_od_core.t_cell[],
	osm_sequence sc_dt_global."StringPairs"[],
	gps_sequence sc_dt_gc."VehiclePos"[],
	trajectory_sequence sc_dt_gc."VehiclePos"[],
	"osmWay_sequence" sc_dt_osm."Way"[]
);


--
-- Name: t_header_GeoReference; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_header_GeoReference" AS (
	proj sc_dt_global.string,
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_header_Offset; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_header_Offset" AS (
	x sc_dt_global.double,
	y sc_dt_global.double,
	hdg sc_dt_global.double,
	z sc_dt_global.double,
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_header; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.t_header AS (
	"revMajor" sc_dt_global."integer",
	"revMinor" sc_dt_global."integer",
	name sc_dt_global.string,
	version sc_dt_global.string,
	date sc_dt_global.datetime,
	north sc_dt_global.double,
	south sc_dt_global.double,
	east sc_dt_global.double,
	west sc_dt_global.double,
	vendor sc_dt_global.string,
	"geoReference_sequence" sc_dt_od_core."t_header_GeoReference"[],
	offset_sequence sc_dt_od_core."t_header_Offset"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_yesNo; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."t_yesNo" AS ENUM (
    'yes',
    'no'
);


--
-- Name: t_zeroOne; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."t_zeroOne" AS sc_dt_global.double;


--
-- Name: e_contactPoint; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."e_contactPoint" AS ENUM (
    'start',
    'end'
);


--
-- Name: e_elementDir; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."e_elementDir" AS ENUM (
    '+',
    '-'
);


--
-- Name: e_junctionGroup_type; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."e_junctionGroup_type" AS ENUM (
    'roundabout',
    'unknown'
);


--
-- Name: e_junction_type; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.e_junction_type AS ENUM (
    'default',
    'virtual'
);


--
-- Name: e_road_surface_CRG_mode; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."e_road_surface_CRG_mode" AS ENUM (
    'attached',
    'attached0',
    'genuine',
    'global'
);


--
-- Name: e_road_surface_CRG_purpose; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."e_road_surface_CRG_purpose" AS ENUM (
    'elevation',
    'friction'
);


--
-- Name: t_junction_connection_laneLink; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."t_junction_connection_laneLink" AS (
	"from" sc_dt_od_core."_laneId",
	"to" sc_dt_od_core."_laneId"
);


--
-- Name: e_road_link_elementType; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_road_link_elementType" AS ENUM (
    'road',
    'junction'
);


--
-- Name: t_junction_predecessorSuccessor; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."t_junction_predecessorSuccessor" AS (
	"elementType" sc_dt_od_road."e_road_link_elementType",
	"elementId" sc_dt_od_core."_elementId",
	"elementS" sc_dt_od_core."t_grZero",
	"elementDir" sc_dt_od_junction."e_elementDir"
);


--
-- Name: t_junction_connection; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.t_junction_connection AS (
	id sc_dt_od_core."_junctionConnectionId",
	type sc_dt_od_junction.e_junction_type,
	"incomingRoad" sc_dt_od_core."_roadId",
	"connectingRoad" sc_dt_od_core."_roadId",
	"contactPoint" sc_dt_od_junction."e_contactPoint",
	predecessor_sequence sc_dt_od_junction."t_junction_predecessorSuccessor"[],
	successor_sequence sc_dt_od_junction."t_junction_predecessorSuccessor"[],
	"laneLink_sequence" sc_dt_od_junction."t_junction_connection_laneLink"[]
);


--
-- Name: t_junction_controller; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.t_junction_controller AS (
	id sc_dt_od_core."_junctionControllerId",
	type sc_dt_global.string,
	sequence sc_dt_od_core."_nonNegativeInteger"
);


--
-- Name: t_junction_priority; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.t_junction_priority AS (
	high sc_dt_od_core."_roadId",
	low sc_dt_od_core."_roadId"
);


--
-- Name: t_junction_surface_CRG; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."t_junction_surface_CRG" AS (
	file sc_dt_global.string,
	mode sc_dt_od_junction."e_road_surface_CRG_mode",
	purpose sc_dt_od_junction."e_road_surface_CRG_purpose",
	"zOffset" sc_dt_global.double,
	"zScale" sc_dt_global.double
);


--
-- Name: t_junction_surface; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.t_junction_surface AS (
	"CRG_sequence" sc_dt_od_junction."t_junction_surface_CRG"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_junction; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction.t_junction AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_junctionId",
	type sc_dt_od_junction.e_junction_type,
	connection_sequence sc_dt_od_junction.t_junction_connection[],
	priority_sequence sc_dt_od_junction.t_junction_priority[],
	controller_sequence sc_dt_od_junction.t_junction_controller[],
	surface_sequence sc_dt_od_junction.t_junction_surface[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_junctionGroup_junctionReference; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."t_junctionGroup_junctionReference" AS (
	junction sc_dt_od_core."_junctionId"
);


--
-- Name: t_junctionGroup; Type: TYPE; Schema: sc_dt_od_junction; Owner: -
--

CREATE TYPE sc_dt_od_junction."t_junctionGroup" AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_junctionGroupId",
	type sc_dt_od_junction."e_junctionGroup_type",
	"junctionReference_sequence" sc_dt_od_junction."t_junctionGroup_junctionReference"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: e_accessRestrictionType; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_accessRestrictionType" AS ENUM (
    'simulator',
    'autonomousTraffic',
    'pedestrian',
    'passengerCar',
    'bus',
    'delivery',
    'emergency',
    'taxi',
    'throughTraffic',
    'truck',
    'bicycle',
    'motorcycle',
    'none',
    'trucks'
);


--
-- Name: e_laneType; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_laneType" AS ENUM (
    'shoulder',
    'border',
    'driving',
    'stop',
    'none',
    'restricted',
    'parking',
    'median',
    'biking',
    'sidewalk',
    'curb',
    'exit',
    'entry',
    'onRamp',
    'offRamp',
    'connectingRamp',
    'bidirectional',
    'special1',
    'special2',
    'special3',
    'roadWorks',
    'tram',
    'rail',
    'bus',
    'taxi',
    'HOV',
    'mwyEntry',
    'mwyExit'
);


--
-- Name: e_roadMarkColor; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_roadMarkColor" AS ENUM (
    'standard',
    'blue',
    'green',
    'red',
    'white',
    'yellow',
    'orange'
);


--
-- Name: e_roadMarkRule; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_roadMarkRule" AS ENUM (
    'no passing',
    'caution',
    'none'
);


--
-- Name: e_roadMarkType; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_roadMarkType" AS ENUM (
    'none',
    'solid',
    'broken',
    'solid solid',
    'solid broken',
    'broken solid',
    'broken broken',
    'botts dots',
    'grass',
    'curb',
    'custom',
    'edge'
);


--
-- Name: e_roadMarkWeight; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_roadMarkWeight" AS ENUM (
    'standard',
    'bold'
);


--
-- Name: e_road_lanes_laneSection_lcr_lane_roadMark_laneChange; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_road_lanes_laneSection_lcr_lane_roadMark_laneChange" AS ENUM (
    'increase',
    'decrease',
    'both',
    'none'
);


--
-- Name: e_road_lanes_laneSection_lr_lane_access_rule; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."e_road_lanes_laneSection_lr_lane_access_rule" AS ENUM (
    'allow',
    'deny'
);


--
-- Name: t_bool; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane.t_bool AS ENUM (
    'false',
    'true'
);


--
-- Name: t_road_lanes_laneOffset; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneOffset" AS (
	s sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor" AS (
	id sc_dt_od_core."_laneId"
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_link; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link" AS (
	predecessor_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor"[],
	successor_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line" AS (
	length sc_dt_global.string,
	"sOffset" sc_dt_od_core."t_grEqZero",
	"tOffset" sc_dt_global.double,
	rule sc_dt_od_lane."e_roadMarkRule",
	width sc_dt_global.string
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark_explicit; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_explicit" AS (
	line_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark_sway; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_sway" AS (
	ds sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark_type_line; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_type_line" AS (
	length sc_dt_global.string,
	space sc_dt_od_core."t_grEqZero",
	"sOffset" sc_dt_od_core."t_grEqZero",
	"tOffset" sc_dt_global.double,
	rule sc_dt_od_lane."e_roadMarkRule",
	width sc_dt_global.string,
	color sc_dt_od_lane."e_roadMarkColor"
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark_type; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_type" AS (
	name sc_dt_global.string,
	width sc_dt_od_core."t_grEqZero",
	line_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_type_line"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_lcr_lane_roadMark; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	type sc_dt_od_lane."e_roadMarkType",
	weight sc_dt_od_lane."e_roadMarkWeight",
	color sc_dt_od_lane."e_roadMarkColor",
	material sc_dt_global.string,
	width sc_dt_od_core."t_grEqZero",
	"laneChange" sc_dt_od_lane."e_road_lanes_laneSection_lcr_lane_roadMark_laneChange",
	height sc_dt_global.double,
	sway_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_sway"[],
	type_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_type"[],
	explicit_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark_explicit"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_lr_lane_access; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	rule sc_dt_od_lane."e_road_lanes_laneSection_lr_lane_access_rule",
	restriction sc_dt_od_lane."e_accessRestrictionType"
);


--
-- Name: t_road_lanes_laneSection_lr_lane_border; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lanes_laneSection_lr_lane_height; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	"inner" sc_dt_global.double,
	"outer" sc_dt_global.double
);


--
-- Name: t_road_lanes_laneSection_lr_lane_material; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	surface sc_dt_global.string,
	friction sc_dt_od_core."t_grEqZero",
	roughness sc_dt_od_core."t_grEqZero"
);


--
-- Name: t_road_lanes_laneSection_lr_lane_rule; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	value sc_dt_global.string
);


--
-- Name: t_road_lanes_laneSection_lr_lane_speed; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	max sc_dt_od_core."t_grEqZero",
	unit sc_dt_od_core."e_unitSpeed"
);


--
-- Name: t_road_lanes_laneSection_lr_lane_width; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lanes_laneSection_center_lane; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_center_lane" AS (
	id sc_dt_od_core."_laneId",
	type sc_dt_od_lane."e_laneType",
	level sc_dt_od_lane.t_bool,
	link_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link"[],
	border_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border"[],
	width_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width"[],
	"roadMark_sequence" sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark"[],
	material_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material"[],
	speed_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed"[],
	access_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access"[],
	height_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height"[],
	rule_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_center; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_center" AS (
	lane_sequence sc_dt_od_lane."t_road_lanes_laneSection_center_lane"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_left_lane; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_left_lane" AS (
	id sc_dt_od_core."_laneId",
	type sc_dt_od_lane."e_laneType",
	level sc_dt_od_lane.t_bool,
	link_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link"[],
	border_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border"[],
	width_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width"[],
	"roadMark_sequence" sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark"[],
	material_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material"[],
	speed_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed"[],
	access_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access"[],
	height_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height"[],
	rule_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_left; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_left" AS (
	lane_sequence sc_dt_od_lane."t_road_lanes_laneSection_left_lane"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_right_lane; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_right_lane" AS (
	id sc_dt_od_core."_laneId",
	type sc_dt_od_lane."e_laneType",
	level sc_dt_od_lane.t_bool,
	link_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link"[],
	border_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border"[],
	width_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width"[],
	"roadMark_sequence" sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark"[],
	material_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material"[],
	speed_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed"[],
	access_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access"[],
	height_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height"[],
	rule_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection_right; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_right" AS (
	lane_sequence sc_dt_od_lane."t_road_lanes_laneSection_right_lane"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes_laneSection; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection" AS (
	s sc_dt_od_core."t_grEqZero",
	"singleSide" sc_dt_od_lane.t_bool,
	left_sequence sc_dt_od_lane."t_road_lanes_laneSection_left"[],
	center sc_dt_od_lane."t_road_lanes_laneSection_center",
	right_sequence sc_dt_od_lane."t_road_lanes_laneSection_right"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lanes; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane.t_road_lanes AS (
	"laneOffset_sequence" sc_dt_od_lane."t_road_lanes_laneOffset"[],
	"laneSection_sequence" sc_dt_od_lane."t_road_lanes_laneSection"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_laneValidity; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_objects_object_laneValidity" AS (
	"fromLane" sc_dt_od_core."_laneId",
	"toLane" sc_dt_od_core."_laneId"
);


--
-- Name: e_borderType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_borderType" AS ENUM (
    'concrete',
    'curb'
);


--
-- Name: e_bridgeType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_bridgeType" AS ENUM (
    'concrete',
    'steel',
    'brick',
    'wood'
);


--
-- Name: e_objectType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_objectType" AS ENUM (
    'none',
    'obstacle',
    'car',
    'pole',
    'tree',
    'vegetation',
    'barrier',
    'building',
    'parkingSpace',
    'patch',
    'railing',
    'trafficIsland',
    'crosswalk',
    'streetLamp',
    'gantry',
    'soundBarrier',
    'van',
    'bus',
    'trailer',
    'bike',
    'motorbike',
    'tram',
    'train',
    'pedestrian',
    'wind',
    'roadMark'
);


--
-- Name: e_orientation; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.e_orientation AS ENUM (
    '+',
    '-',
    'none'
);


--
-- Name: e_outlineFillType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_outlineFillType" AS ENUM (
    'grass',
    'concrete',
    'cobble',
    'asphalt',
    'pavement',
    'gravel',
    'soil'
);


--
-- Name: e_road_objects_object_parkingSpace_access; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_road_objects_object_parkingSpace_access" AS ENUM (
    'all',
    'car',
    'women',
    'handicapped',
    'bus',
    'truck',
    'electric',
    'residents'
);


--
-- Name: e_sideType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_sideType" AS ENUM (
    'left',
    'right',
    'front',
    'rear'
);


--
-- Name: e_tunnelType; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."e_tunnelType" AS ENUM (
    'standard',
    'underpass'
);


--
-- Name: t_road_objects_bridge; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_bridge AS (
	s sc_dt_od_core."t_grEqZero",
	length sc_dt_od_core."t_grEqZero",
	name sc_dt_global.string,
	id sc_dt_od_core."_bridgeId",
	type sc_dt_od_object."e_bridgeType",
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_markings_marking_cornerReference; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."t_road_objects_object_markings_marking_cornerReference" AS (
	id sc_dt_od_core."_outlinePointId"
);


--
-- Name: t_road_objects_object_borders_border; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_borders_border AS (
	width sc_dt_od_core."t_grEqZero",
	type sc_dt_od_object."e_borderType",
	"outlineId" sc_dt_od_core."_outlineId",
	"useCompleteOutline" sc_dt_od_lane.t_bool,
	"cornerReference_sequence" sc_dt_od_object."t_road_objects_object_markings_marking_cornerReference"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_borders; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_borders AS (
	border_sequence sc_dt_od_object.t_road_objects_object_borders_border[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_markings_marking; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_markings_marking AS (
	side sc_dt_od_object."e_sideType",
	weight sc_dt_od_lane."e_roadMarkWeight",
	width sc_dt_global.string,
	color sc_dt_od_lane."e_roadMarkColor",
	"zOffset" sc_dt_od_core."t_grEqZero",
	"spaceLength" sc_dt_od_core."t_grEqZero",
	"lineLength" sc_dt_global.string,
	"startOffset" sc_dt_global.double,
	"stopOffset" sc_dt_global.double,
	"cornerReference_sequence" sc_dt_od_object."t_road_objects_object_markings_marking_cornerReference"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_markings; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_markings AS (
	marking_sequence sc_dt_od_object.t_road_objects_object_markings_marking[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_material; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_material AS (
	surface sc_dt_global.string,
	friction sc_dt_od_core."t_grEqZero",
	roughness sc_dt_od_core."t_grEqZero"
);


--
-- Name: t_road_objects_object_outlines_outline_cornerLocal; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."t_road_objects_object_outlines_outline_cornerLocal" AS (
	u sc_dt_global.double,
	v sc_dt_global.double,
	z sc_dt_global.double,
	height sc_dt_global.double,
	id sc_dt_od_core."_outlinePointId"
);


--
-- Name: t_road_objects_object_outlines_outline_cornerRoad; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."t_road_objects_object_outlines_outline_cornerRoad" AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	dz sc_dt_global.double,
	height sc_dt_global.double,
	id sc_dt_od_core."_outlinePointId"
);


--
-- Name: t_road_objects_object_outlines_outline; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_outlines_outline AS (
	id sc_dt_od_core."_outlineId",
	"fillType" sc_dt_od_object."e_outlineFillType",
	"outer" sc_dt_od_lane.t_bool,
	closed sc_dt_od_lane.t_bool,
	"laneType" sc_dt_od_lane."e_laneType",
	"cornerRoad_sequence" sc_dt_od_object."t_road_objects_object_outlines_outline_cornerRoad"[],
	"cornerLocal_sequence" sc_dt_od_object."t_road_objects_object_outlines_outline_cornerLocal"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_outlines; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_outlines AS (
	outline_sequence sc_dt_od_object.t_road_objects_object_outlines_outline[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_object_parkingSpace; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."t_road_objects_object_parkingSpace" AS (
	access sc_dt_od_object."e_road_objects_object_parkingSpace_access",
	restrictions sc_dt_global.string
);


--
-- Name: t_road_objects_object_repeat; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object_repeat AS (
	s sc_dt_od_core."t_grEqZero",
	length sc_dt_od_core."t_grEqZero",
	distance sc_dt_od_core."t_grEqZero",
	"tStart" sc_dt_global.double,
	"tEnd" sc_dt_global.double,
	"heightStart" sc_dt_global.double,
	"heightEnd" sc_dt_global.double,
	"zOffsetStart" sc_dt_global.double,
	"zOffsetEnd" sc_dt_global.double,
	"widthStart" sc_dt_od_core."t_grEqZero",
	"widthEnd" sc_dt_od_core."t_grEqZero",
	"lengthStart" sc_dt_od_core."t_grEqZero",
	"lengthEnd" sc_dt_od_core."t_grEqZero",
	"radiusStart" sc_dt_od_core."t_grEqZero",
	"radiusEnd" sc_dt_od_core."t_grEqZero"
);


--
-- Name: t_road_objects_object; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_object AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	"zOffset" sc_dt_global.double,
	type sc_dt_od_object."e_objectType",
	"validLength" sc_dt_od_core."t_grEqZero",
	orientation sc_dt_od_object.e_orientation,
	subtype sc_dt_global.string,
	dynamic sc_dt_od_core."t_yesNo",
	hdg sc_dt_global.double,
	name sc_dt_global.string,
	pitch sc_dt_global.double,
	id sc_dt_od_core."_objectId",
	roll sc_dt_global.double,
	height sc_dt_global.double,
	length sc_dt_global.double,
	width sc_dt_global.double,
	radius sc_dt_global.double,
	repeat_sequence sc_dt_od_object.t_road_objects_object_repeat[],
	outline_sequence sc_dt_od_object.t_road_objects_object_outlines_outline[],
	outlines_sequence sc_dt_od_object.t_road_objects_object_outlines[],
	material_sequence sc_dt_od_object.t_road_objects_object_material[],
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	"parkingSpace_sequence" sc_dt_od_object."t_road_objects_object_parkingSpace"[],
	markings_sequence sc_dt_od_object.t_road_objects_object_markings[],
	borders_sequence sc_dt_od_object.t_road_objects_object_borders[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_objectReference; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object."t_road_objects_objectReference" AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	id sc_dt_od_core."_objectId",
	"zOffset" sc_dt_global.double,
	"validLength" sc_dt_od_core."t_grEqZero",
	orientation sc_dt_od_object.e_orientation,
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects_tunnel; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects_tunnel AS (
	s sc_dt_od_core."t_grEqZero",
	length sc_dt_od_core."t_grEqZero",
	name sc_dt_global.string,
	id sc_dt_od_core."_tunnelId",
	type sc_dt_od_object."e_tunnelType",
	lighting sc_dt_od_core."t_zeroOne",
	daylight sc_dt_od_core."t_zeroOne",
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_objects; Type: TYPE; Schema: sc_dt_od_object; Owner: -
--

CREATE TYPE sc_dt_od_object.t_road_objects AS (
	object_sequence sc_dt_od_object.t_road_objects_object[],
	"objectReference_sequence" sc_dt_od_object."t_road_objects_objectReference"[],
	tunnel_sequence sc_dt_od_object.t_road_objects_tunnel[],
	bridge_sequence sc_dt_od_object.t_road_objects_bridge[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: e_road_railroad_switch_position; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.e_road_railroad_switch_position AS ENUM (
    'dynamic',
    'straight',
    'turn'
);


--
-- Name: e_station_platform_segment_side; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.e_station_platform_segment_side AS ENUM (
    'left',
    'right'
);


--
-- Name: e_station_type; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.e_station_type AS ENUM (
    'small',
    'medium',
    'large'
);


--
-- Name: t_road_railroad_switch_mainTrack; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad."t_road_railroad_switch_mainTrack" AS (
	id sc_dt_od_core."_trackId",
	s sc_dt_od_core."t_grEqZero",
	dir sc_dt_od_junction."e_elementDir",
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_railroad_switch_partner; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_road_railroad_switch_partner AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_switchId",
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_railroad_switch_sideTrack; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad."t_road_railroad_switch_sideTrack" AS (
	id sc_dt_od_core."_trackId",
	s sc_dt_od_core."t_grEqZero",
	dir sc_dt_od_junction."e_elementDir",
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_railroad_switch; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_road_railroad_switch AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_switchId",
	"position" sc_dt_od_railroad.e_road_railroad_switch_position,
	"mainTrack_sequence" sc_dt_od_railroad."t_road_railroad_switch_mainTrack"[],
	"sideTrack_sequence" sc_dt_od_railroad."t_road_railroad_switch_sideTrack"[],
	partner_sequence sc_dt_od_railroad.t_road_railroad_switch_partner[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_railroad; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_road_railroad AS (
	switch_sequence sc_dt_od_railroad.t_road_railroad_switch[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_station_platform_segment; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_station_platform_segment AS (
	"roadId" sc_dt_od_core."_roadId",
	"sStart" sc_dt_od_core."t_grEqZero",
	"sEnd" sc_dt_od_core."t_grEqZero",
	side sc_dt_od_railroad.e_station_platform_segment_side
);


--
-- Name: t_station_platform; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_station_platform AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_platformId",
	segment_sequence sc_dt_od_railroad.t_station_platform_segment[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_station; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_station AS (
	name sc_dt_global.string,
	id sc_dt_od_core."_stationId",
	type sc_dt_od_railroad.e_station_type,
	platform_sequence sc_dt_od_railroad.t_station_platform[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: e_countryCode; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_countryCode" AS ENUM (
    'AD',
    'AE',
    'AF',
    'AG',
    'AI',
    'AL',
    'AM',
    'AO',
    'AR',
    'AT',
    'AU',
    'AZ',
    'BA',
    'BB',
    'BD',
    'BE',
    'BF',
    'BG',
    'BH',
    'BI',
    'BJ',
    'BM',
    'BN',
    'BO',
    'BR',
    'BS',
    'BT',
    'BW',
    'BY',
    'BZ',
    'CA',
    'CD',
    'CF',
    'CG',
    'CH',
    'CI',
    'CK',
    'CL',
    'CM',
    'CN',
    'CO',
    'CR',
    'CU',
    'CV',
    'CY',
    'CZ',
    'DE',
    'DJ',
    'DK',
    'DM',
    'DO',
    'DZ',
    'EC',
    'EE',
    'EG',
    'EH',
    'ER',
    'ES',
    'ET',
    'FI',
    'FJ',
    'FK',
    'FM',
    'FO',
    'FR',
    'GA',
    'GB',
    'GD',
    'GE',
    'GG',
    'GH',
    'GI',
    'GL',
    'GM',
    'GN',
    'GQ',
    'GR',
    'GS',
    'GT',
    'GW',
    'GY',
    'HN',
    'HR',
    'HT',
    'HU',
    'ID',
    'IE',
    'IL',
    'IM',
    'IN',
    'IO',
    'IQ',
    'IR',
    'IS',
    'IT',
    'JE',
    'JM',
    'JO',
    'JP',
    'KE',
    'KG',
    'KH',
    'KI',
    'KM',
    'KN',
    'KP',
    'KR',
    'KW',
    'KY',
    'KZ',
    'LA',
    'LB',
    'LC',
    'LI',
    'LK',
    'LR',
    'LS',
    'LT',
    'LU',
    'LV',
    'LY',
    'MA',
    'MC',
    'MD',
    'ME',
    'MG',
    'MH',
    'MK',
    'ML',
    'MM',
    'MN',
    'MR',
    'MS',
    'MT',
    'MU',
    'MV',
    'MW',
    'MX',
    'MY',
    'MZ',
    'NA',
    'NE',
    'NG',
    'NI',
    'NL',
    'NO',
    'NP',
    'NR',
    'NU',
    'NZ',
    'OM',
    'PA',
    'PE',
    'PG',
    'PH',
    'PK',
    'PL',
    'PN',
    'PT',
    'PW',
    'PY',
    'QA',
    'RO',
    'RS',
    'RU',
    'RW',
    'SA',
    'SB',
    'SC',
    'SD',
    'SE',
    'SG',
    'SH',
    'SI',
    'SK',
    'SL',
    'SM',
    'SN',
    'SO',
    'SR',
    'SS',
    'ST',
    'SV',
    'SY',
    'SZ',
    'TC',
    'TD',
    'TG',
    'TH',
    'TJ',
    'TK',
    'TL',
    'TM',
    'TN',
    'TO',
    'TR',
    'TT',
    'TV',
    'TW',
    'TZ',
    'UA',
    'UG',
    'US',
    'UY',
    'UZ',
    'VA',
    'VC',
    'VE',
    'VG',
    'VN',
    'VU',
    'WS',
    'XK',
    'YE',
    'ZA',
    'ZM',
    'ZW',
    'AFG',
    'AGO',
    'AIA',
    'ALB',
    'AND',
    'ARE',
    'ARG',
    'ARM',
    'ATG',
    'AUS',
    'AUT',
    'AZE',
    'BDI',
    'BEL',
    'BEN',
    'BFA',
    'BGD',
    'BGR',
    'BHR',
    'BHS',
    'BIH',
    'BLR',
    'BLZ',
    'BMU',
    'BOL',
    'BRA',
    'BRB',
    'BRN',
    'BTN',
    'BWA',
    'CAF',
    'CAN',
    'CHE',
    'CHL',
    'CHN',
    'CIV',
    'CMR',
    'COD',
    'COG',
    'COK',
    'COL',
    'COM',
    'CPV',
    'CRI',
    'CUB',
    'CYM',
    'CYP',
    'CZE',
    'DEU',
    'DJI',
    'DMA',
    'DNK',
    'DOM',
    'DZA',
    'ECU',
    'EGY',
    'ERI',
    'ESH',
    'ESP',
    'EST',
    'ETH',
    'FIN',
    'FJI',
    'FLK',
    'FRA',
    'FRO',
    'FSM',
    'GAB',
    'GBR',
    'GEO',
    'GGY',
    'GHA',
    'GIB',
    'GIN',
    'GMB',
    'GNB',
    'GNQ',
    'GRC',
    'GRD',
    'GRL',
    'GTM',
    'GUY',
    'HND',
    'HRV',
    'HTI',
    'HUN',
    'IDN',
    'IMN',
    'IND',
    'IOT',
    'IRL',
    'IRN',
    'IRQ',
    'ISL',
    'ISR',
    'ITA',
    'JAM',
    'JEY',
    'JOR',
    'JPN',
    'KAZ',
    'KEN',
    'KGZ',
    'KHM',
    'KIR',
    'KNA',
    'KOR',
    'KWT',
    'LAO',
    'LBN',
    'LBR',
    'LBY',
    'LCA',
    'LIE',
    'LKA',
    'LSO',
    'LTU',
    'LUX',
    'LVA',
    'MAR',
    'MCO',
    'MDA',
    'MDG',
    'MDV',
    'MEX',
    'MHL',
    'MKD',
    'MLI',
    'MLT',
    'MMR',
    'MNE',
    'MNG',
    'MOZ',
    'MRT',
    'MSR',
    'MUS',
    'MWI',
    'MYS',
    'NAM',
    'NER',
    'NGA',
    'NIC',
    'NIU',
    'NLD',
    'NOR',
    'NPL',
    'NRU',
    'NZL',
    'OMN',
    'PAK',
    'PAN',
    'PCN',
    'PER',
    'PHL',
    'PLW',
    'PNG',
    'POL',
    'PRK',
    'PRT',
    'PRY',
    'QAT',
    'ROU',
    'RUS',
    'RWA',
    'SAU',
    'SDN',
    'SEN',
    'SGP',
    'SGS',
    'SHN',
    'SLB',
    'SLE',
    'SLV',
    'SMR',
    'SOM',
    'SRB',
    'SSD',
    'STP',
    'SUR',
    'SVK',
    'SVN',
    'SWE',
    'SWZ',
    'SYC',
    'SYR',
    'TCA',
    'TCD',
    'TGO',
    'THA',
    'TJK',
    'TKL',
    'TKM',
    'TLS',
    'TON',
    'TTO',
    'TUN',
    'TUR',
    'TUV',
    'TWN',
    'TZA',
    'UGA',
    'UKR',
    'URY',
    'USA',
    'UZB',
    'VAT',
    'VCT',
    'VEN',
    'VGB',
    'VNM',
    'VUT',
    'WSM',
    'XKX',
    'YEM',
    'ZAF',
    'ZMB',
    'ZWE',
    'OpenDRIVE',
    'Austria',
    'Brazil',
    'China',
    'France',
    'Germany',
    'Italy',
    'Switzerland'
);


--
-- Name: e_direction; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.e_direction AS ENUM (
    'same',
    'opposite'
);


--
-- Name: e_paramPoly3_pRange; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_paramPoly3_pRange" AS ENUM (
    'arcLength',
    'normalized'
);


--
-- Name: e_roadType; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_roadType" AS ENUM (
    'unknown',
    'rural',
    'motorway',
    'town',
    'lowSpeed',
    'pedestrian',
    'bicycle',
    'townExpressway',
    'townCollector',
    'townArterial',
    'townPrivate',
    'townLocal',
    'townPlayStreet'
);


--
-- Name: e_trafficRule; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_trafficRule" AS ENUM (
    'RHT',
    'LHT'
);


--
-- Name: t_maxSpeed; Type: DOMAIN; Schema: sc_dt_od_road; Owner: -
--

CREATE DOMAIN sc_dt_od_road."t_maxSpeed" AS sc_dt_global.string;


--
-- Name: t_road_elevationProfile_elevation; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_elevationProfile_elevation" AS (
	s sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_elevationProfile; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_elevationProfile" AS (
	elevation_sequence sc_dt_od_road."t_road_elevationProfile_elevation"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_lateralProfile_shape; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_lateralProfile_shape" AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lateralProfile_superelevation; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_lateralProfile_superelevation" AS (
	s sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_lateralProfile; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_lateralProfile" AS (
	superelevation_sequence sc_dt_od_road."t_road_lateralProfile_superelevation"[],
	shape_sequence sc_dt_od_road."t_road_lateralProfile_shape"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_link_predecessorSuccessor; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_link_predecessorSuccessor" AS (
	"elementId" sc_dt_od_core."_elementId",
	"elementType" sc_dt_od_road."e_road_link_elementType",
	"contactPoint" sc_dt_od_junction."e_contactPoint",
	"elementS" sc_dt_od_core."t_grEqZero",
	"elementDir" sc_dt_od_junction."e_elementDir"
);


--
-- Name: t_road_link; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.t_road_link AS (
	predecessor_sequence sc_dt_od_road."t_road_link_predecessorSuccessor"[],
	successor_sequence sc_dt_od_road."t_road_link_predecessorSuccessor"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_planView_geometry_arc; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry_arc" AS (
	curvature sc_dt_global.double
);


--
-- Name: t_road_planView_geometry_line; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry_line" AS (
);


--
-- Name: t_road_planView_geometry_paramPoly3; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry_paramPoly3" AS (
	"aU" sc_dt_global.double,
	"bU" sc_dt_global.double,
	"cU" sc_dt_global.double,
	"dU" sc_dt_global.double,
	"aV" sc_dt_global.double,
	"bV" sc_dt_global.double,
	"cV" sc_dt_global.double,
	"dV" sc_dt_global.double,
	"pRange" sc_dt_od_road."e_paramPoly3_pRange"
);


--
-- Name: t_road_planView_geometry_poly3; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry_poly3" AS (
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: t_road_planView_geometry_spiral; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry_spiral" AS (
	"curvStart" sc_dt_global.double,
	"curvEnd" sc_dt_global.double
);


--
-- Name: t_road_planView_geometry; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView_geometry" AS (
	s sc_dt_od_core."t_grEqZero",
	x sc_dt_global.double,
	y sc_dt_global.double,
	hdg sc_dt_global.double,
	length sc_dt_global.double,
	line_sequence sc_dt_od_road."t_road_planView_geometry_line"[],
	spiral_sequence sc_dt_od_road."t_road_planView_geometry_spiral"[],
	arc_sequence sc_dt_od_road."t_road_planView_geometry_arc"[],
	poly3_sequence sc_dt_od_road."t_road_planView_geometry_poly3"[],
	parampoly3_sequence sc_dt_od_road."t_road_planView_geometry_paramPoly3"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_planView; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_planView" AS (
	geometry_sequence sc_dt_od_road."t_road_planView_geometry"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_surface_CRG; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."t_road_surface_CRG" AS (
	file sc_dt_global.string,
	"sStart" sc_dt_od_core."t_grEqZero",
	"sEnd" sc_dt_od_core."t_grEqZero",
	orientation sc_dt_od_road.e_direction,
	mode sc_dt_od_junction."e_road_surface_CRG_mode",
	purpose sc_dt_od_junction."e_road_surface_CRG_purpose",
	"sOffset" sc_dt_global.double,
	"tOffset" sc_dt_global.double,
	"zOffset" sc_dt_global.double,
	"zScale" sc_dt_global.double,
	"hOffset" sc_dt_global.double
);


--
-- Name: t_road_surface; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.t_road_surface AS (
	"CRG_sequence" sc_dt_od_road."t_road_surface_CRG"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_type_speed; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.t_road_type_speed AS (
	max sc_dt_od_road."t_maxSpeed",
	unit sc_dt_od_core."e_unitSpeed"
);


--
-- Name: t_road_type; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.t_road_type AS (
	s sc_dt_od_core."t_grEqZero",
	type sc_dt_od_road."e_roadType",
	country sc_dt_od_road."e_countryCode",
	speed_sequence sc_dt_od_road.t_road_type_speed[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: e_road_signals_signal_reference_elementType; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal."e_road_signals_signal_reference_elementType" AS ENUM (
    'object',
    'signal'
);


--
-- Name: e_road_signals_signal_type; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.e_road_signals_signal_type AS ENUM (
    'traffic_lights',
    'crossing',
    'traffic_calming',
    'traffic_sign',
    'traffic_signal'
);


--
-- Name: t_road_signals_signal_dependency; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_road_signals_signal_dependency AS (
	id sc_dt_od_core."_signalId",
	type sc_dt_global.string
);


--
-- Name: t_road_signals_signal_positionInertial; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal."t_road_signals_signal_positionInertial" AS (
	x sc_dt_global.double,
	y sc_dt_global.double,
	hdg sc_dt_global.double,
	z sc_dt_global.double,
	pitch sc_dt_global.double,
	roll sc_dt_global.double
);


--
-- Name: t_road_signals_signal_positionRoad; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal."t_road_signals_signal_positionRoad" AS (
	"roadId" sc_dt_od_core."_roadId",
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	"zOffset" sc_dt_global.double,
	"hOffset" sc_dt_global.double,
	pitch sc_dt_global.double,
	roll sc_dt_global.double
);


--
-- Name: t_road_signals_signal_reference; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_road_signals_signal_reference AS (
	"elementType" sc_dt_od_signal."e_road_signals_signal_reference_elementType",
	"elementId" sc_dt_od_core."_elementId",
	type sc_dt_global.string
);


--
-- Name: t_road_signals_signal; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_road_signals_signal AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	id sc_dt_od_core."_signalId",
	name sc_dt_global.string,
	dynamic sc_dt_od_core."t_yesNo",
	orientation sc_dt_od_object.e_orientation,
	"zOffset" sc_dt_global.double,
	country sc_dt_od_road."e_countryCode",
	"countryRevision" sc_dt_global.string,
	type sc_dt_od_signal.e_road_signals_signal_type,
	subtype sc_dt_global.string,
	value sc_dt_global.double,
	unit sc_dt_od_core.e_unit,
	height sc_dt_od_core."t_grEqZero",
	width sc_dt_od_core."t_grEqZero",
	text sc_dt_global.string,
	"hOffset" sc_dt_global.double,
	pitch sc_dt_global.double,
	roll sc_dt_global.double,
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	dependency_sequence sc_dt_od_signal.t_road_signals_signal_dependency[],
	reference_sequence sc_dt_od_signal.t_road_signals_signal_reference[],
	"positionRoad_sequence" sc_dt_od_signal."t_road_signals_signal_positionRoad"[],
	"positionInertial_sequence" sc_dt_od_signal."t_road_signals_signal_positionInertial"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_signals_signalReference; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal."t_road_signals_signalReference" AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	id sc_dt_od_core."_signalId",
	orientation sc_dt_od_object.e_orientation,
	validity_sequence sc_dt_od_lane."t_road_objects_object_laneValidity"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_signals; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_road_signals AS (
	signal_sequence sc_dt_od_signal.t_road_signals_signal[],
	"signalReference_sequence" sc_dt_od_signal."t_road_signals_signalReference"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road.t_road AS (
	name sc_dt_global.string,
	length sc_dt_global.double,
	id sc_dt_od_core."_roadId",
	junction sc_dt_od_core."_junctionId",
	rule sc_dt_od_road."e_trafficRule",
	link_sequence sc_dt_od_road.t_road_link[],
	type_sequence sc_dt_od_road.t_road_type[],
	"planView" sc_dt_od_road."t_road_planView",
	"elevationProfile_sequence" sc_dt_od_road."t_road_elevationProfile"[],
	"lateralProfile_sequence" sc_dt_od_road."t_road_lateralProfile"[],
	lanes sc_dt_od_lane.t_road_lanes,
	objects_sequence sc_dt_od_object.t_road_objects[],
	signals_sequence sc_dt_od_signal.t_road_signals[],
	surface_sequence sc_dt_od_road.t_road_surface[],
	railroad_sequence sc_dt_od_railroad.t_road_railroad[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_controller_control; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_controller_control AS (
	"signalId" sc_dt_od_core."_signalId",
	type sc_dt_global.string
);


--
-- Name: t_controller; Type: TYPE; Schema: sc_dt_od_signal; Owner: -
--

CREATE TYPE sc_dt_od_signal.t_controller AS (
	id sc_dt_od_core."_controllerId",
	name sc_dt_global.string,
	sequence sc_dt_od_core."_nonNegativeInteger",
	control_sequence sc_dt_od_signal.t_controller_control[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: OpenDRIVE; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."OpenDRIVE" AS (
	header sc_dt_od_core.t_header,
	road_sequence sc_dt_od_road.t_road[],
	controller_sequence sc_dt_od_signal.t_controller[],
	junction_sequence sc_dt_od_junction.t_junction[],
	"junctionGroup_sequence" sc_dt_od_junction."t_junctionGroup"[],
	station_sequence sc_dt_od_railroad.t_station[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: _negativeInteger; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_negativeInteger" AS sc_dt_global."integer";


--
-- Name: _positiveInteger; Type: DOMAIN; Schema: sc_dt_od_core; Owner: -
--

CREATE DOMAIN sc_dt_od_core."_positiveInteger" AS sc_dt_global."integer";


--
-- Name: a_ds; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_ds AS (
	ds sc_dt_od_core."t_grEqZero"
);


--
-- Name: a_ds_polynom; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_ds_polynom AS (
	ds sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: a_polynom; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_polynom AS (
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: a_s; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_s AS (
	s sc_dt_od_core."t_grEqZero"
);


--
-- Name: a_sOffset; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."a_sOffset" AS (
	"sOffset" sc_dt_od_core."t_grEqZero"
);


--
-- Name: a_sOffset_polynom; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."a_sOffset_polynom" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: a_sOffset_tOffset; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."a_sOffset_tOffset" AS (
	"sOffset" sc_dt_od_core."t_grEqZero",
	"tOffset" sc_dt_global.double
);


--
-- Name: a_s_polynom; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_s_polynom AS (
	s sc_dt_od_core."t_grEqZero",
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: a_s_t; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_s_t AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double
);


--
-- Name: a_s_t_polynom; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_s_t_polynom AS (
	s sc_dt_od_core."t_grEqZero",
	t sc_dt_global.double,
	a sc_dt_global.double,
	b sc_dt_global.double,
	c sc_dt_global.double,
	d sc_dt_global.double
);


--
-- Name: a_xy_hdg; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core.a_xy_hdg AS (
	x sc_dt_global.double,
	y sc_dt_global.double,
	hdg sc_dt_global.double
);


--
-- Name: e_unitDistance; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_unitDistance" AS ENUM (
    'm',
    'km',
    'ft',
    'mile'
);


--
-- Name: e_unitMass; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_unitMass" AS ENUM (
    'kg',
    't'
);


--
-- Name: e_unitSlope; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."e_unitSlope" AS ENUM (
    '%'
);


--
-- Name: g_additionalData; Type: TYPE; Schema: sc_dt_od_core; Owner: -
--

CREATE TYPE sc_dt_od_core."g_additionalData" AS (
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: _t_road_lanes_laneSection_lcr_lane; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."_t_road_lanes_laneSection_lcr_lane" AS (
	id sc_dt_od_core."_laneId",
	type sc_dt_od_lane."e_laneType",
	level sc_dt_od_lane.t_bool,
	link_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link"[],
	border_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border"[],
	width_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width"[],
	"roadMark_sequence" sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark"[],
	material_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material"[],
	speed_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed"[],
	access_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access"[],
	height_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height"[],
	rule_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: _t_road_lanes_laneSection_lcr; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."_t_road_lanes_laneSection_lcr" AS (
	lane_sequence sc_dt_od_lane."_t_road_lanes_laneSection_lcr_lane"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_bool_default_false; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane.t_bool_default_false AS ENUM (
    'false',
    'true'
);


--
-- Name: t_bool_default_true; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane.t_bool_default_true AS ENUM (
    'true',
    'false'
);


--
-- Name: t_road_lanes_laneSection_lr_lane; Type: TYPE; Schema: sc_dt_od_lane; Owner: -
--

CREATE TYPE sc_dt_od_lane."t_road_lanes_laneSection_lr_lane" AS (
	type sc_dt_od_lane."e_laneType",
	level sc_dt_od_lane.t_bool,
	link_sequence sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_link"[],
	border_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_border"[],
	width_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_width"[],
	"roadMark_sequence" sc_dt_od_lane."t_road_lanes_laneSection_lcr_lane_roadMark"[],
	material_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_material"[],
	speed_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_speed"[],
	access_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_access"[],
	height_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_height"[],
	rule_sequence sc_dt_od_lane."t_road_lanes_laneSection_lr_lane_rule"[],
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: t_road_railroad_switch_track; Type: TYPE; Schema: sc_dt_od_railroad; Owner: -
--

CREATE TYPE sc_dt_od_railroad.t_road_railroad_switch_track AS (
	id sc_dt_od_core."_trackId",
	s sc_dt_od_core."t_grEqZero",
	dir sc_dt_od_junction."e_elementDir",
	include_sequence sc_dt_od_core.t_include[],
	"userData_sequence" sc_dt_od_core."t_userData"[],
	"dataQuality_sequence" sc_dt_od_core."t_dataQuality"[]
);


--
-- Name: e_countryCode_deprecated; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_countryCode_deprecated" AS ENUM (
    'OpenDRIVE',
    'Austria',
    'Brazil',
    'China',
    'France',
    'Germany',
    'Italy',
    'Switzerland',
    'USA'
);


--
-- Name: e_countryCode_iso3166alpha2; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_countryCode_iso3166alpha2" AS ENUM (
    'AD',
    'AE',
    'AF',
    'AG',
    'AI',
    'AL',
    'AM',
    'AO',
    'AR',
    'AT',
    'AU',
    'AZ',
    'BA',
    'BB',
    'BD',
    'BE',
    'BF',
    'BG',
    'BH',
    'BI',
    'BJ',
    'BM',
    'BN',
    'BO',
    'BR',
    'BS',
    'BT',
    'BW',
    'BY',
    'BZ',
    'CA',
    'CD',
    'CF',
    'CG',
    'CH',
    'CI',
    'CK',
    'CL',
    'CM',
    'CN',
    'CO',
    'CR',
    'CU',
    'CV',
    'CY',
    'CZ',
    'DE',
    'DJ',
    'DK',
    'DM',
    'DO',
    'DZ',
    'EC',
    'EE',
    'EG',
    'EH',
    'ER',
    'ES',
    'ET',
    'FI',
    'FJ',
    'FK',
    'FM',
    'FO',
    'FR',
    'GA',
    'GB',
    'GD',
    'GE',
    'GG',
    'GH',
    'GI',
    'GL',
    'GM',
    'GN',
    'GQ',
    'GR',
    'GS',
    'GT',
    'GW',
    'GY',
    'HN',
    'HR',
    'HT',
    'HU',
    'ID',
    'IE',
    'IL',
    'IM',
    'IN',
    'IO',
    'IQ',
    'IR',
    'IS',
    'IT',
    'JE',
    'JM',
    'JO',
    'JP',
    'KE',
    'KG',
    'KH',
    'KI',
    'KM',
    'KN',
    'KP',
    'KR',
    'KW',
    'KY',
    'KZ',
    'LA',
    'LB',
    'LC',
    'LI',
    'LK',
    'LR',
    'LS',
    'LT',
    'LU',
    'LV',
    'LY',
    'MA',
    'MC',
    'MD',
    'ME',
    'MG',
    'MH',
    'MK',
    'ML',
    'MM',
    'MN',
    'MR',
    'MS',
    'MT',
    'MU',
    'MV',
    'MW',
    'MX',
    'MY',
    'MZ',
    'NA',
    'NE',
    'NG',
    'NI',
    'NL',
    'NO',
    'NP',
    'NR',
    'NU',
    'NZ',
    'OM',
    'PA',
    'PE',
    'PG',
    'PH',
    'PK',
    'PL',
    'PN',
    'PT',
    'PW',
    'PY',
    'QA',
    'RO',
    'RS',
    'RU',
    'RW',
    'SA',
    'SB',
    'SC',
    'SD',
    'SE',
    'SG',
    'SH',
    'SI',
    'SK',
    'SL',
    'SM',
    'SN',
    'SO',
    'SR',
    'SS',
    'ST',
    'SV',
    'SY',
    'SZ',
    'TC',
    'TD',
    'TG',
    'TH',
    'TJ',
    'TK',
    'TL',
    'TM',
    'TN',
    'TO',
    'TR',
    'TT',
    'TV',
    'TW',
    'TZ',
    'UA',
    'UG',
    'US',
    'UY',
    'UZ',
    'VA',
    'VC',
    'VE',
    'VG',
    'VN',
    'VU',
    'WS',
    'XK',
    'YE',
    'ZA',
    'ZM',
    'ZW'
);


--
-- Name: e_countryCode_iso3166alpha3_deprecated; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_countryCode_iso3166alpha3_deprecated" AS ENUM (
    'AFG',
    'AGO',
    'AIA',
    'ALB',
    'AND',
    'ARE',
    'ARG',
    'ARM',
    'ATG',
    'AUS',
    'AUT',
    'AZE',
    'BDI',
    'BEL',
    'BEN',
    'BFA',
    'BGD',
    'BGR',
    'BHR',
    'BHS',
    'BIH',
    'BLR',
    'BLZ',
    'BMU',
    'BOL',
    'BRA',
    'BRB',
    'BRN',
    'BTN',
    'BWA',
    'CAF',
    'CAN',
    'CHE',
    'CHL',
    'CHN',
    'CIV',
    'CMR',
    'COD',
    'COG',
    'COK',
    'COL',
    'COM',
    'CPV',
    'CRI',
    'CUB',
    'CYM',
    'CYP',
    'CZE',
    'DEU',
    'DJI',
    'DMA',
    'DNK',
    'DOM',
    'DZA',
    'ECU',
    'EGY',
    'ERI',
    'ESH',
    'ESP',
    'EST',
    'ETH',
    'FIN',
    'FJI',
    'FLK',
    'FRA',
    'FRO',
    'FSM',
    'GAB',
    'GBR',
    'GEO',
    'GGY',
    'GHA',
    'GIB',
    'GIN',
    'GMB',
    'GNB',
    'GNQ',
    'GRC',
    'GRD',
    'GRL',
    'GTM',
    'GUY',
    'HND',
    'HRV',
    'HTI',
    'HUN',
    'IDN',
    'IMN',
    'IND',
    'IOT',
    'IRL',
    'IRN',
    'IRQ',
    'ISL',
    'ISR',
    'ITA',
    'JAM',
    'JEY',
    'JOR',
    'JPN',
    'KAZ',
    'KEN',
    'KGZ',
    'KHM',
    'KIR',
    'KNA',
    'KOR',
    'KWT',
    'LAO',
    'LBN',
    'LBR',
    'LBY',
    'LCA',
    'LIE',
    'LKA',
    'LSO',
    'LTU',
    'LUX',
    'LVA',
    'MAR',
    'MCO',
    'MDA',
    'MDG',
    'MDV',
    'MEX',
    'MHL',
    'MKD',
    'MLI',
    'MLT',
    'MMR',
    'MNE',
    'MNG',
    'MOZ',
    'MRT',
    'MSR',
    'MUS',
    'MWI',
    'MYS',
    'NAM',
    'NER',
    'NGA',
    'NIC',
    'NIU',
    'NLD',
    'NOR',
    'NPL',
    'NRU',
    'NZL',
    'OMN',
    'PAK',
    'PAN',
    'PCN',
    'PER',
    'PHL',
    'PLW',
    'PNG',
    'POL',
    'PRK',
    'PRT',
    'PRY',
    'QAT',
    'ROU',
    'RUS',
    'RWA',
    'SAU',
    'SDN',
    'SEN',
    'SGP',
    'SGS',
    'SHN',
    'SLB',
    'SLE',
    'SLV',
    'SMR',
    'SOM',
    'SRB',
    'SSD',
    'STP',
    'SUR',
    'SVK',
    'SVN',
    'SWE',
    'SWZ',
    'SYC',
    'SYR',
    'TCA',
    'TCD',
    'TGO',
    'THA',
    'TJK',
    'TKL',
    'TKM',
    'TLS',
    'TON',
    'TTO',
    'TUN',
    'TUR',
    'TUV',
    'TWN',
    'TZA',
    'UGA',
    'UKR',
    'URY',
    'USA',
    'UZB',
    'VAT',
    'VCT',
    'VEN',
    'VGB',
    'VNM',
    'VUT',
    'WSM',
    'XKX',
    'YEM',
    'ZAF',
    'ZMB',
    'ZWE'
);


--
-- Name: e_maxSpeedString; Type: TYPE; Schema: sc_dt_od_road; Owner: -
--

CREATE TYPE sc_dt_od_road."e_maxSpeedString" AS ENUM (
    'no limit',
    'undefined'
);


--
-- Name: Node; Type: TYPE; Schema: sc_dt_osm; Owner: -
--

CREATE TYPE sc_dt_osm."Node" AS (
	osm sc_dt_global."StringPairs",
	coord sc_dt_gc."LLCoordSysXYCell"
);


--
-- Name: clearGPS(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGPS"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."GPSCellsData";
    DELETE FROM sc_ods."GPSFileData";
    DELETE FROM sc_ods."GPSLogs";
    DELETE FROM sc_ods."GPSNativeData";
    DELETE FROM sc_ods."GPSSettings";
    DELETE FROM sc_ods."GPSStatus";
    DELETE FROM sc_ods."GPSValidData";
    DELETE FROM sc_ods."GPSValidSeqCellsData";
    
    ALTER SEQUENCE sc_ods."GPSCellsDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSFileDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSNativeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSStatusIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSValidDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSValidSeqCellsDataIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearGPSAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGPSAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearGPS"();
    CALL sc_ods."clearTraj"();
    CALL sc_ods."clearOSMWay"();
    CALL sc_ods."clearOSMNode"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearGeoJSONApplying(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGeoJSONApplying"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."GeoJSONApplyingLogs";
    DELETE FROM sc_ods."GeoJSONApplyingData";
    DELETE FROM sc_ods."GeoJSONApplyingSettings";
    DELETE FROM sc_ods."GeoJSONApplyingStatus";
    
    ALTER SEQUENCE sc_ods."GeoJSONApplyingLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearGeoJSONApplyingAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGeoJSONApplyingAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearGeoJSONApplying"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearGeoJSONStaging(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGeoJSONStaging"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."GeoJSONStagingFileData";
    DELETE FROM sc_ods."GeoJSONStagingLogs";
    DELETE FROM sc_ods."GeoJSONStagingNativeData";
    DELETE FROM sc_ods."GeoJSONStagingSettings";
    DELETE FROM sc_ods."GeoJSONStagingStatus";
    
    ALTER SEQUENCE sc_ods."GeoJSONStagingFileDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingNativeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearGeoJSONStagingAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearGeoJSONStagingAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearGeoJSONStaging"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearOSMCntryArea(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMCntryArea"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."OSMCntryAreaData";
    DELETE FROM sc_ods."OSMCntryAreaHist";
    DELETE FROM sc_ods."OSMCntryAreaLogs";
    DELETE FROM sc_ods."OSMCntryAreaSettings";
    DELETE FROM sc_ods."OSMCntryAreaStatus";
    ALTER SEQUENCE sc_ods."OSMCntryAreaDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearOSMCntryAreaAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMCntryAreaAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearOSMCntryArea"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearOSMNode(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMNode"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."OSMNodeData";
    DELETE FROM sc_ods."OSMNodeHist";
    DELETE FROM sc_ods."OSMNodeLogs";
    DELETE FROM sc_ods."OSMNodeSettings";
    DELETE FROM sc_ods."OSMNodeStatus";
    
    ALTER SEQUENCE sc_ods."OSMNodeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearOSMNodeAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMNodeAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearOSMNode"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearOSMWay(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMWay"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."OSMWayData";
    DELETE FROM sc_ods."OSMWayHist";
    DELETE FROM sc_ods."OSMWayLogs";
    DELETE FROM sc_ods."OSMWaySettings";
    DELETE FROM sc_ods."OSMWayStatus";
    
    ALTER SEQUENCE sc_ods."OSMWayDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWaySettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearOSMWayAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearOSMWayAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearOSMWay"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearTraj(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearTraj"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."TrajData";
    DELETE FROM sc_ods."TrajLogs";
    DELETE FROM sc_ods."TrajSeqCellsData";
    DELETE FROM sc_ods."TrajSettings";
    DELETE FROM sc_ods."TrajStatus";
    
    ALTER SEQUENCE sc_ods."TrajDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajSeqCellsDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clearTrajAndDependencies(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearTrajAndDependencies"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clearTraj"();
    CALL sc_ods."clearXODR"();
    COMMIT;
END;
$$;


--
-- Name: clearXODR(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clearXODR"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."XODRData";
    DELETE FROM sc_ods."XODRHist";
    DELETE FROM sc_ods."XODRLogs";
    DELETE FROM sc_ods."XODRSettings";
    DELETE FROM sc_ods."XODRStatus";
    ALTER SEQUENCE sc_ods."XODRDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clear_DataAndLogs(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_DataAndLogs"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clear_DataOnly"();
    CALL sc_ods."clear_LogsOnly"();
END;
$$;


--
-- Name: clear_DataAndSettings(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_DataAndSettings"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clear_DataOnly"();
    CALL sc_ods."clear_SettingsOnly"();
END;
$$;


--
-- Name: clear_DataOnly(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_DataOnly"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."_GlobalStatus";
    DELETE FROM sc_ods."_UserStatus";

    DELETE FROM sc_ods."GPSCellsData";
    DELETE FROM sc_ods."GPSFileData";
    DELETE FROM sc_ods."GPSNativeData";
    DELETE FROM sc_ods."GPSStatus";
    DELETE FROM sc_ods."GPSValidData";
    DELETE FROM sc_ods."GPSValidSeqCellsData";
    
    DELETE FROM sc_ods."OSMCntryAreaData";
    DELETE FROM sc_ods."OSMCntryAreaHist";
    DELETE FROM sc_ods."OSMCntryAreaStatus";

    DELETE FROM sc_ods."OSMNodeData";
    DELETE FROM sc_ods."OSMNodeHist";
    DELETE FROM sc_ods."OSMNodeStatus";

    DELETE FROM sc_ods."OSMWayData";
    DELETE FROM sc_ods."OSMWayHist";
    DELETE FROM sc_ods."OSMWayStatus";

    DELETE FROM sc_ods."TrajData";
    DELETE FROM sc_ods."TrajSeqCellsData";
    DELETE FROM sc_ods."TrajStatus";

    DELETE FROM sc_ods."GeoJSONStagingFileData";
    DELETE FROM sc_ods."GeoJSONStagingNativeData";
    DELETE FROM sc_ods."GeoJSONStagingStatus";

    DELETE FROM sc_ods."GeoJSONApplyingData";
    DELETE FROM sc_ods."GeoJSONApplyingStatus";

    DELETE FROM sc_ods."XODRData";
    DELETE FROM sc_ods."XODRHist";
    DELETE FROM sc_ods."XODRStatus";

    ALTER SEQUENCE sc_ods."_GlobalStatusIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."_UserStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."GPSCellsDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSFileDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSNativeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSStatusIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSValidDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSValidSeqCellsDataIdSeq" RESTART WITH 1;
    
    ALTER SEQUENCE sc_ods."OSMCntryAreaDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."OSMNodeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."OSMWayDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."TrajDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajSeqCellsDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."GeoJSONStagingFileDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingNativeDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."GeoJSONApplyingDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingStatusIdSeq" RESTART WITH 1;

    ALTER SEQUENCE sc_ods."XODRDataIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRHistIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRStatusIdSeq" RESTART WITH 1;
    COMMIT;
END;
$$;


--
-- Name: clear_Database(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_Database"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clear_DataOnly"();
    CALL sc_ods."clear_LogsOnly"();
    CALL sc_ods."clear_SettingsOnly"();
END;
$$;


--
-- Name: clear_LogsAndSettings(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_LogsAndSettings"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    CALL sc_ods."clear_LogsOnly"();
    CALL sc_ods."clear_SettingsOnly"();
END;
$$;


--
-- Name: clear_LogsOnly(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_LogsOnly"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."_GlobalLogs";
    DELETE FROM sc_ods."_UserLogs";
    DELETE FROM sc_ods."GPSLogs";
    DELETE FROM sc_ods."OSMCntryAreaLogs";
    DELETE FROM sc_ods."OSMNodeLogs";
    DELETE FROM sc_ods."OSMWayLogs";
    DELETE FROM sc_ods."TrajLogs";
    DELETE FROM sc_ods."GeoJSONStagingLogs";
    DELETE FROM sc_ods."GeoJSONApplyingLogs";
    DELETE FROM sc_ods."XODRLogs";
        
    ALTER SEQUENCE sc_ods."_GlobalLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."_UserLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWayLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingLogsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRLogsIdSeq" RESTART WITH 1;
    
    COMMIT;
END;
$$;


--
-- Name: clear_SettingsOnly(); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."clear_SettingsOnly"()
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
    DELETE FROM sc_ods."_GlobalSettings";
    DELETE FROM sc_ods."_UserSettings";
    DELETE FROM sc_ods."GPSSettings";
    DELETE FROM sc_ods."OSMCntryAreaSettings";
    DELETE FROM sc_ods."OSMNodeSettings";
    DELETE FROM sc_ods."OSMWaySettings";
    DELETE FROM sc_ods."TrajSettings";
    DELETE FROM sc_ods."GeoJSONStagingSettings";
    DELETE FROM sc_ods."GeoJSONApplyingSettings";
    DELETE FROM sc_ods."XODRSettings";
        
    ALTER SEQUENCE sc_ods."_GlobalSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."_UserSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GPSSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMCntryAreaSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMNodeSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."OSMWaySettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."TrajSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONStagingSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."GeoJSONApplyingSettingsIdSeq" RESTART WITH 1;
    ALTER SEQUENCE sc_ods."XODRSettingsIdSeq" RESTART WITH 1;
    
    COMMIT;
END;
$$;


--
-- Name: getGPSCellsDataCntToProcForOSMNode(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getGPSCellsDataCntToProcForOSMNode"() RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastProcedGPSCellsDataIdForOSMNode" sc_dt_global.integer;
"_gpsCellsDataCntToProcForOSMNode" sc_dt_global.integer;
BEGIN
	-- Ignore app user id
	"_lastProcedGPSCellsDataIdForOSMNode" = (SELECT "stateValue" FROM sc_ods."OSMNodeStatus" WHERE "stateKey" = 'lastProcedGPSCellsDataIdForOSMNode' LIMIT 1);
	IF "_lastProcedGPSCellsDataIdForOSMNode" IS NOT NULL THEN
		"_gpsCellsDataCntToProcForOSMNode" = (SELECT COUNT(*) FROM sc_ods."GPSCellsData" WHERE id > "_lastProcedGPSCellsDataIdForOSMNode");
	ELSE
		"_gpsCellsDataCntToProcForOSMNode" = (SELECT COUNT(*) FROM sc_ods."GPSCellsData");
	END IF;
	RETURN "_gpsCellsDataCntToProcForOSMNode";
END;
$$;


--
-- Name: getGPSCellsDataCntToProcForOSMWay(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getGPSCellsDataCntToProcForOSMWay"() RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastProcedGPSCellsDataIdForOSMWay" sc_dt_global.integer;
"_gpsCellsDataCntToProcForOSMWay" sc_dt_global.integer;
BEGIN
	-- Ignore app user id
	"_lastProcedGPSCellsDataIdForOSMWay" = (SELECT "stateValue" FROM sc_ods."OSMWayStatus" WHERE "stateKey" = 'lastProcedGPSCellsDataIdForOSMWay' LIMIT 1);
	IF "_lastProcedGPSCellsDataIdForOSMWay" IS NOT NULL THEN
		"_gpsCellsDataCntToProcForOSMWay" = (SELECT COUNT(*) FROM sc_ods."GPSCellsData" WHERE id > "_lastProcedGPSCellsDataIdForOSMWay");
	ELSE
		"_gpsCellsDataCntToProcForOSMWay" = (SELECT COUNT(*) FROM sc_ods."GPSCellsData");
	END IF;
	RETURN "_gpsCellsDataCntToProcForOSMWay";
END;
$$;


--
-- Name: getGPSValidDataCntToProcForTraj(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getGPSValidDataCntToProcForTraj"() RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastProcedGPSValidDataIdForTraj" sc_dt_global.integer;
"_gpsValidDataCntToProcForTraj" sc_dt_global.integer;
BEGIN
	-- Ignore app user id
	"_lastProcedGPSValidDataIdForTraj" = (SELECT "stateValue" FROM sc_ods."TrajStatus" WHERE "stateKey" = 'lastProcedGPSValidDataIdForTraj' LIMIT 1);
	IF "_lastProcedGPSValidDataIdForTraj" IS NOT NULL THEN
		"_gpsValidDataCntToProcForTraj" = (SELECT COUNT(*) FROM sc_ods."GPSValidData" WHERE id > "_lastProcedGPSValidDataIdForTraj");
	ELSE
		"_gpsValidDataCntToProcForTraj" = (SELECT COUNT(*) FROM sc_ods."GPSValidData");
	END IF;
	RETURN "_gpsValidDataCntToProcForTraj";
END;
$$;


--
-- Name: getGeoJSONStagingNativeDataCntToProcForApplying(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getGeoJSONStagingNativeDataCntToProcForApplying"() RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastProcedGeoJSONStagingNativeDataIdForApplying" sc_dt_global.integer;
"_geoJSONStagingNativeDataCntToProcForApplying" sc_dt_global.integer;
BEGIN
	-- Ignore app user id
	"_lastProcedGeoJSONStagingNativeDataIdForApplying" = (SELECT "stateValue" FROM sc_ods."GeoJSONApplyingStatus" WHERE "stateKey" = 'lastProcedGeoJSONStagingNativeDataIdForApplying' LIMIT 1);
	IF "_lastProcedGeoJSONStagingNativeDataIdForApplying" IS NOT NULL THEN
		"_geoJSONStagingNativeDataCntToProcForApplying" = (SELECT COUNT(*) FROM sc_ods."GeoJSONStagingNativeData" WHERE id > "_lastProcedGeoJSONStagingNativeDataIdForApplying");
	ELSE
		"_geoJSONStagingNativeDataCntToProcForApplying" = (SELECT COUNT(*) FROM sc_ods."GeoJSONStagingNativeData");
	END IF;
	RETURN "_geoJSONStagingNativeDataCntToProcForApplying";
END;
$$;


--
-- Name: getLatestXODRHistId(sc_dt_global."integer", sc_dt_global."integer"); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getLatestXODRHistId"("_cellRow" sc_dt_global."integer", "_cellCol" sc_dt_global."integer") RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
	RETURN (SELECT id FROM sc_ods."XODRHist" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol" ORDER BY id DESC LIMIT 1);
END;
$$;


--
-- Name: getTrajDataCntToProcForXODR(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."getTrajDataCntToProcForXODR"() RETURNS sc_dt_global."integer"
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastProcedTrajSeqCellsDataIdForXODR" sc_dt_global.integer;
"_trajDataCntToProcForXODR" sc_dt_global.integer;
BEGIN
	-- Ignore app user id
	"_lastProcedTrajSeqCellsDataIdForXODR" = (SELECT "stateValue" FROM sc_ods."XODRStatus" WHERE "stateKey" = 'lastProcedTrajSeqCellsDataIdForXODR' LIMIT 1);
	IF "_lastProcedTrajSeqCellsDataIdForXODR" IS NOT NULL THEN
		"_trajDataCntToProcForXODR" = (SELECT SUM("endId" - "startId" + 1) FROM sc_ods."TrajSeqCellsData" WHERE id > "_lastProcedTrajSeqCellsDataIdForXODR");
	ELSE
		"_trajDataCntToProcForXODR" = (SELECT SUM("endId" - "startId" + 1) FROM sc_ods."TrajSeqCellsData");
	END IF;
	RETURN "_trajDataCntToProcForXODR";
END;
$$;


--
-- Name: insertGPSValidData(sc_dt_global.string, sc_dt_global.string, sc_dt_global."integer", sc_dt_global."integer", sc_dt_global."integer", sc_dt_global."int", sc_dt_global.double, sc_dt_global."int", sc_dt_global."int", sc_dt_global.string, sc_dt_global.string, sc_dt_global."int", sc_dt_global.string, sc_dt_global.string, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."insertGPSValidData"("_appUser" sc_dt_global.string, "_gpsFilePath" sc_dt_global.string, "_gpsFileId" sc_dt_global."integer", "_cellRow" sc_dt_global."integer", "_cellCol" sc_dt_global."integer", "_GPS Week" sc_dt_global."int", "_GPS TOW [s]" sc_dt_global.double, "_Pos Mode" sc_dt_global."int", "_INS Mode" sc_dt_global."int", "_Hdg Mode" sc_dt_global.string, "_SVs Tracked" sc_dt_global.string, "_SVs Used" sc_dt_global."int", "_UTC Date" sc_dt_global.string, "_UTC Time" sc_dt_global.string, "_Lat [deg]" sc_dt_global.double, "_Lon [deg]" sc_dt_global.double, "_Alt Ellips [m]" sc_dt_global.double, "_SOG [m/s]" sc_dt_global.double, "_COG [deg]" sc_dt_global.double, "_Hdg [deg]" sc_dt_global.double, "_Vert Vel [m/s]" sc_dt_global.double, "_Roll [deg]" sc_dt_global.double, "_Pitch [deg]" sc_dt_global.double, "_Yaw [deg]" sc_dt_global.double, "_PDOP" sc_dt_global.double, "_HDOP" sc_dt_global.double, "_EHPE [m]" sc_dt_global.double, "_EVPE [m]" sc_dt_global.double, "_Baseline 2D [m]" sc_dt_global.double, "_Baseline 3D [m]" sc_dt_global.double, "_Corr. Age [s]" sc_dt_global.double, "_Delta TOW [ms]" sc_dt_global.double, "_2D Delta Pos [m]" sc_dt_global.double, "_3D Delta Pos [m]" sc_dt_global.double)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastInsertedGPSValidDataId" sc_dt_global.integer;
"_lastInsertedGPSValidSeqCellsDataId" sc_dt_global.integer;
"_lastInsertedGPSValidSeqCellsDataCellRow" sc_dt_global.integer;
"_lastInsertedGPSValidSeqCellsDataCellCol" sc_dt_global.integer;
"_existedGPSCellsDataId" sc_dt_global.integer;
BEGIN
	INSERT INTO sc_ods."GPSValidData" ( 
			"gpsFilePath", "gpsFileId", "cellRow", "cellCol", "GPS Week", "GPS TOW [s]"
			, "Pos Mode", "INS Mode", "Hdg Mode", "SVs Tracked", "SVs Used", "UTC Date", "UTC Time"
			, "Lat [deg]", "Lon [deg]", "Alt Ellips [m]", "SOG [m/s]", "COG [deg]", "Hdg [deg]", "Vert Vel [m/s]"
			, "Roll [deg]", "Pitch [deg]", "Yaw [deg]", "PDOP", "HDOP", "EHPE [m]", "EVPE [m]", "Baseline 2D [m]", "Baseline 3D [m]"
			, "Corr. Age [s]", "Delta TOW [ms]", "2D Delta Pos [m]", "3D Delta Pos [m]" 
		) VALUES (
			"_gpsFilePath", "_gpsFileId", "_cellRow", "_cellCol", "_GPS Week", "_GPS TOW [s]"
			, "_Pos Mode", "_INS Mode", "_Hdg Mode", "_SVs Tracked", "_SVs Used", "_UTC Date", "_UTC Time"
			, "_Lat [deg]", "_Lon [deg]", "_Alt Ellips [m]", "_SOG [m/s]", "_COG [deg]", "_Hdg [deg]", "_Vert Vel [m/s]"
			, "_Roll [deg]", "_Pitch [deg]", "_Yaw [deg]", "_PDOP", "_HDOP", "_EHPE [m]", "_EVPE [m]", "_Baseline 2D [m]", "_Baseline 3D [m]"
			, "_Corr. Age [s]", "_Delta TOW [ms]", "_2D Delta Pos [m]", "_3D Delta Pos [m]"
		) RETURNING id INTO "_lastInsertedGPSValidDataId";
	
	"_existedGPSCellsDataId" := (SELECT id FROM sc_ods."GPSCellsData" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol" LIMIT 1);
	IF "_existedGPSCellsDataId" IS NULL THEN
		INSERT INTO sc_ods."GPSCellsData" ("cellRow", "cellCol") VALUES ("_cellRow", "_cellCol");
	END IF;
	
	"_lastInsertedGPSValidSeqCellsDataId" := (SELECT "stateValue" FROM sc_ods."GPSStatus" WHERE "appUser" = "_appUser" AND "stateKey" = 'lastInsertedGPSValidSeqCellsDataId' LIMIT 1);
	
	IF "_lastInsertedGPSValidSeqCellsDataId" IS NOT NULL THEN
		"_lastInsertedGPSValidSeqCellsDataCellRow" := (SELECT "cellRow" FROM sc_ods."GPSValidSeqCellsData" WHERE id = "_lastInsertedGPSValidSeqCellsDataId");
		"_lastInsertedGPSValidSeqCellsDataCellCol" := (SELECT "cellCol" FROM sc_ods."GPSValidSeqCellsData" WHERE id = "_lastInsertedGPSValidSeqCellsDataId");
		
		IF "_lastInsertedGPSValidSeqCellsDataCellRow" = "_cellRow" AND "_lastInsertedGPSValidSeqCellsDataCellCol" = "_cellCol" THEN
			UPDATE sc_ods."GPSValidSeqCellsData" SET "endId" = "_lastInsertedGPSValidDataId" WHERE id = "_lastInsertedGPSValidSeqCellsDataId";
			COMMIT;
			RETURN;
		END IF;
	END IF;
	
	INSERT INTO sc_ods."GPSValidSeqCellsData" (
			"gpsFileId", "cellRow", "cellCol", "startId", "endId"
		) VALUES (
			"_gpsFileId", "_cellRow", "_cellCol", "_lastInsertedGPSValidDataId", "_lastInsertedGPSValidDataId"
		) RETURNING id INTO "_lastInsertedGPSValidSeqCellsDataId";
		
	CALL sc_ods."updateGPSStatus"("_appUser", 'lastInsertedGPSValidSeqCellsDataId', CAST("_lastInsertedGPSValidSeqCellsDataId" AS sc_dt_global.string));
	
	COMMIT;
END;
$$;


--
-- Name: insertGeoJSONApplyingData(sc_dt_global."integer", sc_dt_global.string, sc_dt_global."integer", sc_dt_global.string, sc_dt_global.string, sc_dt_global.string, sc_dt_global."integer", sc_dt_global.string, sc_dt_global."integer", sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."insertGeoJSONApplyingData"("_geoJSONStagingNativeDataId" sc_dt_global."integer", "_geoJSONStagingFilePath" sc_dt_global.string, "_geoJSONStagingFileId" sc_dt_global."integer", _tag sc_dt_global.string, _json sc_dt_global.string, _operation sc_dt_global.string, "_xodrHistIdBefore" sc_dt_global."integer", "_contentBefore" sc_dt_global.string, "_xodrHistIdAfter" sc_dt_global."integer", "_contentAfter" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
BEGIN
	INSERT INTO sc_ods."GeoJSONApplyingData"
			("geoJSONStagingNativeDataId", "geoJSONStagingFilePath", "geoJSONStagingFileId", geom4326, tag, json, operation, "xodrHistIdBefore", "contentBefore", "xodrHistIdAfter", "contentAfter") VALUES
			("_geoJSONStagingNativeDataId", "_geoJSONStagingFilePath", "_geoJSONStagingFileId"
			, (SELECT geom4326 FROM sc_ods."GeoJSONStagingNativeData" WHERE id = "_geoJSONStagingNativeDataId" LIMIT 1)
			, _tag, _json, _operation
			, "_xodrHistIdBefore"
			, json_populate_record(null::sc_dt_od_core."OpenDRIVE", CAST("_contentBefore" AS JSON))
			, "_xodrHistIdAfter"
			, json_populate_record(null::sc_dt_od_core."OpenDRIVE", CAST("_contentAfter" AS JSON)));
    COMMIT;
END;
$$;


--
-- Name: insertTrajData(sc_dt_global.string, sc_dt_global."integer", sc_dt_global."integer", sc_dt_global."integer", sc_dt_global.double, sc_dt_global.string, sc_dt_global.string, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double, sc_dt_global.double); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."insertTrajData"("_appUser" sc_dt_global.string, "_gpsFileId" sc_dt_global."integer", "_cellRow" sc_dt_global."integer", "_cellCol" sc_dt_global."integer", "_GPS TOW [s]" sc_dt_global.double, "_UTC Date" sc_dt_global.string, "_UTC Time" sc_dt_global.string, "_Lat [deg]" sc_dt_global.double, "_Lon [deg]" sc_dt_global.double, "_SOG [m/s]" sc_dt_global.double, "_Roll [deg]" sc_dt_global.double, "_Pitch [deg]" sc_dt_global.double, "_Yaw [deg]" sc_dt_global.double, "_HDOP" sc_dt_global.double, "_EHPE [m]" sc_dt_global.double, "_EVPE [m]" sc_dt_global.double)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_lastInsertedTrajDataId" sc_dt_global.integer;
"_lastInsertedTrajSeqCellsDataId" sc_dt_global.integer;
"_lastInsertedTrajSeqCellsDataCellRow" sc_dt_global.integer;
"_lastInsertedTrajSeqCellsDataCellCol" sc_dt_global.integer;
BEGIN
	INSERT INTO sc_ods."TrajData" ( 
			"gpsFileId", "cellRow", "cellCol", "GPS TOW [s]"
			, "UTC Date", "UTC Time"
			, "Lat [deg]", "Lon [deg]", "SOG [m/s]"
			, "Roll [deg]", "Pitch [deg]", "Yaw [deg]", "HDOP", "EHPE [m]", "EVPE [m]"
		) VALUES (
			"_gpsFileId", "_cellRow", "_cellCol", "_GPS TOW [s]"
			, "_UTC Date", "_UTC Time"
			, "_Lat [deg]", "_Lon [deg]", "_SOG [m/s]"
			, "_Roll [deg]", "_Pitch [deg]", "_Yaw [deg]", "_HDOP", "_EHPE [m]", "_EVPE [m]"
		) RETURNING id INTO "_lastInsertedTrajDataId";
	
	"_lastInsertedTrajSeqCellsDataId" := (SELECT "stateValue" FROM sc_ods."TrajStatus" WHERE "appUser" = "_appUser" AND "stateKey" = 'lastInsertedTrajSeqCellsDataId' LIMIT 1);
	
	IF "_lastInsertedTrajSeqCellsDataId" IS NOT NULL THEN
		"_lastInsertedTrajSeqCellsDataCellRow" := (SELECT "cellRow" FROM sc_ods."TrajSeqCellsData" WHERE id = "_lastInsertedTrajSeqCellsDataId");
		"_lastInsertedTrajSeqCellsDataCellCol" := (SELECT "cellCol" FROM sc_ods."TrajSeqCellsData" WHERE id = "_lastInsertedTrajSeqCellsDataId");
		
		IF "_lastInsertedTrajSeqCellsDataCellRow" = "_cellRow" AND "_lastInsertedTrajSeqCellsDataCellCol" = "_cellCol" THEN
			UPDATE sc_ods."TrajSeqCellsData" SET "endId" = "_lastInsertedTrajDataId" WHERE id = "_lastInsertedTrajSeqCellsDataId";
			COMMIT;
			RETURN;
		END IF;
	END IF;
	
	INSERT INTO sc_ods."TrajSeqCellsData" (
			"gpsFileId", "cellRow", "cellCol", "startId", "endId"
		) VALUES (
			"_gpsFileId", "_cellRow", "_cellCol", "_lastInsertedTrajDataId", "_lastInsertedTrajDataId"
		) RETURNING id INTO "_lastInsertedTrajSeqCellsDataId";
		
	CALL sc_ods."updateTrajStatus"("_appUser", 'lastInsertedTrajSeqCellsDataId', CAST("_lastInsertedTrajSeqCellsDataId" AS sc_dt_global.string));
	
	COMMIT;
END;
$$;


--
-- Name: set_box4326(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods.set_box4326() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  IF NEW.geom4326 IS NULL THEN
    NEW.box4326 = NULL;
  ELSE 
    NEW.box4326 = BOX2D(NEW.geom4326);
  END IF;
  RETURN NEW;
END;
$$;


--
-- Name: set_createdDateTime(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."set_createdDateTime"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  NEW."createdDateTime" = CURRENT_TIMESTAMP;
  RETURN new;
END;
$$;


--
-- Name: set_createdUpdatedDateTime(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."set_createdUpdatedDateTime"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  NEW."createdDateTime" = CURRENT_TIMESTAMP;
  NEW."updatedDateTime" = NEW."createdDateTime";
  RETURN new;
END;
$$;


--
-- Name: set_geom4326(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods.set_geom4326() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  IF NEW."Lon [deg]" IS NOT NULL AND NEW."Lat [deg]" IS NOT NULL THEN
    NEW.geom4326 = ST_SetSRID( ST_Point( NEW."Lon [deg]", NEW."Lat [deg]"), 4326);
  END IF;
  RETURN NEW;
END;
$$;


--
-- Name: set_updatedDateTime(); Type: FUNCTION; Schema: sc_ods; Owner: -
--

CREATE FUNCTION sc_ods."set_updatedDateTime"() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
  NEW."updatedDateTime" = CURRENT_TIMESTAMP;
  RETURN new;
END;
$$;


--
-- Name: updateGPSSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGPSSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGPSSettingsId" sc_dt_global.integer;
BEGIN
	"_existedGPSSettingsId" := (SELECT id FROM sc_ods."GPSSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedGPSSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."GPSSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedGPSSettingsId";
	ELSE
		INSERT INTO sc_ods."GPSSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateGPSStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGPSStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGPSStatusId" sc_dt_global.integer;
BEGIN
	"_existedGPSStatusId" := (SELECT id FROM sc_ods."GPSStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedGPSStatusId" IS NOT NULL THEN
		UPDATE sc_ods."GPSStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedGPSStatusId";
	ELSE
		INSERT INTO sc_ods."GPSStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateGeoJSONApplyingSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGeoJSONApplyingSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGeoJSONApplyingSettingsId" sc_dt_global.integer;
BEGIN
	"_existedGeoJSONApplyingSettingsId" := (SELECT id FROM sc_ods."GeoJSONApplyingSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedGeoJSONApplyingSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."GeoJSONApplyingSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedGeoJSONApplyingSettingsId";
	ELSE
		INSERT INTO sc_ods."GeoJSONApplyingSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateGeoJSONApplyingStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGeoJSONApplyingStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGeoJSONApplyingStatusId" sc_dt_global.integer;
BEGIN
	"_existedGeoJSONApplyingStatusId" := (SELECT id FROM sc_ods."GeoJSONApplyingStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedGeoJSONApplyingStatusId" IS NOT NULL THEN
		UPDATE sc_ods."GeoJSONApplyingStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedGeoJSONApplyingStatusId";
	ELSE
		INSERT INTO sc_ods."GeoJSONApplyingStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateGeoJSONStagingSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGeoJSONStagingSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGeoJSONStagingSettingsId" sc_dt_global.integer;
BEGIN
	"_existedGeoJSONStagingSettingsId" := (SELECT id FROM sc_ods."GeoJSONStagingSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedGeoJSONStagingSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."GeoJSONStagingSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedGeoJSONStagingSettingsId";
	ELSE
		INSERT INTO sc_ods."GeoJSONStagingSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateGeoJSONStagingStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateGeoJSONStagingStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedGeoJSONStagingStatusId" sc_dt_global.integer;
BEGIN
	"_existedGeoJSONStagingStatusId" := (SELECT id FROM sc_ods."GeoJSONStagingStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedGeoJSONStagingStatusId" IS NOT NULL THEN
		UPDATE sc_ods."GeoJSONStagingStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedGeoJSONStagingStatusId";
	ELSE
		INSERT INTO sc_ods."GeoJSONStagingStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMCntryAreaDataAndHist(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMCntryAreaDataAndHist"(_iso3166_1 sc_dt_global.string, _json sc_dt_global.string, _geom4326_text sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
_geom4326 geometry;
"_existedOSMCntryAreaDataId" sc_dt_global.integer;
BEGIN
    _geom4326 := ST_GeomFromText(_geom4326_text, 4326);
	"_existedOSMCntryAreaDataId" := (SELECT id FROM sc_ods."OSMCntryAreaData" WHERE iso3166_1 = _iso3166_1 LIMIT 1);
	IF "_existedOSMCntryAreaDataId" IS NOT NULL THEN
		UPDATE sc_ods."OSMCntryAreaData" 
			SET json = _json, geom4326 = _geom4326
			WHERE id = "_existedOSMCntryAreaDataId";
	ELSE
		INSERT INTO sc_ods."OSMCntryAreaData"
			(iso3166_1, json, geom4326) VALUES 
			(_iso3166_1, _json, _geom4326);
	END IF;
	INSERT INTO sc_ods."OSMCntryAreaHist"
			(iso3166_1, json, geom4326) VALUES 
			(_iso3166_1, _json, _geom4326);
    COMMIT;
END;
$$;


--
-- Name: updateOSMCntryAreaSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMCntryAreaSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMCntryAreaSettingsId" sc_dt_global.integer;
BEGIN
	"_existedOSMCntryAreaSettingsId" := (SELECT id FROM sc_ods."OSMCntryAreaSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedOSMCntryAreaSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."OSMCntryAreaSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedOSMCntryAreaSettingsId";
	ELSE
		INSERT INTO sc_ods."OSMCntryAreaSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMCntryAreaStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMCntryAreaStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMCntryAreaStatusId" sc_dt_global.integer;
BEGIN
	"_existedOSMCntryAreaStatusId" := (SELECT id FROM sc_ods."OSMCntryAreaStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedOSMCntryAreaStatusId" IS NOT NULL THEN
		UPDATE sc_ods."OSMCntryAreaStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedOSMCntryAreaStatusId";
	ELSE
		INSERT INTO sc_ods."OSMCntryAreaStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMNodeDataAndHist(sc_dt_global."integer", sc_dt_global.string, sc_dt_global.string, sc_dt_global.string[]); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMNodeDataAndHist"(_osm_id sc_dt_global."integer", _json sc_dt_global.string, _geom4326_text sc_dt_global.string, _values sc_dt_global.string[])
    LANGUAGE plpgsql
    AS $$
DECLARE
_geom4326 geometry;
"_existedOSMNodeDataId" sc_dt_global.integer;
BEGIN
    _geom4326 := ST_GeomFromText(_geom4326_text, 4326);
	"_existedOSMNodeDataId" := (SELECT id FROM sc_ods."OSMNodeData" WHERE "osmId" = _osm_id LIMIT 1);
	IF "_existedOSMNodeDataId" IS NOT NULL THEN
		UPDATE sc_ods."OSMNodeData" 
			SET json = _json, geom4326 = _geom4326, "abandoned" = _values[1], "abandoned:amenity" = _values[2], "abandoned:building" = _values[3], "abandoned:car" = _values[4], "abandoned:crossing" = _values[5], "abandoned:highway" = _values[6], "abandoned:highway:traffic_signals" = _values[7], "abandoned:natural" = _values[8], "abandoned:natural:tree" = _values[9], "abandoned:parking" = _values[10], "abandoned:pole" = _values[11], "abandoned:railway" = _values[12], "abandoned:railway:traffic_signals" = _values[13], "abandoned:traffic_sign" = _values[14], "abandoned:tree" = _values[15], "accomodation" = _values[16], "addr:building" = _values[17], "addr:housename" = _values[18], "amenity" = _values[19], "amenity_1" = _values[20], "amenity_2" = _values[21], "area" = _values[22], "area:building" = _values[23], "area:highway" = _values[24], "area:traffic_calming" = _values[25], "barrier" = _values[26], "barrier:tree" = _values[27], "barrier:type" = _values[28], "bicycle" = _values[29], "bicycle:parking" = _values[30], "bicycle_parking:position" = _values[31], "bicycle:traffic_signals" = _values[32], "blazed:natural" = _values[33], "bollard" = _values[34], "bollard:traffic_sign" = _values[35], "broken" = _values[36], "broken:traffic_sign" = _values[37], "building" = _values[38], "calming" = _values[39], "camera:mount" = _values[40], "construction" = _values[41], "construction:amenity" = _values[42], "construction:building" = _values[43], "construction:crossing" = _values[44], "construction:crossing:island" = _values[45], "construction:demolished:highway" = _values[46], "construction:demolished:highway:traffic_signals" = _values[47], "construction:highway" = _values[48], "construction:highway:traffic_sign" = _values[49], "construction:highway:traffic_signal" = _values[50], "construction:highway:traffic_signals" = _values[51], "construction:junction" = _values[52], "construction:parking" = _values[53], "construction:road_marking" = _values[54], "construction:traffic_signals" = _values[55], "crane" = _values[56], "crane:type" = _values[57], "crossing" = _values[58], "crossing_1" = _values[59], "crossing_2" = _values[60], "crossing:island" = _values[61], "crossing:road_marking" = _values[62], "crosswalk" = _values[63], "cycleway" = _values[64], "cycleway:left" = _values[65], "cycleway:left:traffic_sign" = _values[66], "cycleway:left:traffic_signals" = _values[67], "cycleway:right" = _values[68], "cycleway:right:traffic_sign" = _values[69], "cycleway:right:traffic_signals" = _values[70], "cycleway:traffic_sign" = _values[71], "cycleway:traffic_signals" = _values[72], "dead:natural" = _values[73], "demolished" = _values[74], "demolished:amenity" = _values[75], "demolished:building" = _values[76], "demolished:crossing" = _values[77], "demolished:highway" = _values[78], "demolished:highway:traffic_signals" = _values[79], "demolished:junction" = _values[80], "demolished:natural" = _values[81], "demolished:parking" = _values[82], "demolished:traffic_sign" = _values[83], "destroyed" = _values[84], "destroyed:building" = _values[85], "destroyed:natural" = _values[86], "destroyed:traffic_sign" = _values[87], "device" = _values[88], "device:traffic_signals" = _values[89], "disabled" = _values[90], "disabled:highway" = _values[91], "disabled:highway:traffic_signals" = _values[92], "disabled:traffic_sign" = _values[93], "disused" = _values[94], "disused:building" = _values[95], "disused:crossing" = _values[96], "disused:highway" = _values[97], "disused:highway:traffic_signals" = _values[98], "disused:parking" = _values[99], "disused:playground" = _values[100], "disused:playground:roundabout" = _values[101], "disused:traffic_sign" = _values[102], "disused:traffic_signals" = _values[103], "enforcement" = _values[104], "fence" = _values[105], "fence:pole" = _values[106], "fence_type" = _values[107], "fence:type" = _values[108], "footway" = _values[109], "forest" = _values[110], "gantry" = _values[111], "gantry:type" = _values[112], "gone:natural" = _values[113], "handrail" = _values[114], "highway" = _values[115], "highway_1" = _values[116], "highway_1:traffic_signals" = _values[117], "highway_2" = _values[118], "highway_2:traffic_signals" = _values[119], "highway:backward" = _values[120], "highway:backward:traffic_signals" = _values[121], "highway:backwards" = _values[122], "highway:backwards:traffic_signals" = _values[123], "highway:bicycle" = _values[124], "highway:bicycle:traffic_signals" = _values[125], "highway:construction" = _values[126], "highway:construction:traffic_signals" = _values[127], "highway:disused" = _values[128], "highway:disused:traffic_signals" = _values[129], "highway:forward" = _values[130], "highway:forward:traffic_signals" = _values[131], "highway:historic" = _values[132], "highway:historic:traffic_signals" = _values[133], "highway:street_lamp" = _values[134], "highway:traffic_signals" = _values[135], "historic" = _values[136], "historic_1" = _values[137], "historic_1:building" = _values[138], "historic:building" = _values[139], "historic:crossing" = _values[140], "historic:highway" = _values[141], "historic:highway:traffic_signals" = _values[142], "historical" = _values[143], "historical:building" = _values[144], "house" = _values[145], "industrial" = _values[146], "intersection" = _values[147], "intersection:traffic_signals" = _values[148], "junction" = _values[149], "junction:separate" = _values[150], "junction:separate:traffic_signals" = _values[151], "junction:traffic_signals" = _values[152], "kerb:road_marking" = _values[153], "lamp_type" = _values[154], "lamp:type" = _values[155], "landuse" = _values[156], "level_crossing" = _values[157], "light" = _values[158], "light:type" = _values[159], "lit" = _values[160], "location" = _values[161], "location:traffic_sign" = _values[162], "man_made" = _values[163], "man_made:separate" = _values[164], "man_made:separate:traffic_sign" = _values[165], "mini_roundabout" = _values[166], "miniroundabout" = _values[167], "motorcycle" = _values[168], "motorcycle:parking" = _values[169], "name" = _values[170], "name:building" = _values[171], "natura" = _values[172], "natural" = _values[173], "natural_1" = _values[174], "natural_1:tree" = _values[175], "natural:tree" = _values[176], "obstacle" = _values[177], "obstacle:traffic_sign" = _values[178], "old_amenity" = _values[179], "old:amenity" = _values[180], "old_natural" = _values[181], "old:natural" = _values[182], "park" = _values[183], "parking" = _values[184], "parking_1" = _values[185], "parking_position" = _values[186], "parking_slots" = _values[187], "parking_space" = _values[188], "parking_zone" = _values[189], "plant" = _values[190], "playground" = _values[191], "playground:roundabout" = _values[192], "pole" = _values[193], "public_transport" = _values[194], "railing" = _values[195], "railway" = _values[196], "razed" = _values[197], "razed:amenity" = _values[198], "razed:building" = _values[199], "razed:crossing" = _values[200], "razed:crossing:island" = _values[201], "razed:highway" = _values[202], "razed:highway:traffic_signals" = _values[203], "razed:natural" = _values[204], "razed:natural:tree" = _values[205], "razed:playground" = _values[206], "razed:pole" = _values[207], "razed:traffic_sign" = _values[208], "razed:traffic_signals" = _values[209], "razed:tree" = _values[210], "ref" = _values[211], "ref:pole" = _values[212], "residential" = _values[213], "road" = _values[214], "road_mark" = _values[215], "road_marking" = _values[216], "road:traffic_signals" = _values[217], "roadMark" = _values[218], "roundabout" = _values[219], "ruined" = _values[220], "ruined:building" = _values[221], "ruins" = _values[222], "ruins:building" = _values[223], "ruins:car" = _values[224], "ruins:tree" = _values[225], "seamark" = _values[226], "seamark:building" = _values[227], "seasonal:winter" = _values[228], "seasonal:winter:traffic_sign" = _values[229], "service:vehicle:parking" = _values[230], "services" = _values[231], "sidewalk" = _values[232], "sidewalk:left" = _values[233], "sidewalk:left:traffic_sign" = _values[234], "sidewalk:right" = _values[235], "sidewalk:right:traffic_sign" = _values[236], "sidewalk:traffic_sign" = _values[237], "site" = _values[238], "street_cabinet" = _values[239], "street_cabinet:traffic_sign" = _values[240], "street_cabinet:traffic_signal" = _values[241], "street_cabinet:traffic_signals" = _values[242], "street_furniture" = _values[243], "street_lamp" = _values[244], "street_light" = _values[245], "streetLamp" = _values[246], "streetlamp:ref" = _values[247], "streetlight" = _values[248], "structure" = _values[249], "temporarily:gone" = _values[250], "temporarily:gone:traffic_sign" = _values[251], "temporarily_removed" = _values[252], "temporarily_removed:traffic_sign" = _values[253], "temporary" = _values[254], "temporary:building" = _values[255], "traffic_calming" = _values[256], "traffic_control" = _values[257], "traffic_control:traffic_signals" = _values[258], "traffic_island" = _values[259], "traffic_lights" = _values[260], "traffic_sign" = _values[261], "traffic_sign_1" = _values[262], "traffic_signal" = _values[263], "traffic_signals" = _values[264], "traffic_signals_1" = _values[265], "training" = _values[266], "transport" = _values[267], "transport:traffic_signals" = _values[268], "transportation" = _values[269], "tree" = _values[270], "trees" = _values[271], "type" = _values[272], "type:pole" = _values[273], "use" = _values[274], "user_defined" = _values[275], "user_defined_other" = _values[276], "vegetation" = _values[277], "waterway" = _values[278], "waterway:traffic_sign" = _values[279], "zone" = _values[280], "zone:parking" = _values[281]
			WHERE id = "_existedOSMNodeDataId";
	ELSE
		INSERT INTO sc_ods."OSMNodeData"
			("osmId", json, geom4326, "abandoned", "abandoned:amenity", "abandoned:building", "abandoned:car", "abandoned:crossing", "abandoned:highway", "abandoned:highway:traffic_signals", "abandoned:natural", "abandoned:natural:tree", "abandoned:parking", "abandoned:pole", "abandoned:railway", "abandoned:railway:traffic_signals", "abandoned:traffic_sign", "abandoned:tree", "accomodation", "addr:building", "addr:housename", "amenity", "amenity_1", "amenity_2", "area", "area:building", "area:highway", "area:traffic_calming", "barrier", "barrier:tree", "barrier:type", "bicycle", "bicycle:parking", "bicycle_parking:position", "bicycle:traffic_signals", "blazed:natural", "bollard", "bollard:traffic_sign", "broken", "broken:traffic_sign", "building", "calming", "camera:mount", "construction", "construction:amenity", "construction:building", "construction:crossing", "construction:crossing:island", "construction:demolished:highway", "construction:demolished:highway:traffic_signals", "construction:highway", "construction:highway:traffic_sign", "construction:highway:traffic_signal", "construction:highway:traffic_signals", "construction:junction", "construction:parking", "construction:road_marking", "construction:traffic_signals", "crane", "crane:type", "crossing", "crossing_1", "crossing_2", "crossing:island", "crossing:road_marking", "crosswalk", "cycleway", "cycleway:left", "cycleway:left:traffic_sign", "cycleway:left:traffic_signals", "cycleway:right", "cycleway:right:traffic_sign", "cycleway:right:traffic_signals", "cycleway:traffic_sign", "cycleway:traffic_signals", "dead:natural", "demolished", "demolished:amenity", "demolished:building", "demolished:crossing", "demolished:highway", "demolished:highway:traffic_signals", "demolished:junction", "demolished:natural", "demolished:parking", "demolished:traffic_sign", "destroyed", "destroyed:building", "destroyed:natural", "destroyed:traffic_sign", "device", "device:traffic_signals", "disabled", "disabled:highway", "disabled:highway:traffic_signals", "disabled:traffic_sign", "disused", "disused:building", "disused:crossing", "disused:highway", "disused:highway:traffic_signals", "disused:parking", "disused:playground", "disused:playground:roundabout", "disused:traffic_sign", "disused:traffic_signals", "enforcement", "fence", "fence:pole", "fence_type", "fence:type", "footway", "forest", "gantry", "gantry:type", "gone:natural", "handrail", "highway", "highway_1", "highway_1:traffic_signals", "highway_2", "highway_2:traffic_signals", "highway:backward", "highway:backward:traffic_signals", "highway:backwards", "highway:backwards:traffic_signals", "highway:bicycle", "highway:bicycle:traffic_signals", "highway:construction", "highway:construction:traffic_signals", "highway:disused", "highway:disused:traffic_signals", "highway:forward", "highway:forward:traffic_signals", "highway:historic", "highway:historic:traffic_signals", "highway:street_lamp", "highway:traffic_signals", "historic", "historic_1", "historic_1:building", "historic:building", "historic:crossing", "historic:highway", "historic:highway:traffic_signals", "historical", "historical:building", "house", "industrial", "intersection", "intersection:traffic_signals", "junction", "junction:separate", "junction:separate:traffic_signals", "junction:traffic_signals", "kerb:road_marking", "lamp_type", "lamp:type", "landuse", "level_crossing", "light", "light:type", "lit", "location", "location:traffic_sign", "man_made", "man_made:separate", "man_made:separate:traffic_sign", "mini_roundabout", "miniroundabout", "motorcycle", "motorcycle:parking", "name", "name:building", "natura", "natural", "natural_1", "natural_1:tree", "natural:tree", "obstacle", "obstacle:traffic_sign", "old_amenity", "old:amenity", "old_natural", "old:natural", "park", "parking", "parking_1", "parking_position", "parking_slots", "parking_space", "parking_zone", "plant", "playground", "playground:roundabout", "pole", "public_transport", "railing", "railway", "razed", "razed:amenity", "razed:building", "razed:crossing", "razed:crossing:island", "razed:highway", "razed:highway:traffic_signals", "razed:natural", "razed:natural:tree", "razed:playground", "razed:pole", "razed:traffic_sign", "razed:traffic_signals", "razed:tree", "ref", "ref:pole", "residential", "road", "road_mark", "road_marking", "road:traffic_signals", "roadMark", "roundabout", "ruined", "ruined:building", "ruins", "ruins:building", "ruins:car", "ruins:tree", "seamark", "seamark:building", "seasonal:winter", "seasonal:winter:traffic_sign", "service:vehicle:parking", "services", "sidewalk", "sidewalk:left", "sidewalk:left:traffic_sign", "sidewalk:right", "sidewalk:right:traffic_sign", "sidewalk:traffic_sign", "site", "street_cabinet", "street_cabinet:traffic_sign", "street_cabinet:traffic_signal", "street_cabinet:traffic_signals", "street_furniture", "street_lamp", "street_light", "streetLamp", "streetlamp:ref", "streetlight", "structure", "temporarily:gone", "temporarily:gone:traffic_sign", "temporarily_removed", "temporarily_removed:traffic_sign", "temporary", "temporary:building", "traffic_calming", "traffic_control", "traffic_control:traffic_signals", "traffic_island", "traffic_lights", "traffic_sign", "traffic_sign_1", "traffic_signal", "traffic_signals", "traffic_signals_1", "training", "transport", "transport:traffic_signals", "transportation", "tree", "trees", "type", "type:pole", "use", "user_defined", "user_defined_other", "vegetation", "waterway", "waterway:traffic_sign", "zone", "zone:parking") VALUES 
			(_osm_id, _json, _geom4326, _values[1], _values[2], _values[3], _values[4], _values[5], _values[6], _values[7], _values[8], _values[9], _values[10], _values[11], _values[12], _values[13], _values[14], _values[15], _values[16], _values[17], _values[18], _values[19], _values[20], _values[21], _values[22], _values[23], _values[24], _values[25], _values[26], _values[27], _values[28], _values[29], _values[30], _values[31], _values[32], _values[33], _values[34], _values[35], _values[36], _values[37], _values[38], _values[39], _values[40], _values[41], _values[42], _values[43], _values[44], _values[45], _values[46], _values[47], _values[48], _values[49], _values[50], _values[51], _values[52], _values[53], _values[54], _values[55], _values[56], _values[57], _values[58], _values[59], _values[60], _values[61], _values[62], _values[63], _values[64], _values[65], _values[66], _values[67], _values[68], _values[69], _values[70], _values[71], _values[72], _values[73], _values[74], _values[75], _values[76], _values[77], _values[78], _values[79], _values[80], _values[81], _values[82], _values[83], _values[84], _values[85], _values[86], _values[87], _values[88], _values[89], _values[90], _values[91], _values[92], _values[93], _values[94], _values[95], _values[96], _values[97], _values[98], _values[99], _values[100], _values[101], _values[102], _values[103], _values[104], _values[105], _values[106], _values[107], _values[108], _values[109], _values[110], _values[111], _values[112], _values[113], _values[114], _values[115], _values[116], _values[117], _values[118], _values[119], _values[120], _values[121], _values[122], _values[123], _values[124], _values[125], _values[126], _values[127], _values[128], _values[129], _values[130], _values[131], _values[132], _values[133], _values[134], _values[135], _values[136], _values[137], _values[138], _values[139], _values[140], _values[141], _values[142], _values[143], _values[144], _values[145], _values[146], _values[147], _values[148], _values[149], _values[150], _values[151], _values[152], _values[153], _values[154], _values[155], _values[156], _values[157], _values[158], _values[159], _values[160], _values[161], _values[162], _values[163], _values[164], _values[165], _values[166], _values[167], _values[168], _values[169], _values[170], _values[171], _values[172], _values[173], _values[174], _values[175], _values[176], _values[177], _values[178], _values[179], _values[180], _values[181], _values[182], _values[183], _values[184], _values[185], _values[186], _values[187], _values[188], _values[189], _values[190], _values[191], _values[192], _values[193], _values[194], _values[195], _values[196], _values[197], _values[198], _values[199], _values[200], _values[201], _values[202], _values[203], _values[204], _values[205], _values[206], _values[207], _values[208], _values[209], _values[210], _values[211], _values[212], _values[213], _values[214], _values[215], _values[216], _values[217], _values[218], _values[219], _values[220], _values[221], _values[222], _values[223], _values[224], _values[225], _values[226], _values[227], _values[228], _values[229], _values[230], _values[231], _values[232], _values[233], _values[234], _values[235], _values[236], _values[237], _values[238], _values[239], _values[240], _values[241], _values[242], _values[243], _values[244], _values[245], _values[246], _values[247], _values[248], _values[249], _values[250], _values[251], _values[252], _values[253], _values[254], _values[255], _values[256], _values[257], _values[258], _values[259], _values[260], _values[261], _values[262], _values[263], _values[264], _values[265], _values[266], _values[267], _values[268], _values[269], _values[270], _values[271], _values[272], _values[273], _values[274], _values[275], _values[276], _values[277], _values[278], _values[279], _values[280], _values[281]);
	END IF;
	INSERT INTO sc_ods."OSMNodeHist"
			("osmId", json, geom4326, "abandoned", "abandoned:amenity", "abandoned:building", "abandoned:car", "abandoned:crossing", "abandoned:highway", "abandoned:highway:traffic_signals", "abandoned:natural", "abandoned:natural:tree", "abandoned:parking", "abandoned:pole", "abandoned:railway", "abandoned:railway:traffic_signals", "abandoned:traffic_sign", "abandoned:tree", "accomodation", "addr:building", "addr:housename", "amenity", "amenity_1", "amenity_2", "area", "area:building", "area:highway", "area:traffic_calming", "barrier", "barrier:tree", "barrier:type", "bicycle", "bicycle:parking", "bicycle_parking:position", "bicycle:traffic_signals", "blazed:natural", "bollard", "bollard:traffic_sign", "broken", "broken:traffic_sign", "building", "calming", "camera:mount", "construction", "construction:amenity", "construction:building", "construction:crossing", "construction:crossing:island", "construction:demolished:highway", "construction:demolished:highway:traffic_signals", "construction:highway", "construction:highway:traffic_sign", "construction:highway:traffic_signal", "construction:highway:traffic_signals", "construction:junction", "construction:parking", "construction:road_marking", "construction:traffic_signals", "crane", "crane:type", "crossing", "crossing_1", "crossing_2", "crossing:island", "crossing:road_marking", "crosswalk", "cycleway", "cycleway:left", "cycleway:left:traffic_sign", "cycleway:left:traffic_signals", "cycleway:right", "cycleway:right:traffic_sign", "cycleway:right:traffic_signals", "cycleway:traffic_sign", "cycleway:traffic_signals", "dead:natural", "demolished", "demolished:amenity", "demolished:building", "demolished:crossing", "demolished:highway", "demolished:highway:traffic_signals", "demolished:junction", "demolished:natural", "demolished:parking", "demolished:traffic_sign", "destroyed", "destroyed:building", "destroyed:natural", "destroyed:traffic_sign", "device", "device:traffic_signals", "disabled", "disabled:highway", "disabled:highway:traffic_signals", "disabled:traffic_sign", "disused", "disused:building", "disused:crossing", "disused:highway", "disused:highway:traffic_signals", "disused:parking", "disused:playground", "disused:playground:roundabout", "disused:traffic_sign", "disused:traffic_signals", "enforcement", "fence", "fence:pole", "fence_type", "fence:type", "footway", "forest", "gantry", "gantry:type", "gone:natural", "handrail", "highway", "highway_1", "highway_1:traffic_signals", "highway_2", "highway_2:traffic_signals", "highway:backward", "highway:backward:traffic_signals", "highway:backwards", "highway:backwards:traffic_signals", "highway:bicycle", "highway:bicycle:traffic_signals", "highway:construction", "highway:construction:traffic_signals", "highway:disused", "highway:disused:traffic_signals", "highway:forward", "highway:forward:traffic_signals", "highway:historic", "highway:historic:traffic_signals", "highway:street_lamp", "highway:traffic_signals", "historic", "historic_1", "historic_1:building", "historic:building", "historic:crossing", "historic:highway", "historic:highway:traffic_signals", "historical", "historical:building", "house", "industrial", "intersection", "intersection:traffic_signals", "junction", "junction:separate", "junction:separate:traffic_signals", "junction:traffic_signals", "kerb:road_marking", "lamp_type", "lamp:type", "landuse", "level_crossing", "light", "light:type", "lit", "location", "location:traffic_sign", "man_made", "man_made:separate", "man_made:separate:traffic_sign", "mini_roundabout", "miniroundabout", "motorcycle", "motorcycle:parking", "name", "name:building", "natura", "natural", "natural_1", "natural_1:tree", "natural:tree", "obstacle", "obstacle:traffic_sign", "old_amenity", "old:amenity", "old_natural", "old:natural", "park", "parking", "parking_1", "parking_position", "parking_slots", "parking_space", "parking_zone", "plant", "playground", "playground:roundabout", "pole", "public_transport", "railing", "railway", "razed", "razed:amenity", "razed:building", "razed:crossing", "razed:crossing:island", "razed:highway", "razed:highway:traffic_signals", "razed:natural", "razed:natural:tree", "razed:playground", "razed:pole", "razed:traffic_sign", "razed:traffic_signals", "razed:tree", "ref", "ref:pole", "residential", "road", "road_mark", "road_marking", "road:traffic_signals", "roadMark", "roundabout", "ruined", "ruined:building", "ruins", "ruins:building", "ruins:car", "ruins:tree", "seamark", "seamark:building", "seasonal:winter", "seasonal:winter:traffic_sign", "service:vehicle:parking", "services", "sidewalk", "sidewalk:left", "sidewalk:left:traffic_sign", "sidewalk:right", "sidewalk:right:traffic_sign", "sidewalk:traffic_sign", "site", "street_cabinet", "street_cabinet:traffic_sign", "street_cabinet:traffic_signal", "street_cabinet:traffic_signals", "street_furniture", "street_lamp", "street_light", "streetLamp", "streetlamp:ref", "streetlight", "structure", "temporarily:gone", "temporarily:gone:traffic_sign", "temporarily_removed", "temporarily_removed:traffic_sign", "temporary", "temporary:building", "traffic_calming", "traffic_control", "traffic_control:traffic_signals", "traffic_island", "traffic_lights", "traffic_sign", "traffic_sign_1", "traffic_signal", "traffic_signals", "traffic_signals_1", "training", "transport", "transport:traffic_signals", "transportation", "tree", "trees", "type", "type:pole", "use", "user_defined", "user_defined_other", "vegetation", "waterway", "waterway:traffic_sign", "zone", "zone:parking") VALUES 
			(_osm_id, _json, _geom4326, _values[1], _values[2], _values[3], _values[4], _values[5], _values[6], _values[7], _values[8], _values[9], _values[10], _values[11], _values[12], _values[13], _values[14], _values[15], _values[16], _values[17], _values[18], _values[19], _values[20], _values[21], _values[22], _values[23], _values[24], _values[25], _values[26], _values[27], _values[28], _values[29], _values[30], _values[31], _values[32], _values[33], _values[34], _values[35], _values[36], _values[37], _values[38], _values[39], _values[40], _values[41], _values[42], _values[43], _values[44], _values[45], _values[46], _values[47], _values[48], _values[49], _values[50], _values[51], _values[52], _values[53], _values[54], _values[55], _values[56], _values[57], _values[58], _values[59], _values[60], _values[61], _values[62], _values[63], _values[64], _values[65], _values[66], _values[67], _values[68], _values[69], _values[70], _values[71], _values[72], _values[73], _values[74], _values[75], _values[76], _values[77], _values[78], _values[79], _values[80], _values[81], _values[82], _values[83], _values[84], _values[85], _values[86], _values[87], _values[88], _values[89], _values[90], _values[91], _values[92], _values[93], _values[94], _values[95], _values[96], _values[97], _values[98], _values[99], _values[100], _values[101], _values[102], _values[103], _values[104], _values[105], _values[106], _values[107], _values[108], _values[109], _values[110], _values[111], _values[112], _values[113], _values[114], _values[115], _values[116], _values[117], _values[118], _values[119], _values[120], _values[121], _values[122], _values[123], _values[124], _values[125], _values[126], _values[127], _values[128], _values[129], _values[130], _values[131], _values[132], _values[133], _values[134], _values[135], _values[136], _values[137], _values[138], _values[139], _values[140], _values[141], _values[142], _values[143], _values[144], _values[145], _values[146], _values[147], _values[148], _values[149], _values[150], _values[151], _values[152], _values[153], _values[154], _values[155], _values[156], _values[157], _values[158], _values[159], _values[160], _values[161], _values[162], _values[163], _values[164], _values[165], _values[166], _values[167], _values[168], _values[169], _values[170], _values[171], _values[172], _values[173], _values[174], _values[175], _values[176], _values[177], _values[178], _values[179], _values[180], _values[181], _values[182], _values[183], _values[184], _values[185], _values[186], _values[187], _values[188], _values[189], _values[190], _values[191], _values[192], _values[193], _values[194], _values[195], _values[196], _values[197], _values[198], _values[199], _values[200], _values[201], _values[202], _values[203], _values[204], _values[205], _values[206], _values[207], _values[208], _values[209], _values[210], _values[211], _values[212], _values[213], _values[214], _values[215], _values[216], _values[217], _values[218], _values[219], _values[220], _values[221], _values[222], _values[223], _values[224], _values[225], _values[226], _values[227], _values[228], _values[229], _values[230], _values[231], _values[232], _values[233], _values[234], _values[235], _values[236], _values[237], _values[238], _values[239], _values[240], _values[241], _values[242], _values[243], _values[244], _values[245], _values[246], _values[247], _values[248], _values[249], _values[250], _values[251], _values[252], _values[253], _values[254], _values[255], _values[256], _values[257], _values[258], _values[259], _values[260], _values[261], _values[262], _values[263], _values[264], _values[265], _values[266], _values[267], _values[268], _values[269], _values[270], _values[271], _values[272], _values[273], _values[274], _values[275], _values[276], _values[277], _values[278], _values[279], _values[280], _values[281]);
    COMMIT;
END;
$$;


--
-- Name: updateOSMNodeSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMNodeSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMNodeSettingsId" sc_dt_global.integer;
BEGIN
	"_existedOSMNodeSettingsId" := (SELECT id FROM sc_ods."OSMNodeSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedOSMNodeSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."OSMNodeSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedOSMNodeSettingsId";
	ELSE
		INSERT INTO sc_ods."OSMNodeSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMNodeStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMNodeStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMNodeStatusId" sc_dt_global.integer;
BEGIN
	"_existedOSMNodeStatusId" := (SELECT id FROM sc_ods."OSMNodeStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedOSMNodeStatusId" IS NOT NULL THEN
		UPDATE sc_ods."OSMNodeStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedOSMNodeStatusId";
	ELSE
		INSERT INTO sc_ods."OSMNodeStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMWayDataAndHist(sc_dt_global."integer", sc_dt_global.string, sc_dt_global.string, sc_dt_global.string[]); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMWayDataAndHist"(_osm_id sc_dt_global."integer", _json sc_dt_global.string, _geom4326_text sc_dt_global.string, _values sc_dt_global.string[])
    LANGUAGE plpgsql
    AS $$
DECLARE
_geom4326 geometry;
"_existedOSMWayDataId" sc_dt_global.integer;
BEGIN
    _geom4326 := ST_GeomFromText(_geom4326_text, 4326);
	"_existedOSMWayDataId" := (SELECT id FROM sc_ods."OSMWayData" WHERE "osmId" = _osm_id LIMIT 1);
	IF "_existedOSMWayDataId" IS NOT NULL THEN
		UPDATE sc_ods."OSMWayData" 
			SET json = _json, geom4326 = _geom4326, "access" = _values[1], "access:lanes" = _values[2], "access:lanes:backward" = _values[3], "access:lanes:forward" = _values[4], "addr:country" = _values[5], "bidirectional" = _values[6], "car_pooling:lanes" = _values[7], "driving_direction:lanes" = _values[8], "driving_side" = _values[9], "driving_side:lanes" = _values[10], "elevation" = _values[11], "elevation_from_road" = _values[12], "elevation:lanes" = _values[13], "highway" = _values[14], "junction" = _values[15], "lanes" = _values[16], "lanes:backward" = _values[17], "lanes:bidirectional" = _values[18], "lanes:direction" = _values[19], "lanes:forward" = _values[20], "lanes:left" = _values[21], "lanes:right" = _values[22], "lane:width" = _values[23], "lanes:width" = _values[24], "width:lanes" = _values[25], "maxspeed" = _values[26], "maxspeed:lanes" = _values[27], "name" = _values[28], "oneway" = _values[29], "parking:condition:left" = _values[30], "parking:condition:right" = _values[31], "parking:lane:left" = _values[32], "parking:lane:right" = _values[33], "parking:lanes" = _values[34], "parking:lanes:left" = _values[35], "parking:lanes:right" = _values[36], "parking:left" = _values[37], "parking:right" = _values[38], "road_marking" = _values[39], "road_marking:center" = _values[40], "central_line" = _values[41], "central_reservation" = _values[42], "centreline" = _values[43], "divider" = _values[44], "road_marking:center:color" = _values[45], "centreline:color" = _values[46], "road_marking:center:material" = _values[47], "divider:material" = _values[48], "road_marking:color" = _values[49], "road_marking:colour" = _values[50], "road_marking:curb" = _values[51], "barrier" = _values[52], "barrier:type" = _values[53], "sloped_curb" = _values[54], "road_marking:lanes" = _values[55], "road_marking:lanes:color" = _values[56], "road_marking:lanes:material" = _values[57], "surface" = _values[58]
			WHERE id = "_existedOSMWayDataId";
	ELSE
		INSERT INTO sc_ods."OSMWayData"
			("osmId", json, geom4326, "access", "access:lanes", "access:lanes:backward", "access:lanes:forward", "addr:country", "bidirectional", "car_pooling:lanes", "driving_direction:lanes", "driving_side", "driving_side:lanes", "elevation", "elevation_from_road", "elevation:lanes", "highway", "junction", "lanes", "lanes:backward", "lanes:bidirectional", "lanes:direction", "lanes:forward", "lanes:left", "lanes:right", "lane:width", "lanes:width", "width:lanes", "maxspeed", "maxspeed:lanes", "name", "oneway", "parking:condition:left", "parking:condition:right", "parking:lane:left", "parking:lane:right", "parking:lanes", "parking:lanes:left", "parking:lanes:right", "parking:left", "parking:right", "road_marking", "road_marking:center", "central_line", "central_reservation", "centreline", "divider", "road_marking:center:color", "centreline:color", "road_marking:center:material", "divider:material", "road_marking:color", "road_marking:colour", "road_marking:curb", "barrier", "barrier:type", "sloped_curb", "road_marking:lanes", "road_marking:lanes:color", "road_marking:lanes:material", "surface") VALUES 
			(_osm_id, _json, _geom4326, _values[1], _values[2], _values[3], _values[4], _values[5], _values[6], _values[7], _values[8], _values[9], _values[10], _values[11], _values[12], _values[13], _values[14], _values[15], _values[16], _values[17], _values[18], _values[19], _values[20], _values[21], _values[22], _values[23], _values[24], _values[25], _values[26], _values[27], _values[28], _values[29], _values[30], _values[31], _values[32], _values[33], _values[34], _values[35], _values[36], _values[37], _values[38], _values[39], _values[40], _values[41], _values[42], _values[43], _values[44], _values[45], _values[46], _values[47], _values[48], _values[49], _values[50], _values[51], _values[52], _values[53], _values[54], _values[55], _values[56], _values[57], _values[58]);
	END IF;
	INSERT INTO sc_ods."OSMWayHist"
			("osmId", json, geom4326, "access", "access:lanes", "access:lanes:backward", "access:lanes:forward", "addr:country", "bidirectional", "car_pooling:lanes", "driving_direction:lanes", "driving_side", "driving_side:lanes", "elevation", "elevation_from_road", "elevation:lanes", "highway", "junction", "lanes", "lanes:backward", "lanes:bidirectional", "lanes:direction", "lanes:forward", "lanes:left", "lanes:right", "lane:width", "lanes:width", "width:lanes", "maxspeed", "maxspeed:lanes", "name", "oneway", "parking:condition:left", "parking:condition:right", "parking:lane:left", "parking:lane:right", "parking:lanes", "parking:lanes:left", "parking:lanes:right", "parking:left", "parking:right", "road_marking", "road_marking:center", "central_line", "central_reservation", "centreline", "divider", "road_marking:center:color", "centreline:color", "road_marking:center:material", "divider:material", "road_marking:color", "road_marking:colour", "road_marking:curb", "barrier", "barrier:type", "sloped_curb", "road_marking:lanes", "road_marking:lanes:color", "road_marking:lanes:material", "surface") VALUES 
			(_osm_id, _json, _geom4326, _values[1], _values[2], _values[3], _values[4], _values[5], _values[6], _values[7], _values[8], _values[9], _values[10], _values[11], _values[12], _values[13], _values[14], _values[15], _values[16], _values[17], _values[18], _values[19], _values[20], _values[21], _values[22], _values[23], _values[24], _values[25], _values[26], _values[27], _values[28], _values[29], _values[30], _values[31], _values[32], _values[33], _values[34], _values[35], _values[36], _values[37], _values[38], _values[39], _values[40], _values[41], _values[42], _values[43], _values[44], _values[45], _values[46], _values[47], _values[48], _values[49], _values[50], _values[51], _values[52], _values[53], _values[54], _values[55], _values[56], _values[57], _values[58]);
    COMMIT;
END;
$$;


--
-- Name: updateOSMWaySettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMWaySettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMWaySettingsId" sc_dt_global.integer;
BEGIN
	"_existedOSMWaySettingsId" := (SELECT id FROM sc_ods."OSMWaySettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedOSMWaySettingsId" IS NOT NULL THEN
		UPDATE sc_ods."OSMWaySettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedOSMWaySettingsId";
	ELSE
		INSERT INTO sc_ods."OSMWaySettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateOSMWayStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateOSMWayStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedOSMWayStatusId" sc_dt_global.integer;
BEGIN
	"_existedOSMWayStatusId" := (SELECT id FROM sc_ods."OSMWayStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedOSMWayStatusId" IS NOT NULL THEN
		UPDATE sc_ods."OSMWayStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedOSMWayStatusId";
	ELSE
		INSERT INTO sc_ods."OSMWayStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateTrajSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateTrajSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedTrajSettingsId" sc_dt_global.integer;
BEGIN
	"_existedTrajSettingsId" := (SELECT id FROM sc_ods."TrajSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedTrajSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."TrajSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedTrajSettingsId";
	ELSE
		INSERT INTO sc_ods."TrajSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateTrajStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateTrajStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedTrajStatusId" sc_dt_global.integer;
BEGIN
	"_existedTrajStatusId" := (SELECT id FROM sc_ods."TrajStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedTrajStatusId" IS NOT NULL THEN
		UPDATE sc_ods."TrajStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedTrajStatusId";
	ELSE
		INSERT INTO sc_ods."TrajStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateXODRDataAndHist(sc_dt_global."integer", sc_dt_global."integer", sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateXODRDataAndHist"("_cellRow" sc_dt_global."integer", "_cellCol" sc_dt_global."integer", _json sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
_content sc_dt_od_core."OpenDRIVE";
"_existedXODRDataId" sc_dt_global.integer;
"_existedXODRHistCount" sc_dt_global.integer;
"_oldestValidXODRHistId" sc_dt_global.integer;
BEGIN
	_content := json_populate_record(null::sc_dt_od_core."OpenDRIVE", CAST(_json AS JSON));
	"_existedXODRDataId" := (SELECT id FROM sc_ods."XODRData" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol" LIMIT 1);
	IF "_existedXODRDataId" IS NOT NULL THEN
		UPDATE sc_ods."XODRData" 
			SET content = _content
			WHERE id = "_existedXODRDataId";
	ELSE
		INSERT INTO sc_ods."XODRData"
			("cellRow", "cellCol", content) VALUES 
			("_cellRow", "_cellCol", _content);
	END IF;
	"_existedXODRHistCount" := (SELECT COUNT(*) FROM sc_ods."XODRHist" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol");
	IF "_existedXODRHistCount" > 20 THEN
		"_oldestValidXODRHistId" := (SELECT id FROM sc_ods."XODRHist" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol" ORDER BY id DESC LIMIT 1 OFFSET 1);
		DELETE FROM sc_ods."XODRHist" WHERE "cellRow" = "_cellRow" AND "cellCol" = "_cellCol" AND id < "_oldestValidXODRHistId";
	END IF;
	INSERT INTO sc_ods."XODRHist"
			("cellRow", "cellCol", content) VALUES 
			("_cellRow", "_cellCol", _content);
    COMMIT;
END;
$$;


--
-- Name: updateXODRSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateXODRSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedXODRSettingsId" sc_dt_global.integer;
BEGIN
	"_existedXODRSettingsId" := (SELECT id FROM sc_ods."XODRSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existedXODRSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."XODRSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existedXODRSettingsId";
	ELSE
		INSERT INTO sc_ods."XODRSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: updateXODRStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."updateXODRStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existedXODRStatusId" sc_dt_global.integer;
BEGIN
	"_existedXODRStatusId" := (SELECT id FROM sc_ods."XODRStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existedXODRStatusId" IS NOT NULL THEN
		UPDATE sc_ods."XODRStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existedXODRStatusId";
	ELSE
		INSERT INTO sc_ods."XODRStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: update_GlobalSettings(sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."update_GlobalSettings"("_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existed_GlobalSettingsId" sc_dt_global.integer;
BEGIN
	"_existed_GlobalSettingsId" := (SELECT id FROM sc_ods."_GlobalSettings" WHERE "settingKey" = "_settingKey" LIMIT 1);
	IF "_existed_GlobalSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."_GlobalSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existed_GlobalSettingsId";
	ELSE
		INSERT INTO sc_ods."_GlobalSettings"
			("settingKey", "settingValue") VALUES 
			("_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: update_GlobalStatus(sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."update_GlobalStatus"("_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existed_GlobalStatusId" sc_dt_global.integer;
BEGIN
	"_existed_GlobalStatusId" := (SELECT id FROM sc_ods."_GlobalStatus" WHERE "stateKey" = "_stateKey" LIMIT 1);
	IF "_existed_GlobalStatusId" IS NOT NULL THEN
		UPDATE sc_ods."_GlobalStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existed_GlobalStatusId";
	ELSE
		INSERT INTO sc_ods."_GlobalStatus"
			("stateKey", "stateValue") VALUES 
			("_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: update_UserSettings(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."update_UserSettings"("_appUser" sc_dt_global.string, "_settingKey" sc_dt_global.string, "_settingValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existed_UserSettingsId" sc_dt_global.integer;
BEGIN
	"_existed_UserSettingsId" := (SELECT id FROM sc_ods."_UserSettings" WHERE "appUser" = "_appUser" AND "settingKey" = "_settingKey" LIMIT 1);
	IF "_existed_UserSettingsId" IS NOT NULL THEN
		UPDATE sc_ods."_UserSettings" 
			SET "settingValue" = "_settingValue"
			WHERE id = "_existed_UserSettingsId";
	ELSE
		INSERT INTO sc_ods."_UserSettings"
			("appUser", "settingKey", "settingValue") VALUES 
			("_appUser", "_settingKey", "_settingValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: update_UserStatus(sc_dt_global.string, sc_dt_global.string, sc_dt_global.string); Type: PROCEDURE; Schema: sc_ods; Owner: -
--

CREATE PROCEDURE sc_ods."update_UserStatus"("_appUser" sc_dt_global.string, "_stateKey" sc_dt_global.string, "_stateValue" sc_dt_global.string)
    LANGUAGE plpgsql
    AS $$
DECLARE
"_existed_UserStatusId" sc_dt_global.integer;
BEGIN
	"_existed_UserStatusId" := (SELECT id FROM sc_ods."_UserStatus" WHERE "appUser" = "_appUser" AND "stateKey" = "_stateKey" LIMIT 1);
	IF "_existed_UserStatusId" IS NOT NULL THEN
		UPDATE sc_ods."_UserStatus" 
			SET "stateValue" = "_stateValue"
			WHERE id = "_existed_UserStatusId";
	ELSE
		INSERT INTO sc_ods."_UserStatus"
			("appUser", "stateKey", "stateValue") VALUES 
			("_appUser", "_stateKey", "_stateValue");
	END IF;
    COMMIT;
END;
$$;


--
-- Name: GPSCellsDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSCellsDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: GPSCellsData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSCellsData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSCellsDataIdSeq"'::regclass) NOT NULL,
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: GPSFileDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSFileDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSFileData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSFileData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSFileDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: GPSLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: GPSNativeDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSNativeDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSNativeData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSNativeData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSNativeDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    "gpsFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    "GPS Week" sc_dt_global."int",
    "GPS TOW [s]" sc_dt_global.double,
    "Pos Mode" sc_dt_global."int",
    "INS Mode" sc_dt_global."int",
    "Hdg Mode" sc_dt_global.string,
    "SVs Tracked" sc_dt_global.string,
    "SVs Used" sc_dt_global."int",
    "UTC Date" sc_dt_global.string,
    "UTC Time" sc_dt_global.string,
    "Lat [deg]" sc_dt_global.double,
    "Lon [deg]" sc_dt_global.double,
    "Alt Ellips [m]" sc_dt_global.double,
    "SOG [m/s]" sc_dt_global.double,
    "COG [deg]" sc_dt_global.double,
    "Hdg [deg]" sc_dt_global.double,
    "Vert Vel [m/s]" sc_dt_global.double,
    "Roll [deg]" sc_dt_global.double,
    "Pitch [deg]" sc_dt_global.double,
    "Yaw [deg]" sc_dt_global.double,
    "PDOP" sc_dt_global.double,
    "HDOP" sc_dt_global.double,
    "EHPE [m]" sc_dt_global.double,
    "EVPE [m]" sc_dt_global.double,
    "Baseline 2D [m]" sc_dt_global.double,
    "Baseline 3D [m]" sc_dt_global.double,
    "Corr. Age [s]" sc_dt_global.double,
    "Delta TOW [ms]" sc_dt_global.double,
    "2D Delta Pos [m]" sc_dt_global.double,
    "3D Delta Pos [m]" sc_dt_global.double
);


--
-- Name: GPSSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: GPSStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: GPSValidDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSValidDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSValidData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSValidData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSValidDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    "gpsFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    "GPS Week" sc_dt_global."int",
    "GPS TOW [s]" sc_dt_global.double,
    "Pos Mode" sc_dt_global."int",
    "INS Mode" sc_dt_global."int",
    "Hdg Mode" sc_dt_global.string,
    "SVs Tracked" sc_dt_global.string,
    "SVs Used" sc_dt_global."int",
    "UTC Date" sc_dt_global.string,
    "UTC Time" sc_dt_global.string,
    "Lat [deg]" sc_dt_global.double,
    "Lon [deg]" sc_dt_global.double,
    "Alt Ellips [m]" sc_dt_global.double,
    "SOG [m/s]" sc_dt_global.double,
    "COG [deg]" sc_dt_global.double,
    "Hdg [deg]" sc_dt_global.double,
    "Vert Vel [m/s]" sc_dt_global.double,
    "Roll [deg]" sc_dt_global.double,
    "Pitch [deg]" sc_dt_global.double,
    "Yaw [deg]" sc_dt_global.double,
    "PDOP" sc_dt_global.double,
    "HDOP" sc_dt_global.double,
    "EHPE [m]" sc_dt_global.double,
    "EVPE [m]" sc_dt_global.double,
    "Baseline 2D [m]" sc_dt_global.double,
    "Baseline 3D [m]" sc_dt_global.double,
    "Corr. Age [s]" sc_dt_global.double,
    "Delta TOW [ms]" sc_dt_global.double,
    "2D Delta Pos [m]" sc_dt_global.double,
    "3D Delta Pos [m]" sc_dt_global.double
);


--
-- Name: GPSValidSeqCellsDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GPSValidSeqCellsDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GPSValidSeqCellsData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GPSValidSeqCellsData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GPSValidSeqCellsDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    "gpsFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    "startId" sc_dt_global."integer",
    "endId" sc_dt_global."integer"
);


--
-- Name: GeoJSONApplyingDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONApplyingDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONApplyingData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONApplyingData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONApplyingDataIdSeq"'::regclass) NOT NULL,
    "geoJSONStagingNativeDataId" sc_dt_global."integer",
    "geoJSONStagingFilePath" sc_dt_global.string,
    "geoJSONStagingFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    tag sc_dt_global.string,
    json sc_dt_global.string,
    operation sc_dt_global.string,
    "xodrHistIdBefore" sc_dt_global."integer",
    "contentBefore" sc_dt_od_core."OpenDRIVE",
    "xodrHistIdAfter" sc_dt_global."integer",
    "contentAfter" sc_dt_od_core."OpenDRIVE"
);


--
-- Name: GeoJSONApplyingLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONApplyingLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONApplyingLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONApplyingLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONApplyingLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: GeoJSONApplyingSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONApplyingSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONApplyingSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONApplyingSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONApplyingSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: GeoJSONApplyingStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONApplyingStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONApplyingStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONApplyingStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONApplyingStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: GeoJSONStagingFileDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONStagingFileDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONStagingFileData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONStagingFileData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONStagingFileDataIdSeq"'::regclass) NOT NULL,
    "geoJSONStagingFilePath" sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: GeoJSONStagingLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONStagingLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONStagingLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONStagingLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONStagingLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: GeoJSONStagingNativeDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONStagingNativeDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONStagingNativeData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONStagingNativeData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONStagingNativeDataIdSeq"'::regclass) NOT NULL,
    "geoJSONStagingFilePath" sc_dt_global.string,
    "geoJSONStagingFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    tag sc_dt_global.string,
    json sc_dt_global.string
);


--
-- Name: GeoJSONStagingSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONStagingSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONStagingSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONStagingSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONStagingSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: GeoJSONStagingStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."GeoJSONStagingStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: GeoJSONStagingStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."GeoJSONStagingStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."GeoJSONStagingStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: OSMCntryAreaDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMCntryAreaDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMCntryAreaData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMCntryAreaData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMCntryAreaDataIdSeq"'::regclass) NOT NULL,
    iso3166_1 sc_dt_global.string,
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: OSMCntryAreaHistIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMCntryAreaHistIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMCntryAreaHist; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMCntryAreaHist" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMCntryAreaHistIdSeq"'::regclass) NOT NULL,
    iso3166_1 sc_dt_global.string,
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: OSMCntryAreaLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMCntryAreaLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMCntryAreaLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMCntryAreaLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMCntryAreaLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: OSMCntryAreaSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMCntryAreaSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMCntryAreaSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMCntryAreaSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMCntryAreaSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: OSMCntryAreaStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMCntryAreaStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMCntryAreaStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMCntryAreaStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMCntryAreaStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: OSMNodeDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMNodeDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMNodeData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMNodeData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMNodeDataIdSeq"'::regclass) NOT NULL,
    "osmId" sc_dt_global."integer",
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    abandoned sc_dt_global.string,
    "abandoned:amenity" sc_dt_global.string,
    "abandoned:building" sc_dt_global.string,
    "abandoned:car" sc_dt_global.string,
    "abandoned:crossing" sc_dt_global.string,
    "abandoned:highway" sc_dt_global.string,
    "abandoned:highway:traffic_signals" sc_dt_global.string,
    "abandoned:natural" sc_dt_global.string,
    "abandoned:natural:tree" sc_dt_global.string,
    "abandoned:parking" sc_dt_global.string,
    "abandoned:pole" sc_dt_global.string,
    "abandoned:railway" sc_dt_global.string,
    "abandoned:railway:traffic_signals" sc_dt_global.string,
    "abandoned:traffic_sign" sc_dt_global.string,
    "abandoned:tree" sc_dt_global.string,
    accomodation sc_dt_global.string,
    "addr:building" sc_dt_global.string,
    "addr:housename" sc_dt_global.string,
    amenity sc_dt_global.string,
    amenity_1 sc_dt_global.string,
    amenity_2 sc_dt_global.string,
    area sc_dt_global.string,
    "area:building" sc_dt_global.string,
    "area:highway" sc_dt_global.string,
    "area:traffic_calming" sc_dt_global.string,
    barrier sc_dt_global.string,
    "barrier:tree" sc_dt_global.string,
    "barrier:type" sc_dt_global.string,
    bicycle sc_dt_global.string,
    "bicycle:parking" sc_dt_global.string,
    "bicycle_parking:position" sc_dt_global.string,
    "bicycle:traffic_signals" sc_dt_global.string,
    "blazed:natural" sc_dt_global.string,
    bollard sc_dt_global.string,
    "bollard:traffic_sign" sc_dt_global.string,
    broken sc_dt_global.string,
    "broken:traffic_sign" sc_dt_global.string,
    building sc_dt_global.string,
    calming sc_dt_global.string,
    "camera:mount" sc_dt_global.string,
    construction sc_dt_global.string,
    "construction:amenity" sc_dt_global.string,
    "construction:building" sc_dt_global.string,
    "construction:crossing" sc_dt_global.string,
    "construction:crossing:island" sc_dt_global.string,
    "construction:demolished:highway" sc_dt_global.string,
    "construction:demolished:highway:traffic_signals" sc_dt_global.string,
    "construction:highway" sc_dt_global.string,
    "construction:highway:traffic_sign" sc_dt_global.string,
    "construction:highway:traffic_signal" sc_dt_global.string,
    "construction:highway:traffic_signals" sc_dt_global.string,
    "construction:junction" sc_dt_global.string,
    "construction:parking" sc_dt_global.string,
    "construction:road_marking" sc_dt_global.string,
    "construction:traffic_signals" sc_dt_global.string,
    crane sc_dt_global.string,
    "crane:type" sc_dt_global.string,
    crossing sc_dt_global.string,
    crossing_1 sc_dt_global.string,
    crossing_2 sc_dt_global.string,
    "crossing:island" sc_dt_global.string,
    "crossing:road_marking" sc_dt_global.string,
    crosswalk sc_dt_global.string,
    cycleway sc_dt_global.string,
    "cycleway:left" sc_dt_global.string,
    "cycleway:left:traffic_sign" sc_dt_global.string,
    "cycleway:left:traffic_signals" sc_dt_global.string,
    "cycleway:right" sc_dt_global.string,
    "cycleway:right:traffic_sign" sc_dt_global.string,
    "cycleway:right:traffic_signals" sc_dt_global.string,
    "cycleway:traffic_sign" sc_dt_global.string,
    "cycleway:traffic_signals" sc_dt_global.string,
    "dead:natural" sc_dt_global.string,
    demolished sc_dt_global.string,
    "demolished:amenity" sc_dt_global.string,
    "demolished:building" sc_dt_global.string,
    "demolished:crossing" sc_dt_global.string,
    "demolished:highway" sc_dt_global.string,
    "demolished:highway:traffic_signals" sc_dt_global.string,
    "demolished:junction" sc_dt_global.string,
    "demolished:natural" sc_dt_global.string,
    "demolished:parking" sc_dt_global.string,
    "demolished:traffic_sign" sc_dt_global.string,
    destroyed sc_dt_global.string,
    "destroyed:building" sc_dt_global.string,
    "destroyed:natural" sc_dt_global.string,
    "destroyed:traffic_sign" sc_dt_global.string,
    device sc_dt_global.string,
    "device:traffic_signals" sc_dt_global.string,
    disabled sc_dt_global.string,
    "disabled:highway" sc_dt_global.string,
    "disabled:highway:traffic_signals" sc_dt_global.string,
    "disabled:traffic_sign" sc_dt_global.string,
    disused sc_dt_global.string,
    "disused:building" sc_dt_global.string,
    "disused:crossing" sc_dt_global.string,
    "disused:highway" sc_dt_global.string,
    "disused:highway:traffic_signals" sc_dt_global.string,
    "disused:parking" sc_dt_global.string,
    "disused:playground" sc_dt_global.string,
    "disused:playground:roundabout" sc_dt_global.string,
    "disused:traffic_sign" sc_dt_global.string,
    "disused:traffic_signals" sc_dt_global.string,
    enforcement sc_dt_global.string,
    fence sc_dt_global.string,
    "fence:pole" sc_dt_global.string,
    fence_type sc_dt_global.string,
    "fence:type" sc_dt_global.string,
    footway sc_dt_global.string,
    forest sc_dt_global.string,
    gantry sc_dt_global.string,
    "gantry:type" sc_dt_global.string,
    "gone:natural" sc_dt_global.string,
    handrail sc_dt_global.string,
    highway sc_dt_global.string,
    highway_1 sc_dt_global.string,
    "highway_1:traffic_signals" sc_dt_global.string,
    highway_2 sc_dt_global.string,
    "highway_2:traffic_signals" sc_dt_global.string,
    "highway:backward" sc_dt_global.string,
    "highway:backward:traffic_signals" sc_dt_global.string,
    "highway:backwards" sc_dt_global.string,
    "highway:backwards:traffic_signals" sc_dt_global.string,
    "highway:bicycle" sc_dt_global.string,
    "highway:bicycle:traffic_signals" sc_dt_global.string,
    "highway:construction" sc_dt_global.string,
    "highway:construction:traffic_signals" sc_dt_global.string,
    "highway:disused" sc_dt_global.string,
    "highway:disused:traffic_signals" sc_dt_global.string,
    "highway:forward" sc_dt_global.string,
    "highway:forward:traffic_signals" sc_dt_global.string,
    "highway:historic" sc_dt_global.string,
    "highway:historic:traffic_signals" sc_dt_global.string,
    "highway:street_lamp" sc_dt_global.string,
    "highway:traffic_signals" sc_dt_global.string,
    historic sc_dt_global.string,
    historic_1 sc_dt_global.string,
    "historic_1:building" sc_dt_global.string,
    "historic:building" sc_dt_global.string,
    "historic:crossing" sc_dt_global.string,
    "historic:highway" sc_dt_global.string,
    "historic:highway:traffic_signals" sc_dt_global.string,
    historical sc_dt_global.string,
    "historical:building" sc_dt_global.string,
    house sc_dt_global.string,
    industrial sc_dt_global.string,
    intersection sc_dt_global.string,
    "intersection:traffic_signals" sc_dt_global.string,
    junction sc_dt_global.string,
    "junction:separate" sc_dt_global.string,
    "junction:separate:traffic_signals" sc_dt_global.string,
    "junction:traffic_signals" sc_dt_global.string,
    "kerb:road_marking" sc_dt_global.string,
    lamp_type sc_dt_global.string,
    "lamp:type" sc_dt_global.string,
    landuse sc_dt_global.string,
    level_crossing sc_dt_global.string,
    light sc_dt_global.string,
    "light:type" sc_dt_global.string,
    lit sc_dt_global.string,
    location sc_dt_global.string,
    "location:traffic_sign" sc_dt_global.string,
    man_made sc_dt_global.string,
    "man_made:separate" sc_dt_global.string,
    "man_made:separate:traffic_sign" sc_dt_global.string,
    mini_roundabout sc_dt_global.string,
    miniroundabout sc_dt_global.string,
    motorcycle sc_dt_global.string,
    "motorcycle:parking" sc_dt_global.string,
    name sc_dt_global.string,
    "name:building" sc_dt_global.string,
    natura sc_dt_global.string,
    "natural" sc_dt_global.string,
    natural_1 sc_dt_global.string,
    "natural_1:tree" sc_dt_global.string,
    "natural:tree" sc_dt_global.string,
    obstacle sc_dt_global.string,
    "obstacle:traffic_sign" sc_dt_global.string,
    old_amenity sc_dt_global.string,
    "old:amenity" sc_dt_global.string,
    old_natural sc_dt_global.string,
    "old:natural" sc_dt_global.string,
    park sc_dt_global.string,
    parking sc_dt_global.string,
    parking_1 sc_dt_global.string,
    parking_position sc_dt_global.string,
    parking_slots sc_dt_global.string,
    parking_space sc_dt_global.string,
    parking_zone sc_dt_global.string,
    plant sc_dt_global.string,
    playground sc_dt_global.string,
    "playground:roundabout" sc_dt_global.string,
    pole sc_dt_global.string,
    public_transport sc_dt_global.string,
    railing sc_dt_global.string,
    railway sc_dt_global.string,
    razed sc_dt_global.string,
    "razed:amenity" sc_dt_global.string,
    "razed:building" sc_dt_global.string,
    "razed:crossing" sc_dt_global.string,
    "razed:crossing:island" sc_dt_global.string,
    "razed:highway" sc_dt_global.string,
    "razed:highway:traffic_signals" sc_dt_global.string,
    "razed:natural" sc_dt_global.string,
    "razed:natural:tree" sc_dt_global.string,
    "razed:playground" sc_dt_global.string,
    "razed:pole" sc_dt_global.string,
    "razed:traffic_sign" sc_dt_global.string,
    "razed:traffic_signals" sc_dt_global.string,
    "razed:tree" sc_dt_global.string,
    ref sc_dt_global.string,
    "ref:pole" sc_dt_global.string,
    residential sc_dt_global.string,
    road sc_dt_global.string,
    road_mark sc_dt_global.string,
    road_marking sc_dt_global.string,
    "road:traffic_signals" sc_dt_global.string,
    "roadMark" sc_dt_global.string,
    roundabout sc_dt_global.string,
    ruined sc_dt_global.string,
    "ruined:building" sc_dt_global.string,
    ruins sc_dt_global.string,
    "ruins:building" sc_dt_global.string,
    "ruins:car" sc_dt_global.string,
    "ruins:tree" sc_dt_global.string,
    seamark sc_dt_global.string,
    "seamark:building" sc_dt_global.string,
    "seasonal:winter" sc_dt_global.string,
    "seasonal:winter:traffic_sign" sc_dt_global.string,
    "service:vehicle:parking" sc_dt_global.string,
    services sc_dt_global.string,
    sidewalk sc_dt_global.string,
    "sidewalk:left" sc_dt_global.string,
    "sidewalk:left:traffic_sign" sc_dt_global.string,
    "sidewalk:right" sc_dt_global.string,
    "sidewalk:right:traffic_sign" sc_dt_global.string,
    "sidewalk:traffic_sign" sc_dt_global.string,
    site sc_dt_global.string,
    street_cabinet sc_dt_global.string,
    "street_cabinet:traffic_sign" sc_dt_global.string,
    "street_cabinet:traffic_signal" sc_dt_global.string,
    "street_cabinet:traffic_signals" sc_dt_global.string,
    street_furniture sc_dt_global.string,
    street_lamp sc_dt_global.string,
    street_light sc_dt_global.string,
    "streetLamp" sc_dt_global.string,
    "streetlamp:ref" sc_dt_global.string,
    streetlight sc_dt_global.string,
    structure sc_dt_global.string,
    "temporarily:gone" sc_dt_global.string,
    "temporarily:gone:traffic_sign" sc_dt_global.string,
    temporarily_removed sc_dt_global.string,
    "temporarily_removed:traffic_sign" sc_dt_global.string,
    temporary sc_dt_global.string,
    "temporary:building" sc_dt_global.string,
    traffic_calming sc_dt_global.string,
    traffic_control sc_dt_global.string,
    "traffic_control:traffic_signals" sc_dt_global.string,
    traffic_island sc_dt_global.string,
    traffic_lights sc_dt_global.string,
    traffic_sign sc_dt_global.string,
    traffic_sign_1 sc_dt_global.string,
    traffic_signal sc_dt_global.string,
    traffic_signals sc_dt_global.string,
    traffic_signals_1 sc_dt_global.string,
    training sc_dt_global.string,
    transport sc_dt_global.string,
    "transport:traffic_signals" sc_dt_global.string,
    transportation sc_dt_global.string,
    tree sc_dt_global.string,
    trees sc_dt_global.string,
    type sc_dt_global.string,
    "type:pole" sc_dt_global.string,
    use sc_dt_global.string,
    user_defined sc_dt_global.string,
    user_defined_other sc_dt_global.string,
    vegetation sc_dt_global.string,
    waterway sc_dt_global.string,
    "waterway:traffic_sign" sc_dt_global.string,
    zone sc_dt_global.string,
    "zone:parking" sc_dt_global.string
);


--
-- Name: OSMNodeHistIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMNodeHistIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMNodeHist; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMNodeHist" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMNodeHistIdSeq"'::regclass) NOT NULL,
    "osmId" sc_dt_global."integer",
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    abandoned sc_dt_global.string,
    "abandoned:amenity" sc_dt_global.string,
    "abandoned:building" sc_dt_global.string,
    "abandoned:car" sc_dt_global.string,
    "abandoned:crossing" sc_dt_global.string,
    "abandoned:highway" sc_dt_global.string,
    "abandoned:highway:traffic_signals" sc_dt_global.string,
    "abandoned:natural" sc_dt_global.string,
    "abandoned:natural:tree" sc_dt_global.string,
    "abandoned:parking" sc_dt_global.string,
    "abandoned:pole" sc_dt_global.string,
    "abandoned:railway" sc_dt_global.string,
    "abandoned:railway:traffic_signals" sc_dt_global.string,
    "abandoned:traffic_sign" sc_dt_global.string,
    "abandoned:tree" sc_dt_global.string,
    accomodation sc_dt_global.string,
    "addr:building" sc_dt_global.string,
    "addr:housename" sc_dt_global.string,
    amenity sc_dt_global.string,
    amenity_1 sc_dt_global.string,
    amenity_2 sc_dt_global.string,
    area sc_dt_global.string,
    "area:building" sc_dt_global.string,
    "area:highway" sc_dt_global.string,
    "area:traffic_calming" sc_dt_global.string,
    barrier sc_dt_global.string,
    "barrier:tree" sc_dt_global.string,
    "barrier:type" sc_dt_global.string,
    bicycle sc_dt_global.string,
    "bicycle:parking" sc_dt_global.string,
    "bicycle_parking:position" sc_dt_global.string,
    "bicycle:traffic_signals" sc_dt_global.string,
    "blazed:natural" sc_dt_global.string,
    bollard sc_dt_global.string,
    "bollard:traffic_sign" sc_dt_global.string,
    broken sc_dt_global.string,
    "broken:traffic_sign" sc_dt_global.string,
    building sc_dt_global.string,
    calming sc_dt_global.string,
    "camera:mount" sc_dt_global.string,
    construction sc_dt_global.string,
    "construction:amenity" sc_dt_global.string,
    "construction:building" sc_dt_global.string,
    "construction:crossing" sc_dt_global.string,
    "construction:crossing:island" sc_dt_global.string,
    "construction:demolished:highway" sc_dt_global.string,
    "construction:demolished:highway:traffic_signals" sc_dt_global.string,
    "construction:highway" sc_dt_global.string,
    "construction:highway:traffic_sign" sc_dt_global.string,
    "construction:highway:traffic_signal" sc_dt_global.string,
    "construction:highway:traffic_signals" sc_dt_global.string,
    "construction:junction" sc_dt_global.string,
    "construction:parking" sc_dt_global.string,
    "construction:road_marking" sc_dt_global.string,
    "construction:traffic_signals" sc_dt_global.string,
    crane sc_dt_global.string,
    "crane:type" sc_dt_global.string,
    crossing sc_dt_global.string,
    crossing_1 sc_dt_global.string,
    crossing_2 sc_dt_global.string,
    "crossing:island" sc_dt_global.string,
    "crossing:road_marking" sc_dt_global.string,
    crosswalk sc_dt_global.string,
    cycleway sc_dt_global.string,
    "cycleway:left" sc_dt_global.string,
    "cycleway:left:traffic_sign" sc_dt_global.string,
    "cycleway:left:traffic_signals" sc_dt_global.string,
    "cycleway:right" sc_dt_global.string,
    "cycleway:right:traffic_sign" sc_dt_global.string,
    "cycleway:right:traffic_signals" sc_dt_global.string,
    "cycleway:traffic_sign" sc_dt_global.string,
    "cycleway:traffic_signals" sc_dt_global.string,
    "dead:natural" sc_dt_global.string,
    demolished sc_dt_global.string,
    "demolished:amenity" sc_dt_global.string,
    "demolished:building" sc_dt_global.string,
    "demolished:crossing" sc_dt_global.string,
    "demolished:highway" sc_dt_global.string,
    "demolished:highway:traffic_signals" sc_dt_global.string,
    "demolished:junction" sc_dt_global.string,
    "demolished:natural" sc_dt_global.string,
    "demolished:parking" sc_dt_global.string,
    "demolished:traffic_sign" sc_dt_global.string,
    destroyed sc_dt_global.string,
    "destroyed:building" sc_dt_global.string,
    "destroyed:natural" sc_dt_global.string,
    "destroyed:traffic_sign" sc_dt_global.string,
    device sc_dt_global.string,
    "device:traffic_signals" sc_dt_global.string,
    disabled sc_dt_global.string,
    "disabled:highway" sc_dt_global.string,
    "disabled:highway:traffic_signals" sc_dt_global.string,
    "disabled:traffic_sign" sc_dt_global.string,
    disused sc_dt_global.string,
    "disused:building" sc_dt_global.string,
    "disused:crossing" sc_dt_global.string,
    "disused:highway" sc_dt_global.string,
    "disused:highway:traffic_signals" sc_dt_global.string,
    "disused:parking" sc_dt_global.string,
    "disused:playground" sc_dt_global.string,
    "disused:playground:roundabout" sc_dt_global.string,
    "disused:traffic_sign" sc_dt_global.string,
    "disused:traffic_signals" sc_dt_global.string,
    enforcement sc_dt_global.string,
    fence sc_dt_global.string,
    "fence:pole" sc_dt_global.string,
    fence_type sc_dt_global.string,
    "fence:type" sc_dt_global.string,
    footway sc_dt_global.string,
    forest sc_dt_global.string,
    gantry sc_dt_global.string,
    "gantry:type" sc_dt_global.string,
    "gone:natural" sc_dt_global.string,
    handrail sc_dt_global.string,
    highway sc_dt_global.string,
    highway_1 sc_dt_global.string,
    "highway_1:traffic_signals" sc_dt_global.string,
    highway_2 sc_dt_global.string,
    "highway_2:traffic_signals" sc_dt_global.string,
    "highway:backward" sc_dt_global.string,
    "highway:backward:traffic_signals" sc_dt_global.string,
    "highway:backwards" sc_dt_global.string,
    "highway:backwards:traffic_signals" sc_dt_global.string,
    "highway:bicycle" sc_dt_global.string,
    "highway:bicycle:traffic_signals" sc_dt_global.string,
    "highway:construction" sc_dt_global.string,
    "highway:construction:traffic_signals" sc_dt_global.string,
    "highway:disused" sc_dt_global.string,
    "highway:disused:traffic_signals" sc_dt_global.string,
    "highway:forward" sc_dt_global.string,
    "highway:forward:traffic_signals" sc_dt_global.string,
    "highway:historic" sc_dt_global.string,
    "highway:historic:traffic_signals" sc_dt_global.string,
    "highway:street_lamp" sc_dt_global.string,
    "highway:traffic_signals" sc_dt_global.string,
    historic sc_dt_global.string,
    historic_1 sc_dt_global.string,
    "historic_1:building" sc_dt_global.string,
    "historic:building" sc_dt_global.string,
    "historic:crossing" sc_dt_global.string,
    "historic:highway" sc_dt_global.string,
    "historic:highway:traffic_signals" sc_dt_global.string,
    historical sc_dt_global.string,
    "historical:building" sc_dt_global.string,
    house sc_dt_global.string,
    industrial sc_dt_global.string,
    intersection sc_dt_global.string,
    "intersection:traffic_signals" sc_dt_global.string,
    junction sc_dt_global.string,
    "junction:separate" sc_dt_global.string,
    "junction:separate:traffic_signals" sc_dt_global.string,
    "junction:traffic_signals" sc_dt_global.string,
    "kerb:road_marking" sc_dt_global.string,
    lamp_type sc_dt_global.string,
    "lamp:type" sc_dt_global.string,
    landuse sc_dt_global.string,
    level_crossing sc_dt_global.string,
    light sc_dt_global.string,
    "light:type" sc_dt_global.string,
    lit sc_dt_global.string,
    location sc_dt_global.string,
    "location:traffic_sign" sc_dt_global.string,
    man_made sc_dt_global.string,
    "man_made:separate" sc_dt_global.string,
    "man_made:separate:traffic_sign" sc_dt_global.string,
    mini_roundabout sc_dt_global.string,
    miniroundabout sc_dt_global.string,
    motorcycle sc_dt_global.string,
    "motorcycle:parking" sc_dt_global.string,
    name sc_dt_global.string,
    "name:building" sc_dt_global.string,
    natura sc_dt_global.string,
    "natural" sc_dt_global.string,
    natural_1 sc_dt_global.string,
    "natural_1:tree" sc_dt_global.string,
    "natural:tree" sc_dt_global.string,
    obstacle sc_dt_global.string,
    "obstacle:traffic_sign" sc_dt_global.string,
    old_amenity sc_dt_global.string,
    "old:amenity" sc_dt_global.string,
    old_natural sc_dt_global.string,
    "old:natural" sc_dt_global.string,
    park sc_dt_global.string,
    parking sc_dt_global.string,
    parking_1 sc_dt_global.string,
    parking_position sc_dt_global.string,
    parking_slots sc_dt_global.string,
    parking_space sc_dt_global.string,
    parking_zone sc_dt_global.string,
    plant sc_dt_global.string,
    playground sc_dt_global.string,
    "playground:roundabout" sc_dt_global.string,
    pole sc_dt_global.string,
    public_transport sc_dt_global.string,
    railing sc_dt_global.string,
    railway sc_dt_global.string,
    razed sc_dt_global.string,
    "razed:amenity" sc_dt_global.string,
    "razed:building" sc_dt_global.string,
    "razed:crossing" sc_dt_global.string,
    "razed:crossing:island" sc_dt_global.string,
    "razed:highway" sc_dt_global.string,
    "razed:highway:traffic_signals" sc_dt_global.string,
    "razed:natural" sc_dt_global.string,
    "razed:natural:tree" sc_dt_global.string,
    "razed:playground" sc_dt_global.string,
    "razed:pole" sc_dt_global.string,
    "razed:traffic_sign" sc_dt_global.string,
    "razed:traffic_signals" sc_dt_global.string,
    "razed:tree" sc_dt_global.string,
    ref sc_dt_global.string,
    "ref:pole" sc_dt_global.string,
    residential sc_dt_global.string,
    road sc_dt_global.string,
    road_mark sc_dt_global.string,
    road_marking sc_dt_global.string,
    "road:traffic_signals" sc_dt_global.string,
    "roadMark" sc_dt_global.string,
    roundabout sc_dt_global.string,
    ruined sc_dt_global.string,
    "ruined:building" sc_dt_global.string,
    ruins sc_dt_global.string,
    "ruins:building" sc_dt_global.string,
    "ruins:car" sc_dt_global.string,
    "ruins:tree" sc_dt_global.string,
    seamark sc_dt_global.string,
    "seamark:building" sc_dt_global.string,
    "seasonal:winter" sc_dt_global.string,
    "seasonal:winter:traffic_sign" sc_dt_global.string,
    "service:vehicle:parking" sc_dt_global.string,
    services sc_dt_global.string,
    sidewalk sc_dt_global.string,
    "sidewalk:left" sc_dt_global.string,
    "sidewalk:left:traffic_sign" sc_dt_global.string,
    "sidewalk:right" sc_dt_global.string,
    "sidewalk:right:traffic_sign" sc_dt_global.string,
    "sidewalk:traffic_sign" sc_dt_global.string,
    site sc_dt_global.string,
    street_cabinet sc_dt_global.string,
    "street_cabinet:traffic_sign" sc_dt_global.string,
    "street_cabinet:traffic_signal" sc_dt_global.string,
    "street_cabinet:traffic_signals" sc_dt_global.string,
    street_furniture sc_dt_global.string,
    street_lamp sc_dt_global.string,
    street_light sc_dt_global.string,
    "streetLamp" sc_dt_global.string,
    "streetlamp:ref" sc_dt_global.string,
    streetlight sc_dt_global.string,
    structure sc_dt_global.string,
    "temporarily:gone" sc_dt_global.string,
    "temporarily:gone:traffic_sign" sc_dt_global.string,
    temporarily_removed sc_dt_global.string,
    "temporarily_removed:traffic_sign" sc_dt_global.string,
    temporary sc_dt_global.string,
    "temporary:building" sc_dt_global.string,
    traffic_calming sc_dt_global.string,
    traffic_control sc_dt_global.string,
    "traffic_control:traffic_signals" sc_dt_global.string,
    traffic_island sc_dt_global.string,
    traffic_lights sc_dt_global.string,
    traffic_sign sc_dt_global.string,
    traffic_sign_1 sc_dt_global.string,
    traffic_signal sc_dt_global.string,
    traffic_signals sc_dt_global.string,
    traffic_signals_1 sc_dt_global.string,
    training sc_dt_global.string,
    transport sc_dt_global.string,
    "transport:traffic_signals" sc_dt_global.string,
    transportation sc_dt_global.string,
    tree sc_dt_global.string,
    trees sc_dt_global.string,
    type sc_dt_global.string,
    "type:pole" sc_dt_global.string,
    use sc_dt_global.string,
    user_defined sc_dt_global.string,
    user_defined_other sc_dt_global.string,
    vegetation sc_dt_global.string,
    waterway sc_dt_global.string,
    "waterway:traffic_sign" sc_dt_global.string,
    zone sc_dt_global.string,
    "zone:parking" sc_dt_global.string
);


--
-- Name: OSMNodeLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMNodeLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMNodeLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMNodeLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMNodeLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: OSMNodeSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMNodeSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMNodeSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMNodeSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMNodeSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: OSMNodeStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMNodeStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMNodeStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMNodeStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMNodeStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: OSMWayDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMWayDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMWayData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMWayData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMWayDataIdSeq"'::regclass) NOT NULL,
    "osmId" sc_dt_global."integer",
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    access sc_dt_global.string,
    "access:lanes" sc_dt_global.string,
    "access:lanes:backward" sc_dt_global.string,
    "access:lanes:forward" sc_dt_global.string,
    "addr:country" sc_dt_global.string,
    bidirectional sc_dt_global.string,
    "car_pooling:lanes" sc_dt_global.string,
    "driving_direction:lanes" sc_dt_global.string,
    driving_side sc_dt_global.string,
    "driving_side:lanes" sc_dt_global.string,
    elevation sc_dt_global.string,
    elevation_from_road sc_dt_global.string,
    "elevation:lanes" sc_dt_global.string,
    highway sc_dt_global.string,
    junction sc_dt_global.string,
    lanes sc_dt_global.string,
    "lanes:backward" sc_dt_global.string,
    "lanes:bidirectional" sc_dt_global.string,
    "lanes:direction" sc_dt_global.string,
    "lanes:forward" sc_dt_global.string,
    "lanes:left" sc_dt_global.string,
    "lanes:right" sc_dt_global.string,
    "lane:width" sc_dt_global.string,
    "lanes:width" sc_dt_global.string,
    "width:lanes" sc_dt_global.string,
    maxspeed sc_dt_global.string,
    "maxspeed:lanes" sc_dt_global.string,
    name sc_dt_global.string,
    oneway sc_dt_global.string,
    "parking:condition:left" sc_dt_global.string,
    "parking:condition:right" sc_dt_global.string,
    "parking:lane:left" sc_dt_global.string,
    "parking:lane:right" sc_dt_global.string,
    "parking:lanes" sc_dt_global.string,
    "parking:lanes:left" sc_dt_global.string,
    "parking:lanes:right" sc_dt_global.string,
    "parking:left" sc_dt_global.string,
    "parking:right" sc_dt_global.string,
    road_marking sc_dt_global.string,
    "road_marking:center" sc_dt_global.string,
    central_line sc_dt_global.string,
    central_reservation sc_dt_global.string,
    centreline sc_dt_global.string,
    divider sc_dt_global.string,
    "road_marking:center:color" sc_dt_global.string,
    "centreline:color" sc_dt_global.string,
    "road_marking:center:material" sc_dt_global.string,
    "divider:material" sc_dt_global.string,
    "road_marking:color" sc_dt_global.string,
    "road_marking:colour" sc_dt_global.string,
    "road_marking:curb" sc_dt_global.string,
    barrier sc_dt_global.string,
    "barrier:type" sc_dt_global.string,
    sloped_curb sc_dt_global.string,
    "road_marking:lanes" sc_dt_global.string,
    "road_marking:lanes:color" sc_dt_global.string,
    "road_marking:lanes:material" sc_dt_global.string,
    surface sc_dt_global.string
);


--
-- Name: OSMWayHistIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMWayHistIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMWayHist; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMWayHist" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMWayHistIdSeq"'::regclass) NOT NULL,
    "osmId" sc_dt_global."integer",
    json sc_dt_global.string,
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    access sc_dt_global.string,
    "access:lanes" sc_dt_global.string,
    "access:lanes:backward" sc_dt_global.string,
    "access:lanes:forward" sc_dt_global.string,
    "addr:country" sc_dt_global.string,
    bidirectional sc_dt_global.string,
    "car_pooling:lanes" sc_dt_global.string,
    "driving_direction:lanes" sc_dt_global.string,
    driving_side sc_dt_global.string,
    "driving_side:lanes" sc_dt_global.string,
    elevation sc_dt_global.string,
    elevation_from_road sc_dt_global.string,
    "elevation:lanes" sc_dt_global.string,
    highway sc_dt_global.string,
    junction sc_dt_global.string,
    lanes sc_dt_global.string,
    "lanes:backward" sc_dt_global.string,
    "lanes:bidirectional" sc_dt_global.string,
    "lanes:direction" sc_dt_global.string,
    "lanes:forward" sc_dt_global.string,
    "lanes:left" sc_dt_global.string,
    "lanes:right" sc_dt_global.string,
    "lane:width" sc_dt_global.string,
    "lanes:width" sc_dt_global.string,
    "width:lanes" sc_dt_global.string,
    maxspeed sc_dt_global.string,
    "maxspeed:lanes" sc_dt_global.string,
    name sc_dt_global.string,
    oneway sc_dt_global.string,
    "parking:condition:left" sc_dt_global.string,
    "parking:condition:right" sc_dt_global.string,
    "parking:lane:left" sc_dt_global.string,
    "parking:lane:right" sc_dt_global.string,
    "parking:lanes" sc_dt_global.string,
    "parking:lanes:left" sc_dt_global.string,
    "parking:lanes:right" sc_dt_global.string,
    "parking:left" sc_dt_global.string,
    "parking:right" sc_dt_global.string,
    road_marking sc_dt_global.string,
    "road_marking:center" sc_dt_global.string,
    central_line sc_dt_global.string,
    central_reservation sc_dt_global.string,
    centreline sc_dt_global.string,
    divider sc_dt_global.string,
    "road_marking:center:color" sc_dt_global.string,
    "centreline:color" sc_dt_global.string,
    "road_marking:center:material" sc_dt_global.string,
    "divider:material" sc_dt_global.string,
    "road_marking:color" sc_dt_global.string,
    "road_marking:colour" sc_dt_global.string,
    "road_marking:curb" sc_dt_global.string,
    barrier sc_dt_global.string,
    "barrier:type" sc_dt_global.string,
    sloped_curb sc_dt_global.string,
    "road_marking:lanes" sc_dt_global.string,
    "road_marking:lanes:color" sc_dt_global.string,
    "road_marking:lanes:material" sc_dt_global.string,
    surface sc_dt_global.string
);


--
-- Name: OSMWayLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMWayLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMWayLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMWayLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMWayLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: OSMWaySettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMWaySettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMWaySettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMWaySettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMWaySettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: OSMWayStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."OSMWayStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: OSMWayStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."OSMWayStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."OSMWayStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: TrajDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."TrajDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: TrajData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."TrajData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."TrajDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    "gpsFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    "GPS Week" sc_dt_global."int",
    "GPS TOW [s]" sc_dt_global.double,
    "Pos Mode" sc_dt_global."int",
    "INS Mode" sc_dt_global."int",
    "Hdg Mode" sc_dt_global.string,
    "SVs Tracked" sc_dt_global.string,
    "SVs Used" sc_dt_global."int",
    "UTC Date" sc_dt_global.string,
    "UTC Time" sc_dt_global.string,
    "Lat [deg]" sc_dt_global.double,
    "Lon [deg]" sc_dt_global.double,
    "Alt Ellips [m]" sc_dt_global.double,
    "SOG [m/s]" sc_dt_global.double,
    "COG [deg]" sc_dt_global.double,
    "Hdg [deg]" sc_dt_global.double,
    "Vert Vel [m/s]" sc_dt_global.double,
    "Roll [deg]" sc_dt_global.double,
    "Pitch [deg]" sc_dt_global.double,
    "Yaw [deg]" sc_dt_global.double,
    "PDOP" sc_dt_global.double,
    "HDOP" sc_dt_global.double,
    "EHPE [m]" sc_dt_global.double,
    "EVPE [m]" sc_dt_global.double,
    "Baseline 2D [m]" sc_dt_global.double,
    "Baseline 3D [m]" sc_dt_global.double,
    "Corr. Age [s]" sc_dt_global.double,
    "Delta TOW [ms]" sc_dt_global.double,
    "2D Delta Pos [m]" sc_dt_global.double,
    "3D Delta Pos [m]" sc_dt_global.double
);


--
-- Name: TrajLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."TrajLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: TrajLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."TrajLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."TrajLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: TrajSeqCellsDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."TrajSeqCellsDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: TrajSeqCellsData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."TrajSeqCellsData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."TrajSeqCellsDataIdSeq"'::regclass) NOT NULL,
    "gpsFilePath" sc_dt_global.string,
    "gpsFileId" sc_dt_global."integer",
    geom4326 public.geometry,
    box4326 public.box2d,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime,
    "startId" sc_dt_global."integer",
    "endId" sc_dt_global."integer"
);


--
-- Name: TrajSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."TrajSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: TrajSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."TrajSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."TrajSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: TrajStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."TrajStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: TrajStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."TrajStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."TrajStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: XODRDataIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."XODRDataIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: XODRData; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."XODRData" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."XODRDataIdSeq"'::regclass) NOT NULL,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    content sc_dt_od_core."OpenDRIVE",
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: XODRHistIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."XODRHistIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: XODRHist; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."XODRHist" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."XODRHistIdSeq"'::regclass) NOT NULL,
    "cellRow" sc_dt_global."integer",
    "cellCol" sc_dt_global."integer",
    content sc_dt_od_core."OpenDRIVE",
    geom4326 public.geometry,
    box4326 public.box2d,
    "createdDateTime" sc_dt_global.datetime,
    "updatedDateTime" sc_dt_global.datetime
);


--
-- Name: XODRLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."XODRLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: XODRLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."XODRLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."XODRLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: XODRSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."XODRSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: XODRSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."XODRSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."XODRSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: XODRStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."XODRStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: XODRStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."XODRStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."XODRStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: _GlobalLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_GlobalLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _GlobalLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_GlobalLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_GlobalLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: _GlobalSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_GlobalSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _GlobalSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_GlobalSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_GlobalSettingsIdSeq"'::regclass) NOT NULL,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: _GlobalStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_GlobalStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _GlobalStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_GlobalStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_GlobalStatusIdSeq"'::regclass) NOT NULL,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: _UserLogsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_UserLogsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _UserLogs; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_UserLogs" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_UserLogsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "loggedDateTime" sc_dt_global.datetime,
    "threadId" sc_dt_global.string,
    "loggerId" sc_dt_global.string,
    content sc_dt_global.string,
    "fullMessage" sc_dt_global.string
);


--
-- Name: _UserSettingsIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_UserSettingsIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _UserSettings; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_UserSettings" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_UserSettingsIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "settingKey" sc_dt_global.string,
    "settingValue" sc_dt_global.string
);


--
-- Name: _UserStatusIdSeq; Type: SEQUENCE; Schema: sc_ods; Owner: -
--

CREATE SEQUENCE sc_ods."_UserStatusIdSeq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
-- Name: _UserStatus; Type: TABLE; Schema: sc_ods; Owner: -
--

CREATE TABLE sc_ods."_UserStatus" (
    id sc_dt_global."integer" DEFAULT nextval('sc_ods."_UserStatusIdSeq"'::regclass) NOT NULL,
    "appUser" sc_dt_global.string,
    "stateKey" sc_dt_global.string,
    "stateValue" sc_dt_global.string
);


--
-- Name: viewGeoJSONApplyingData; Type: VIEW; Schema: sc_ods; Owner: -
--

CREATE VIEW sc_ods."viewGeoJSONApplyingData" AS
 SELECT "GeoJSONApplyingData".tag,
    "GeoJSONApplyingData".json,
    "GeoJSONApplyingData".operation,
    to_json("GeoJSONApplyingData"."contentBefore") AS "contentBefore",
    to_json("GeoJSONApplyingData"."contentAfter") AS "contentAfter"
   FROM sc_ods."GeoJSONApplyingData"
  ORDER BY "GeoJSONApplyingData".id;


--
-- Data for Name: GPSCellsData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSCellsData" (id, geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: GPSFileData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSFileData" (id, "gpsFilePath", geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: GPSLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: GPSNativeData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSNativeData" (id, "gpsFilePath", "gpsFileId", geom4326, box4326, "createdDateTime", "updatedDateTime", "GPS Week", "GPS TOW [s]", "Pos Mode", "INS Mode", "Hdg Mode", "SVs Tracked", "SVs Used", "UTC Date", "UTC Time", "Lat [deg]", "Lon [deg]", "Alt Ellips [m]", "SOG [m/s]", "COG [deg]", "Hdg [deg]", "Vert Vel [m/s]", "Roll [deg]", "Pitch [deg]", "Yaw [deg]", "PDOP", "HDOP", "EHPE [m]", "EVPE [m]", "Baseline 2D [m]", "Baseline 3D [m]", "Corr. Age [s]", "Delta TOW [ms]", "2D Delta Pos [m]", "3D Delta Pos [m]") FROM stdin;
\.


--
-- Data for Name: GPSSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: GPSStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: GPSValidData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSValidData" (id, "gpsFilePath", "gpsFileId", geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", "GPS Week", "GPS TOW [s]", "Pos Mode", "INS Mode", "Hdg Mode", "SVs Tracked", "SVs Used", "UTC Date", "UTC Time", "Lat [deg]", "Lon [deg]", "Alt Ellips [m]", "SOG [m/s]", "COG [deg]", "Hdg [deg]", "Vert Vel [m/s]", "Roll [deg]", "Pitch [deg]", "Yaw [deg]", "PDOP", "HDOP", "EHPE [m]", "EVPE [m]", "Baseline 2D [m]", "Baseline 3D [m]", "Corr. Age [s]", "Delta TOW [ms]", "2D Delta Pos [m]", "3D Delta Pos [m]") FROM stdin;
\.


--
-- Data for Name: GPSValidSeqCellsData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GPSValidSeqCellsData" (id, "gpsFilePath", "gpsFileId", geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", "startId", "endId") FROM stdin;
\.


--
-- Data for Name: GeoJSONApplyingData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONApplyingData" (id, "geoJSONStagingNativeDataId", "geoJSONStagingFilePath", "geoJSONStagingFileId", geom4326, box4326, "createdDateTime", "updatedDateTime", tag, json, operation, "xodrHistIdBefore", "contentBefore", "xodrHistIdAfter", "contentAfter") FROM stdin;
\.


--
-- Data for Name: GeoJSONApplyingLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONApplyingLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: GeoJSONApplyingSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONApplyingSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: GeoJSONApplyingStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONApplyingStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: GeoJSONStagingFileData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONStagingFileData" (id, "geoJSONStagingFilePath", geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: GeoJSONStagingLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONStagingLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: GeoJSONStagingNativeData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONStagingNativeData" (id, "geoJSONStagingFilePath", "geoJSONStagingFileId", geom4326, box4326, "createdDateTime", "updatedDateTime", tag, json) FROM stdin;
\.


--
-- Data for Name: GeoJSONStagingSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONStagingSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: GeoJSONStagingStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."GeoJSONStagingStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: OSMCntryAreaData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMCntryAreaData" (id, iso3166_1, json, geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: OSMCntryAreaHist; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMCntryAreaHist" (id, iso3166_1, json, geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: OSMCntryAreaLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMCntryAreaLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: OSMCntryAreaSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMCntryAreaSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: OSMCntryAreaStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMCntryAreaStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: OSMNodeData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMNodeData" (id, "osmId", json, geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", abandoned, "abandoned:amenity", "abandoned:building", "abandoned:car", "abandoned:crossing", "abandoned:highway", "abandoned:highway:traffic_signals", "abandoned:natural", "abandoned:natural:tree", "abandoned:parking", "abandoned:pole", "abandoned:railway", "abandoned:railway:traffic_signals", "abandoned:traffic_sign", "abandoned:tree", accomodation, "addr:building", "addr:housename", amenity, amenity_1, amenity_2, area, "area:building", "area:highway", "area:traffic_calming", barrier, "barrier:tree", "barrier:type", bicycle, "bicycle:parking", "bicycle_parking:position", "bicycle:traffic_signals", "blazed:natural", bollard, "bollard:traffic_sign", broken, "broken:traffic_sign", building, calming, "camera:mount", construction, "construction:amenity", "construction:building", "construction:crossing", "construction:crossing:island", "construction:demolished:highway", "construction:demolished:highway:traffic_signals", "construction:highway", "construction:highway:traffic_sign", "construction:highway:traffic_signal", "construction:highway:traffic_signals", "construction:junction", "construction:parking", "construction:road_marking", "construction:traffic_signals", crane, "crane:type", crossing, crossing_1, crossing_2, "crossing:island", "crossing:road_marking", crosswalk, cycleway, "cycleway:left", "cycleway:left:traffic_sign", "cycleway:left:traffic_signals", "cycleway:right", "cycleway:right:traffic_sign", "cycleway:right:traffic_signals", "cycleway:traffic_sign", "cycleway:traffic_signals", "dead:natural", demolished, "demolished:amenity", "demolished:building", "demolished:crossing", "demolished:highway", "demolished:highway:traffic_signals", "demolished:junction", "demolished:natural", "demolished:parking", "demolished:traffic_sign", destroyed, "destroyed:building", "destroyed:natural", "destroyed:traffic_sign", device, "device:traffic_signals", disabled, "disabled:highway", "disabled:highway:traffic_signals", "disabled:traffic_sign", disused, "disused:building", "disused:crossing", "disused:highway", "disused:highway:traffic_signals", "disused:parking", "disused:playground", "disused:playground:roundabout", "disused:traffic_sign", "disused:traffic_signals", enforcement, fence, "fence:pole", fence_type, "fence:type", footway, forest, gantry, "gantry:type", "gone:natural", handrail, highway, highway_1, "highway_1:traffic_signals", highway_2, "highway_2:traffic_signals", "highway:backward", "highway:backward:traffic_signals", "highway:backwards", "highway:backwards:traffic_signals", "highway:bicycle", "highway:bicycle:traffic_signals", "highway:construction", "highway:construction:traffic_signals", "highway:disused", "highway:disused:traffic_signals", "highway:forward", "highway:forward:traffic_signals", "highway:historic", "highway:historic:traffic_signals", "highway:street_lamp", "highway:traffic_signals", historic, historic_1, "historic_1:building", "historic:building", "historic:crossing", "historic:highway", "historic:highway:traffic_signals", historical, "historical:building", house, industrial, intersection, "intersection:traffic_signals", junction, "junction:separate", "junction:separate:traffic_signals", "junction:traffic_signals", "kerb:road_marking", lamp_type, "lamp:type", landuse, level_crossing, light, "light:type", lit, location, "location:traffic_sign", man_made, "man_made:separate", "man_made:separate:traffic_sign", mini_roundabout, miniroundabout, motorcycle, "motorcycle:parking", name, "name:building", natura, "natural", natural_1, "natural_1:tree", "natural:tree", obstacle, "obstacle:traffic_sign", old_amenity, "old:amenity", old_natural, "old:natural", park, parking, parking_1, parking_position, parking_slots, parking_space, parking_zone, plant, playground, "playground:roundabout", pole, public_transport, railing, railway, razed, "razed:amenity", "razed:building", "razed:crossing", "razed:crossing:island", "razed:highway", "razed:highway:traffic_signals", "razed:natural", "razed:natural:tree", "razed:playground", "razed:pole", "razed:traffic_sign", "razed:traffic_signals", "razed:tree", ref, "ref:pole", residential, road, road_mark, road_marking, "road:traffic_signals", "roadMark", roundabout, ruined, "ruined:building", ruins, "ruins:building", "ruins:car", "ruins:tree", seamark, "seamark:building", "seasonal:winter", "seasonal:winter:traffic_sign", "service:vehicle:parking", services, sidewalk, "sidewalk:left", "sidewalk:left:traffic_sign", "sidewalk:right", "sidewalk:right:traffic_sign", "sidewalk:traffic_sign", site, street_cabinet, "street_cabinet:traffic_sign", "street_cabinet:traffic_signal", "street_cabinet:traffic_signals", street_furniture, street_lamp, street_light, "streetLamp", "streetlamp:ref", streetlight, structure, "temporarily:gone", "temporarily:gone:traffic_sign", temporarily_removed, "temporarily_removed:traffic_sign", temporary, "temporary:building", traffic_calming, traffic_control, "traffic_control:traffic_signals", traffic_island, traffic_lights, traffic_sign, traffic_sign_1, traffic_signal, traffic_signals, traffic_signals_1, training, transport, "transport:traffic_signals", transportation, tree, trees, type, "type:pole", use, user_defined, user_defined_other, vegetation, waterway, "waterway:traffic_sign", zone, "zone:parking") FROM stdin;
\.


--
-- Data for Name: OSMNodeHist; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMNodeHist" (id, "osmId", json, geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", abandoned, "abandoned:amenity", "abandoned:building", "abandoned:car", "abandoned:crossing", "abandoned:highway", "abandoned:highway:traffic_signals", "abandoned:natural", "abandoned:natural:tree", "abandoned:parking", "abandoned:pole", "abandoned:railway", "abandoned:railway:traffic_signals", "abandoned:traffic_sign", "abandoned:tree", accomodation, "addr:building", "addr:housename", amenity, amenity_1, amenity_2, area, "area:building", "area:highway", "area:traffic_calming", barrier, "barrier:tree", "barrier:type", bicycle, "bicycle:parking", "bicycle_parking:position", "bicycle:traffic_signals", "blazed:natural", bollard, "bollard:traffic_sign", broken, "broken:traffic_sign", building, calming, "camera:mount", construction, "construction:amenity", "construction:building", "construction:crossing", "construction:crossing:island", "construction:demolished:highway", "construction:demolished:highway:traffic_signals", "construction:highway", "construction:highway:traffic_sign", "construction:highway:traffic_signal", "construction:highway:traffic_signals", "construction:junction", "construction:parking", "construction:road_marking", "construction:traffic_signals", crane, "crane:type", crossing, crossing_1, crossing_2, "crossing:island", "crossing:road_marking", crosswalk, cycleway, "cycleway:left", "cycleway:left:traffic_sign", "cycleway:left:traffic_signals", "cycleway:right", "cycleway:right:traffic_sign", "cycleway:right:traffic_signals", "cycleway:traffic_sign", "cycleway:traffic_signals", "dead:natural", demolished, "demolished:amenity", "demolished:building", "demolished:crossing", "demolished:highway", "demolished:highway:traffic_signals", "demolished:junction", "demolished:natural", "demolished:parking", "demolished:traffic_sign", destroyed, "destroyed:building", "destroyed:natural", "destroyed:traffic_sign", device, "device:traffic_signals", disabled, "disabled:highway", "disabled:highway:traffic_signals", "disabled:traffic_sign", disused, "disused:building", "disused:crossing", "disused:highway", "disused:highway:traffic_signals", "disused:parking", "disused:playground", "disused:playground:roundabout", "disused:traffic_sign", "disused:traffic_signals", enforcement, fence, "fence:pole", fence_type, "fence:type", footway, forest, gantry, "gantry:type", "gone:natural", handrail, highway, highway_1, "highway_1:traffic_signals", highway_2, "highway_2:traffic_signals", "highway:backward", "highway:backward:traffic_signals", "highway:backwards", "highway:backwards:traffic_signals", "highway:bicycle", "highway:bicycle:traffic_signals", "highway:construction", "highway:construction:traffic_signals", "highway:disused", "highway:disused:traffic_signals", "highway:forward", "highway:forward:traffic_signals", "highway:historic", "highway:historic:traffic_signals", "highway:street_lamp", "highway:traffic_signals", historic, historic_1, "historic_1:building", "historic:building", "historic:crossing", "historic:highway", "historic:highway:traffic_signals", historical, "historical:building", house, industrial, intersection, "intersection:traffic_signals", junction, "junction:separate", "junction:separate:traffic_signals", "junction:traffic_signals", "kerb:road_marking", lamp_type, "lamp:type", landuse, level_crossing, light, "light:type", lit, location, "location:traffic_sign", man_made, "man_made:separate", "man_made:separate:traffic_sign", mini_roundabout, miniroundabout, motorcycle, "motorcycle:parking", name, "name:building", natura, "natural", natural_1, "natural_1:tree", "natural:tree", obstacle, "obstacle:traffic_sign", old_amenity, "old:amenity", old_natural, "old:natural", park, parking, parking_1, parking_position, parking_slots, parking_space, parking_zone, plant, playground, "playground:roundabout", pole, public_transport, railing, railway, razed, "razed:amenity", "razed:building", "razed:crossing", "razed:crossing:island", "razed:highway", "razed:highway:traffic_signals", "razed:natural", "razed:natural:tree", "razed:playground", "razed:pole", "razed:traffic_sign", "razed:traffic_signals", "razed:tree", ref, "ref:pole", residential, road, road_mark, road_marking, "road:traffic_signals", "roadMark", roundabout, ruined, "ruined:building", ruins, "ruins:building", "ruins:car", "ruins:tree", seamark, "seamark:building", "seasonal:winter", "seasonal:winter:traffic_sign", "service:vehicle:parking", services, sidewalk, "sidewalk:left", "sidewalk:left:traffic_sign", "sidewalk:right", "sidewalk:right:traffic_sign", "sidewalk:traffic_sign", site, street_cabinet, "street_cabinet:traffic_sign", "street_cabinet:traffic_signal", "street_cabinet:traffic_signals", street_furniture, street_lamp, street_light, "streetLamp", "streetlamp:ref", streetlight, structure, "temporarily:gone", "temporarily:gone:traffic_sign", temporarily_removed, "temporarily_removed:traffic_sign", temporary, "temporary:building", traffic_calming, traffic_control, "traffic_control:traffic_signals", traffic_island, traffic_lights, traffic_sign, traffic_sign_1, traffic_signal, traffic_signals, traffic_signals_1, training, transport, "transport:traffic_signals", transportation, tree, trees, type, "type:pole", use, user_defined, user_defined_other, vegetation, waterway, "waterway:traffic_sign", zone, "zone:parking") FROM stdin;
\.


--
-- Data for Name: OSMNodeLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMNodeLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: OSMNodeSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMNodeSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: OSMNodeStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMNodeStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: OSMWayData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMWayData" (id, "osmId", json, geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", access, "access:lanes", "access:lanes:backward", "access:lanes:forward", "addr:country", bidirectional, "car_pooling:lanes", "driving_direction:lanes", driving_side, "driving_side:lanes", elevation, elevation_from_road, "elevation:lanes", highway, junction, lanes, "lanes:backward", "lanes:bidirectional", "lanes:direction", "lanes:forward", "lanes:left", "lanes:right", "lane:width", "lanes:width", "width:lanes", maxspeed, "maxspeed:lanes", name, oneway, "parking:condition:left", "parking:condition:right", "parking:lane:left", "parking:lane:right", "parking:lanes", "parking:lanes:left", "parking:lanes:right", "parking:left", "parking:right", road_marking, "road_marking:center", central_line, central_reservation, centreline, divider, "road_marking:center:color", "centreline:color", "road_marking:center:material", "divider:material", "road_marking:color", "road_marking:colour", "road_marking:curb", barrier, "barrier:type", sloped_curb, "road_marking:lanes", "road_marking:lanes:color", "road_marking:lanes:material", surface) FROM stdin;
\.


--
-- Data for Name: OSMWayHist; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMWayHist" (id, "osmId", json, geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", access, "access:lanes", "access:lanes:backward", "access:lanes:forward", "addr:country", bidirectional, "car_pooling:lanes", "driving_direction:lanes", driving_side, "driving_side:lanes", elevation, elevation_from_road, "elevation:lanes", highway, junction, lanes, "lanes:backward", "lanes:bidirectional", "lanes:direction", "lanes:forward", "lanes:left", "lanes:right", "lane:width", "lanes:width", "width:lanes", maxspeed, "maxspeed:lanes", name, oneway, "parking:condition:left", "parking:condition:right", "parking:lane:left", "parking:lane:right", "parking:lanes", "parking:lanes:left", "parking:lanes:right", "parking:left", "parking:right", road_marking, "road_marking:center", central_line, central_reservation, centreline, divider, "road_marking:center:color", "centreline:color", "road_marking:center:material", "divider:material", "road_marking:color", "road_marking:colour", "road_marking:curb", barrier, "barrier:type", sloped_curb, "road_marking:lanes", "road_marking:lanes:color", "road_marking:lanes:material", surface) FROM stdin;
\.


--
-- Data for Name: OSMWayLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMWayLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: OSMWaySettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMWaySettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: OSMWayStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."OSMWayStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: TrajData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."TrajData" (id, "gpsFilePath", "gpsFileId", geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", "GPS Week", "GPS TOW [s]", "Pos Mode", "INS Mode", "Hdg Mode", "SVs Tracked", "SVs Used", "UTC Date", "UTC Time", "Lat [deg]", "Lon [deg]", "Alt Ellips [m]", "SOG [m/s]", "COG [deg]", "Hdg [deg]", "Vert Vel [m/s]", "Roll [deg]", "Pitch [deg]", "Yaw [deg]", "PDOP", "HDOP", "EHPE [m]", "EVPE [m]", "Baseline 2D [m]", "Baseline 3D [m]", "Corr. Age [s]", "Delta TOW [ms]", "2D Delta Pos [m]", "3D Delta Pos [m]") FROM stdin;
\.


--
-- Data for Name: TrajLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."TrajLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: TrajSeqCellsData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."TrajSeqCellsData" (id, "gpsFilePath", "gpsFileId", geom4326, box4326, "cellRow", "cellCol", "createdDateTime", "updatedDateTime", "startId", "endId") FROM stdin;
\.


--
-- Data for Name: TrajSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."TrajSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: TrajStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."TrajStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: XODRData; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."XODRData" (id, "cellRow", "cellCol", content, geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: XODRHist; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."XODRHist" (id, "cellRow", "cellCol", content, geom4326, box4326, "createdDateTime", "updatedDateTime") FROM stdin;
\.


--
-- Data for Name: XODRLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."XODRLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: XODRSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."XODRSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: XODRStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."XODRStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: _GlobalLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_GlobalLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: _GlobalSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_GlobalSettings" (id, "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: _GlobalStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_GlobalStatus" (id, "stateKey", "stateValue") FROM stdin;
\.


--
-- Data for Name: _UserLogs; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_UserLogs" (id, "appUser", "loggedDateTime", "threadId", "loggerId", content, "fullMessage") FROM stdin;
\.


--
-- Data for Name: _UserSettings; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_UserSettings" (id, "appUser", "settingKey", "settingValue") FROM stdin;
\.


--
-- Data for Name: _UserStatus; Type: TABLE DATA; Schema: sc_ods; Owner: -
--

COPY sc_ods."_UserStatus" (id, "appUser", "stateKey", "stateValue") FROM stdin;
\.


--
-- Name: GPSCellsDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSCellsDataIdSeq"', 1, false);


--
-- Name: GPSFileDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSFileDataIdSeq"', 1, false);


--
-- Name: GPSLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSLogsIdSeq"', 1, false);


--
-- Name: GPSNativeDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSNativeDataIdSeq"', 1, false);


--
-- Name: GPSSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSSettingsIdSeq"', 1, false);


--
-- Name: GPSStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSStatusIdSeq"', 1, false);


--
-- Name: GPSValidDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSValidDataIdSeq"', 1, false);


--
-- Name: GPSValidSeqCellsDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GPSValidSeqCellsDataIdSeq"', 1, false);


--
-- Name: GeoJSONApplyingDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONApplyingDataIdSeq"', 1, false);


--
-- Name: GeoJSONApplyingLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONApplyingLogsIdSeq"', 1, false);


--
-- Name: GeoJSONApplyingSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONApplyingSettingsIdSeq"', 1, false);


--
-- Name: GeoJSONApplyingStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONApplyingStatusIdSeq"', 1, false);


--
-- Name: GeoJSONStagingFileDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONStagingFileDataIdSeq"', 1, false);


--
-- Name: GeoJSONStagingLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONStagingLogsIdSeq"', 1, false);


--
-- Name: GeoJSONStagingNativeDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONStagingNativeDataIdSeq"', 1, false);


--
-- Name: GeoJSONStagingSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONStagingSettingsIdSeq"', 1, false);


--
-- Name: GeoJSONStagingStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."GeoJSONStagingStatusIdSeq"', 1, false);


--
-- Name: OSMCntryAreaDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMCntryAreaDataIdSeq"', 1, false);


--
-- Name: OSMCntryAreaHistIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMCntryAreaHistIdSeq"', 1, false);


--
-- Name: OSMCntryAreaLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMCntryAreaLogsIdSeq"', 1, false);


--
-- Name: OSMCntryAreaSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMCntryAreaSettingsIdSeq"', 1, false);


--
-- Name: OSMCntryAreaStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMCntryAreaStatusIdSeq"', 1, false);


--
-- Name: OSMNodeDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMNodeDataIdSeq"', 1, false);


--
-- Name: OSMNodeHistIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMNodeHistIdSeq"', 1, false);


--
-- Name: OSMNodeLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMNodeLogsIdSeq"', 1, false);


--
-- Name: OSMNodeSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMNodeSettingsIdSeq"', 1, false);


--
-- Name: OSMNodeStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMNodeStatusIdSeq"', 1, false);


--
-- Name: OSMWayDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMWayDataIdSeq"', 1, false);


--
-- Name: OSMWayHistIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMWayHistIdSeq"', 1, false);


--
-- Name: OSMWayLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMWayLogsIdSeq"', 1, false);


--
-- Name: OSMWaySettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMWaySettingsIdSeq"', 1, false);


--
-- Name: OSMWayStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."OSMWayStatusIdSeq"', 1, false);


--
-- Name: TrajDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."TrajDataIdSeq"', 1, false);


--
-- Name: TrajLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."TrajLogsIdSeq"', 1, false);


--
-- Name: TrajSeqCellsDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."TrajSeqCellsDataIdSeq"', 1, false);


--
-- Name: TrajSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."TrajSettingsIdSeq"', 1, false);


--
-- Name: TrajStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."TrajStatusIdSeq"', 1, false);


--
-- Name: XODRDataIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."XODRDataIdSeq"', 1, false);


--
-- Name: XODRHistIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."XODRHistIdSeq"', 1, false);


--
-- Name: XODRLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."XODRLogsIdSeq"', 1, false);


--
-- Name: XODRSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."XODRSettingsIdSeq"', 1, false);


--
-- Name: XODRStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."XODRStatusIdSeq"', 1, false);


--
-- Name: _GlobalLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_GlobalLogsIdSeq"', 1, false);


--
-- Name: _GlobalSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_GlobalSettingsIdSeq"', 1, false);


--
-- Name: _GlobalStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_GlobalStatusIdSeq"', 1, false);


--
-- Name: _UserLogsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_UserLogsIdSeq"', 1, false);


--
-- Name: _UserSettingsIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_UserSettingsIdSeq"', 1, false);


--
-- Name: _UserStatusIdSeq; Type: SEQUENCE SET; Schema: sc_ods; Owner: -
--

SELECT pg_catalog.setval('sc_ods."_UserStatusIdSeq"', 1, false);


--
-- Name: GPSCellsData GPSCellsDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSCellsData"
    ADD CONSTRAINT "GPSCellsDataPKey" PRIMARY KEY (id);


--
-- Name: GPSCellsData GPSCellsDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSCellsData"
    ADD CONSTRAINT "GPSCellsDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GPSCellsData GPSCellsDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSCellsData"
    ADD CONSTRAINT "GPSCellsDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GPSFileData GPSFileDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSFileData"
    ADD CONSTRAINT "GPSFileDataPKey" PRIMARY KEY (id);


--
-- Name: GPSFileData GPSFileDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSFileData"
    ADD CONSTRAINT "GPSFileDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GPSFileData GPSFileDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSFileData"
    ADD CONSTRAINT "GPSFileDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GPSLogs GPSLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSLogs"
    ADD CONSTRAINT "GPSLogsPKey" PRIMARY KEY (id);


--
-- Name: GPSNativeData GPSNativeDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSNativeData"
    ADD CONSTRAINT "GPSNativeDataPKey" PRIMARY KEY (id);


--
-- Name: GPSNativeData GPSNativeDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSNativeData"
    ADD CONSTRAINT "GPSNativeDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GPSNativeData GPSNativeDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSNativeData"
    ADD CONSTRAINT "GPSNativeDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GPSSettings GPSSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSSettings"
    ADD CONSTRAINT "GPSSettingsPKey" PRIMARY KEY (id);


--
-- Name: GPSSettings GPSSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSSettings"
    ADD CONSTRAINT "GPSSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: GPSStatus GPSStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSStatus"
    ADD CONSTRAINT "GPSStatusPKey" PRIMARY KEY (id);


--
-- Name: GPSStatus GPSStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSStatus"
    ADD CONSTRAINT "GPSStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: GPSValidData GPSValidDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidData"
    ADD CONSTRAINT "GPSValidDataPKey" PRIMARY KEY (id);


--
-- Name: GPSValidData GPSValidDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidData"
    ADD CONSTRAINT "GPSValidDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GPSValidData GPSValidDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidData"
    ADD CONSTRAINT "GPSValidDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidSeqCellsData"
    ADD CONSTRAINT "GPSValidSeqCellsDataPKey" PRIMARY KEY (id);


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidSeqCellsData"
    ADD CONSTRAINT "GPSValidSeqCellsDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GPSValidSeqCellsData"
    ADD CONSTRAINT "GPSValidSeqCellsDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GeoJSONApplyingData GeoJSONApplyingDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingData"
    ADD CONSTRAINT "GeoJSONApplyingDataPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONApplyingData GeoJSONApplyingDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingData"
    ADD CONSTRAINT "GeoJSONApplyingDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GeoJSONApplyingData GeoJSONApplyingDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingData"
    ADD CONSTRAINT "GeoJSONApplyingDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GeoJSONApplyingLogs GeoJSONApplyingLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingLogs"
    ADD CONSTRAINT "GeoJSONApplyingLogsPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONApplyingSettings GeoJSONApplyingSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingSettings"
    ADD CONSTRAINT "GeoJSONApplyingSettingsPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONApplyingSettings GeoJSONApplyingSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingSettings"
    ADD CONSTRAINT "GeoJSONApplyingSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: GeoJSONApplyingStatus GeoJSONApplyingStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingStatus"
    ADD CONSTRAINT "GeoJSONApplyingStatusPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONApplyingStatus GeoJSONApplyingStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONApplyingStatus"
    ADD CONSTRAINT "GeoJSONApplyingStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: GeoJSONStagingFileData GeoJSONStagingFileDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingFileData"
    ADD CONSTRAINT "GeoJSONStagingFileDataPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONStagingFileData GeoJSONStagingFileDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingFileData"
    ADD CONSTRAINT "GeoJSONStagingFileDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GeoJSONStagingFileData GeoJSONStagingFileDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingFileData"
    ADD CONSTRAINT "GeoJSONStagingFileDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GeoJSONStagingLogs GeoJSONStagingLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingLogs"
    ADD CONSTRAINT "GeoJSONStagingLogsPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingNativeData"
    ADD CONSTRAINT "GeoJSONStagingNativeDataPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingNativeData"
    ADD CONSTRAINT "GeoJSONStagingNativeDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingNativeData"
    ADD CONSTRAINT "GeoJSONStagingNativeDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: GeoJSONStagingSettings GeoJSONStagingSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingSettings"
    ADD CONSTRAINT "GeoJSONStagingSettingsPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONStagingSettings GeoJSONStagingSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingSettings"
    ADD CONSTRAINT "GeoJSONStagingSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: GeoJSONStagingStatus GeoJSONStagingStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingStatus"
    ADD CONSTRAINT "GeoJSONStagingStatusPKey" PRIMARY KEY (id);


--
-- Name: GeoJSONStagingStatus GeoJSONStagingStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."GeoJSONStagingStatus"
    ADD CONSTRAINT "GeoJSONStagingStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: OSMCntryAreaData OSMCntryAreaDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaData"
    ADD CONSTRAINT "OSMCntryAreaDataPKey" PRIMARY KEY (id);


--
-- Name: OSMCntryAreaData OSMCntryAreaDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaData"
    ADD CONSTRAINT "OSMCntryAreaDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMCntryAreaData OSMCntryAreaDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaData"
    ADD CONSTRAINT "OSMCntryAreaDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMCntryAreaData OSMCntryAreaDataUniqueiso3166_1; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaData"
    ADD CONSTRAINT "OSMCntryAreaDataUniqueiso3166_1" UNIQUE (iso3166_1);


--
-- Name: OSMCntryAreaHist OSMCntryAreaHistPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaHist"
    ADD CONSTRAINT "OSMCntryAreaHistPKey" PRIMARY KEY (id);


--
-- Name: OSMCntryAreaHist OSMCntryAreaHistUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaHist"
    ADD CONSTRAINT "OSMCntryAreaHistUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMCntryAreaHist OSMCntryAreaHistUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaHist"
    ADD CONSTRAINT "OSMCntryAreaHistUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMCntryAreaLogs OSMCntryAreaLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaLogs"
    ADD CONSTRAINT "OSMCntryAreaLogsPKey" PRIMARY KEY (id);


--
-- Name: OSMCntryAreaSettings OSMCntryAreaSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaSettings"
    ADD CONSTRAINT "OSMCntryAreaSettingsPKey" PRIMARY KEY (id);


--
-- Name: OSMCntryAreaSettings OSMCntryAreaSettingsUniqueAppUserSettingKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaSettings"
    ADD CONSTRAINT "OSMCntryAreaSettingsUniqueAppUserSettingKey" UNIQUE ("appUser", "settingKey");


--
-- Name: OSMCntryAreaStatus OSMCntryAreaStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaStatus"
    ADD CONSTRAINT "OSMCntryAreaStatusPKey" PRIMARY KEY (id);


--
-- Name: OSMCntryAreaStatus OSMCntryAreaStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMCntryAreaStatus"
    ADD CONSTRAINT "OSMCntryAreaStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: OSMNodeData OSMNodeDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeData"
    ADD CONSTRAINT "OSMNodeDataPKey" PRIMARY KEY (id);


--
-- Name: OSMNodeData OSMNodeDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeData"
    ADD CONSTRAINT "OSMNodeDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMNodeData OSMNodeDataUniqueOSMId; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeData"
    ADD CONSTRAINT "OSMNodeDataUniqueOSMId" UNIQUE ("osmId");


--
-- Name: OSMNodeData OSMNodeDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeData"
    ADD CONSTRAINT "OSMNodeDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMNodeHist OSMNodeHistPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeHist"
    ADD CONSTRAINT "OSMNodeHistPKey" PRIMARY KEY (id);


--
-- Name: OSMNodeHist OSMNodeHistUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeHist"
    ADD CONSTRAINT "OSMNodeHistUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMNodeHist OSMNodeHistUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeHist"
    ADD CONSTRAINT "OSMNodeHistUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMNodeLogs OSMNodeLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeLogs"
    ADD CONSTRAINT "OSMNodeLogsPKey" PRIMARY KEY (id);


--
-- Name: OSMNodeSettings OSMNodeSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeSettings"
    ADD CONSTRAINT "OSMNodeSettingsPKey" PRIMARY KEY (id);


--
-- Name: OSMNodeSettings OSMNodeSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeSettings"
    ADD CONSTRAINT "OSMNodeSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: OSMNodeStatus OSMNodeStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeStatus"
    ADD CONSTRAINT "OSMNodeStatusPKey" PRIMARY KEY (id);


--
-- Name: OSMNodeStatus OSMNodeStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMNodeStatus"
    ADD CONSTRAINT "OSMNodeStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: OSMWayData OSMWayDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayData"
    ADD CONSTRAINT "OSMWayDataPKey" PRIMARY KEY (id);


--
-- Name: OSMWayData OSMWayDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayData"
    ADD CONSTRAINT "OSMWayDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMWayData OSMWayDataUniqueOSMId; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayData"
    ADD CONSTRAINT "OSMWayDataUniqueOSMId" UNIQUE ("osmId");


--
-- Name: OSMWayData OSMWayDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayData"
    ADD CONSTRAINT "OSMWayDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMWayHist OSMWayHistPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayHist"
    ADD CONSTRAINT "OSMWayHistPKey" PRIMARY KEY (id);


--
-- Name: OSMWayHist OSMWayHistUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayHist"
    ADD CONSTRAINT "OSMWayHistUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: OSMWayHist OSMWayHistUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayHist"
    ADD CONSTRAINT "OSMWayHistUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: OSMWayLogs OSMWayLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayLogs"
    ADD CONSTRAINT "OSMWayLogsPKey" PRIMARY KEY (id);


--
-- Name: OSMWaySettings OSMWaySettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWaySettings"
    ADD CONSTRAINT "OSMWaySettingsPKey" PRIMARY KEY (id);


--
-- Name: OSMWaySettings OSMWaySettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWaySettings"
    ADD CONSTRAINT "OSMWaySettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: OSMWayStatus OSMWayStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayStatus"
    ADD CONSTRAINT "OSMWayStatusPKey" PRIMARY KEY (id);


--
-- Name: OSMWayStatus OSMWayStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."OSMWayStatus"
    ADD CONSTRAINT "OSMWayStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: TrajData TrajDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajData"
    ADD CONSTRAINT "TrajDataPKey" PRIMARY KEY (id);


--
-- Name: TrajData TrajDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajData"
    ADD CONSTRAINT "TrajDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: TrajData TrajDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajData"
    ADD CONSTRAINT "TrajDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: TrajLogs TrajLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajLogs"
    ADD CONSTRAINT "TrajLogsPKey" PRIMARY KEY (id);


--
-- Name: TrajSeqCellsData TrajSeqCellsDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajSeqCellsData"
    ADD CONSTRAINT "TrajSeqCellsDataPKey" PRIMARY KEY (id);


--
-- Name: TrajSeqCellsData TrajSeqCellsDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajSeqCellsData"
    ADD CONSTRAINT "TrajSeqCellsDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: TrajSeqCellsData TrajSeqCellsDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajSeqCellsData"
    ADD CONSTRAINT "TrajSeqCellsDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: TrajSettings TrajSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajSettings"
    ADD CONSTRAINT "TrajSettingsPKey" PRIMARY KEY (id);


--
-- Name: TrajSettings TrajSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajSettings"
    ADD CONSTRAINT "TrajSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: TrajStatus TrajStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajStatus"
    ADD CONSTRAINT "TrajStatusPKey" PRIMARY KEY (id);


--
-- Name: TrajStatus TrajStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."TrajStatus"
    ADD CONSTRAINT "TrajStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: XODRData XODRDataPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRData"
    ADD CONSTRAINT "XODRDataPKey" PRIMARY KEY (id);


--
-- Name: XODRData XODRDataUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRData"
    ADD CONSTRAINT "XODRDataUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: XODRData XODRDataUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRData"
    ADD CONSTRAINT "XODRDataUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: XODRHist XODRHistPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRHist"
    ADD CONSTRAINT "XODRHistPKey" PRIMARY KEY (id);


--
-- Name: XODRHist XODRHistUniqueCreatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRHist"
    ADD CONSTRAINT "XODRHistUniqueCreatedDateTime" UNIQUE ("createdDateTime");


--
-- Name: XODRHist XODRHistUniqueUpdatedDateTime; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRHist"
    ADD CONSTRAINT "XODRHistUniqueUpdatedDateTime" UNIQUE ("updatedDateTime");


--
-- Name: XODRLogs XODRLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRLogs"
    ADD CONSTRAINT "XODRLogsPKey" PRIMARY KEY (id);


--
-- Name: XODRSettings XODRSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRSettings"
    ADD CONSTRAINT "XODRSettingsPKey" PRIMARY KEY (id);


--
-- Name: XODRSettings XODRSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRSettings"
    ADD CONSTRAINT "XODRSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: XODRStatus XODRStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRStatus"
    ADD CONSTRAINT "XODRStatusPKey" PRIMARY KEY (id);


--
-- Name: XODRStatus XODRStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."XODRStatus"
    ADD CONSTRAINT "XODRStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: _GlobalLogs _GlobalLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_GlobalLogs"
    ADD CONSTRAINT "_GlobalLogsPKey" PRIMARY KEY (id);


--
-- Name: _GlobalSettings _GlobalSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_GlobalSettings"
    ADD CONSTRAINT "_GlobalSettingsPKey" PRIMARY KEY (id);


--
-- Name: _GlobalSettings _GlobalSettingsUniqueSettingKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_GlobalSettings"
    ADD CONSTRAINT "_GlobalSettingsUniqueSettingKey" UNIQUE ("settingKey");


--
-- Name: _GlobalStatus _GlobalStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_GlobalStatus"
    ADD CONSTRAINT "_GlobalStatusPKey" PRIMARY KEY (id);


--
-- Name: _GlobalStatus _GlobalStatusUniqueStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_GlobalStatus"
    ADD CONSTRAINT "_GlobalStatusUniqueStateKey" UNIQUE ("stateKey");


--
-- Name: _UserLogs _UserLogsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_UserLogs"
    ADD CONSTRAINT "_UserLogsPKey" PRIMARY KEY (id);


--
-- Name: _UserSettings _UserSettingsPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_UserSettings"
    ADD CONSTRAINT "_UserSettingsPKey" PRIMARY KEY (id);


--
-- Name: _UserSettings _UserSettingsUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_UserSettings"
    ADD CONSTRAINT "_UserSettingsUniqueAppUserStateKey" UNIQUE ("appUser", "settingKey");


--
-- Name: _UserStatus _UserStatusPKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_UserStatus"
    ADD CONSTRAINT "_UserStatusPKey" PRIMARY KEY (id);


--
-- Name: _UserStatus _UserStatusUniqueAppUserStateKey; Type: CONSTRAINT; Schema: sc_ods; Owner: -
--

ALTER TABLE ONLY sc_ods."_UserStatus"
    ADD CONSTRAINT "_UserStatusUniqueAppUserStateKey" UNIQUE ("appUser", "stateKey");


--
-- Name: GPSCellsDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSCellsDataIndexCellRowCellCol" ON sc_ods."GPSCellsData" USING btree ("cellRow", "cellCol");


--
-- Name: GPSCellsDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSCellsDataIndexGeom4326" ON sc_ods."GPSCellsData" USING gist (geom4326);


--
-- Name: GPSFileDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSFileDataIndexGeom4326" ON sc_ods."GPSFileData" USING gist (geom4326);


--
-- Name: GPSNativeDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSNativeDataIndexGeom4326" ON sc_ods."GPSNativeData" USING gist (geom4326);


--
-- Name: GPSValidDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSValidDataIndexCellRowCellCol" ON sc_ods."GPSValidData" USING btree ("cellRow", "cellCol");


--
-- Name: GPSValidDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSValidDataIndexGeom4326" ON sc_ods."GPSValidData" USING gist (geom4326);


--
-- Name: GPSValidSeqCellsDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSValidSeqCellsDataIndexCellRowCellCol" ON sc_ods."GPSValidSeqCellsData" USING btree ("cellRow", "cellCol");


--
-- Name: GPSValidSeqCellsDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GPSValidSeqCellsDataIndexGeom4326" ON sc_ods."GPSValidSeqCellsData" USING gist (geom4326);


--
-- Name: GeoJSONApplyingDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GeoJSONApplyingDataIndexGeom4326" ON sc_ods."GeoJSONApplyingData" USING gist (geom4326);


--
-- Name: GeoJSONStagingFileDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GeoJSONStagingFileDataIndexGeom4326" ON sc_ods."GeoJSONStagingFileData" USING gist (geom4326);


--
-- Name: GeoJSONStagingNativeDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "GeoJSONStagingNativeDataIndexGeom4326" ON sc_ods."GeoJSONStagingNativeData" USING gist (geom4326);


--
-- Name: OSMCntryAreaDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMCntryAreaDataIndexGeom4326" ON sc_ods."OSMCntryAreaData" USING gist (geom4326);


--
-- Name: OSMCntryAreaHistIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMCntryAreaHistIndexGeom4326" ON sc_ods."OSMCntryAreaHist" USING gist (geom4326);


--
-- Name: OSMNodeDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMNodeDataIndexCellRowCellCol" ON sc_ods."OSMNodeData" USING btree ("cellRow", "cellCol");


--
-- Name: OSMNodeDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMNodeDataIndexGeom4326" ON sc_ods."OSMNodeData" USING gist (geom4326);


--
-- Name: OSMNodeHistIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMNodeHistIndexCellRowCellCol" ON sc_ods."OSMNodeHist" USING btree ("cellRow", "cellCol");


--
-- Name: OSMNodeHistIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMNodeHistIndexGeom4326" ON sc_ods."OSMNodeHist" USING gist (geom4326);


--
-- Name: OSMWayDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMWayDataIndexCellRowCellCol" ON sc_ods."OSMWayData" USING btree ("cellRow", "cellCol");


--
-- Name: OSMWayDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMWayDataIndexGeom4326" ON sc_ods."OSMWayData" USING gist (geom4326);


--
-- Name: OSMWayHistIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMWayHistIndexCellRowCellCol" ON sc_ods."OSMWayHist" USING btree ("cellRow", "cellCol");


--
-- Name: OSMWayHistIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "OSMWayHistIndexGeom4326" ON sc_ods."OSMWayHist" USING gist (geom4326);


--
-- Name: TrajDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "TrajDataIndexCellRowCellCol" ON sc_ods."TrajData" USING btree ("cellRow", "cellCol");


--
-- Name: TrajDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "TrajDataIndexGeom4326" ON sc_ods."TrajData" USING gist (geom4326);


--
-- Name: TrajSeqCellsDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "TrajSeqCellsDataIndexCellRowCellCol" ON sc_ods."TrajSeqCellsData" USING btree ("cellRow", "cellCol");


--
-- Name: TrajSeqCellsDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "TrajSeqCellsDataIndexGeom4326" ON sc_ods."TrajSeqCellsData" USING gist (geom4326);


--
-- Name: XODRDataIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "XODRDataIndexCellRowCellCol" ON sc_ods."XODRData" USING btree ("cellRow", "cellCol");


--
-- Name: XODRDataIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "XODRDataIndexGeom4326" ON sc_ods."XODRData" USING gist (geom4326);


--
-- Name: XODRHistIndexCellRowCellCol; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "XODRHistIndexCellRowCellCol" ON sc_ods."XODRHist" USING btree ("cellRow", "cellCol");


--
-- Name: XODRHistIndexGeom4326; Type: INDEX; Schema: sc_ods; Owner: -
--

CREATE INDEX "XODRHistIndexGeom4326" ON sc_ods."XODRHist" USING gist (geom4326);


--
-- Name: GPSCellsData GPSCellsData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSCellsData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GPSCellsData GPSCellsData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSCellsData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GPSCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GPSCellsData GPSCellsData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSCellsData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GPSCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GPSFileData GPSFileData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSFileData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GPSFileData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GPSFileData GPSFileData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSFileData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GPSFileData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GPSNativeData GPSNativeData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSNativeData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GPSNativeData GPSNativeData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSNativeData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GPSNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GPSNativeData GPSNativeData_set_geom4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSNativeData_set_geom4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_geom4326();


--
-- Name: GPSNativeData GPSNativeData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSNativeData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GPSNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GPSValidData GPSValidData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSValidData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GPSValidData GPSValidData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GPSValidData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GPSValidData GPSValidData_set_geom4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidData_set_geom4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSValidData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_geom4326();


--
-- Name: GPSValidData GPSValidData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GPSValidData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidSeqCellsData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GPSValidSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidSeqCellsData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GPSValidSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GPSValidSeqCellsData GPSValidSeqCellsData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GPSValidSeqCellsData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GPSValidSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GeoJSONApplyingData GeoJSONApplyingData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONApplyingData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GeoJSONApplyingData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GeoJSONApplyingData GeoJSONApplyingData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONApplyingData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GeoJSONApplyingData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GeoJSONApplyingData GeoJSONApplyingData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONApplyingData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GeoJSONApplyingData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GeoJSONStagingFileData GeoJSONStagingFileData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONStagingFileData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GeoJSONStagingFileData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GeoJSONStagingFileData GeoJSONStagingFileData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONStagingFileData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GeoJSONStagingFileData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONStagingNativeData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."GeoJSONStagingNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONStagingNativeData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."GeoJSONStagingNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: GeoJSONStagingNativeData GeoJSONStagingNativeData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "GeoJSONStagingNativeData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."GeoJSONStagingNativeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMCntryAreaData OSMCntryAreaData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMCntryAreaData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMCntryAreaData OSMCntryAreaData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMCntryAreaData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMCntryAreaData OSMCntryAreaData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMCntryAreaData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMCntryAreaHist OSMCntryAreaHist_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaHist_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMCntryAreaHist" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMCntryAreaHist OSMCntryAreaHist_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaHist_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMCntryAreaHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMCntryAreaHist OSMCntryAreaHist_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMCntryAreaHist_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMCntryAreaHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMNodeData OSMNodeData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMNodeData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMNodeData OSMNodeData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMNodeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMNodeData OSMNodeData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMNodeData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMNodeHist OSMNodeHist_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeHist_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMNodeHist" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMNodeHist OSMNodeHist_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeHist_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMNodeHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMNodeHist OSMNodeHist_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMNodeHist_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMNodeHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMWayData OSMWayData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMWayData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMWayData OSMWayData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMWayData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMWayData OSMWayData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMWayData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: OSMWayHist OSMWayHist_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayHist_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."OSMWayHist" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: OSMWayHist OSMWayHist_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayHist_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."OSMWayHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: OSMWayHist OSMWayHist_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "OSMWayHist_set_updatedDateTime" BEFORE UPDATE ON sc_ods."OSMWayHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: TrajData TrajData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."TrajData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: TrajData TrajData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."TrajData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: TrajData TrajData_set_geom4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajData_set_geom4326" BEFORE INSERT OR UPDATE ON sc_ods."TrajData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_geom4326();


--
-- Name: TrajData TrajData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."TrajData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: TrajSeqCellsData TrajSeqCellsData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajSeqCellsData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."TrajSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: TrajSeqCellsData TrajSeqCellsData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajSeqCellsData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."TrajSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: TrajSeqCellsData TrajSeqCellsData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "TrajSeqCellsData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."TrajSeqCellsData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: XODRData XODRData_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRData_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."XODRData" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: XODRData XODRData_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRData_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."XODRData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: XODRData XODRData_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRData_set_updatedDateTime" BEFORE UPDATE ON sc_ods."XODRData" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- Name: XODRHist XODRHist_set_box4326; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRHist_set_box4326" BEFORE INSERT OR UPDATE ON sc_ods."XODRHist" FOR EACH ROW EXECUTE FUNCTION sc_ods.set_box4326();


--
-- Name: XODRHist XODRHist_set_createdUpdatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRHist_set_createdUpdatedDateTime" BEFORE INSERT ON sc_ods."XODRHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_createdUpdatedDateTime"();


--
-- Name: XODRHist XODRHist_set_updatedDateTime; Type: TRIGGER; Schema: sc_ods; Owner: -
--

CREATE TRIGGER "XODRHist_set_updatedDateTime" BEFORE UPDATE ON sc_ods."XODRHist" FOR EACH ROW EXECUTE FUNCTION sc_ods."set_updatedDateTime"();


--
-- PostgreSQL database dump complete
--

