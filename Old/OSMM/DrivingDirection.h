#ifndef __OSMM_DRIVINGDIRECTION_H__
#define __OSMM_DRIVINGDIRECTION_H__

#include "Common/Common.h"

namespace OSMM
{

	enum DrivingDirection
	{
		POSITIVE,
		NEGATIVE,
		BOTH
	};

	static inline QString GetDrivingDirectionString(DrivingDirection driving_direction)
	{
		static QString driving_directions[] =
		{
			"POSITIVE",
			"NEGATIVE",
			"BOTH"
		};

		return driving_directions[(int)driving_direction];
	}

}

#endif // __OSMM_DRIVINGDIRECTION_H__