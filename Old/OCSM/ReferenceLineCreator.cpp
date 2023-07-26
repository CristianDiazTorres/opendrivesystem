#include "OCSM/ReferenceLineCreator.h"

namespace OCSM
{

	Common::VehiclePosVec ReferenceLineCreator::Create(Common::ConstVehiclePosVec& trajectory,
		ConstMeasurementContent& content,
		ConstExternalSourceProviderVec& external_source_providers)
	{
        Q_UNUSED(content);

		MyCout << "========== Creating reference line ==========" << MyEndl;

		if (external_source_providers.isEmpty())
		{
			MyCout << "Reference line points: " << trajectory.size() << MyEndl;
			return trajectory;
		}

		ExternalSourceProvider& external_source_provider = *external_source_providers[0];
		OSMM::ConstRoadVec& roads = external_source_provider.GetSavedData();
		Common::VehiclePosVec result;
		for (int i = 0; i < roads.size(); i++)
		{
			OSMM::ConstRoad& road = roads[i];
			OSMM::ConstLaneSectionVec& lane_sections = road.lane_sections;
			for (int j = 0; j < lane_sections.size(); j++)
			{
				OSMM::ConstLaneSection& lane_section = lane_sections[j];
                result << lane_section.chord_coords;
			}
		}

		MyCout << "Reference line points: " << result.size() << MyEndl;
		return result;
	}

}
