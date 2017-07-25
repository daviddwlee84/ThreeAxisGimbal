/**
 * @file PID.h
 * @brief Define PID class structure
 * @author David Lee
 * @version 0.1
 * @date 2017-07-22
 */
#ifndef PID_H
#define PID_H

#define DEF_KP 0.1
#define DEF_KI 0.5
#define DEF_KD 0.01

#define DEF_DT 0.1
#define DEF_MAX 100
#define DEF_MIN -100

class PID{
	private:
		double _Kp;		// Proportional gain
		double _Ki;		// Integral gain
		double _Kd;		// Derivative gain
		double _dt;		// Loop interval time
		double _max;	// Maximum value of manipulated variable
		double _min;	// Minimum value of manipulated variable

		double _pre_error;
        double _integral;


	public:

		PID(); 
		PID(double Kp, double Ki, double Kd);
		PID(double Kp, double Ki, double Kd, double dt, double max, double min);
		~PID();

		void SetParam(double Kp, double Ki, double Kd);
		double Calculate(double setpoint, double pv);

		void Debug(void);
};

#endif

