/** @file MotorLoadSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _MOTOR_LOAD_SENSOR_H
  #define _MOTOR_LOAD_SENSOR_H
  
#include <Arduino.h>
#include <MappedAnalogSensor.h>

/**
 * MotorLoad Sensor
 *
 * Measures motor-load
 */
class MotorLoadSensor : public MappedAnalogSensor {
  public:
  
  /**
    * Constructor
    *
    * @param pin The Analog Input pin connected to the load sensing circuit
    */
    MotorLoadSensor(byte pin) : MappedAnalogSensor(pin) {
      _translationMap.add((TranslationPair) {0, 0} );
      _translationMap.add((TranslationPair) {1024, 1000} );

      _translationMapLength = _translationMap.size();
    }
};

#endif // _MOTOR_LOAD_SENSOR_H
