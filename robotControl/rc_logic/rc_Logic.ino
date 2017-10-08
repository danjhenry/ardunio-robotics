#include <Arduino.h>

const int pins[4] = {5, 4, 3, 2};

void setup() {
  Serial.begin(9600);
}

void loop() {
  bool state;
  String motorCode;
  char input;
  if (Serial.available() > 0) {
    input = Serial.read();
    for (int i = 4; i--;) {
      state = (input >> i) & 0x01;
      motor(state, pins[i]);
    }
  }
}

void motor(bool state, int pin) {
  if (state) {
    digitalWrite(pin, HIGH);
  }
  else {
    digitalWrite(pin, LOW);
  }
}
