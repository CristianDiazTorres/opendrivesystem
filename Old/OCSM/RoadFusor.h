
#ifndef __OCSM_ROADFUSOR_H__
#define __OCSM_ROADFUSOR_H__

#include "OpenDRIVE/core/OpenDRIVE.h"

namespace OCSM
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
        OpenDRIVE::OpenDRIVE Fuse(OpenDRIVE::OpenDRIVE& created_content, OpenDRIVE::OpenDRIVE& matched_content);

    };

}

#endif // __OCSM_ROADFUSOR_H__
