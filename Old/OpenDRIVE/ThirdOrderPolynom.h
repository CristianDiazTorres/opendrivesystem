#ifndef __OPENDRIVE_THIRDORDERPOLYNOM_H__
#define __OPENDRIVE_THIRDORDERPOLYNOM_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	 * Polynom of third order
	 *
	 */
    struct ThirdOrderPolynom
	{
		double s;
		double a;
		double b;
		double c;
		double d;

	public:
		/**
		 * Constructor that initializes the polynom with base properties
		 *
		 * @param s S offset
		 * @param a A parameter of the polynom
		 * @param b B parameter of the polynom
		 * @param c C parameter of the polynom
		 * @param d D parameter of the polynom
		 */
        ThirdOrderPolynom(double s, double a, double b, double c, double d)
        {
            this->s = s; this->a = a; this->b = b; this->c = c; this->d = d;
        }

        ThirdOrderPolynom(){}

        bool read(const Common::DomElement& node, const QString& s_name = "s")
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute(s_name, &this->s);
            checker += node.QueryDoubleAttribute("a", &this->a);
            checker += node.QueryDoubleAttribute("b", &this->b);
            checker += node.QueryDoubleAttribute("c", &this->c);
            checker += node.QueryDoubleAttribute("d", &this->d);

            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing attributes";
                return false;
            }

            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node, const QString& s_name = "s") const
        {
            Q_UNUSED(doc);
            node.setDoubleAttribute(s_name, this->s);
            node.setDoubleAttribute("a", this->a);
            node.setDoubleAttribute("b", this->b);
            node.setDoubleAttribute("c", this->c);
            node.setDoubleAttribute("d", this->d);
        }

		bool IsCompatible(CONST ThirdOrderPolynom& other) CONST
		{
			return this->s == other.s &&
				this->a == other.a &&
				this->b == other.b &&
				this->c == other.c &&
				this->d == other.d;
		}

        /**
         * Method to check if sample S is inside the record interval
         */
        bool CheckInterval(double s_check)
        {
            if (s_check >= this->s)
                return true;
            else
                return false;
        }

        /**
         * Returns the value at sample S
         */
        double GetValue(double s_check)
        {
            double ds = s_check - this->s;
            double value = this->a + this->b * ds + this->c * ds * ds + this->d * ds * ds * ds;
            return value;
        }
        //----------------------------------------------------------------------------------


	};
	//----------------------------------------------------------------------------------

}

#endif // __OPENDRIVE_THIRDORDERPOLYNOM_H__
