#include <ArduinoSTL.h>
#include <Servo.h>
#include <Arduino.h>
#include "robotic_arm.h"

using namespace std;
void servo::servoHome(){
  for(int i = 0; i < 4; i++){  
  }
}

void servo::attach_servos() {
  servoBase.attach(servo_base);
  servoClaw.attach(servo_claw);
  servoForward.attach(servo_forward);
  servoUpdown.attach(servo_updown);
}

void servo::which_servo(String servo, String dir, String IRcall) {
  if (servo == "servoBase") {
    base_pos = run_servo(base_limit, servoBase, dir, IRcall, base_pos, servo);
  }
  else if (servo == "servoClaw") {
    claw_pos = run_servo(claw_limit, servoClaw, dir, IRcall, claw_pos, servo);
  }
  else if (servo == "servoForward") {
    forward_pos = run_servo(forward_limit, servoForward, dir, IRcall, forward_pos, servo);
  }
  else if (servo == "servoUpdown") {
    updown_pos = run_servo(updown_limit, servoUpdown, dir, IRcall, updown_pos, servo);
  }
}

int servo::run_servo(int* limiting_angle, Servo servo, String dir, String IRcall, int pos, String Serv) {
  if ( dir == "back") {
    if (IRcall == "ffffffff") {
      Serial.print(Serv);
      cout << " Angle: " << pos << endl;
      pos--;
      if (pos <= limiting_angle[0]) {
        pos = limiting_angle[0];
      }
      else {
        servo.write(pos);
        cout << "servo testing" << endl;
      }
    }
  }
  if (dir == "forward") {
    if (IRcall == "ffffffff") {
      Serial.print(Serv);
      cout << " Angle: " << pos << endl;
      pos++;
      if (pos >= limiting_angle[1]) {
        pos = limiting_angle[1];
      }
      else {
        servo.write(pos);
        cout << "servo testing" << endl;
      }
    }
  }
  return pos;
}
