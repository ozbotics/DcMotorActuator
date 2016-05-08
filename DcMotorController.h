/** @file DcMotorController.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _DC_MOTOR_CONTROLLER_H
  #define _DC_MOTOR_CONTROLLER_H
  
#include <Arduino.h>
#include <LinkedList.h>

#include "DcMotor.h"

class DcMotor;

/**
 * DC Motor Controller
 *
 * DC Motor Controller(s) can support a number of Motor Channels (4)
 * Motor Speed is mangaed via this Controller 
 *  (by modulating a duty cycle of the speedPin line
 */
class DcMotorController  {
  protected:
    byte _speedPin;
    
  public:
    DcMotorController(byte speedPin) : _speedPin(speedPin) {
      pinMode(_speedPin, OUTPUT); 
      setSpeed(0);
    }
    
    void setSpeed(byte speedAmount) {
      analogWrite(this->_speedPin, speedAmount);
    }

};

#endif //_DC_MOTOR_CONTROLLER_H
