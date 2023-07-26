#include "OpenDRIVE/GeometryLine.h"

namespace OpenDRIVE
{
	//***********************************************************************************
	//Line geometry 
	//***********************************************************************************
	/**
	 * Constructor that initializes the base properties of the record
	 */
    GeometryLine::GeometryLine(double s, double x, double y, double hdg, double length)
        : RoadGeometry(0, s, x, y, hdg, length)
	{
	}

	//-------------------------------------------------

	/**
	 * Gets the coordinates at the sample S offset
	 */
    void GeometryLine::GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG)
	{
		double newLength = s_check - this->s;
		//find the end of the chord line
		retX = this->x + cos(this->hdg) * newLength;
		retY = this->y + sin(this->hdg) * newLength;

		retHDG = this->hdg;
	}


}
