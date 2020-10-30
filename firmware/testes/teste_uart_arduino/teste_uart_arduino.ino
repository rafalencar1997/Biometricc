#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

#define RS 12
#define EN 11
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define RX 9
#define TX 10

// RX e TX
SoftwareSerial esp32(RX, TX);
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(115200);
  esp32.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biometricc :D");
}

void loop() {
  String msg = getMessage();
  if(msg != ""){
    Serial.println(msg);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
  }
}


String getMessage(){
  String message = "";
  char character;
  while(esp32.available() > 0){
    character = esp32.read();
    message = message + character;
    if(character == '\n'){
      return message;
    }
  }
}
