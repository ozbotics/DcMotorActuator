#ifndef _DC_MOTOR_CONTROLLER_H
  #define _DC_MOTOR_CONTROLLER_H
  
#include <Arduino.h>
#include <LinkedList.h>

#include "DcMotor.h"
#include <Actuator.h>

class DcMotor;

class DcMotorController : public Actuator {
  protected:
    byte _speedPin;
    byte _maxMotors;

    LinkedList<DcMotor*> _motors = LinkedList<DcMotor*>();
    byte _numMotors = 0;
    
  public:
    DcMotorController(byte speedPin, byte maxMotors) : _speedPin(speedPin), _maxMotors(maxMotors), Actuator() {
      pinMode(_speedPin, OUTPUT); 
      setSpeed(0);
    }
    
    void setSpeed(byte speedAmount) {
      analogWrite(this->_speedPin, speedAmount);
    }

//    DcMotor * addMotor(byte selectPin, byte speedAmount, bool enableLevel=1);
//    DcMotor * getMotor(byte motorNumber);
    
//    byte getNumMotors();
    
    virtual void start();
    virtual void stop();

};

#endif //_DC_MOTOR_CONTROLLER_H
