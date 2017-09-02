#include "servoConfig.h"
#include <ArduinoSTL.h>
#include <Arduino.h>


using namespace std;

servoConfig base(0, 180);
servoConfig fwrd(65, 180);
servoConfig updwn(70, 180);
servoConfig claw(135, 180);

void setup() {
  Serial.begin(9600);
  base.attachPin(5);
  fwrd.attachPin(9);
  updwn.attachPin(10);
  claw.attachPin(3);
}

void loop() {
  string servoName;
  int angle;
  cout << "Enter which servo to move. ('base', 'updwn', 'claw', 'fwrd'): ";
  cin >> servoName;
  cout << servoName << endl;
  cout << "Enter an angle: ";
  cin >> angle;
  cout << angle << endl;

  if (servoName == "base") {
    base.angleChange(angle);
  }
  else if (servoName == "claw") {
    claw.angleChange(angle);
  }
  else if (servoName == "fwrd") {
    fwrd.angleChange(angle);
  }
  else if (servoName == "updwn") {
    updwn.angleChange(angle);
  }
}
