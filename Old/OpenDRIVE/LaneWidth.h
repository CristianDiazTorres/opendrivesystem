#ifndef __OPENDRIVE_LANEWIDTH_H__
#define __OPENDRIVE_LANEWIDTH_H__

#include "OpenDRIVE/ThirdOrderPolynom.h"

namespace OpenDRIVE
{
    /**
    * Lane width class. Holds all the data that describes a lane width
    *
    */
    struct LaneWidth : public ThirdOrderPolynom
    {
    public:

        /**
        * Constructor
        * @param s s-offset of the record starting from the lane section s-offset
        * @ param a,b,c,d The 4 parameters of the polynomial
        */
        LaneWidth(double s, double a, double b, double c, double d)
            : ThirdOrderPolynom (s, a, b, c, d)
        {
        }

        LaneWidth(){}

        bool read(const Common::DomElement& node)
        {
            return ThirdOrderPolynom::read(node, "sOffset");
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneWidth = doc.createElement("width");
            node.appendChild(nodeLaneWidth);

            ThirdOrderPolynom::write(doc, nodeLaneWidth, "sOffset");
        }
    };
}

#endif // __OPENDRIVE_LANEWIDTH_H__
