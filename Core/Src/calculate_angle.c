///*
// * calculate_angle.c
// *
// *  Created on: Feb 18, 2024
// *      Author: simaalaverdyan
// */
//
#include "calculate_angle.h"

void CalculateAccAngle(Angle_t* angle, MPU6050_t* mpu)
{
	angle->acc_roll = atan2(mpu->Accel_Y_RAW, sqrt(pow(mpu->Accel_X_RAW, 2) + pow(mpu->Accel_Z_RAW, 2))) * 180 / M_PI;
	angle->acc_pitch = atan2(-mpu->Accel_X_RAW, sqrt(pow(mpu->Accel_Y_RAW, 2) + pow(mpu->Accel_Z_RAW, 2))) * 180 / M_PI;

}


