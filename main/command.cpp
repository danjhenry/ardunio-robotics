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

void servoConfig::angleChange(int angle) {
  int pos = motor.read();
  if (angle < pos) {
    for (int i = pos; i > angle; i--) {
      if (i <= limit[0]) {
        break;
      }
      motor.write(i);
      delay(10);
    }
  }
  else if (angle > pos) {
    for (int i = pos; i < angle; i++) {
      if (i >= limit[1]) {
        break;
      }
      motor.write(i);
      delay(10);
    }
  }
}
