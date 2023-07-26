#pragma once

#include "GeoCoordinate/Internal/Internal.h"
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include "Common/Main/StringContants.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, lat/*In degrees*/, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, lon/*In degrees*/, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct LL
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(LL)

public:
    LL()
    {
    }

    LL(double lat, double lon)
    {
        this->lat = lat;
        this->lon = lon;
    }

    LL(const QJsonValue& json)
    {
        this->lat = json.toObject()[_SC_lat].toDouble();
        this->lon = json.toObject()[_SC_lon].toDouble();
    }

    LL(const QJsonObject& json)
    {
        this->lat = json[_SC_lat].toDouble();
        this->lon = json[_SC_lon].toDouble();
    }

    LL(const QJsonArray& json)
    {
        this->lat = json[1].toDouble();
        this->lon = json[0].toDouble();
    }

    inline QJsonArray toJsonArray() const
    {
        QJsonArray result;
        result.push_back(this->lon);
        result.push_back(this->lat);
        return result;
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject result;
        result[_SC_lat] = this->lat;
        result[_SC_lon] = this->lon;
        return result;
    }

    inline operator QJsonArray() const
    {
        return toJsonArray();
    }

    inline operator QJsonObject() const
    {
        return toJsonObject();
    }

public:
    inline void parseString(QString text)
    {
        _NCM::parse2NumbersFromString(text, lat, lon);
    }

    static inline QRectF calcBound(const QVector<LL>& points)
    {
        double left, top, right, bottom;
        left = right = points.first().lon;
        top = bottom = points.first().lat;
        for (int i = 1; i < points.size(); i ++)
        {
            const LL& pt = points[i];
            if (pt.lon < left)
                left = pt.lon;
            else if (pt.lon > right)
                right = pt.lon;

            if (pt.lat < top)
                top = pt.lat;
            else if (pt.lat > bottom)
                bottom = pt.lat;
        }

        return QRectF(left, top, right - left, bottom - top);
    }
};

typedef QVector<LL>             LLVec;
typedef QVector<LLVec>          LLVecVec;
typedef QVector<LLVecVec>       LLVecVecVec;

template <typename T>
inline double getMinLat(const QVector<T>& lls)
{
    double minLat = lls.first().lat;
    for (int i = 1; i < lls.size(); i ++)
    {
        double lat = lls[i].lat;
        if (lat < minLat)
            minLat = lat;
    }
    return minLat;
}

template <typename T>
inline double getMaxLat(const QVector<T>& lls)
{
    double maxLat = lls.first().lat;
    for (int i = 1; i < lls.size(); i ++)
    {
        double lat = lls[i].lat;
        if (lat > maxLat)
            maxLat = lat;
    }
    return maxLat;
}

template <typename T>
inline double getMinLon(const QVector<T>& lls)
{
    double minLon = lls.first().lon;
    for (int i = 1; i < lls.size(); i ++)
    {
        double lon = lls[i].lon;
        if (lon < minLon)
            minLon = lon;
    }
    return minLon;
}

template <typename T>
inline double getMaxLon(const QVector<T>& lls)
{
    double maxLon = lls.first().lon;
    for (int i = 1; i < lls.size(); i ++)
    {
        double lon = lls[i].lon;
        if (lon > maxLon)
            maxLon = lon;
    }
    return maxLon;
}

}

