#pragma once

#include "OSM/Internal/Internal.h"
#include "UniversialType/Main/UniversialType.h"
#include "UniversialType/Main/StringPairs.h"
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

namespace _NOSM
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_osm) \
    _UNIVERSIAL_TYPE_TAG(usingType, StringPairs, osm) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType, LLCoordSysXYCell, coord) lineEnd \
    EMPTY_COMMAND

struct Node
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(Node)

public:
    inline void parseFromOSMJson(QJsonObject obj)
    {
        (LL&)(this->coord) = LL(obj);
        this->coord.updateAllFromLL();

        osm[_SC_id] = QString::number((qint64)obj[_SC_id].toDouble());

        QJsonObject tags = obj[_SC_tags].toObject();

        QJsonObject::iterator iter = tags.begin();
        for (; iter != tags.end(); iter ++)
            osm[iter.key()] = iter.value().toString();
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject obj;

        obj[_SC_coord] = coord.toJsonObject();

        StringMap::ConstIterator iter = osm.constBegin();
        for (; iter != osm.constEnd(); iter ++)
            obj[iter.key()] = iter.value();

        return obj;
    }

    inline operator QJsonObject() const
    {
        return toJsonObject();
    }
};

typedef QVector<Node>		NodeVec;

}

