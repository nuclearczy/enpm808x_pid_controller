#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

/* Copyright 2019
 * @file   PID.h
 * @author
 */

#include <iostream>
#include <vector>
#include <ctime>

class PID {
 private:
  /**
   * @brief private variable for Kp.
   */
  double Kp;

  /**
   * @brief private variable for Ki.
   */
  double Ki;

  /**
   * @brief private variable for Kd.
   */
  double Kd;

  /**
   * @brief private variable for storing previous error.
   */
  double prevError;

  /**
   * @brief private variable for storing sum of errors.
   */
  double sumError;

  /**
   * @brief private variable for storing previous time.
   */
  double prevTime;

  /**
   * @brief private variable for storing the pid setpoint.
   */
  double setpoint;

 public:
  /**
   * @brief  constructor for PID class with four parameters.
   */
  PID(double kpValue, double kiValue, double kdValue, double spValue);

  /**
   * @brief  constructor for PID class with three parameters.
   */
  PID(double kpValue, double kiValue, double kdValue);

  /**
   * @brief  constructor for PID class with two parameters.
   */
  PID(double kpValue, double kiValue);

  /**
   * @brief  constructor for PID class with one parameter.
   */
  explicit PID(double kpValue);

  /**
   * @brief  resets all the private variables of the class to zero except @prevTime.
   * Set @prevTime to the current time
   * @param  no parameter.
   * @return type void.
   */
  void reset();

  /**
   * @brief  sets the setpoint value.
   * @param  one parameter which is the setpoint value.
   * @return type void.
   */
  void setSetpoint(double spValue);

  /**
   * @brief  returns the kp value.
   * @param  no parameter.
   * @return type double.
   */
  double getKp();

  /**
   * @brief  returns the ki value.
   * @param  no parameter.
   * @return type double.
   */
  double getKi();

  /**
   * @brief  returns the kd value.
   * @param  no parameter.
   * @return type double.
   */
  double getKd();

  /**
   * @brief  sets the kp value.
   * @param  one parameter which is the kp value.
   * @return type void.
   */
  void setKp(double kpValue);

  /**
   * @brief  sets the ki value.
   * @param  one parameter which is the ki value.
   * @return type void.
   */
  void setKi(double kiValue);

  /**
   * @brief  sets the kd value.
   * @param  one parameter which is the kd value.
   * @return type void.
   */
  void setKd(double kdValue);

  /**
   * @brief  This function calculates the pid output using @feedback and setpoint.
   * Error is setpoint-@feedback. dt is updated by calculating the difference between
   * the current time and @prevTime
   * @param  one parameter which is the feedback value.
   * @return type double.
   */
  double compute(double feedback);
};
#endif  // INCLUDE_PID_H_
