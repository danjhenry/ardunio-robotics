#include <IRremote.h>
#include <ArduinoSTL.h>
#include <IRremoteInt.h>
#include <Arduino.h>
#include <Servo.h>

class servo {
  public:
    int run_servo(int* limting_angle, Servo servo, String dir, String IRcall, int pos, String Serv);
    void which_servo(String servo, String dir, String IRcall);
    void home_pos(int home_angle, Servo servo, int servo_pin);
    void attach_servos();
    void servoHome();
  private:
    const int servo_base = 5;
    const int servo_claw = 3;
    const int servo_forward = 9;
    const int servo_updown = 10;

    Servo servoBase;
    Servo servoClaw;
    Servo servoForward;
    Servo servoUpdown;

    int base_limit[2] {0, 180};
    int forward_limit[2] {65, 180};
    int updown_limit[2] {70, 180};
    int claw_limit[2] {135, 180};

    int base_pos;
    int claw_pos;
    int forward_pos;
    int updown_pos;

    int homePos[4] {90, 65, 180, 140};
    Servo servoHome[4] { servoBase, servoForward, servoUpdown, servoClaw};

};

class remote {
  public:
    String IRscan();
    void IRint();
    void Button_detection();

  private:
    String button1 = "e318261b"; // power button
    String button2 = "511dbb"; // vol+ button
    String button3 = "ee886d7f"; // func/stop button
    String button4 = "52a3d41f"; // |<< button
    String button5 = "d7e84b1b"; // >|| button
    String button6 = "20fe4dbb"; // >>| button
    String button7 = "f076c13b"; // \/ button
    String button8 = "a3c8eddb"; // vol- button
    String button9 = "e5cfbd7f"; // /\ button
    String button10 = "c101e57b"; // 0 button
    String button11 = "97483bfb"; // EQ
    String button12 = "f0c41643"; // st/rept
    String button13 = "9716be3f"; // 1 button
    String button14 = "3d9ae3f7"; // 2 button
    String button15 = "6182021b"; // 3 button
    String button16 = "8c22657b"; // 4 button
    String button17 = "488f3cbb"; // 5 button
    String button18 = "449e79f"; // 6 button
    String button19 = "32c6fdf7"; // 7 button
    String button20 = "1bc0157b"; // 8 button
    String button21 = "3ec3fc1b"; // 9 button
    String hold_button = "ffffffff"; // hold button

    String IRvalue = "";
    int timeout = 0;
};
























