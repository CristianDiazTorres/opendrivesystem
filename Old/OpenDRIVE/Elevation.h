#ifndef __OPENDRIVE_ELEVATION_H__
#define __OPENDRIVE_ELEVATION_H__

#include "OpenDRIVE/ThirdOrderPolynom.h"

namespace OpenDRIVE
{
	//----------------------------------------------------------------------------------
	/**
	 * Elevation class is used to store information about a road elevation record
	 * It inherits the Polynom class and has no additional properties
	 *
	 *
	 *
	 */
    struct Elevation : public ThirdOrderPolynom
	{
	public:
		/**
		 * Constructor which intializes the base properties
		 */
        Elevation(double s, double a, double b, double c, double d)
            : ThirdOrderPolynom(s, a, b, c, d)
        {
        }

        Elevation(){}

        //bool read(const Common::DomElement& node);

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeElevation = doc.createElement("elevation");
            node.appendChild(nodeElevation);

            ThirdOrderPolynom::write(doc, nodeElevation);
        }
	};


}

#endif // __OPENDRIVE_ELEVATION_H__
