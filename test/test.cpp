#include <gtest/gtest.h>
#include <PID.h>

TEST(pidClassTest, should_pass) {
  // Testing whether the Kp gets initialized with constructor
  PID pid(2);
  EXPECT_EQ(pid.getKp(), 2);

  // Testing whether the computer function works
  pid.setSetpoint(2);
  double controlOut;
  controlOut = pid.compute(3);
  double Kp;
  Kp = pid.getKp();
  EXPECT_EQ(controlOut, -Kp);
}
