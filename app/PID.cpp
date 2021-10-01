/**
 * @file PID.cpp
 * @author Sameer Pusegaonkar (sameer@umd.edu) - Driver, Kavyashree Devadiga (kavya@umd.edu) - Navigator 
 * @brief A file to define members of the PID class
 * @version 0.1
 * @date 2021-09-31
 * @copyright Copyright (c) 2021
 */

#include "PID.h"

/**
  * @brief Construct a new PID object. Sets values of kp, ki, kd to 0
*/
PID::PID() {
  /**
   * @todo Set the initial values of the private members of the class
   * 
   */
}

/**
   * @brief Returns the proportional constant 
   * @return double: Proportional constant 
*/
double PID::GetKP() {
  /**
   * @todo Should return the KP constant
   */
  return 0;
}

/**
 * @brief Returns the integral constant 
 * @return double: Integral constant
 */
double PID::GetKI() {
  /**
   * @todo Should return the KI constant
   */
  return 0;
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
  /**
   * @todo Set the constant KP
   */
}

/**
 * @brief Updates the differential constant attribute to _kd
 * @param _kd : Differential constant value to be set
 */
void PID::SetKD(double _kd) {
  /**
   * @todo Set the constant KD
   */
}

/**
 * @brief Updates the integral constant attribute to _ki
 * @param _ki : Integral constant value to be set
 */
void PID::SetKI(double _ki) {
  /**
   * @todo Set the constant KI
   */
}

/**
 * @brief Computes & sets the proportional error using the target & current velocity of the system
 * to the proportional_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeProportionalError(
    double target_velocity, double current_velocity) {
    /**
     * @todo Compute proportional error by using the standard formula
     */
}

/**
 * @brief Computes & sets the integral error using the target & current velocity of the system
 * to the integral_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeIntegralError(
    double target_velocity, double current_velocity) {
    /**
     * @todo Compute integral error by using the standard formula
     * 
     */
}

/**
 * @brief Computes & sets the differential error using the target & current velocity of the system
 * to the differential_error attribute
 * @param target_velocity Target velocity of the system
 * @param current_velocity Current velocity of the system
 */
void PID::ComputeDifferentialError(
    double target_velocity, double current_velocity) {
    /**
     * @todo Compute differential error by using the standard formula
     * 
     */
}

/**
 * @brief Invokes methods to calculte P-I-D error & returns the final error
 * @param target_velocity  Target velocity of the system
 * @param current_velocity Current velocity of the system
 * @return double Final Error
 */ 
double PID::ComputeError(double target_velocity, double current_velocity) {
  /**
   * @todo Compute final error by using the standard formula
   * 
   */
  return 0;
}
