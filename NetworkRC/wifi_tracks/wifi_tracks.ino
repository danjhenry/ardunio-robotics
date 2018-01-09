#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "";
const char* password = "";

ESP8266WebServer server(80);

void handleControls() {
  digitalWrite(LED_BUILTIN, LOW);
  String message = "";
  //motor a
  if (server.arg("aSpeed") != "")
  {
    float Spd = server.arg("aSpeed").toInt();
    analogWrite(D1, Spd);
    message += "motor a speed: " + String((Spd / 1023) * 100) + "%\n";
  }
  if (server.arg("aDir") != "")
  {
    String state = "Backward";
    int dir = server.arg("aDir").toInt();
    digitalWrite(D3, dir);
    if (dir) {
      state = "Forward";
    }
    message += "motor a direction: " + state + "\n";
  }
  //motor b
  if (server.arg("bSpeed") != "")
  {
    float Spd = server.arg("bSpeed").toInt();
    analogWrite(D2, Spd);
    message += "motor b speed: " + String((Spd / 1023) * 100) + "%\n";
  }
  if (server.arg("bDir") != "")
  {
    String state = "Backward";
    int dir = server.arg("bDir").toInt();
    digitalWrite(D4, dir);
    if (dir) {
      state = "Forward";
    }
    message += "motor b direction: " + state + "\n";
  }
  if (server.arg("resp") != "") {
    server.send(200, "text / plain", message);
  }
  else{
      server.send(200);
  }
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
  server.on("/", handleControls);
  server.begin();
  Serial.println("Server listening:");

  //Motor Interface setup.
  pinMode(D1, OUTPUT); // motor A speed (pwm 0 - 1023)
  pinMode(D3, OUTPUT); // motor A direction
  pinMode(D2, OUTPUT); // motor B speed (pwm 0 - 1023)
  pinMode(D4, OUTPUT); // motor B direction

  //LED blink per request.
  pinMode(LED_BUILTIN, OUTPUT); // on board LED
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  server.handleClient();
}

