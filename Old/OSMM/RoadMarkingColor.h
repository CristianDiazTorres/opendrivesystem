#ifndef __OSMM_ROADMARKINGCOLOR_H__
#define __OSMM_ROADMARKINGCOLOR_H__

#include "Common/Common.h"

namespace OSMM
{

	enum RoadMarkingColor
	{
		WHITE,
		YELLOW,
		RED,
		GREEN,
		BLUE
	};

	static inline QString GetRoadMarkingColorString(RoadMarkingColor road_marking_color)
	{
		static QString road_marking_colors[]
		{
			"WHITE",
			"YELLOW",
			"RED",
			"GREEN",
			"BLUE"
		};

		return road_marking_colors[(int)road_marking_color];
	}

}

#endif // __OSMM_ROADMARKINGCOLOR_H__