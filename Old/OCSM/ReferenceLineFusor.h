
#ifndef __OCSM_REFERENCELINEFUSOR_H__
#define __OCSM_REFERENCELINEFUSOR_H__

#include "Common/VehiclePos.h"

namespace OCSM
{

    /*
     * 4.12 ReferenceLineFusor Module
     * 4.12.1 I/O
     * 	Input: The ReferenceLineFusor module shall be supplied with two RLR.
     * 	Output: The ReferenceLineFusor module shall output a fused RLR.
     * 4.12.2 System Level Requirements
     * 	RLF-1: the ReferenceLineFusor shall combine two RLR into a single one
     * 4.12.3 Software Level Requirements
     * 	RLF-1 ::Fuse() shall output a list of GeoCoordinates where the 1rst point is the first point of the longest RLR and the last point is the last point of the longest RLR.
     * 	RLF-2: Fuse() shall approximate the fused RLR as succession of clothoids.
     */

    class ReferenceLineFusor
    {
    public:
        bool IsCompatible(Common::ConstVehiclePosVec& created_rlr, Common::ConstVehiclePosVec& matched_rlr);

        /**
         * @return Common::VehiclePosVec
         * @param created_rlr
         * @param matched_rlr
         */
        Common::VehiclePosVec Fuse(Common::ConstVehiclePosVec& created_rlr, Common::ConstVehiclePosVec& matched_rlr);
    };

}

#endif // __OCSM_REFERENCELINEFUSOR_H__

