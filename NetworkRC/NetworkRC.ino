#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const char* ssid = "QuantiumLink";
const char* password = "HPGNLWZ2DNTXB5K7";

ESP8266WebServer server(80);
Servo turn;

void handleControls() {
  String message = "";
  if (server.arg("aSpeed") != "")
  {
    float Spd = server.arg("aSpeed").toInt();
    analogWrite(D2, Spd);
    analogWrite(D1, Spd);
    message += "motor speed: " + String((Spd / 1023) * 100) + "%\n";
  }
  if (server.arg("aDir") != "")
  {
    String state = "Backward";
    int dir = server.arg("aDir").toInt();
    digitalWrite(D4, dir);
    digitalWrite(D3, dir);
    if (dir) {
      state = "Forward";
    }
    message += "motor direction: " + state + "\n";
  }
  if (server.arg("steerAngle") != "")
  {
    turn.write(server.arg("steerAngle").toInt());
    message += "servo angle: " + server.arg("steerAngle");
  }
  server.send(200, "text / plain", message);
}

void setup() {

  //Communication setup.
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Waiting to connect…");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  server.on("/controls", handleControls);
  server.begin();
  Serial.println("Server listening:");

  //Motor Interface setup.
  pinMode(D1, OUTPUT); // motor A speed (pwm 0 - 1023)
  pinMode(D3, OUTPUT); // motor A direction
  pinMode(D2, OUTPUT); // motor B speed (pwm 0 - 1023)
  pinMode(D4, OUTPUT); // motor B direction
  
  turn.attach(D0); // steering Control (pwm 60 - 80 - 100)
}

void loop() {
  server.handleClient();
}
