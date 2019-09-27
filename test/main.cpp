#include <gtest/gtest.h>
#include <PID.h>

int main(int argc, char** argv) {
  PID pid(2);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
