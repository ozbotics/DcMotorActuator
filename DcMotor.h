#ifndef _DC_MOTOR_H
  #define _DC_MOTOR_H
  
#include <Arduino.h>

#include "DcMotorController.h"
#include <Actuator.h>
#include <Value.h>

class DcMotorController;

class DcMotor : public Actuator {
  protected:
    DcMotorController* _controller;
    byte _selectPin;
    byte _speedAmount;
    bool _enableLevel;   // Pull selectPin (HI | LOW) to enable

  public:
    Value<bool> enabled;
    
    DcMotor(DcMotorController* controller, byte selectPin, byte speedAmount, bool enableLevel=true) : _controller(controller), _selectPin(selectPin), _speedAmount(speedAmount), _enableLevel(enableLevel), Actuator() {
      pinMode(_selectPin, OUTPUT); 
      enable(false);
    }
    
    void enable(bool _enabled);
    
    virtual void start();
    virtual void stop();

};
  
#endif //_DC_MOTOR_H
