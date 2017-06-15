#include <IRremote.h>
#include <IRremoteInt.h>
#include <Arduino.h>
#include <ArduinoSTL.h>
#include "robotic_arm.h"

using namespace std;

int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
servo Move;

void remote::IRint() {
  irrecv.enableIRIn();
  Move.attach_servos();
}

String remote::IRscan() {
  if (irrecv.decode(&results)) {
    timeout = 0;
    IRvalue = String(results.value, HEX);
    irrecv.resume();
  }
  else if (timeout == 20) {
    IRvalue = "No Signal";
  }
  else {
    timeout++;
  }
  return IRvalue;
}

void remote::Button_detection() {

  cout << "main loop: ";
  Serial.println(IRscan());
  cout << endl;

  if (IRscan() == button4) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoBase", "back", IRscan());
    }
  }
  else if (IRscan() == button6) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoBase", "forward", IRscan());
    }
  }
  else if (IRscan() == button7) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoClaw", "forward", IRscan());
    }
  }
  else if (IRscan() == button9) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoClaw", "back", IRscan());
    }
  }
  else if (IRscan() == button14) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoForward", "forward", IRscan());
    }
  }
  else if (IRscan() == button20) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoForward", "back", IRscan());
    }
  }
  else if (IRscan() == button16) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoUpdown", "forward", IRscan());
    }
  }
  else if (IRscan() == button18) {
    delay(200);
    while (IRscan() == hold_button) {
      Move.which_servo("servoUpdown", "back", IRscan());
    }
  }
  delay(100);
}
