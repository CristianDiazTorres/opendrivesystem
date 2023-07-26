#ifndef __OPENDRIVE_GEOMETRYBLOCK_H__
#define __OPENDRIVE_GEOMETRYBLOCK_H__

#include "OpenDRIVE/RoadGeometry.h"

namespace OpenDRIVE
{
	//----------------------------------------------------------------------------------
	/**
	 * GeometryBlock is a class used to combine multiple geometry records into blocks.
	 * The basic use for this is to combine spiral-arc-spiral sequence of records into
	 * a signel "Turn" block for an easier way to define turns, keeping close to the
	 * road building practice of curvature use for transitions between straight segments and arcs
	 */
    struct GeometryBlock
	{
		/**
		 * Vector of geometry records that make up a block
		 */
        QVector<RoadGeometry> road_geoms;

	public:

        bool read(Common::DomElement node, int blockType);
        void write(QDomDocument& doc, Common::DomElement& node) const;

		size_t GetGeometryCount() { return this->road_geoms.size(); }

		bool CheckPoint(double x, double y)
		{
			for (int i = 0; i < this->road_geoms.size(); i++)
			{
                if (this->road_geoms[i].CheckPoint(x, y))
					return true;
			}
			return false;
		}

		Common::VehiclePosVec GetPoints(Common::ConstVehiclePosVec& trajectory)
		{
			Common::VehiclePosVec result;

			for (int i = 0; i < this->road_geoms.size(); i++)
			{
                if (this->road_geoms[i].CheckPoint(trajectory))
				{
					result.resize(result.size() + 1);
                    result.back().x = this->road_geoms[i].x;
                    result.back().y = this->road_geoms[i].y;
				}
			}
			return result;
		}

		//-------------------------------------------------

        /**
         * Getter for the overal block length (summ of geometry record lengths)
         */
        double GetBlockLength();

		/**
		 *  Checks if the block is a straight line block or a turn
		 */
        bool CheckIfLine() const;

		//-------------------------------------------------

		/**
		 * Recalculates the geometry blocks when one of the geometry records is modified
		 * Makes sure that every geometry records starts where the previous record ends
		 */
		void Recalculate(double s, double x, double y, double hdg);

		//-------------------------------------------------

		/**
		 *  Evaluation methods
		 */
		double GetLastS2();

        int GetLastCoords(double& s, double& retX, double& retY, double& retHDG);
		bool CheckInterval(double s_check);
        int GetCoords(double s_check, double& retX, double& retY);
        int GetCoords(double s_check, double& retX, double& retY, double& retHDG);

	};

}

#endif // __OPENDRIVE_GEOMETRYBLOCK_H__
