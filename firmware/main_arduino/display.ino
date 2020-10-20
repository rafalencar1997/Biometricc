#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void displaySetup() {  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biometricc :D");
}


void displayFunctions(msg) {

  switch(msg) {
    case :
      lcd.clear();
      lcd.setCursor(0, 0);
      if(mgs == "Init"){
        lcd.print("Biometricc :D");
    }  
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Biometricc :D");
    default : 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Biometricc :D");
  }   
}
