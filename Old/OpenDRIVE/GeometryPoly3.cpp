#include "OpenDRIVE/GeometryPoly3.h"
#define _USE_MATH_DEFINES
#include <math.h>

//#define PI 3.14159265358979323846264338327950288
extern int fresnl(double, double*, double*);

namespace OpenDRIVE
{
	//***********************************************************************************
	//Cubic Polynom geometry. Has to be implemented
	//***********************************************************************************
	/**
	 * Constructor that initializes the base properties of the record
	 */
    GeometryPoly3::GeometryPoly3(double s, double x, double y, double hdg, double length, double a, double b, double c, double d)
        : RoadGeometry(3, s, x, y, hdg, length)
	{
        this->a = a; this->b = b; this->c = c; this->d = d;
	}

}
