/**@Copyright (C) 2019 Ari Kupferberg, Zuyang Cao
 * @file        PID.cpp
 * @author      Ari Kupferberg, Zuyang Cao
 * @date        09/26/2019
 * @brief       Implementation for PID class.
 */

#include <PID.h>
#include <ctime>

/**
 * PID constructor.
 */
PID::PID(double kpValue, double kiValue, double kdValue, double spValue) {
  this->Kp = kpValue;
  this->Ki = kiValue;
  this->Kd = kdValue;
  this->setpoint = spValue;
  this->prevError = 0;
  this->sumError = 0;
  this->deltaTime = 1;

}

/**
 * PID with 0 set point constructor.
 */
PID::PID(double kpValue, double kiValue, double kdValue) {
  this->Kp = kpValue;
  this->Ki = kiValue;
  this->Kd = kdValue;
  this->setpoint = 0;
  this->prevError = 0;
  this->sumError = 0;
  this->deltaTime = 1;
}

/**
 * PI constructor.
 */
PID::PID(double kpValue, double kiValue) {
  this->Kp = kpValue;
  this->Ki = kiValue;
  this->Kd = 0;
  this->setpoint = 0;
  this->prevError = 0;
  this->sumError = 0;
  this->deltaTime = 1;
}

/**
 * P constructor.
 */
PID::PID(double kpValue) {
  this->Kp = kpValue;
  this->Ki = 0;
  this->Kd = 0;
  this->setpoint = 0;
  this->prevError = 0;
  this->sumError = 0;
  this->deltaTime = 1;
}

/**
 * Resets all the private variables of the class to zero except @deltaTime.
 */
void PID::reset() {
  this->Kp = 0;
  this->Ki = 0;
  this->Kd = 0;
  this->setpoint = 0;
  this->prevError = 0;
  this->sumError = 0;
  this->deltaTime = 1;
}

/**
 * Set setpoint for controller.
 */
void PID::setSetpoint(double spValue) {
  this->setpoint = spValue;
}

/**
 * Get kp from controller.
 */
double PID::getKp() {
  return Kp;
}

/**
 * Get ki from controller.
 */
double PID::getKi() {
  return Ki;
}

/**
 * Get kd from controller.
 */
double PID::getKd() {
  return Kd;
}

/**
 * Set dt for controller.
 */
void PID::setDt(double dtValue) {
  this->deltaTime = dtValue;
}

/**
 * Set kp for controller.
 */
void PID::setKp(double kpValue) {
  this->Kp = kpValue;
}

/**
 * Set ki for controller.
 */
void PID::setKi(double kiValue) {
  this->Ki = kiValue;
}

/**
 * Set kd for controller.
 */
void PID::setKd(double kdValue) {
  this->Kd = kdValue;
}

/**
 * Compute the output.
 */
double PID::compute(double feedback) {
  double output = 0;
  double currentError = setpoint - feedback;
  sumError += currentError;
  output = Kp * currentError + Ki * sumError * deltaTime
      + Kd * (currentError - prevError) / deltaTime;
  prevError = currentError;
  return output;
}
