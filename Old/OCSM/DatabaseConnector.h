
#ifndef __OCSM_DATABASECONNECTOR_H__
#define __OCSM_DATABASECONNECTOR_H__

#include "Common/VehiclePos.h"
#include "OpenDRIVE/core/OpenDRIVE.h"

namespace OCSM
{

	/*
	 * 4.4 DatabaseConnector interfaces
	 * 4.4.1 I/O
     * Input: Modules implementing DatabaseConnector shall be supplied with a GeoCoordinates. Output: Modules implementing DatabaseConnector shall output an OpenDRIVE::OpenDRIVE.
	 *
	 * 4.4.2 System Level Requirements
	 * DC-1: the DatabaseConnector shall tell if an OpenDRIVE 1lealready exists in the database for the SGA to which a given point belongs to.
     * DC-2: the DatabaseConnector shall output OpenDRIVE::OpenDRIVE for the SGAs of a given point, (respectively north, east, south, west of it).
     * DC-3: the DatabaseConnector shall update an SGA of the database when being passed an OpenDRIVE::OpenDRIVE for the given SGA.
	*/

	class DatabaseConnector
	{
    public:
        virtual int GetNewRoadID() = 0;
        virtual int GetNewLaneID() = 0;
        virtual int GetNewObjectID() = 0;
        virtual int GetNewJunctionID() = 0;
        virtual int GetNewJunctionConnectionID() = 0;
        virtual int GetNewJunctionControllerID() = 0;

		virtual QString GetName(int zone, int grid_row, int grid_col) = 0;
		QString GetName(Common::ConstVehiclePos& coord)
		{
			return GetName(coord.zone, coord.grid_row, coord.grid_col);
		}

		/**
		 * @return bool
		 * @param coord
		 */
		virtual bool Exists(Common::ConstVehiclePos& coord) = 0;

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coordinates
		 */
        virtual OpenDRIVE::OpenDRIVE Get(Common::ConstVehiclePos& coord) = 0;

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        virtual OpenDRIVE::OpenDRIVE GetNorth(Common::ConstVehiclePos& coord) = 0;

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        virtual OpenDRIVE::OpenDRIVE GetSouth(Common::ConstVehiclePos& coord) = 0;

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        virtual OpenDRIVE::OpenDRIVE GetEast(Common::ConstVehiclePos& coord) = 0;

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        virtual OpenDRIVE::OpenDRIVE GetWest(Common::ConstVehiclePos& coord) = 0;

		/**
		 * @param content
		 */
        virtual void Update(Common::ConstVehiclePos& coord, OpenDRIVE::OpenDRIVE& content) = 0;

	};

}

#endif // __OCSM_DATABASECONNECTOR_H__
