/** @file DcMotor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _DC_MOTOR_H
  #define _DC_MOTOR_H
  
#include <Arduino.h>

#include "DcMotorController.h"
#include <Actuator.h>
#include <Value.h>

class DcMotorController;

/**
 * DcMotor Actuator
 *
 * Turn on DC Motor when enabled
 */
class DcMotor : public Actuator {
  protected:
    DcMotorController* _controller;  /**< protected variable _controller The shared motor controller object */ 
    byte _selectPin;                 /**< protected variable _selectPin The pin connected to the motor-enable line of the MotorController */ 
    byte _speedAmount;               /**< protected variable _speedAmount The speed amount to use when this motor is enabled */ 
    bool _enableLevel;               /**< protected variable _enableLevel Pull selectPin (HI | LOW) to enable */

    void _setEnabled(bool _enabled);

  public:
    //Value<bool> enabled; 
    
    DcMotor(DcMotorController* controller, byte selectPin, byte speedAmount, bool enableLevel=true) : _controller(controller), _selectPin(selectPin), _speedAmount(speedAmount), _enableLevel(enableLevel), Actuator() {
      pinMode(_selectPin, OUTPUT); 
      _setEnabled(false);
    }
    
    
    virtual void start();
    virtual void stop();

};
  
#endif //_DC_MOTOR_H
