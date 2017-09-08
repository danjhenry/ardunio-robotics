#include "servoConfig.h"
#include <ArduinoSTL.h>
#include <Arduino.h>


using namespace std;

servoConfig base(0, 179);
servoConfig fwrd(65, 179);
servoConfig updwn(70, 179);
servoConfig claw(135, 179);

void setup() {
  Serial.begin(9600);
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
    base.attachPin(5);
    base.angleChange(angle);
    base.detachPin();
  }
  else if (servoName == "claw") {
    claw.attachPin(3);
    claw.angleChange(angle);
    claw.detachPin();
  }
  else if (servoName == "fwrd") {
    fwrd.attachPin(9);
    fwrd.angleChange(angle);
  }
  else if (servoName == "updwn") {
    updwn.attachPin(10);
    updwn.angleChange(angle);
    updwn.detachPin();
  }
}



















