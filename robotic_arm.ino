#include <Arduino.h>
#include <ArduinoSTL.h>
#include "robotic_arm.h"

using std::cout;
using std::cin;
using std::endl;

remote record;

void setup() {
  record.IRint();
  Serial.begin(9600);
}

void loop() {
  record.Button_detection();
}


























