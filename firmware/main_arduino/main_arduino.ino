#include "imports.h"

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// RX e TX
SoftwareSerial esp32(RX, TX);

void setup() {
  Serial.begin(115200);
  esp32.begin(115200);
  displaySetup();
}

void loop() {
  String msg = getMessage();
  runFunction(msg);
}
