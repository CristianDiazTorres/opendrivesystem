#include "OCSM/OCSM.h"
#include "OCSM/FileReader.h"
#include "OCSM/EgoTrajectoryCreator.h"
#include "OCSM/TrajectorySpliter.h"
#include "OCSM/TrajectoryToRoadMatcher.h"
#include "OCSM/ReferenceLineCreator.h"
#include "OCSM/OSMMExternalSourceProvider.h"
#include "OCSM/ReferenceLineFusor.h"
#include "OCSM/RoadBuilder.h"
#include "OCSM/RoadFusor.h"
#include "OCSM/LocalFilesDatabaseConnector.h"

namespace OCSM
{
	void OCSM::SetDatabaseRootPath(ConstQString& root_path)
	{
		LocalFilesDatabaseConnector::SetRootPath(root_path);
	}

	void OCSM::Process(ConstQString& file_path, int point_count)
	{
		MeasurementContent measurement_content = FileReader<MeasurementContent>().Read(file_path, point_count);

		Common::VehiclePosVec trajectory = EgoTrajectoryCreator().ComputeTrajectory(measurement_content);

		Common::VehiclePosVecVec trajectories = TrajectorySpliter().Split(trajectory);

		TrajectoryToRoadMatcher trajectory_to_road_matcher;

		ReferenceLineCreator reference_line_creator;

		OSMMExternalSourceProvider osmm_external_source_provider;
		ExternalSourceProviderVec external_source_providers;
		external_source_providers.push_back(&osmm_external_source_provider);

		ReferenceLineFusor reference_line_fusor;

		RoadBuilder road_builder;

		LocalFilesDatabaseConnector local_files_database_connector;
		DatabaseConnector& database_connector = local_files_database_connector;

		RoadFusor road_fusor;

		for (int i = 0; i < trajectories.size(); i++)
		{
			Common::ConstVehiclePosVec& trajectory = trajectories[i];

			for (int j = 0; j < external_source_providers.size(); j++)
                (*external_source_providers[j]).RequestDataForPath(trajectory, database_connector);

			Common::VehiclePosVec created_rlr = reference_line_creator.Create(trajectory, measurement_content, external_source_providers);

			OpenDRIVE::OpenDRIVE created_drive_content;

			if (!database_connector.Exists(trajectory[0]))
			{
				created_drive_content = road_builder.Build(created_rlr, trajectory, measurement_content, database_connector, external_source_providers);
			}
			else
			{
				OpenDRIVE::OpenDRIVE matched_drive_content = database_connector.Get(trajectory[0]);

				if (trajectory_to_road_matcher.MatchingRoadForTrajectory(trajectory, matched_drive_content))
				{
					Common::ConstVehiclePosVec& matched_rlr = trajectory_to_road_matcher.GetReferenceLineOfMatchingRoad(trajectory, matched_drive_content);

					if (!reference_line_fusor.IsCompatible(created_rlr, matched_rlr))
					{
						created_rlr = reference_line_fusor.Fuse(created_rlr, matched_rlr);
					}
				}

				created_drive_content = road_builder.Build(created_rlr, trajectory, measurement_content, database_connector, external_source_providers);

                if (!created_drive_content.isCompatible(matched_drive_content))
				{
					created_drive_content = road_fusor.Fuse(created_drive_content, matched_drive_content);
				}
			}

			database_connector.Update(trajectory[0], created_drive_content);
		}
	}

}
