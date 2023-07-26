#ifndef __OSMM_LANESECTION_H__
#define __OSMM_LANESECTION_H__

#include "OSMM/Lane.h"
#include "Common/VehiclePos.h"
#include "Common/WayNode.h"

namespace OSMM
{

	struct LaneSection
	{
		LaneVec lanes;
		Common::VehiclePosVec chord_coords;
		Common::WayNodeVec way_nodes;

	public:
        inline LaneSection(){}

        inline QJsonObject ToQJsonObject() const
		{
			QJsonObject obj;
            obj["lanes"] = Common::ToQJsonArrayOfObject(this->lanes);
            obj["chord_coords"] = Common::ToQJsonArrayOfArray(this->chord_coords);
            obj["way_nodes"] = Common::ToQJsonArrayOfObject(this->way_nodes);

            return obj;
		}

        inline operator QJsonObject() const
        {
            return ToQJsonObject();
        }
	};

	typedef CONST LaneSection			ConstLaneSection;
	typedef QVector<LaneSection>		LaneSectionVec;
	typedef CONST LaneSectionVec		ConstLaneSectionVec;

}

#endif // __OSMM_LANESECTION_H__
