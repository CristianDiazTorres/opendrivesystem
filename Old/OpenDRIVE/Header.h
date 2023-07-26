#ifndef __OPENDRIVE_HEADER_H__
#define __OPENDRIVE_HEADER_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	 * Class used to store the heading details of the OpenDRIVE file
	 */
	class Header
	{

		/**
		 * Base properties
		 */
        int rev_major;
        int rev_minor;
		QString name;
        float version;
        QString date;
        double north;
        double south;
        double east;
        double west;
	public:
		/**
		 * Constructor that initializes the base properties
		 */
        Header(){}
        Header(int rev_major, int rev_minor, QString name, float version, QString date,
                double north, double south, double east, double west)
        {
            this->rev_major = rev_major;
            this->rev_minor = rev_minor;
            this->name = name;
            this->version = version;
            this->date = date;
            this->north = north;
            this->south = south;
            this->east = east;
            this->west = west;

        }

        /**
         * The following methods are used to read the data from the XML file and fill in the the OpenDRIVE structure
         * Methods follow the hierarchical structure and are called automatically when ReadFile is executed
         */
        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryIntAttribute("revMajor", &rev_major);
            checker += node.QueryIntAttribute("revMinor", &rev_minor);
            checker += node.QueryStringAttribute("name", &name);
            checker += node.QueryFloatAttribute("version", &version);
            checker += node.QueryStringAttribute("date", &date);
            checker += node.QueryDoubleAttribute("north", &north);
            checker += node.QueryDoubleAttribute("south", &south);
            checker += node.QueryDoubleAttribute("east", &east);
            checker += node.QueryDoubleAttribute("west", &west);

            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Header attributes";
                return false;
            }
            return true;
        }

        /**
         * The following methods are used to create the XML representation of the OpenDRIVE structure
         * Methods follow the same hierarchical structure and are called automatically when WriteFile
         * is executed
         */
        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeHeader = doc.createElement("header");
            node.appendChild(nodeHeader);

            nodeHeader.setAttribute("revMajor", this->rev_major);
            nodeHeader.setAttribute("revMinor", this->rev_minor);
            nodeHeader.setAttribute("name", this->name);
            nodeHeader.setAttribute("version", QString::number(this->version, 'f', 2));
            nodeHeader.setAttribute("date", this->date);

            nodeHeader.setDoubleAttribute("north", this->north);
            nodeHeader.setDoubleAttribute("south", this->south);
            nodeHeader.setDoubleAttribute("east", this->east);
            nodeHeader.setDoubleAttribute("west", this->west);
        }
	};

}

#endif // __OPENDRIVE_HEADER_H__
