#include <Arduino.h>
#include "servoConfig.h"
#include <ArduinoSTL.h>

using namespace std;

servoConfig::servoConfig(int lowerLimit, int upperLimit) {
  limit[0] = lowerLimit;
  limit[1] = upperLimit;
}

void servoConfig::attachPin(int pinNum) {
  motor.attach(pinNum);
}

void servoConfig::detachPin() {
  motor.detach();
}

void servoConfig::angleChange(int angle) {
  int pos = motor.read();
  if (angle > limit[0] and angle < limit[1]) {
    motor.write(angle);
    delay(500);
  }
  else if (angle <= limit[0]) {
    motor.write(limit[0]);
    delay(500);
  }
  else if (angle >= limit[1]) {
    motor.write(limit[1]);
    delay(500);
  }
}
