//#include "mpu6050.h"
//#include <main.h>
//#include <stdlib.h>
//
//extern I2C_HandleTypeDef hi2c1;
//
//int init_mpu6050()
//{
//	HAL_StatusTypeDef res = HAL_I2C_IsDeviceReady(&hi2c1, DEVICE_ADDRESS, 1, 1000);
//
//	if (res == HAL_OK)
//	{
//		printf("MPU6050 is ready \n");
//	}
//	else
//	{
//		printf("Device is not ready %d \n", res);
//		return (-1);
//	}
//
//	uint8_t pData = FS_GYRO_250;
//	res = HAL_I2C_Mem_Write(&hi2c1, DEVICE_ADDRESS, CONFIG_GYRO_REG, 1, &pData, 1, 1000);
//
//	if (res == HAL_OK)
//	{
//	  printf("Configuring gyroscope \n");
//	}
//	else
//	{
//	  printf("Failed to configure gyroscope \n");
//	  return (-2);
//	}
//
//	pData = FD_ACC_2G;
//	res = HAL_I2C_Mem_Write(&hi2c1, DEVICE_ADDRESS, CONFIG_ACC_REG, 1, &pData, 1, 1000);
//
//	if (res == HAL_OK)
//	{
//	  printf("Configuring accelerometer \n");
//	}
//	else
//	{
//	  printf("Failed to configure accelerometer \n");
//	  return (-3);
//	}
//
//	pData = 0;
//	res = HAL_I2C_Mem_Write(&hi2c1, DEVICE_ADDRESS, PWR_MGMT_1, 1, &pData, 1, 1000);
//
//	if (res == HAL_OK)
//	{
//	  printf("Exiting from sleep mode \n");
//	}
//	else
//	{
//	  printf("Failed to exit sleep mode \n");
//	  return (-4);
//	}
//	return (1);
//}
//
//int read_acceleration_mpu6050(MPU6050_t *mpu)
//{
//	uint8_t pdata[6];
//	memset(pdata, 0, sizeof(pdata));
//	if(HAL_I2C_Mem_Read(&hi2c1, DEVICE_ADDRESS, ACCEL_XOUT_H_REG, I2C_MEMADD_SIZE_8BIT, pdata, 6, 100) == HAL_OK)
//	{
//		mpu->x_acc_raw = ((int16_t)pdata[0] << 8 | pdata[1]);
//		mpu->y_acc_raw = ((int16_t)pdata[2] << 8 | pdata[3]);
//		mpu->z_acc_raw = ((int16_t)pdata[4] << 8 | pdata[5]);
//
//		mpu->x_acc = ((float)mpu->x_acc_raw / 16384.0 );
//		mpu->y_acc = ((float)mpu->y_acc_raw / 16384.0 );
//		mpu->z_acc = ((float)mpu->z_acc_raw / 16384.0 );
//
//		return 1;
//	}
//	else
//	{
//		printf("Error on I2C read (acceleration)\n");
//		return 0;
//	}
//}
//
//int read_gyroscope_mpu6050(MPU6050_t *mpu)
//{
//	uint8_t data[6];
//
//	if (HAL_I2C_Mem_Read(&hi2c1, DEVICE_ADDRESS, GYRO_XOUT_H_REG, I2C_MEMADD_SIZE_8BIT, data, 6, 100) == HAL_OK)
//	{
//		mpu->x_gyro_raw = (int16_t)data[0] << 8 | data[1];
//		mpu->y_gyro_raw = (int16_t)data[2] << 8 | data[3];
//		mpu->z_gyro_raw = (int16_t)data[4] << 8 | data[5];
//
//		mpu->x_gyro = ((float)mpu->x_gyro_raw / 131.0);
//		mpu->y_gyro = ((float)mpu->y_gyro_raw / 131.0);
//		mpu->z_gyro = ((float)mpu->z_gyro_raw / 131.0);
//
//		return 1;
//	}
//	else
//	{
//		printf("Error on I2C read (gyroscope)\n");
//		return 0;
//	}
//}
//
//void calibrate_mpu6050(MPU6050_t *mpu)
//{
//	  printf("Calibrating gyroscope .... dont move the hardware ..........");
//
//	  int x = 0, y = 0, z = 0, i;
//
//	  read_gyroscope_mpu6050(mpu);
//
//	  // Gyro Offset Calculation
//	  x = mpu->x_gyro_raw;
//	  y = mpu->y_gyro_raw;
//	  z = mpu->z_gyro_raw;
//
//	  for (i = 1; i <= 1000; i++){
//		read_gyroscope_mpu6050(mpu);
//	    x = (x + mpu->x_gyro_raw)/2;
//	    y = (y + mpu->y_gyro_raw)/2;
//	    z = (z + mpu->z_gyro_raw)/2;
//	    printf(".");
//	  }
//	  printf(".");
//	  mpu->gyro_x_OC = x;
//	  mpu->gyro_y_OC = y;
//	  mpu->gyro_z_OC = z;
//
//
//	  // Accel Offset Calculation
//	  printf("Calibrating accelrometer .... dont move the hardware ..........");
//	  x = mpu->x_acc_raw;
//	  y = mpu->y_acc_raw;
//	  z = mpu->z_acc_raw;
//
//	  for (i=1;i<=1000;i++){
//		read_acceleration_mpu6050(mpu);
//	    x=(x+mpu->x_acc_raw)/2;
//	    y=(y+mpu->y_acc_raw)/2;
//	    z=(z+mpu->z_acc_raw)/2;
//	    printf(".");
//	  }
//	  printf(".");
//	  mpu->accel_x_OC = x;
//	  mpu->accel_y_OC = y;
//	  mpu->accel_z_OC = z-(float)g*1000/(500*0.0305);
//}
