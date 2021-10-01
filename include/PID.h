/**
 * @file PID.h
 * @author Sameer Pusegaonkar (sameer@umd.edu) - Driver, Kavyashree Devadiga (kavya@umd.edu) - Navigator 
 * @brief A header file to compute error for a PID Controller
 * @version 0.1
 * @date 2021-09-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

#include <queue>

/**
 * @brief A class representing the PID controller
 * 
 */
class PID {
 private:
  double kp;  ///< Variable to store the PID proportional constant
  double ki;  ///< Variable to store the PID integral constant
  double kd;  ///< Variable to store the PID differential constant
  std::queue<double> previous_errors;  ///< Stores all the previous errors
  double time_difference;  ///<  Delta time
  double integral_error;   ///< Stores current integral error
  double proportional_error;  ///< Stores current proportional error
  double differential_error;  ///< Stores current differential  error

  /**
   * @brief Computes & sets the proportional error using the target & current velocity of the system
   * to the proportional_error attribute
   * 
   * @param target_velocity Target velocity of the system
   * @param current_velocity Current velocity of the system
   */
  void ComputeProportionalError(
      double target_velocity, double current_velocity);

  /**
   * @brief Computes & sets the integral error using the target & current velocity of the system
   * to the integral_error attribute
   * 
   * @param target_velocity Target velocity of the system
   * @param current_velocity Current velocity of the system
   */
  void ComputeIntegralError(
      double target_velocity, double current_velocity);

  /**
   * @brief Computes & sets the differential error using the target & current velocity of the system
   * to the differential_error attribute
   * 
   * @param target_velocity Target velocity of the system
   * @param current_velocity Current velocity of the system
   */
  void ComputeDifferentialError(
      double target_velocity, double current_velocity);
};

#endif  // INCLUDE_PID_H_
