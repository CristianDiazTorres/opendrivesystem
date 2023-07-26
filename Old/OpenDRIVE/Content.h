#ifndef __OPENDRIVE_CONTENT_H__
#define __OPENDRIVE_CONTENT_H__

#include "OpenDRIVE/Header.h"
#include "OpenDRIVE/Road.h"
#include "OpenDRIVE/Junction.h"

namespace OpenDRIVE
{
	/**
	 * The main class in OpenDRIVE structure
	 * Holds the two vectors of the top-level records: ROAD and JUNCTION
	 * Has methods to add, get and delete those records
	 * From this class - one could get access to any record in OpenDRIVE structure
	 * going down the hierarchy
	 */
    struct Content
	{

		/**
		 * Header of the OpenDRIVE file
		 */
        Header header;

		/**
		 * Vectors used to store the top-level ROAD and JUNCTION records
		 */
		QVector<Road> roads;
		QVector<Junction> junctions;

		//-------------------------------------------------

	public:

        bool read(QString fileName);

        /**
         * Writes the data from the OpenDRIVE structure to a file
         */
        bool write(QString fileName) const;

		//-------------------------------------------------

		bool IsCompatible(CONST Content& other) CONST;

		void Fuse(CONST Content& other);

		bool CheckPoint(double x, double y)
		{
			for (int i = 0; i < this->roads.size(); i++)
			{
				if (this->roads[i].CheckPoint(x, y))
					return true;
			}
			return false;
		}

		Common::VehiclePosVec GetPoints(Common::ConstVehiclePosVec& trajectory)
		{
			Common::VehiclePosVec result;
			for (int i = 0; i < this->roads.size(); i++)
			{
				Common::VehiclePosVec sub_result = this->roads[i].GetPoints(trajectory);
                result << sub_result;
			}
			return result;
		}

	};

	typedef CONST Content		ConstContent;

}

#endif // __OPENDRIVE_CONTENT_H__
