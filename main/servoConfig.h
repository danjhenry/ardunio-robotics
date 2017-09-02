#include <Arduino.h>
#include <ArduinoSTL.h>
#include <Servo.h>

using namespace std;

class servoConfig {
  public:
    servoConfig(int lowerLimit, int upperLimit);
    void attachPin(int pinNum);
    void angleChange(int angle);

  private:
    int limit[2];
    Servo motor;
};
