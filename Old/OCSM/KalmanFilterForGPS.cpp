#include "OCSM/KalmanFilterForGPS.h"
#include "Common/QMatrix4x4D.h"
#include <math.h>

namespace OCSM
{
    template <int N, int M>
    void SetMatrixElements(QGenericMatrix<N, M, double>& mat, double* data)
    {
        mat = QGenericMatrix<N, M, double>(data);
    }

	void KalmanFilterForGPS::Intialize(double t0, double x0, double y0, double vx0, double vy0, double hdop, double /*velocity_measure_error*/)
	{
		dt = -1;

        double x_elems[] = {x0, y0, vx0, vy0};
        SetMatrixElements(X, x_elems);

		ti = t0;

		// initialize the states and input coefficients matrix
        double a_elems[] = {1, 0, t0, 0, 0, 1, 0, t0, 0, 0, 1, 0, 0, 0, 0, 1};
        SetMatrixElements(A, a_elems);

        double b_elems[] = {0.5 * t0 * t0, 0, 0, 0.5 * t0 * t0, t0, 0, 0, t0};
        SetMatrixElements(B, b_elems);

		// errors coefficients matrix
        double p_elems[] = {500, 0, 0, 0, 0, 500, 0, 0, 0, 0, 100, 0, 0, 0, 0, 100};
        SetMatrixElements(P, p_elems);

        K.fill(0);

		// noise model
		//R << hdop,0,0,0,0,hdop,0,0,0,0,velocity_measure_error,0,0,0,0,velocity_measure_error;
		//Z.setRandom();
		//Q.setRandom();
		//Z*=0.1;
		//Q*=0.1;

        double r_elems[] = {hdop, 0, 0, 0, 0, hdop, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
        SetMatrixElements(R, r_elems);

        double q_elems[] = {sqrt(hdop), 0, 0, 0, 0, sqrt(hdop), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
        SetMatrixElements(Q, q_elems);

		//Q=EigenMatrix<double,4,4>::Identity();
	}

	DoubleVec KalmanFilterForGPS::Predict(double t, double x, double y, double vx, double vy, double ax, double ay)
	{
		/*
		* kalman filter algo goes here
		*/

		// fill A,B if dt changes
		if (dt != (t - ti)) // if the new interval equal the old why update A,B
		{
			dt = t - ti;
			ti = t; // get the new interval

            double a_elems[] = {1, 0, dt, 0, 0, 1, 0, dt, 0, 0, 1, 0, 0, 0, 0, 1};
            SetMatrixElements(A, a_elems);

            double b_elems[] = {0.5 * dt * dt, 0, 0, 0.5 * dt * dt, dt, 0, 0, dt};
            SetMatrixElements(B, b_elems);
		}

		/*
		* update measurement + input
		*/
        double xm_elems[] = {x, y, vx, vy};
        SetMatrixElements(Xm, xm_elems);

        double u_elems[] = {ax, ay};
        SetMatrixElements(U, u_elems);

		/*
		* kalman algo starts here
		*/

		// predicted state X(i)=A*X(i-1)+B*U(i)+W;
		Xp = A * X + B * U/*+W*/;

        // predicted covariance P(i)=A*X(i-1)P^(-1)+Q;
        P = (A * P) * A.transposed() + Q;

        // measurment Input
		Y = Xm;//+Z;

        // kalman gain
        K = P * QMatrix4x4D(P + R).inverted().toGenericMatrix<4, 4>();

        // update states
		X = Xp + K * (Y - Xp);

        // update covariance
        P = (QGenericMatrix<4, 4, double>() - K) * P;

		DoubleVec result(4);
		result[0] = X(0, 0);
		result[1] = X(1, 0);
		result[2] = X(2, 0);
		result[3] = X(3, 0);
		return result;

		// next iteration for Xm,U
	}

}
