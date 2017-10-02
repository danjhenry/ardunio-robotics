#include <Arduino.h>

bool on = false;
const int fwrd = 2;
const int back = 3;
const int rght = 4;
const int lft = 5;
int pins[4] = {2, 3, 4 , 5};

void setup() {
  pinMode(fwrd, OUTPUT);
  pinMode(back, OUTPUT);
  pinMode(lft, OUTPUT);
  pinMode(rght, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char movement;
  if (Serial.available() > 0) {
    movement = Serial.read();
    if (movement == 'q' and on == true) {
      for (int i = 0; i < 4; i++) {
        digitalWrite(pins[i], LOW);
      }
      Serial.print("motors off\n");
      on = false;
    }
    else if (movement == 'w') {
      on = true;
      moveMotor(fwrd);
    }
    else if (movement == 's') {
      on = true;
      moveMotor(back);
    }
    else if (movement == 'a') {
      on = true;
      moveMotor(lft);
    }
    else if (movement == 'd') {
      on = true;
      moveMotor(rght);
    }
  }
}

void moveMotor(int pin) {
  digitalWrite(pin, HIGH);
  Serial.print("pin on: ");
  Serial.println(pin);
}

