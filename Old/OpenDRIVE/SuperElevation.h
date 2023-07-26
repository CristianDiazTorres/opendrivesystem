#ifndef __OPENDRIVE_SUPERELEVATION_H__
#define __OPENDRIVE_SUPERELEVATION_H__

#include "OpenDRIVE/ThirdOrderPolynom.h"

namespace OpenDRIVE
{
    /**
     * Superlevation class is used to store information about a road superelevation record
     * It inherits the Polynom class and has no additional properties
     *
     *
     *
     */
    struct SuperElevation : public ThirdOrderPolynom
    {
    public:
        /**
         * Constructor which intializes the base properties
         */
        SuperElevation(double s, double a, double b, double c, double d) : ThirdOrderPolynom(s, a, b, c, d)
        {
        }

        SuperElevation(){}

        //bool read(const Common::DomElement& node);

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeSuperElevation = doc.createElement("superelevation");
            node.appendChild(nodeSuperElevation);

            ThirdOrderPolynom::write(doc, nodeSuperElevation);
        }
    };
}

#endif // __OPENDRIVE_SUPERELEVATION_H__
