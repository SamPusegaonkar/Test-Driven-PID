#include <gtest/gtest.h>
#include "PID.h"

/**
 * @brief Tests the default constructor
*/
TEST(Test_Driven_PID, test_the_default_constructor) {
  PID pid_controller;
  EXPECT_EQ(pid_controller.GetKP(), 0);
  EXPECT_EQ(pid_controller.GetKD(), 0);
  EXPECT_EQ(pid_controller.GetKI(), 0);
}

/**
 * @brief Tests PID controller proportional gain keeping differential
 * and integral constants zero
*/
TEST(Test_Driven_PID, test_with_kp) {
  PID pid_controller;
  pid_controller.SetKP(0.9);
  pid_controller.SetKD(0);
  pid_controller.SetKI(0);
  EXPECT_NEAR(pid_controller.ComputeError(12, 10), 1.8, 0.001);
}


