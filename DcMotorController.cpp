#include "DcMotorController.h"
#include "DcMotor.h"
/*
DcMotor * DcMotorController::addMotor(byte selectPin, byte speedAmount, bool enableLevel) {
  DcMotor* motor;
  
  if (_numMotors < _maxMotors) {
    motor = new DcMotor(this, selectPin, speedAmount, enableLevel);
    _motors.add(motor);

    _numMotors++;
  }
  
  return motor;  // returns null if _maxMotors exceeded
}

DcMotor * DcMotorController::getMotor(byte motorNumber) {
  DcMotor * ret;
  
  if (motorNumber <= _numMotors) {
    ret = _motors.get(motorNumber);
  }
  
  return ret;
}

byte DcMotorController::getNumMotors() {
  return _numMotors;
}
*/
  
void DcMotorController::start() {
  Serial.println(F("DcMotorController::start called"));
}

void DcMotorController::stop() {
  Serial.println(F("DcMotorController::stop called"));
}