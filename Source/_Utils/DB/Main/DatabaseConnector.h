
#pragma once

#include "DB/Internal/Internal.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"
#include "Common/Main/Cacher.h"

namespace _NDB
{

/*
 * 4.4 DatabaseConnector interfaces
 * 4.4.1 I/O
 * Input: Modules implementing DatabaseConnector shall be supplied with a GeoCoordinates. Output: Modules implementing DatabaseConnector shall output an _NOD::OpenDRIVE.
 *
 * 4.4.2 System Level Requirements
 * DC-1: the DatabaseConnector shall tell if an OpenDRIVE 1lealready exists in the database for the SGA to which a given point belongs to.
 * DC-2: the DatabaseConnector shall output _NOD::OpenDRIVE for the SGAs of a given point, (respectively north, east, south, west of it).
 * DC-3: the DatabaseConnector shall update an SGA of the database when being passed an _NOD::OpenDRIVE for the given SGA.
*/

class DatabaseConnector : public QObject
{
public:
    static _NCM::Cacher<Cell, _NOD::OpenDRIVE> odContents;

public:
    virtual bool updateXODRContent(const Cell& cell, _NOD::OpenDRIVE& odContent) = 0;
    virtual _NOD::OpenDRIVE getXODRContent(const Cell& cell) = 0;
    virtual int getNewID(QString key = _SC_id) = 0;

};

}
