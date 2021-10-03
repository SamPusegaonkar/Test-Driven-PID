/**
 * @file PID.cpp
 * @author Sameer Pusegaonkar (sameer@umd.edu) - Driver, Kavyashree Devadiga (kavya@umd.edu) - Navigator 
 * @brief A file to define members of the PID class
 * @version 0.1
 * @date 2021-09-31
 * @copyright Copyright (c) 2021
 */

#include <numeric>
#include "PID.h"

/**
  * @brief Construct a new PID object. Sets values of kp, ki, kd to 0
*/
PID::PID() {
  kp = 0.0;
  ki = 0.0;
  kd = 0.0;
}

/**
   * @brief Returns the proportional constant 
   * @return double: Proportional constant 
*/
double PID::GetKP() {
  return kp;
}

/**
 * @brief Returns the integral constant 
 * @return double: Integral constant
 */
double PID::GetKI() {
  return ki;
}

/**
 * @brief Returns the differential constant 
 * @return double: Differential constant
 */
double PID::GetKD() {
  return kd;
}

/**
 * @brief Updates the proportional constant attribute to _kp
 * @param _kp : Proportional constant value to be set
 */
void PID::SetKP(double _kp) {
  kp = _kp;
}

/**
 * @brief Updates the differential constant attribute to _kd
 * @param _kd : Differential constant value to be set
 */
void PID::SetKD(double _kd) {
  kd = _kd;
}

/**
 * @brief Updates the integral constant attribute to _ki
 * @param _ki : Integral constant value to be set
 */
void PID::SetKI(double _ki) {
  ki = _ki;
}

/**
 * @brief Computes & sets the proportional error using the target & current velocity of the system
 * to the proportional_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeProportionalError(
    double target_velocity, double current_velocity) {
  proportional_error = kp * (target_velocity - current_velocity);
}

/**
 * @brief Computes & sets the integral error using the target & current velocity of the system
 * to the integral_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeIntegralError(
    double target_velocity, double current_velocity) {
  double error = target_velocity - current_velocity;
  double total_error = error;
  if (previous_errors.size() > 0)
    total_error += std::accumulate(previous_errors.begin(),
                                   previous_errors.end(), 0.0);

  integral_error = ki * total_error / (previous_errors.size()+1);
}

/**
 * @brief Computes & sets the differential error using the target & current velocity of the system
 * to the differential_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeDifferentialError(
    double target_velocity, double current_velocity) {
  if (previous_errors.size() > 0)
    differential_error = kd * ((target_velocity - current_velocity) -
                              previous_errors.rbegin()[0]);
  else
    differential_error = 0.0;
}

/**
 * @brief Invokes methods to calculate P-I-D error & returns the final error
 * @param target_velocity  Target velocity of the system
 * @param current_velocity Current velocity of the system
 * @return double Final Error
 */ 
double PID::ComputeError(double target_velocity, double current_velocity) {
  ComputeProportionalError(target_velocity, current_velocity);
  ComputeIntegralError(target_velocity, current_velocity);
  ComputeDifferentialError(target_velocity, current_velocity);
  double correction = proportional_error + integral_error + differential_error;
  previous_errors.push_back(correction);
  return correction;
}
