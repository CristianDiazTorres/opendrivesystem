#include "OCSM/ReferenceLineFusor.h"

namespace OCSM
{

	bool ReferenceLineFusor::IsCompatible(Common::ConstVehiclePosVec& created_rlr, Common::ConstVehiclePosVec& matched_rlr)
	{
		for (int i = 0; i < created_rlr.size(); i++)
		{
			Common::ConstVehiclePos& p1 = created_rlr[i];

			bool found = false;

			for (int j = 0; j < matched_rlr.size(); j++)
			{
				Common::ConstVehiclePos& p2 = matched_rlr[j];

				double distance = p1.GetDistance(p2);
				if (distance < 1)
				{
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}

		return true;
	}

	Common::VehiclePosVec ReferenceLineFusor::Fuse(Common::ConstVehiclePosVec& created_rlr, Common::ConstVehiclePosVec& matched_rlr)
	{
		Common::VehiclePosVec result = created_rlr;

		for (int i = 0; i < matched_rlr.size(); i++)
		{
			Common::ConstVehiclePos& p1 = matched_rlr[i];

			bool found = false;

			for (int j = 0; j < created_rlr.size(); j++)
			{
				Common::ConstVehiclePos& p2 = created_rlr[j];

				double distance = p1.GetDistance(p2);
				if (distance < 1)
				{
					found = true;
					break;
				}
			}

			if (!found)
				result.push_back(p1);
		}

		return result;
	}

}