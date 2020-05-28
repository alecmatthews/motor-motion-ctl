#include "motion_ctl.h"

float CalculateCompensation(int error, MOTION_PARAMS* param) {
  // TODO: may need to add interation time.
  param->integral = param->integral + error;

  int d = error - param->prev_err;
  param->prev_err = error;

  return param->kp * error + param->ki * param->integral + param->kd * d;
}

int CheckLimits(float desired_pos, MOTION_PARAMS* param) {
  return desired_pos > param->max_lim || desired_pos < param->min_lim ? -1 : 0;
}
