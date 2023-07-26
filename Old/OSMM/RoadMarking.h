#ifndef __OSMM_ROADMARKING_H__
#define __OSMM_ROADMARKING_H__

#include "Common/Common.h"

namespace OSMM
{

	enum RoadMarking
	{
		NONE,
		CONTINUOUS,
		DASHED,
		DOUBLED // instead of DOUBLE, to avoid error
	};

	static inline QString GetRoadMarkingString(RoadMarking road_marking)
	{
		static QString road_markings[] =
		{
			"NONE",
			"CONTINUOUS",
			"DASHED",
			"DOUBLED" // instead of DOUBLE, to avoid error
		};

		return road_markings[(int)road_marking];
	}

}

#endif // __OSMM_ROADMARKING_H__