#ifndef __OCSM_KALMANFILTERFORGPS_H__
#define __OCSM_KALMANFILTERFORGPS_H__

/*
 * This function is coded to reduce the GPS error of a car
 * given its GPS(from multi satalites) and its position
 * from other LiDARs if given
 */

#include "Common/Common.h"
#include <QGenericMatrix>

namespace OCSM
{

	/*
	 * for farther details you may refere to :
	 * 1- https://blog.maddevs.io/reduce-gps-data-error-on-android-with-kalman-filter-and-accelerometer-43594faed19c
	 * 2- https://pdfs.semanticscholar.org/0b93/eb84ff2f48ea8d9e2770e4b45d30609095b1.pdf
	 */

	 // NOTES to reader
	 /*
	 * SEE LAST LINE of the header to understand the input represntation
	 * use EIGEN3 library (it's a must)
	 * if you can make the GPS readings in Eigen QVector format I'd be happy
	 * if not I'll handle the convertion or you can replace it with for loop
	 */

	class KalmanFilterForGPS
	{
	private:
		double dt = -1; /*time can't be neg- thus will always initialize if (line 124)*/
		double ti;

		/*
		 * Our state space model taken from motion equations
		 * X(i)= AX(i-1) + BU + W (matrix format)
		 * x(t+dt)= x(t)+ t v(dt) + 0.05 t^2 a(dt)
		 */

        QGenericMatrix<4, 4, double> K, P, A;
        QGenericMatrix<2, 4, double> B;
        QGenericMatrix<1, 4, double> X, Xp, Xm, Y;
        QGenericMatrix<1, 2, double> U;
        //QGenericMatrix<4, 2, double> H;
		/*
		 * A: zero input / state response
		 * B: zero state / input response
		 * X: state(updated)
		 * Xm: states(measured)
		 * Xp: states(predicted)
		 * Y: states(measured)
		 * U: accelaration input
		 * States are position and velocity
		 * K: kalman gain
		 * P: covariance matrix
		 */

		 /*
		  * Errors and noises of the Kalman
		  */
        QGenericMatrix<4, 4, double> R; // covariance of observation noise
        QGenericMatrix<4, 4, double> Q; // covariance of process(algorthem) noise
        //QGenericMatrix<1, 4, double> Z; // covariance of observation(measuremnt) error
        //QGenericMatrix<1, 4, double> W; // covariance of prediction error

		/*
		 * Statistics (for future use)
		 * row:1 GPSx, row:2 GPSy row:3 speed.
		 */
         //QGenericMatrix<2, 2, double> MEANS; // readings means
         //QGenericMatrix<2, 2, double> VARS; // readings variances

	public:
		void Intialize(double t0, double x0, double y0,
			double vx0, double vy0,
			double hdop, double velocity_measure_error = 0 /* unused */);

		// next estimation
		DoubleVec Predict(double t, double x, double y,
			double vx, double vy,
			double ax, double ay);
	};

	/*
	 * Input Understanding
	 * 1 time step
	 * 0 0 initial position x y
	 * 0 0 initial velocity x y
	 * 2 0 acceleration x y
	 * 5 5 GPS measurement error
	 * 1 1 veocity measurement error
	 * 4 number if readings (multi satalites)
	 * 0 0 1 0 0 2 0 GPS x y SPEED x y Acce x y
	 * .... to end of readings
	 *
	 * check the output file too
	 */

}

#endif // __OCSM_KALMANFILTERFORGPS_H__
