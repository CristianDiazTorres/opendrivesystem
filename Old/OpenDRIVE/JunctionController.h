#ifndef __OPENDRIVE_JUNCTIONCONTROLLER_H__
#define __OPENDRIVE_JUNCTIONCONTROLLER_H__

#include "Common/Common.h"

namespace OpenDRIVE
{

	/**
	 * Junction controller class. Holds all the information for a priority record
	 */
    struct JunctionController
	{

		/**
		 * Record parameters
		 */
        QString id;
		QString type;

	public:
		/**
		 * Constructor. Initializes the parameters
		 * @param id ID of the controller to add
		 * @param type Type of control
		 */
		JunctionController(QString id, QString type);
        JunctionController(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryStringAttribute("id", &this->id);
            checker += node.QueryStringAttribute("type", &this->type);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Junction Controller attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeJunctionController = doc.createElement("controller");
            node.appendChild(nodeJunctionController);

            nodeJunctionController.setAttribute("id", this->id);
            nodeJunctionController.setAttribute("type", this->type);
        }
	};

}

#endif // __OPENDRIVE_JUNCTIONCONTROLLER_H__
