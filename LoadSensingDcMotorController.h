#ifndef _LOAD_SENSING_DC_MOTOR_CONTROLLER_H
  #define _LOAD_SENSING_DC_MOTOR_CONTROLLER_H
  
#include <Arduino.h>
#include <Timer.h>
#include <MotorLoadSensor.h>
#include <DcMotorController.h>

class LoadSensingDcMotorController : public DcMotorController {
  protected:
    MotorLoadSensor * _loadSensor;
    static const int _defaultSampleDuration = 2;
    
  public:
    LoadSensingDcMotorController(byte loadSensePin, byte speedPin, byte maxMotors) : DcMotorController(speedPin, maxMotors) {
      _loadSensor = new MotorLoadSensor(loadSensePin);
    }
    
    ~LoadSensingDcMotorController() {
      delete _loadSensor;
    }
    
    MotorLoadSensor * getLoadSensor() {
      return _loadSensor;
    }
    
    int getAveragedLoad(int sampleDuration = _defaultSampleDuration) {
      unsigned int summedLoad = 0;
      unsigned int numSamples = 0;
      
      Timer timer;
      
      timer.start(sampleDuration);
      while (!timer.isComplete()) {
        summedLoad += _loadSensor->getMappedValue();
        numSamples++;
      }
    
      return summedLoad / numSamples;
    }
    
    int getLoad() {
      return _loadSensor->getMappedValue();
    }    
    
};

#endif //_LOAD_SENSING_DC_MOTOR_CONTROLLER_H
