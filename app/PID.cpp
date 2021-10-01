/**
 * @file PID.cpp
 * @author Sameer Pusegaonkar (sameer@umd.edu) - Driver, Kavyashree Devadiga (kavya@umd.edu) - Navigator 
 * @brief A file to define members of the PID class
 * @version 0.1
 * @date 2021-09-31
 * @copyright Copyright (c) 2021
 */

#include <math.h>
#include "PID.h"


/**
  * @brief Construct a new PID object. Sets values of kp, ki, kd to 0
*/
PID::PID() {
  kp = 0.0;
  ki = 0.0;
  kd = 0.0;
  previous_errors.push(1);
  previous_errors.push(4);
  previous_errors.push(3);
  previous_errors.push(2);
}

/**
   * @brief Returns the proportional constant 
   * 
   * @return double: Proportional constant 
*/
double PID::GetKP() {
  return kp;
}

/**
 * @brief Returns the integral constant 
 * 
 * @return double: Integral constant
 */
double PID::GetKI() {
  return ki;
}

/**
 * @brief Returns the differential constant 
 * 
 * @return double: Differential constant
 */
double PID::GetKD() {
  return kd;
}

/**
 * @brief Updates the proportional constant attribute to _kp
 * 
 * @param _kp : Proportional constant value to be set
 */
void PID::SetKP(double _kp) {
  kp = _kp;
}

/**
 * @brief Updates the differential constant attribute to _kd
 * 
 * @param _kd : Differential constant value to be set
 */
void PID::SetKD(double _kd) {
  kd = _kd;
}

/**
 * @brief Updates the integral constant attribute to _ki
 * 
 * @param _ki : Integral constant value to be set
 */
void PID::SetKI(double _ki) {
  ki = _ki;
}
