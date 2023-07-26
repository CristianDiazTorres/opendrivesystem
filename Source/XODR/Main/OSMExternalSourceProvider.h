#pragma once

#include "XODR/Main/ExternalSourceProvider.h"

namespace _NXODR
{
/*
     * 4.3 ExternalSourceProvider interfaces
     * 4.3.1 I/O
     * 	Input: Modules implementing ExternalSourceProvider shall be supplied with a QVector of GeoCoordinates.
     * 	Output: Modules implementing ExternalSourceProvider shall output an ExternalRoadData.
     */

class OSMExternalSourceProvider : public ExternalSourceProvider
{
public:

    virtual QString getProviderName(){ return _SC_OSMExternalSourceProvider; }

    /**
         * @return ExternalRoadData
         * @param geocoordinates
         */
    void getNearestRoadsForPath(bool useBasicTables
                                , const VehiclePosVec& poses
                                , _NOSM::WayVec& allOSMWays, _NOSM::WayVec& nearestWays);
    _NOSM::NodeVec getNodes(bool useBasicTables, Cell cell);

};

}

