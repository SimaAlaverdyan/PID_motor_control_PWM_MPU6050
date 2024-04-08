/*
 * my_pid.h
 *
 *  Created on: Mar 25, 2024
 *      Author: User
 */

#ifndef INC_MY_PID_H_
#define INC_MY_PID_H_

#include <stdio.h>

typedef struct {
    double Kp;
    double Ki;
    double Kd;
    double prev_error;
    double integral;
} PIDController;

double PID1(double angle, double setpoint, double *previous_error, double *prev_input, double *integral, double dt, double kp, double ki, double kd);
double PID2(PIDController *pid, double setpoint, double angle);

#endif /* INC_MY_PID_H_ */
