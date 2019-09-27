/** Copyright 2019 
 *  @file   PID.cpp
 *  @brief  Describes the PID class.
 *  @author 
 */

#include <PID.h>
#include <ctime>

PID::PID(double kpValue, double kiValue, double kdValue, double spValue) {
}

PID::PID(double kpValue, double kiValue, double kdValue) {
}

PID::PID(double kpValue, double kiValue) {
}

PID::PID(double kpValue) {
}

void PID::reset() {
}

void PID::setSetpoint(double spValue) {
}

double PID::getKp() {
}

double PID::getKi() {
}

double PID::getKd() {
}

void PID::setKp(double kpValue) {
}

void PID::setKi(double kiValue) {
}

void PID::setKd(double kdValue) {
}

double PID::compute(double feedback) {
}
