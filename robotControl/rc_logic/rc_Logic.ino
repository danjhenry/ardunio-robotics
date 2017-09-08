#include <ArduinoSTL.h>
#include <Arduino.h>

using namespace std;
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
  string movement;
  string check;
  int pause;
  while (true) {
    cin >> check;
    cout << check << endl;
    if (check == "noInput") {
      for (int i = 0; i < 4; i++) {
        digitalWrite(pins[i], LOW);
      }
    }
    else {
      break;
    }
  }
  cout << "enter motor to move(fwrd, back, left, right, fwrdleft, fwrdright): ";
  cin >> movement;
  cout << movement << endl;

  if (movement == "fwrd") {
    moveMotor(fwrd);
  }
  else if (movement == "back") {
    moveMotor(back);
  }
  else if (movement == "left") {
    moveMotor(lft);
  }
  else if (movement == "right") {
    moveMotor(rght);
  }
  else if (movement == "fwrdleft") {
    moveMotorComb(lft, fwrd);
  }
  else if (movement == "fwrdright") {
    moveMotorComb(rght, fwrd);
  }
}



void moveMotor(int pin) {
  digitalWrite(pin, HIGH);
}

void moveMotorComb(int pin1, int pin2) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
}






















