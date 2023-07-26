#ifndef __OPENDRIVE_OBJECT_H__
#define __OPENDRIVE_OBJECT_H__

#include "Common/Common.h"

namespace OpenDRIVE
{

	//***********************************************************************************
	//Object
	//***********************************************************************************
    struct Object
	{
        double t;
        double zOffset;

        //none, obstacle, pole, tree, vegetation, barrier,
        //building, parkingSpace, patch, railing, trafficIsland,
        //crosswalk, streetLamp, gantry, soundBarrier, roadMark
        QString type; // optional

        double validLength;// optional
        QString orientation;// optional
        QString subtype;// optional
        bool dynamic;// optional
        double hdg;// optional
        QString name;// optional
        double pitch;// optional
        QString id;// optional
        double roll;// optional
        double height;// optional
        double s;
        double length;// optional
        double width;// optional
        double radius;// optional

	public:
        Object(double t, double zOffset, double s)
        {
            this->t = t;
            this->zOffset = zOffset;
            this->s = s;
        }
        Object(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("t", &this->t);
            checker += node.QueryDoubleAttribute("zOffset", &this->zOffset);
            checker += node.QueryStringAttribute("type", &this->type);
            checker += node.QueryStringAttribute("name", &this->name);
            checker += node.QueryDoubleAttribute("s", &this->s);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Object attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeObject = doc.createElement("object");
            node.appendChild(nodeObject);

            nodeObject.setDoubleAttribute("t", this->t);
            nodeObject.setDoubleAttribute("zOffset", this->zOffset);

            if (!this->type.isEmpty())
                nodeObject.setAttribute("type", this->type);

            if (!this->name.isEmpty())
                nodeObject.setAttribute("name", this->name);

            nodeObject.setDoubleAttribute("s", this->s);
        }
	};

}

#endif // __OPENDRIVE_OBJECT_H__
