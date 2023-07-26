#pragma once

#include "GeoCoordinate/GeoCoordinate.h"
#include "Network/Network.h"
#include "Debugger/Debugger.h"
#include "DB/DB.h"
#include "Thread/Thread.h"

using namespace _NNetwork;
using namespace _NDB;
using namespace _NThread;

namespace _NOSM
{

typedef _NGC::LL                LL;
typedef _NGC::CoordSys          CoordSys;
typedef _NGC::XY                XY;
typedef _NGC::CoordSysXY        CoordSysXY;
typedef _NGC::Cell              Cell;
typedef _NGC::CoordSysXYCell    CoordSysXYCell;
typedef _NGC::LLCoordSysXYCell  LLCoordSysXYCell;
typedef _NGC::VehiclePos        VehiclePos;

typedef QVector<LL>                      LLVec;
typedef QVector<LLVec>                   LLVecVec;
typedef QVector<LLVecVec>                LLVecVecVec;
typedef QVector<XY>                      XYVec;
typedef QVector<XYVec>                   XYVecVec;
typedef QVector<LLCoordSysXYCell>        LLCoordSysXYCellVec;
typedef QVector<LLCoordSysXYCellVec>		LLCoordSysXYCellVecVec;
typedef QVector<VehiclePos>              VehiclePosVec;
typedef QVector<VehiclePosVec>           VehiclePosVecVec;

typedef _NUniversialType::StringPairs         StringPairs;

}
