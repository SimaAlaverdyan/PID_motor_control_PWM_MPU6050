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
#define ALPHA 0.98 // Weight factor for gyroscope data
//#define DT 0.01 // Time interval between sensor readings (adjust as needed)

//#include "mpu6050.h"
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
void CalculateGyroAngle(Angle_t* Angle, MPU6050_t* MPU6050);
//void CalculateCompliFilter(Angle_t* Angle, MPU6050_t* MPU6050);
void CalculateCompliFilter(Angle_t* angle, MPU6050_t* mpu, double dt);

int		map(int x, int in_min, int in_max, int out_min, int out_max);
//void	calc_angle(Angle_t *angle, MPU6050_t *mpu);
void calc_angle(Angle_t *angle, MPU6050_t *mpu, double dt);

#endif /* INC_CALCULATE_ANGLE_H_ */
