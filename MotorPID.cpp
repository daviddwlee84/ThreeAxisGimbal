/**
 * @file MotorPID.cpp
 * @brief Manipulate Three Axis Motors' PID
 * @author David Lee
 * @version 0.1
 * @date 2017-07-22
 */
#include "MotorPID.h"
#include "iostream"

MotorPID::MotorPID(){
	new pPIDX = PID();
	new pPIDY = PID();
	new pPIDZ = PID();
}

MotorPID::MotorPID(double Kp, double Ki, double Kd){
	new pPIDX = PID(Kp, Ki, Kd);
	new pPIDY = PID(Kp, Ki, Kd);
	new pPIDZ = PID(Kp, Ki, Kd);
}

MotorPID::MotorPID(double Kp, double Ki, double Kd, double dt, double max, double min){
	new pPIDX = PID(Kp, Ki, Kd, dt, max, min);
	new pPIDY = PID(Kp, Ki, Kd, dt, max, min);
	new pPIDZ = PID(Kp, Ki, Kd, dt, max, min);
}

void MotorPID::ZeroCalib(double X, double Y, double Z){
	_defX = X;
	_defY = Y;
	_defZ = Z;
}

void MotorPID::SetZero(double X, double Y, double Z){
	_refX = X;
	_refY = Y;
	_refZ = Z;
}

void MotorPID::ReturnDefZero(){
	_refX = _defX;
	_refY = _defY;
	_refZ = _defZ;
}


double XRespon, YRespon, ZRespon;
