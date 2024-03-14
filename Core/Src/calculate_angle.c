///*
// * calculate_angle.c
// *
// *  Created on: Feb 18, 2024
// *      Author: simaalaverdyan
// */
//
#include "calculate_angle.h"

// correct angle reading function +-3 error
void CalculateAccAngle(Angle_t* angle, MPU6050_t* mpu)
{
//	angle->acc_roll = atan2(mpu->y_acc_raw, sqrt(pow(mpu->x_acc_raw, 2) + pow(mpu->z_acc_raw, 2))) * 180 / M_PI;
//	angle->acc_pitch = atan2(-mpu->x_acc_raw, sqrt(pow(mpu->y_acc_raw, 2) + pow(mpu->z_acc_raw, 2))) * 180 / M_PI;

	angle->acc_roll = atan2(mpu->Accel_Y_RAW, sqrt(pow(mpu->Accel_X_RAW, 2) + pow(mpu->Accel_Z_RAW, 2))) * 180 / M_PI;
	angle->acc_pitch = atan2(-mpu->Accel_X_RAW, sqrt(pow(mpu->Accel_Y_RAW, 2) + pow(mpu->Accel_Z_RAW, 2))) * 180 / M_PI;

}

//static float dt = 1/200.f; //Sample rate is 200Hz
//void CalculateGyroangle(Angle_t* angle, MPU6050_t* mpu)
//{
//	angle->gyro_roll  += mpu->y_gyro * dt;
//	angle->gyro_pitch += mpu->x_gyro * dt;
//	angle->gyro_yaw   += mpu->z_gyro * dt;
//}

//void CalculateCompliFilter(Angle_t* angle, MPU6050_t* mpu, double dt)
//{
//	CalculateAccAngle(angle, mpu); //Prepare Acc angle before using Complimentary Filter.
//
////	printf("%f \t %f\n", angle->acc_roll, angle->acc_pitch);
//
//	static float alpha = 0.96f;
//	angle->roll  = alpha*(mpu->y_gyro * dt + angle->roll) + (1-alpha) * angle->acc_roll;
//	angle->pitch = alpha*(mpu->x_gyro * dt + angle->pitch) + (1-alpha) * angle->acc_pitch;
//	angle->yaw   = angle->yaw + mpu->z_gyro * dt;
//}

int map(int x, int in_min, int in_max, int out_min, int out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


//void calc_angle(Angle_t *angle, MPU6050_t *mpu, double dt)
//{
//////     Calculate roll, pitch, and yaw angles
//    angle->roll = RADIAN_TO_DEGREE * (atan2(-mpu->y_acc_raw, -mpu->z_acc_raw) + M_PI);
//    angle->pitch = RADIAN_TO_DEGREE * (atan2(-mpu->x_acc_raw, -mpu->z_acc_raw) + M_PI);
//    angle->yaw = RADIAN_TO_DEGREE * (atan2(-mpu->y_acc_raw, -mpu->x_acc_raw) + M_PI);
//
//}


