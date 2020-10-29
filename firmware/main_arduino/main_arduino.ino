#include "imports.h"

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  Serial.begin(115200);
  delay(10);
  displaySetup();
}

void loop() {
  String msg = getMessage();
  
  displayFunctions(msg);
  buzzerFunctions(msg);
}
