/*
 * my_pid.c
 *
 *  Created on: Mar 25, 2024
 *      Author: simaalaverdyan
 */

#include "my_pid.h"

double PID1(double angle, double setpoint, double *previous_error, double *prev_input, double *integral, double dt, double kp, double ki, double kd)
{
	double I = 0;

//	double integral = 0;
    double error = setpoint - angle;
//    dt = 200;
//    printf("ERROR: %f\t", error);
    double P = kp * error;
//    double I = ki * (*previous_error + error) * dt;
//    *integral += ki * error;
    if (error < 5 || error > -5)
    	I = ki * error;

    double D = kd * (error - *previous_error);
//    double D = kd * (angle - *prev_input);
    *previous_error = error;
    *prev_input = angle;

//    double output = P + *integral - D;
    double output = P + I - D;
    return output;
}

double PID2(PIDController *pid, double setpoint, double angle)
{
    double error = setpoint - angle;
    double derivative = error - pid->prev_error;

    pid->integral += error;

    double output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;

    pid->prev_error = error;

    return output;
}

