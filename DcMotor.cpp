#include "DcMotorController.h"
#include "DcMotor.h"

void DcMotor::enable(bool _enabled) {
  bool pinLevel;
  
  enabled.setValue(_enabled);
  
  if (_enableLevel) {
    pinLevel = _enabled;
  } 
  else {
    pinLevel = !_enabled;
  }

  if (_enabled) {
    _controller->setSpeed(_speedAmount);
  }
  
  digitalWrite(_selectPin, pinLevel);
}

void DcMotor::start() {
  enable(true);  
}

void DcMotor::stop() {
  enable(false);  
}