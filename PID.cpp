/**
 * @file PID.cpp
 * @brief PID Implementation
 * @author David Lee
 * @version 0.1
 * @date 2017-07-22
 */
#include "PID.h"
#include <iostream>
#include <cmath>

using namespace std;

PID::PID() : _pre_error(0), _integral(0){
	_Kp = DEF_KP;
	_Ki = DEF_KI;
	_Kd = DEF_KD;
	_dt = DEF_DT;
	_max = DEF_MAX;
	_min = DEF_MIN;
}

PID::PID(double Kp, double Ki, double Kd) : _pre_error(0), _integral(0){
	_Kp = Kp;
	_Ki = Ki;
	_Kd = Kd;
	_dt = DEF_DT;
	_max = DEF_MAX;
	_min = DEF_MIN;
}

PID::PID(double Kp, double Ki, double Kd, double dt, double max, double min) : _pre_error(0), _integral(0){
	_Kp = Kp;
	_Ki = Ki;
	_Kd = Kd;
	_dt = dt;
	_max = max;
	_min = min;
}

PID::~PID(){
}
	
void PID::SetParam(double Kp, double Ki, double Kd){
	_Kp = Kp;
	_Ki = Ki;
	_Kd = Kd;
}


/**
 * @brief 
 *
 * @param setpoint setpoint
 * @param pv current process value
 *
 * @return manipulated variable
 */
double PID::Calculate(double setpoint, double pv){
	// Calculate error
    double error = setpoint - pv;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * _dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Restrict to max/min
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    // Save error to previous error
    _pre_error = error;

    return output;
}

void PID::Debug(){
	printf("_Kp = %lf \n", _Kp);
	printf("_Ki = %lf \n", _Ki);
	printf("_Kd = %lf \n", _Kd);
	printf("_dt = %lf \n", _dt);
	printf("_max = %lf \n", _max);
	printf("_min = %lf \n", _min);
	printf("_pre_error = %lf \n", _pre_error);
	printf("_integral = %lf \n", _integral);
}
