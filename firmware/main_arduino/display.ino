void displaySetup() {  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Biometricc :D");
}

void displayFunctions(String msg) {
  int code = getSplit(msg, ':', 0).toInt();
  Serial.println(msg);
  Serial.println(code);
  switch(code) {
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Biometricc :D");
      break;
    case 1:  
      String temp = getSplit(msg, ':', 1);
      temp.remove(temp.length()-1);
      temp.remove(temp.length()-1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print(temp);
      lcd.print("oC");
      break;
    case 2:  
      String values = getSplit(msg, ':', 1);
      String bpm = getSplit(values, '/', 0);
      String spo2 = getSplit(values, '/', 1);
      spo2.remove(spo2.length()-1);    
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BPM: ");
      lcd.print(bpm);
      lcd.setCursor(0, 1);
      lcd.print("SPO2: ");
      lcd.print(spo2);
      lcd.print("%");
      break;  
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Falha na Medicao");
      lcd.setCursor(0, 1);
      lcd.print("Tempo Esgotado");
      break; 
    default: 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Biometricc :D");
      break;
  }   
}
