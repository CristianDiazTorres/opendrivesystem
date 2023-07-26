#ifndef __OPENDRIVE_ROAD_H__
#define __OPENDRIVE_ROAD_H__

#include "OpenDRIVE/RoadLink.h"
#include "OpenDRIVE/RoadNeighbor.h"
#include "OpenDRIVE/RoadType.h"
#include "OpenDRIVE/GeometryBlock.h"
#include "OpenDRIVE/Elevation.h"
#include "OpenDRIVE/SuperElevation.h"
#include "OpenDRIVE/Crossfall.h"
#include "OpenDRIVE/LaneSection.h"
#include "OpenDRIVE/Object.h"
#include "OpenDRIVE/Signal.h"
#include "OpenDRIVE/Surface.h"

namespace OpenDRIVE
{

	/**
	 * One of the main classes in OpenDRIVE structure
	 * Holds the properties of the Road record and vectors for child records
	 * Has methods to add, clone, get and delete those child records
	 * as well as evaluation methods used, for example, to render the road
	 *
	 */
    struct Road
	{

		// Main road record properties
		QString name;
		double length;
        QString id;
		QString junction;
        QString rule;

		// Linking complex properties (have multiple sub-properties)
        RoadLink predecessor;
        RoadLink successor;
        RoadNeighbor neighbor1;
        RoadNeighbor neighbor2;

		/**
		 * Vectors used to store the child records of the road
		 * such as chordline geometry, elevation profiles, etc
		 */
		 // Road type QVector
		QVector<RoadType> road_types;
		// Geometry block QVector
		QVector<GeometryBlock> geom_blocks;
		// Elevation Profile QVector
		QVector<Elevation> elevations;
		// Superelevation QVector
		QVector<SuperElevation> super_elevations;
		// Crossfall QVector
		QVector<Crossfall> crossfalls;
		// Lane Section QVector
		QVector<LaneSection> lane_sections;
		// Objects vectors
		QVector<Object> objects;
		// Signal QVector
        QVector<Signal> _signals;
        // Surface
        Surface surface;

	public:
		/**
		 * Constructor
		 */
		Road();

		/**
		 * Constructor that initializes the road with base properties
		 *
		 * @param name Name of the road
		 * @param length Length of the road
		 * @param id Unique ID of the road
		 * @param junction ID of the junction, this road might be a part of
		 */
        Road(QString name, double length, QString id, QString junction, QString rule);

		//-------------------------------------------------
        bool read(const Common::DomElement& node);
        void write(QDomDocument& doc, Common::DomElement& node) const;

		bool IsCompatible(CONST Road& other) CONST;

		void Fuse(CONST Road& other);

		bool CheckPoint(double x, double y)
		{
			for (int i = 0; i < this->geom_blocks.size(); i++)
			{
				if (this->geom_blocks[i].CheckPoint(x, y))
					return true;
			}
			return false;
		}

		Common::VehiclePosVec GetPoints(Common::ConstVehiclePosVec& trajectory)
		{
			Common::VehiclePosVec result;
			for (int i = 0; i < this->geom_blocks.size(); i++)
			{
				Common::VehiclePosVec sub_result = this->geom_blocks[i].GetPoints(trajectory);
                result << sub_result;
			}
			return result;
		}

		//-------------------------------------------------

		/**
		 * Recalculates the chordline geometry of the road
		 */
		void RecalculateGeometry();

		//-------------------------------------------------
		// EVALUATION METHODS

		/**
		 * Geometry evaluation
		 */
		bool CheckGeometryInterval(double s_check);
		bool CheckGeometryInterval(double s_check, QString& roadId);
		int GetGeometryCoords(double s_check, double& retX, double& retY);
		int GetGeometryCoords(double s_check, double& retX, double& retY, double& retHDG);


		/**
		 * Other evaluation
		 */
		int CheckRoadTypeInterval(double s_check);
		QString GetRoadTypeValue(double s_check);

		int CheckElevationInterval(double s_check);
		double GetElevationValue(double s_check);

		int CheckSuperElevationInterval(double s_check);
		double GetSuperElevationValue(double s_check);

		int CheckCrossfallInterval(double s_check);
		void GetCrossfallValue(double s_check, double& angleLeft, double& angleRight);

		int CheckLaneSectionInterval(double s_check);
	};


}

#endif // __OPENDRIVE_ROAD_H__
