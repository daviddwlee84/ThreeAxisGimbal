/**
 * @file MotorPID.h
 * @brief Define MotorPID class structure
 * @author David Lee
 * @version 0.1
 * @date 2017-07-22
 */
#ifndef MOTORPID_H
#define MOTORPID_H

#include "PID.h"

class MotorPID{
	private:

		// Reference G-Sensor Value
		double _refX;
		double _refY;
		double _refZ;

		// Initial G-Sensor Value
		double _defX;
		double _defY;
		double _defZ;

		PID *pPIDX;
		PID *pPIDY;
		PID *pPIDZ;

	public:

		MotorPID();
		MotorPID(double Kp, double Ki, double Kd);
		MotorPID(double Kp, double Ki, double Kd, double dt, double max, double min);
		~MotorPID();

		double XRespon(double X, double Y, double Z);
		double YRespon(double X, double Y,double Z);
		double ZRespon(double X, double Y,double Z);

		void ZeroCalib(double X, double Y,double Z);
		void SetZero(double X, double Y, double Z);
		void ReturnDefZero(void);
}

#endif

