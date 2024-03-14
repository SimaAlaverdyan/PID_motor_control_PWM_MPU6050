///*
// * mpu6050.h
// *
// *  Created on: Feb 18, 2024
// *      Author: simaalaverdyan
// */
//
//#ifndef INC_MPU6050_H_
//#define INC_MPU6050_H_
//
//#include <string.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdint.h>
//
//#define DEVICE_ADDRESS	0xD0    //68
//#define DEVICE_ADDRESS1	0x68
//
//#define FS_GYRO_250		0
//#define FS_GYRO_500		8
//#define FS_GYRO_1000	9
//#define FS_GYRO_2000	10
//
//#define FD_ACC_2G		0
//#define FD_ACC_4G		8
//#define FD_ACC_8G		9
//#define FD_ACC_16G		10
//
//#define CONFIG_GYRO_REG		0x1B
//#define CONFIG_ACC_REG		0x1C //28
//#define PWR_MGMT_1			0x6B
//#define ACCEL_XOUT_H_REG	0x3B
//#define GYRO_XOUT_H_REG		0x43
//
//#define MPU6050_ACCEL_XOUT_H 0x3B
//
//#define g 9.81
//
//typedef struct
//{
//    int16_t x_acc_raw;
//    int16_t y_acc_raw;
//    int16_t z_acc_raw;
//    float x_acc;
//    float y_acc;
//    float z_acc;
//
//    int16_t x_gyro_raw;
//    int16_t y_gyro_raw;
//    int16_t z_gyro_raw;
//    float x_gyro;
//    float y_gyro;
//    float z_gyro;
//
//    int		gyro_x_OC;
//    int		gyro_y_OC;
//    int		gyro_z_OC;
//
//    int		accel_x_OC;
//	int		accel_y_OC;
//	int		accel_z_OC;
//
//}	MPU6050_t;
//
//
//int		init_mpu6050();
//int		read_acceleration_mpu6050(MPU6050_t *mpu);
//int		read_gyroscope_mpu6050(MPU6050_t *mpu);
//void	calibrate_mpu6050(MPU6050_t *mpu);
//
//#endif /* INC_MPU6050_H_ */
