#include <Arduino.h>

String forward = "000";
String backward = "100";
String left = "110";
String right = "111";

const int forward_pin = 2;
const int backward_pin = 3;
const int right_pin = 4;
const int left_pin = 5;

void setup() {

  Serial.begin(9600);
}

void loop() {
  bool state;
  String motorCode;
  char input;
  if (Serial.available() > 0) {
    input = Serial.read();
    for (int i = 3; i--;) {
      motorCode += String((input >> i) & 0x01);
    }
    state = (input >> 3) & 0x01;

    if (motorCode == forward) {
      motor(state, forward_pin);
    }
    else if (motorCode == backward) {
      motor(state, backward_pin);
    }
    else if (motorCode == left) {
      motor(state, left_pin);
    }
    else if (motorCode == right) {
      motor(state, right_pin);
    }
  }
}

void motor(bool state, int pin) {
  if (state) {
    digitalWrite(pin, HIGH);
    Serial.println(pin);
  }
  else {
    digitalWrite(pin, LOW);
    Serial.println(pin);
  }
}
