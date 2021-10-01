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
 * @brief Tests PID controller proportional gain, keeping differential
 * and integral constants as 0
*/
TEST(Test_Driven_PID, test_with_kp) {
  PID pid_controller;
  pid_controller.SetKP(0.9);
  pid_controller.SetKD(0);
  pid_controller.SetKI(0);
  EXPECT_NEAR(pid_controller.ComputeError(12, 10), 1.8, 0.001);
}

/**
 * @brief Tests PID controller proportional and integral gain keeping differential
 * constant zero
*/
TEST(Test_Driven_PID, test_with_kp_ki) {
  PID pid_controller;
  pid_controller.SetKP(0.3);
  pid_controller.SetKD(0);
  pid_controller.SetKI(0.2);
  /**
   * Iteration 1
   * (Δe) = 10 - 5 = 5
   * ep = (0.35) = 1.5  && ei = (0.2)(5/1) = 1
   * (Δe) = 2.5 _____________ [5,2.5]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10,5), 2.5,0.001);
  /**
   * Iteration 2
   * (Δe) = 2.5
   * ep = (0.32.5)  && ei = (0.2)(5+2.5/2)
   * (Δe) = 1.5 _____________ [5,2.5,1.5]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10,7.5), 1.5,0.01);
}

