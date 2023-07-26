#include "OpenDRIVE/GeometryArc.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace OpenDRIVE
{

	//***********************************************************************************
	//Arc geometry
	//***********************************************************************************
	/**
	 * Constructor that initializes the base properties of the record
	 */
    GeometryArc::GeometryArc(double s, double x, double y, double hdg, double length, double curvature)
        : RoadGeometry(1, s, x, y, hdg, length)
	{
		this->curvature = curvature;

		ComputeVars();
	}

	/**
	 * Computes the required vars
	 */
    void GeometryArc::ComputeVarsDerived()
	{
		double radius = 0.0;
		//if curvature is 0, radius is also 0, otherwise, radius is 1/curvature
		if (fabs(this->curvature) > 1.00e-15)
		{
			radius = fabs(1.0 / this->curvature);
		}
		//calculate the start angle for the arc plot
		if (this->curvature <= 0)
			this->start_angle = this->hdg + M_PI_2;
		else
			this->start_angle = this->hdg - M_PI_2;

		this->circle_x = this->x + cos(this->start_angle - M_PI) * radius;
		this->circle_y = this->y + sin(this->start_angle - M_PI) * radius;
	}

	//-------------------------------------------------

	/**
	 * Gets the coordinates at the sample S offset
	 */
    void GeometryArc::GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG)
	{
		//s from the beginning of the segment
		double currentLength = s_check - this->s;
		double endAngle = this->start_angle;
		double radius = 0.0;
		//if curvature is 0, radius is also 0, so don't add anything to the initial radius, 
		//otherwise, radius is 1/curvature so the central angle can be calculated and added to the initial direction
		if (fabs(this->curvature) > 1.00e-15)
		{
			endAngle += currentLength / (1.0 / this->curvature);
			radius = fabs(1.0 / this->curvature);
		}

		//coords on the arc for given s value
		retX = this->circle_x + cos(endAngle) * radius;
		retY = this->circle_y + sin(endAngle) * radius;

		//heading at the given position
		if (this->curvature <= 0)
			retHDG = endAngle - M_PI_2;
		else
			retHDG = endAngle + M_PI_2;
	}

}
