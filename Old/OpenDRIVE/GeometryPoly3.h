#ifndef __OPENDRIVE_GEOMETRYPOLY3_H__
#define __OPENDRIVE_GEOMETRYPOLY3_H__

#include "OpenDRIVE/RoadGeometry.h"

namespace OpenDRIVE
{

	//----------------------------------------------------------------------------------
	/**
	 * GeometryPoly3 inherits the RoadGeometry class and adds polynomial properties
	 *
	 */
    struct GeometryPoly3 : public RoadGeometry
	{
		/**
		 * Base record properties
		 */
        double& a = dbl_shared[0];
        double& b = dbl_shared[1];
        double& c = dbl_shared[2];
        double& d = dbl_shared[3];

	public:
		/**
		 * Constructor that initializes the base properties of the record
		 */
		GeometryPoly3(double s, double x, double y, double hdg, double length, double a, double b, double c, double d);

        bool readDerived(const Common::DomElement& node)
        {
            Common::DomElement subNode = node.firstChildElement();
            int checker = DOM_SUCCESS;
            checker += subNode.QueryDoubleAttribute("a", &a);
            checker += subNode.QueryDoubleAttribute("b", &b);
            checker += subNode.QueryDoubleAttribute("c", &c);
            checker += subNode.QueryDoubleAttribute("d", &d);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing arc attributes";
                return false;
            }
            return true;
        }

        void writeDerived(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLine = doc.createElement("poly3");
            node.appendChild(nodeLine);

            node.setDoubleAttribute("a", this->a);
            node.setDoubleAttribute("b", this->b);
            node.setDoubleAttribute("c", this->c);
            node.setDoubleAttribute("d", this->d);
        }

        /**
         * Gets the coordinates at the sample S offset
         */
        void GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG)
        {
            Q_UNUSED(s_check);
            Q_UNUSED(retX);
            Q_UNUSED(retY);
            Q_UNUSED(retHDG);
        }

        /**
         * Computes the required vars
         */
        void ComputeVarsDerived(){}
	};

}

#endif // __OPENDRIVE_GEOMETRYPOLY3_H__
