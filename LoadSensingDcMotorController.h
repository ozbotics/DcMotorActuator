/** @file LoadSensingDcMotorController.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _LOAD_SENSING_DC_MOTOR_CONTROLLER_H
  #define _LOAD_SENSING_DC_MOTOR_CONTROLLER_H
  
#include <Arduino.h>
#include <Timer.h>
#include <MotorLoadSensor.h>
#include <DcMotorController.h>

/**
 * LoadSensing DcMotorController
 *
 * Provides ability to monitor motor load
 */
class LoadSensingDcMotorController : public DcMotorController {
  protected:
    MotorLoadSensor * _loadSensor;  /**< protected variable _loadSensor The motor load Sensor */ 
    static const int _defaultSampleDuration = 2; /**< protected variable _defaultSampleDuration The sample period in milliseconds */ 
    
  public:
  
   /**
    * Constructor
    *
    * @param loadSensePin The Analog Input pin that connects to the motor load sensing circuit
    */
    LoadSensingDcMotorController(byte loadSensePin, byte speedPin, byte maxMotors) : DcMotorController(speedPin, maxMotors) {
      _loadSensor = new MotorLoadSensor(loadSensePin);
    }
    
   /**
    * Destructor
    */
    ~LoadSensingDcMotorController() {
      delete _loadSensor;
    }
    
   /**
    * get the load Sensor
    *
    * @return pointer to load Sensor
    */
    MotorLoadSensor * getLoadSensor() {
      return _loadSensor;
    }
    
   /**
    * get the load Sensor
    * 
    * @todo - refactor this functionality into a parent AveragingAnalogSensor
    * 
    * @param sampleDuration The sample period in milliseconds
    * @return average of load samples take over the duration
    */
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
    
   /**
    * get the load
    *
    * @return average of load measurements taken over the sample duration
    */
    int getLoad() {
      //return _loadSensor->getMappedValue();
      return getAveragedLoad();
    }    
    
};

#endif //_LOAD_SENSING_DC_MOTOR_CONTROLLER_H
