
#pragma once

#include "XODR/Internal/Internal.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"

namespace _NXODR
{

/*
 * 4.13 RoadFusor Module
 * 4.13.1 I/O
 * 	Input: The RoadFusor module shall be supplied with two Content.
 * 	Output: The RoadFusor module shall output a fused Content.
 * 4.13.1 System Level Requirements
 * 	RF-1: the RoadFusor shall fuse the details of two Content.
 * 	RF-2: the RoadFusor shall ensure the consistency of road details in the fused content (for instance, consistency in number of lanes, speed limitations etc.).
 */

class RoadFusor
{
public:
    /**
     * @return Content
     * @param created_content
     * @param matched_content
     */
    QVector<_NOD::t_road> fuse(const QVector<_NOD::t_road>& old_roads, const QVector<_NOD::t_road>& new_roads);
};

}

