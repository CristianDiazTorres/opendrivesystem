#ifndef __OPENDRIVE_GEOMETRYSPIRAL_H__
#define __OPENDRIVE_GEOMETRYSPIRAL_H__

#include "OpenDRIVE/RoadGeometry.h"

namespace OpenDRIVE
{


	//----------------------------------------------------------------------------------
	/**
	 * GeometrySpiral inherits the RoadGeometry class and adds Curvature properties
	 *
	 */
    struct GeometrySpiral : public RoadGeometry
	{
        static const double sqrtPiO2;

		/**
		 * Base record properties
		 */
        double& curvature_start = dbl_shared[0];
        double& curvature_end = dbl_shared[1];

		/**
		 * Computation variables
		 */

        double& a = dbl_shared[2];
        double& curvature = dbl_shared[3];
        double& denormalize_factor = dbl_shared[4];
        double& end_x = dbl_shared[5];
        double& end_y = dbl_shared[6];
        bool& normal_dir = bool_shared[0];

        double& difference_angle = dbl_shared[7];
        double& rot_cos = dbl_shared[8];
        double& rot_sin = dbl_shared[9];

	public:
		/**
		 * Constructor that initializes the base properties of the record
		 */
		GeometrySpiral(double s, double x, double y, double hdg, double length, double curvatureStart, double curvatureEnd);
        GeometrySpiral(){}

		//-------------------------------------------------

        bool readDerived(const Common::DomElement& node)
        {
            Common::DomElement subNode = node.firstChildElement();
            int checker = DOM_SUCCESS;
            checker += subNode.QueryDoubleAttribute("curvStart", &this->curvature_start);
            checker += subNode.QueryDoubleAttribute("curvEnd", &this->curvature_end);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing spiral attributes";
                return false;
            }
            return true;
        }

        void writeDerived(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeSpiral = doc.createElement("spiral");
            node.appendChild(nodeSpiral);

            nodeSpiral.setDoubleAttribute("curvStart", this->curvature_start);
            nodeSpiral.setDoubleAttribute("curvEnd", this->curvature_end);
        }

		/**
		 * Gets the coordinates at the sample S offset
		 */
        void GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG);


		/**
		 * Computes the required vars
		 */
        void ComputeVarsDerived();
	};
}

#endif // __OPENDRIVE_GEOMETRYSPIRAL_H__
