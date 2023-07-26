#pragma once

#include "GeoCoordinate/GeoCoordinate.h"
#include "Common/Common.h"
#include "SettingsOnLocalSystem/SettingsOnLocalSystem.h"

namespace _NDB
{

typedef _NGC::CardinalDirection             CardinalDirection;
typedef _NGC::LL                            LL;
typedef _NGC::CoordSys                      CoordSys;
typedef _NGC::XY                            XY;
typedef _NGC::CoordSysXY                    CoordSysXY;
typedef _NGC::Cell                          Cell;
typedef _NGC::CoordSysXYCell                CoordSysXYCell;
typedef _NGC::LLCoordSysXYCell              LLCoordSysXYCell;
typedef _NGC::VehiclePos                    VehiclePos;

typedef QVector<LL>                         LLVec;
typedef QVector<LLVec>                      LLVecVec;
typedef QVector<LLVecVec>                   LLVecVecVec;
typedef QVector<XY>                         XYVec;
typedef QVector<XYVec>                      XYVecVec;
typedef QVector<LLCoordSysXYCell>           LLCoordSysXYCellVec;
typedef QVector<LLCoordSysXYCellVec>		LLCoordSysXYCellVecVec;
typedef QVector<VehiclePos>                 VehiclePosVec;
typedef QVector<VehiclePosVec>              VehiclePosVecVec;

}
