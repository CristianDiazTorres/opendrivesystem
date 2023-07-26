#ifndef __OPENDRIVE_CROSSFALL_H__
#define __OPENDRIVE_CROSSFALL_H__

#include "OpenDRIVE/ThirdOrderPolynom.h"

namespace OpenDRIVE
{

	/**
	 * Crossfall class is used to store information about a road superelevation record
	 * It inherits the Polynom class and has one additional properties
	 *
	 *
	 *
	 */
    struct Crossfall : public ThirdOrderPolynom
	{

		/**
		 * Base crossfall property
		 */
        QString side;

	public:
		/**
		 * Constructor which intializes the base properties
		 */
        Crossfall(QString side, double s, double a, double b, double c, double d)
            : ThirdOrderPolynom(s, a, b, c, d)
        {
            this->side = side;
        }

        Crossfall(){}

        bool read(const Common::DomElement& node)
        {
            if (!ThirdOrderPolynom::read(node))
                return false;

            int checker = DOM_SUCCESS;
            checker += node.QueryStringAttribute("side", &side);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Crossfall attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeCrossfall = doc.createElement("crossfall");
            node.appendChild(nodeCrossfall);

            ThirdOrderPolynom::write(doc, nodeCrossfall);
            nodeCrossfall.setAttribute("side", side);
        }

		bool IsCompatible(CONST Crossfall& other) CONST
		{
			return ThirdOrderPolynom::IsCompatible(other) &&
                this->side == other.side;
		}
	};

	//----------------------------------------------------------------------------------

}

#endif // __OPENDRIVE_CROSSFALL_H__
