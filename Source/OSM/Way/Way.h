#pragma once

#include "OSM/Internal/Internal.h"
#include "Math/Math.h"
#include "OSM/Node/Node.h"
#include "GeoCoordinate/Main/VehiclePos.h"

/*

https://wiki.openstreetmap.org/wiki/Highways

*/

namespace _NOSM
{

// TODO: ???? : must added NONE_EMPTY for every enum


#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_osm) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , laneCount                 , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , leftLaneCount             , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , forwardLaneCount          , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , bidirectionalLaneCount    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , rightLaneCount            , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int               , backwardLaneCount         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double            , chord_length              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double            , gps_length                , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double            , updated_length            , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType, StringPairs         , osm) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType, LL                      , center_coord) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, VehiclePos   , chord_coords) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, VehiclePos   , gps_coords) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, VehiclePos   , updated_coords) lineEnd \
    EMPTY_COMMAND

struct Way
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(Way)

public:
    Way()
    {
        laneCount = -1;
        leftLaneCount = -1;
        forwardLaneCount = -1;
        bidirectionalLaneCount = -1;
        rightLaneCount = -1;
        backwardLaneCount = -1;
        chord_length = 0;
        gps_length = 0;
        updated_length = 0;
    }

    bool isOneway() const
    {
        return osm.contains(_SC_oneway) && osm[_SC_oneway] != _SC_no;
    }

    bool isLHT() const
    {
        return osm[_SC_driving_side] == _SC_left;
    }

    bool isRHT() const
    {
        return osm[_SC_driving_side] == _SC_right;
    }

    int getMatchedCount(const QString& key, const QString& value)
    {
        int count = 0;
        QList<QString> values = getSplit(key);
        for (QString& subValue : values)
        {
            if (subValue.trimmed() == value)
                count ++;
        }
        return count;
    }

    int getMatchedCountFromLeft(const QString& key, const QString& value)
    {
        int count = 0;
        QList<QString> values = getSplit(key);
        for (QString& subValue : values)
        {
            if (subValue.trimmed() != value)
                return count;
            count ++;
        }
        return count;
    }

    int getMatchedCountFromRight(const QString& key, const QString& value)
    {
        int count = 0;
        StringVec values = getSplit(key).toVector();
        for (int i = values.size() - 1; i >= 0; i --)
        {
            QString& subValue = values[i];
            if (subValue.trimmed() != value)
                return count;
            count ++;
        }
        return count;
    }

    int getMatchedCountFrom(const QString& key, const QString& value, bool fromLeft)
    {
        if (fromLeft)
            return getMatchedCountFromLeft(key, value);
        else
            return getMatchedCountFromRight(key, value);
    }

    int getMatchedLaneDirectionCount(const QString& value)
    {
        int count = getMatchedCount(_SC_driving_direction_lanes_A, value);
        if (count > 0)
            return count;

        count = getMatchedCount(_SC_driving_side_lanes_A, value);
        if (count > 0)
            return count;

        return getMatchedCount(_SC_lanes_direction_A, value);
    }

    int getMatchedLaneDirectionCount(const QString& value, bool fromLeft)
    {
        int count = getMatchedCountFrom(_SC_driving_direction_lanes_A, value, fromLeft);
        if (count > 0)
            return count;

        count = getMatchedCountFrom(_SC_driving_side_lanes_A, value, fromLeft);
        if (count > 0)
            return count;

        return getMatchedCountFrom(_SC_lanes_direction_A, value, fromLeft);
    }

public:
    void parseFromOSMJson(QJsonObject obj);
    void parseLaneCount1();
    void parseJunction();
    void parseOneway();
    void parseLanesWidth();
    void parseLaneCount2();
    void parseRoadMark();

    QJsonObject toJsonObject() const;

    inline operator QJsonObject() const
    {
        return toJsonObject();
    }

    inline void calculateLength()
    {
        this->chord_length = _NMath::calcLengthOfVector(chord_coords_sequence);
        this->gps_length = _NMath::calcLengthOfVector(gps_coords_sequence);
        this->updated_length = _NMath::calcLengthOfVector(updated_coords_sequence);
    }

    void calcUpdatedCoord();

    inline bool isValid() const
    {
        //if (this->chord_length < 1)
        //    return false;

        //DefaultLogger << gps_coords.size();
        if (gps_coords_sequence.size() < 2)
            return false;

        return true;

        if (gps_length < 1)
            return false;

        double lenRatio = gps_length / this->chord_length;
        //DefaultLogger << lenRatio;
        if (lenRatio < 0.4 || lenRatio > 2.5)
            return false;

        return true;
    }

    inline double calcDistance(const VehiclePos& pos) const
    {
        return _NMath::calcDistance(pos, chord_coords_sequence);
    }

    inline void setIfNotContain(const QString& key, const QString& value)
    {
        if (!osm.contains(key))
            osm[key] = value;
    }

    inline QList<QString> getSplit(const QString& key) const
    {
        if (osm.contains(key))
        {
            const QString& value = osm[key];
            return value.split('|');
        }
        return QList<QString>();
    }

    inline void checkIfEqualToLaneCount(const QString& key) const
    {
        Q_ASSERT(getSplit(key).size() == laneCount);
    }

    inline void replaceIfEmptyAppendJoin(const QString& key, const QString& newValue, int count)
    {
        QList<QString> elems = getSplit(key);
        osm[key] = _NCM::getReplacedifEmptyAppendedJoined(elems, newValue, count);
    }

    inline void copyValue(const QString& destKey, const QString& srcKey)
    {
        osm[destKey] = osm[srcKey];
    }

    inline void copyValueIfDestNotExistSrcExists(const QString& destKey, const QString& srcKey)
    {
        if (!osm.contains(destKey) && osm.contains(srcKey))
            copyValue(destKey, srcKey);
    }

    inline void duplicateLastJoin(const QString& key, int count)
    {
        QList<QString> elems = getSplit(key);
        if (elems.isEmpty())
            elems << "";

        osm[key] = _NCM::getDuplicatedLastJoined(elems, count);
    }

    inline void duplicateJoin(const QString& key, const QString& newValue, int count)
    {
        osm[key] = _NCM::getDuplicatedJoind(newValue, count);
    }

    inline void appendJoin(const QString& key, const QString& newValue, int count)
    {
        QList<QString> elems = getSplit(key);
        osm[key] = _NCM::getAppendedJoined(elems, newValue, count);
    }

};

typedef QVector<Way>       WayVec;

}
