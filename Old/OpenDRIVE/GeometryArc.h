#ifndef __OPENDRIVE_GEOMETRYARC_H__
#define __OPENDRIVE_GEOMETRYARC_H__

#include "OpenDRIVE/RoadGeometry.h"

namespace OpenDRIVE
{

	/**
	 * GeometryArc inherits the RoadGeometry class and adds Curvature property
	 *
	 */
    struct GeometryArc : public RoadGeometry
	{

		/**
		 * Base record properties
		 */
        double& curvature = dbl_shared[0];

		/**
		 * Optimization related variables
		 */
        double& circle_x = dbl_shared[1];
        double& circle_y = dbl_shared[2];

		/**
		 * Computation variables
		 */
        double& start_angle = dbl_shared[3];

	public:
		/**
		 * Constructor that initializes the base properties of the record
		 */
		GeometryArc(double s, double x, double y, double hdg, double length, double curvature);
        GeometryArc(){}

		//-------------------------------------------------

        bool readDerived(const Common::DomElement& node)
        {
            Common::DomElement subNode = node.firstChildElement();
            int checker = DOM_SUCCESS;
            checker += subNode.QueryDoubleAttribute("curvature", &this->curvature);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing arc attributes";
                return false;
            }
            return true;
        }

        void writeDerived(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeArc = doc.createElement("arc");
            node.appendChild(nodeArc);

            nodeArc.setDoubleAttribute("curvature", this->curvature);
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

#endif // __OPENDRIVE_GEOMETRYARC_H__
