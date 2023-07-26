#ifndef __OPENDRIVE_GEOMETRYLINE_H__
#define __OPENDRIVE_GEOMETRYLINE_H__

#include "OpenDRIVE/RoadGeometry.h"

namespace OpenDRIVE
{
	//----------------------------------------------------------------------------------
	/**
	 * GeometryLine inherits the RoadGeometry class but adds no additional properties
	 *
	 */
    struct GeometryLine : public RoadGeometry
	{
	public:
		/**
		 * Constructor that initializes the base properties of the record
		 */
		GeometryLine(double s, double x, double y, double hdg, double length);
        GeometryLine(){}

		//-------------------------------------------------

        bool readDerived(const Common::DomElement& node)
        {
            Q_UNUSED(node);
            return true;
        }

        void writeDerived(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLine = doc.createElement("line");
            node.appendChild(nodeLine);
        }

		/**
		 * Gets the coordinates at the sample S offset
		 */
        void GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG);

        /**
         * Computes the required vars
         */
        void ComputeVarsDerived(){}
	};

}

#endif // __OPENDRIVE_GEOMETRYLINE_H__
