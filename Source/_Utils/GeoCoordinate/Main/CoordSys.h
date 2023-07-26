#pragma once

#include "GeoCoordinate/Internal/Internal.h"
#include <assert.h>

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int, coordSysId, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct CoordSys
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(CoordSys)

public:
    CoordSys()
    {
        coordSysId = -1;
    }

protected:
    CoordSys(int coordSysId)
        : coordSysId(coordSysId)
    {
    }

public:
    void assertIfValid() const
    {
        assert(isValid());
    }

    bool isValid() const;
    const char* getProj4() const;

    void setFromLL(const LL& ll);
    void setFromCell(const Cell& cell);

public:
    static CoordSys get3857();
    static CoordSys getAusCoordSys();
};

}
