#ifndef __OPENDRIVE_SURFACE_H__
#define __OPENDRIVE_SURFACE_H__

#include "Common/Common.h"

namespace OpenDRIVE
{

	//***********************************************************************************
    //Surface
	//***********************************************************************************
    struct Surface
	{
	public:
        bool read(const Common::DomElement& node)
        {
            Q_UNUSED(node);
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeSurface = doc.createElement("surface");
            node.appendChild(nodeSurface);
        }
	};

}

#endif // __OPENDRIVE_SURFACE_H__
