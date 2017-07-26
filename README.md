# Three Axis Stabilizer

## Introduction

The three axis stabilizer project that DIY from the very beginning.

The main concept is PID control. To minimum the vibration of moving camera.

## Material Preparation

	* MCU - Arduino Nano
	* 3D Printing Model
	* 3 axis accelerometer sensor * 3 - 
	* Servo Motor * 3 - 

## File Description

* MCU - Arduino
	* ThreeAxisGimbal.ino
* PID Algorithm
	* PID Class
		* PID.cpp
		* PID.h
	* Test Code
		* pid_test.cpp
		* Makefile
			* `make` - compile pid_test.cpp
			* `make clean` - remove execution file
* Motor PID Control
	* MotorPID.cpp
	* MotorPID.h
* GY-80 Sensor
	* ADXL345.cpp
	* ADXL345.h

## Contributor
* David Lee
* 
