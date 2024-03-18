///*
// * calculate_angle.h
// *
// *  Created on: Feb 18, 2024
// *      Author: simaalaverdyan
// */
//
#ifndef INC_CALCULATE_ANGLE_H_
#define INC_CALCULATE_ANGLE_H_

#define RADIAN_TO_DEGREE 180/M_PI
#include "mpu.h"
#include <math.h>

typedef struct _Angle{
	float acc_roll;
	float acc_pitch;
	float acc_yaw;

	float gyro_roll;
	float gyro_pitch;
	float gyro_yaw;

	float roll;
	float pitch;
	float yaw;
}	Angle_t;


extern Angle_t Angle;

void CalculateAccAngle(Angle_t* Angle, MPU6050_t* MPU6050);

#endif /* INC_CALCULATE_ANGLE_H_ */
