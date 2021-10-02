/**
 * @file test.cpp
 * @author Sameer Pusegaonkar (sameer@umd.edu) - Driver, Kavyashree Devadiga (kavya@umd.edu) - Navigator
 * @brief A file to verify the methods of the PID class
 * @version 0.1
 * @date 2021-10-01
 * @copyright Copyright (c) 2021
 *
 */

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
   * ep = (0.3*5) = 1.5  && ei = (0.2)(5/1) = 1
   * (Δe) = 2.5 _____________ [2.5]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10, 5), 2.5, 0.001);
  /**
   * Iteration 2
   * (Δe) = 2.5
   * ep = (0.3*2.5)  && ei = (0.2)(2.5+2.5/2)
   * (Δe) = 1.25 _____________ [2.5,1.25]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10, 7.5), 1.5, 0.01);
}

/**
 * @brief Tests PID controller with proportional, integral and differential gain
*/
TEST(Test_Driven_PID, test_with_kp_ki_kd) {
  PID pid_controller;
  pid_controller.SetKP(0.3);
  pid_controller.SetKD(0.2);
  pid_controller.SetKI(0.01);
  /**
   * Iteration 1
   * (Δe) = 10 - 5 = 5
   * ep = (0.3*5) = 1.5  && ei = (0.01)(5/1) = 0.05 && ed = 0 (no previous iteration)
   * (Δe) = 1.55 _____________ [1.55]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10, 5), 1.55, 0.01);
  /**
   * Iteration 2
   * (Δe) = 10-6.55 = 3.45
   * ep = (0.3*3.45)  && ei = (0.01)(1.55+3.45/2) && ed = 0.2(3.45-1.55)
   * (Δe) = 1.44 _____________ [1.44]
  */
  EXPECT_NEAR(pid_controller.ComputeError(10, 6.55), 1.44, 0.001);
}