
#ifndef __OCSM_LOCALFILESDATABASECONNECTOR_H__
#define __OCSM_LOCALFILESDATABASECONNECTOR_H__

#include "OCSM/DatabaseConnector.h"
#include <QSettings>

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

	class LocalFilesDatabaseConnector : public DatabaseConnector
	{
	protected:
		static QString m_root_path;
        static QSettings* m_settings;

	public:
        static void SetRootPath(ConstQString& root_path);

        static int GetNewID(QString key)
        {
            int id = m_settings->value(key, 0).toInt() + 1;
            m_settings->setValue(key, id);
            return id;
        }

        virtual int GetNewRoadID()
        {
            return GetNewID("roadID");
        }

        virtual int GetNewLaneID()
        {
            return GetNewID("laneID");
        }

        virtual int GetNewObjectID()
        {
            return GetNewID("objectID");
        }

        virtual int GetNewJunctionID()
        {
            return GetNewID("junctionID");
        }

        virtual int GetNewJunctionConnectionID()
        {
            return GetNewID("junctionConnectionID");
        }

        virtual int GetNewJunctionControllerID()
        {
            return GetNewID("junctionControllerID");
        }

		QString GetName(int zone, int grid_row, int grid_col);
		QString GetFilePath(int zone, int grid_row, int grid_col);
		QString GetFilePath(Common::ConstVehiclePos& coord);

		/**
		 * @return bool
		 * @param coord
		 */
		bool Exists(Common::ConstVehiclePos& coord);

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coordinates
		 */
        OpenDRIVE::OpenDRIVE Get(Common::ConstVehiclePos& coord);

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        OpenDRIVE::OpenDRIVE GetNorth(Common::ConstVehiclePos& coord);

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        OpenDRIVE::OpenDRIVE GetSouth(Common::ConstVehiclePos& coord);

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        OpenDRIVE::OpenDRIVE GetEast(Common::ConstVehiclePos& coord);

		/**
         * @return OpenDRIVE::OpenDRIVE
		 * @param coord
		 */
        OpenDRIVE::OpenDRIVE GetWest(Common::ConstVehiclePos& coord);

		/**
		 * @param content
		 */
        void Update(Common::ConstVehiclePos& coord, OpenDRIVE::OpenDRIVE& content);

	};

}

#endif // __OCSM_LOCALFILESDATABASECONNECTOR_H__
