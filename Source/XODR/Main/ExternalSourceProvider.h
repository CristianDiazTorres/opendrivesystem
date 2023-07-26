#pragma once

#include "XODR/Internal/Internal.h"
#include "OSM/Way/Way.h"

namespace _NXODR
{

/*
 * 4.3 ExternalSourceProvider interfaces
 * 4.3.1 I/O
 * 	Input: Modules implementing ExternalSourceProvider shall be supplied with a QVector of GeoCoordinates.
 * 	Output: Modules implementing ExternalSourceProvider shall output an ExternalRoadData.
 */

class ExternalSourceProvider
{
public:
    virtual QString getProviderName() = 0;
};

typedef QVector<ExternalSourceProvider*>     ExternalSourceProviderVec;
typedef const ExternalSourceProviderVec		ConstExternalSourceProviderVec;

}

