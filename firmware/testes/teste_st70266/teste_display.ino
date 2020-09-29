#include <LiquidCrystal.h>

//Display |ESP32 |Pino
//RS      |d04   |24, 
//EN      |d02   |22, 
//D4      |d27   |16, 
//D5      |d14   |17, 
//D6      |d12   |18, 
//D7      |d13   |20;
const int RS = 24, EN = 22, D4 = 16, D5 = 17, D6 = 18, D7 = 20;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(2, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("hello, world!");
  digitalWrite(2, HIGH);
  delay(5000);
  lcd.print("batata!");
  digitalWrite(2, LOW);
  delay(5000);
}
