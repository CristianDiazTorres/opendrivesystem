#ifndef __OPENDRIVE_ROADGEOMETRY_H__
#define __OPENDRIVE_ROADGEOMETRY_H__

#include "Common/VehiclePos.h"

namespace OpenDRIVE
{
	/**
	 * RoadGeometry class is responsible for storing the basic chordline geometry properties
	 *
	 */
    struct RoadGeometry
	{
        /**
		 * Base record properties
		 */
        int geom_type;	//-1-unknown, 0-line, 1-arc, 2-spiral, 3-poly3

		double s;
		double x;
		double y;
		double hdg;
		double length;
		double s2;

        double dbl_shared[10];
        bool bool_shared[1];

	public:
        /**
         * Constructor that initializes the base properties of teh record
         */
        RoadGeometry(int geom_type, double s, double x, double y, double hdg, double length)
        {
            this->geom_type = geom_type;
            this->s = s;
            this->x = x;
            this->y = y;
            this->hdg = hdg;
            this->length = length;
            this->s2 = s + length;
        }

        RoadGeometry(){}

        bool read(const Common::DomElement& node);

        void write(QDomDocument& doc, Common::DomElement& node) const;

        //-------------------------------------------------

		bool CheckPoint(double x, double y)
		{
			return fabs(this->x - x) < 1 && fabs(this->y - y) < 1;
		}

		bool CheckPoint(Common::ConstVehiclePosVec& trajectory)
		{
			for (int i = 0; i < trajectory.size(); i++)
			{
				if (CheckPoint(trajectory[i].x, trajectory[i].y))
					return true;
			}
			return false;
		}

        /**
         * Setter for the base properties
         */
        void SetBase(double s, double x, double y, double hdg, double length, bool recalculate = true)
        {
            this->s = s;
            this->x = x;
            this->y = y;
            this->hdg = hdg;
            this->length = length;
            this->s2 = this->s + this->length;
            if (recalculate) ComputeVars();
        }

		//-------------------------------------------------

		/**
		 * Evaluation methods
		 */
        /**
         * Checks if the sample S gets in the current block interval
         */
        bool CheckInterval(double s_check)
        {
            if ((s_check >= this->s) && (s_check <= this->s2))
                return true;
            else
                return false;
        }

        /**
         * Gets the coordinates at the sample S offset
         */
        void GetCoords(double s_check, double& retX, double& retY)
        {
            double tmp;
            GetCoords(s_check, retX, retY, tmp);
        }
        void GetCoords(double s_check, double& retX, double& retY, double& retHDG);

        /**
         * Computes the required vars
         */
        void ComputeVars();
	};

}

#endif // __OPENDRIVE_ROADGEOMETRY_H__
