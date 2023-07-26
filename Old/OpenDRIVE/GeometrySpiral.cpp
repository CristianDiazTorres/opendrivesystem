#include "OpenDRIVE/GeometrySpiral.h"
#define _USE_MATH_DEFINES
#include <math.h>

//#define PI 3.14159265358979323846264338327950288
extern int fresnl(double, double*, double*);

namespace OpenDRIVE
{
	//***********************************************************************************
	//Spiral geometry
	//***********************************************************************************
	const double GeometrySpiral::sqrtPiO2 = sqrt(M_PI_2);
	/**
	 * Constructor that initializes the base properties of the record
	 */
    GeometrySpiral::GeometrySpiral(double s, double x, double y, double hdg, double length, double curvatureStart, double curvatureEnd)
        : RoadGeometry(2, s, x, y, hdg, length)
	{
		this->curvature_start = curvatureStart;
		this->curvature_end = curvatureEnd;
		ComputeVars();
	}

	/**
	 * Computes the required vars
	 */
    void GeometrySpiral::ComputeVarsDerived()
	{
		this->a = 0;

		//if the curvatureEnd is the non-zero curvature, then the motion is in normal direction along the spiral
		if ((fabs(this->curvature_end) > 1.00e-15) && (fabs(this->curvature_start) <= 1.00e-15))
		{
			this->normal_dir = true;
			this->curvature = this->curvature_end;
			//Calculate the normalization term : a = 1.0/sqrt(2*End_Radius*Total_Curve_Length) 
			this->a = 1.0 / sqrt(2 * 1.0 / fabs(double(this->curvature)) * this->length);
			//Denormalization Factor
			this->denormalize_factor = 1.0 / this->a;

			//Calculate the sine and cosine of the heading angle used to rotate the spiral according to the heading
			this->rot_cos = cos(this->hdg);
			this->rot_sin = sin(this->hdg);
		}
		//else the motion is in the inverse direction along the spiral
		else
		{
			this->normal_dir = false;
			this->curvature = this->curvature_start;
			//Calculate the normalization term : a = 1.0/sqrt(2*End_Radius*Total_Curve_Length) 
			this->a = 1.0 / sqrt(2 * 1.0 / fabs(this->curvature) * this->length);

			//Because we move in the inverse direction, we need to rotate the curve according to the heading
			//around the last point of the normalized spiral
			//Calculate the total length, normalize it and divide by sqrtPiO2, then, calculate the position of the final point.
			double L = (this->s2 - this->s) * this->a / sqrtPiO2;
			fresnl(L, &this->end_y, &this->end_x);
			//Invert the curve if the curvature is negative
			if (this->curvature < 0)
				this->end_y = -this->end_y;

			//Denormalization factor
			this->denormalize_factor = 1.0 / this->a;
			//Find the x,y coords of the final point of the curve in local curve coordinates
			this->end_x *= this->denormalize_factor * sqrtPiO2;
			this->end_y *= this->denormalize_factor * sqrtPiO2;

			//Calculate the tangent angle
			this->difference_angle = L * L * (sqrtPiO2 * sqrtPiO2);
			double diffAngle;
			//Calculate the tangent and heading angle difference that will be used to rotate the spiral
			if (this->curvature < 0)
			{
				diffAngle = this->hdg - this->difference_angle - M_PI;
			}
			else
			{
				diffAngle = this->hdg + this->difference_angle - M_PI;
			}

			//Calculate the sine and cosine of the difference angle
			this->rot_cos = cos(diffAngle);
			this->rot_sin = sin(diffAngle);
		}
	}

	//-------------------------------------------------
	/**
	 * Gets the coordinates at the sample S offset
	 */
    void GeometrySpiral::GetCoordsDerived(double s_check, double& retX, double& retY, double& retHDG)
	{
		double l = 0.0;
		double tmpX = 0.0, tmpY = 0.0;

		//Depending on the moving direction, calculate the length of the curve from its beginning to the current point and normalize
		//it by multiplying with the "a" normalization term
		//Cephes lib for solving Fresnel Integrals, uses cos/sin (PI/2 * X^2) format in its function.
		//So, in order to use the function, transform the argument (which is just L) by dividing it by the sqrt(PI/2) factor and multiply the results by it.
		if (this->normal_dir)
		{
			l = (s_check - this->s) * this->a / sqrtPiO2;
		}
		else
		{
			l = (this->s2 - s_check) * this->a / sqrtPiO2;
		}

		//Solve the Fresnel Integrals
		fresnl(l, &tmpY, &tmpX);
		//If the curvature is negative, invert the curve on the Y axis
		if (this->curvature < 0)
			tmpY = -tmpY;

		//Denormalize the results and multiply by the sqrt(PI/2) term
		tmpX *= this->denormalize_factor * sqrtPiO2;
		tmpY *= this->denormalize_factor * sqrtPiO2;

		//Calculate the heading at the found position. Kill the sqrt(PI/2) term that was added to the L
		l = (s_check - this->s) * this->a;
		double tangentAngle = l * l;
		if (this->curvature < 0)
			tangentAngle = -tangentAngle;
		retHDG = this->hdg + tangentAngle;


		if (!this->normal_dir)
		{
			//If we move in the inverse direction, translate the spiral in order to rotate around its final point
			tmpX -= this->end_x;
			tmpY -= this->end_y;
			//also invert the spiral in the y axis
			tmpY = -tmpY;
		}

		//Translate the curve to the required position and rotate it according to the heading
		retX = this->x + tmpX * this->rot_cos - tmpY * this->rot_sin;
		retY = this->y + tmpY * this->rot_cos + tmpX * this->rot_sin;
	}
}
