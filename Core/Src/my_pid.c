/*
 * my_pid.c
 *
 *  Created on: Mar 25, 2024
 *      Author: User
 */

#include "my_pid.h"

double PID1(double angle, double setpoint, double *previous_error, double dt, double kp, double ki, double kd)
{
    double error = setpoint - angle;
//    dt = 200;
//    printf("ERROR: %f\t", error);
    double P = kp * error;
//    double I = ki * (*previous_error + error) * dt;
    double I = ki * error * dt;
    double D = kd * (error - *previous_error) / dt;

    *previous_error = error;

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

