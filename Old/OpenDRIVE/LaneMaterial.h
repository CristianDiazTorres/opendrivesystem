#ifndef __OPENDRIVE_LANEMATERIAL_H__
#define __OPENDRIVE_LANEMATERIAL_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
    /**
    * Lane material class. Contains all the data that describes a lane material
    */
    struct LaneMaterial
    {

        /*
        * Parameters that describe the lane material
        */
        double s_offset;
        QString surface;
        double friction;
        double roughness;
    public:

        /*
        * Constructor
        */
        LaneMaterial(double sOffset, QString surface, double friction, double roughness)
        {
            this->s_offset = sOffset;
            this->surface = surface;
            this->friction = friction;
            this->roughness = roughness;
        }

        LaneMaterial(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryStringAttribute("surface", &this->surface);
            checker += node.QueryDoubleAttribute("friction", &this->friction);
            checker += node.QueryDoubleAttribute("roughness", &this->roughness);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneMaterial = doc.createElement("material");
            node.appendChild(nodeLaneMaterial);

            nodeLaneMaterial.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneMaterial.setAttribute("surface", this->surface);
            nodeLaneMaterial.setDoubleAttribute("friction", this->friction);
            nodeLaneMaterial.setDoubleAttribute("roughness", this->roughness);
        }

        bool IsCompatible(CONST LaneMaterial& other) CONST
        {
            return this->s_offset == other.s_offset &&
                this->surface == other.surface &&
                this->friction == other.friction &&
                this->roughness == other.roughness;
        }

    };

}

#endif // __OPENDRIVE_LANEMATERIAL_H__
