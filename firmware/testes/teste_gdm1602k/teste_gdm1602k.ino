#include <LiquidCrystal.h>

//Display |ESP32 |Pino
//RS      |d04   |24, 
//EN      |d02   |22, 
//D4      |d27   |16, 
//D5      |d14   |17, 
//D6      |d12   |18, 
//D7      |d13   |20;
//const int RS = 4, EN = 2, D4 = 27, D5 = 14, D6 = 12, D7 = 13;
//
//LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
//LiquidCrystal lcd(12, 11, 2, 3, 4, 5);
LiquidCrystal lcd(22,23,5,18,19,21);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biometricc :D");
}

void loop() {
}
