#ifndef _MOTOR_LOAD_SENSOR_H
  #define _MOTOR_LOAD_SENSOR_H
  
#include <Arduino.h>
#include <MappedAnalogSensor.h>

class MotorLoadSensor : public MappedAnalogSensor {
  public:
    MotorLoadSensor(byte pin) : MappedAnalogSensor(pin) {
      _translationMap.add((TranslationPair) {0, 0} );
      _translationMap.add((TranslationPair) {1024, 1000} );

      _translationMapLength = _translationMap.size();
    }
};

#endif // _MOTOR_LOAD_SENSOR_H
