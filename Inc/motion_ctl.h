/** motion_ctl.h
 * This is the base include file for libmotionctl
 * 
 * @author Alec Matthews <alec500oo@gmail.com>
 */

#pragma once

typedef struct motion_ctl_params {
  float kp;
  float ki;
  float kd;
  float integral;
  float prev_err;
  float max_lim;
  float min_lim;
} MOTION_PARAMS;

/** 
 * Calculate new motion compensation parameters for the system. This function
 * uses the PID algorithm.
 * @param error Error = desired - actual
 * @param param Pointer to the algorithm parameters.
 * @returns New compensation value to be sent out of the system.
 */
float CalculateCompensation(int error, MOTION_PARAMS* param);

/** 
 * Check the limits of the desired position based on the saved limits.
 * @param desired_pos Desired position of the device to check against limits.
 * @param param Pointer to algorithm parameters.
 * @returns 0 on success and negative number on fail.
 */
int CheckLimits(float desired_pos, MOTION_PARAMS* param);
