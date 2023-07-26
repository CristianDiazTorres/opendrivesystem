#pragma once

#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, LLCoordSysXYCell) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, qint64, id, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, qint64, gpsFileId, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, gpsTow, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, QString, date, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, QString, time, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, sog, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, roll/* In radians */, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, pitch/* In radians */, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, heading/* In radians */, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, hdop, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, ehpe, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, evpe, REQUIRED) lineEnd \
    /* Derived properties */ \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, timeSeconds, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, vx, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, vy, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, ax, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, ay, REQUIRED) lineEnd \
    EMPTY_COMMAND


struct VehiclePos : public LLCoordSysXYCell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(VehiclePos)

public:
    VehiclePos()
    {
        id = 0;
        gpsFileId = 0;
        gpsTow = 0;
        sog = 0;
        roll = 0;
        pitch = 0;
        heading = 0;
        hdop = 0;
        ehpe = 0;
        evpe = 0;

        timeSeconds = 0;
        vx = 0;
        vy = 0;
        ax = 0;
        ay = 0;
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject result = LLCoordSysXYCell::toJsonObject();
        result[_SC_id] = this->id;
        result[_SC_gpsFileId] = this->gpsFileId;
        result[_SC_gpsTow] = this->gpsTow;
        result[_SC_date] = this->date;
        result[_SC_time] = this->time;
        result[_SC_sog] = this->sog;
        result[_SC_roll] = this->roll;
        result[_SC_pitch] = this->pitch;
        result[_SC_heading] = this->heading;
        result[_SC_hdop] = this->hdop;
        result[_SC_ehpe] = this->ehpe;
        result[_SC_evpe] = this->evpe;

        return result;
    }

    inline operator QJsonObject() const
    {
        return toJsonObject();
    }

    void updateDerivedProps();

    inline void updateAccelFromPrev(const VehiclePos& prev)
    {
        double dt = this->timeSeconds - prev.timeSeconds;
        this->ax = (this->vx - prev.vx) / dt;
        this->ay = (this->vy - prev.vy) / dt;
    }

    inline void updateAccelFromNext(const VehiclePos& next)
    {
        this->ax = next.ax;
        this->ay = next.ay;
    }

    void setFromPredictedPos(const VehiclePos& pos, const XY& xy, double vx, double vy);
    void setFromIntersectedPos(const VehiclePos& pos, const LL& ll, double vx, double vy);

    void setFrom2Poses_Prev(const VehiclePos& prev, const VehiclePos& next, LL ll);
    void setFrom2Poses_Next(const VehiclePos& prev, const VehiclePos& next, LL ll);
};

typedef QVector<VehiclePos>          VehiclePosVec;
typedef QVector<VehiclePosVec>		VehiclePosVecVec;

}

