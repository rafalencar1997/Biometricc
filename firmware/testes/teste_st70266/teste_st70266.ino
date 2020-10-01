#include <LiquidCrystal.h>

//Display |ESP32 |Pino
//RS      |d04   |24, 
//EN      |d02   |22, 
//D4      |d27   |16, 
//D5      |d14   |17, 
//D6      |d12   |18, 
//D7      |d13   |20;
//const int RS = 24, EN = 22, D4 = 16, D5 = 17, D6 = 18, D7 = 20;
//
//LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biometricc :D");
}

void loop() {
}
