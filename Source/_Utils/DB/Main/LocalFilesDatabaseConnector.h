
#pragma once

#include "DB/Main/DatabaseConnector.h"

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

class LocalFilesDatabaseConnector : public DatabaseConnector
{
public:
    QString getFilePath(const Cell& zoneCell);
    QString getFilePath(const QString& name);
    bool setGPSFilePath(QString& filePath, bool continue_, int count, int& start);

public:
    virtual bool updateXODRContent(const Cell& cell, _NOD::OpenDRIVE& odContent);
    virtual _NOD::OpenDRIVE getXODRContent(const Cell& cell);
    virtual int getNewID(QString key = _SC_id);


};

}
