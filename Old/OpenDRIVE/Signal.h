#ifndef __OPENDRIVE_SIGNAL_H__
#define __OPENDRIVE_SIGNAL_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	//***********************************************************************************
	//Signal
	//***********************************************************************************
    struct Signal
	{
	public:
        bool read(const Common::DomElement& node)
        {
            Q_UNUSED(node);
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Q_UNUSED(doc);
            Q_UNUSED(node);
        }
	};
	//----------------------------------------------------------------------------------

}

#endif // __OPENDRIVE_SIGNAL_H__
