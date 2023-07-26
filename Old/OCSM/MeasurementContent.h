#ifndef __OCSM_MEASUREMENTCONTENT_H__
#define __OCSM_MEASUREMENTCONTENT_H__

#include "Common/VehiclePos.h"

namespace OCSM
{

	typedef QVector<Common::VehiclePos>			MeasurementContent;
	typedef CONST MeasurementContent		ConstMeasurementContent;
	typedef QVector<MeasurementContent>	MeasurementContentVec;
	typedef CONST MeasurementContentVec		ConstMeasurementContentVec;

}

#endif // __OCSM_MEASUREMENTCONTENT_H__

