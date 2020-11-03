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

void runFunction(String message){
  String disp = getSplit(message, '-', 0);
  
  if(disp == "DISP") displayFunctions(getSplit(message, '-', 1));  
  else if(disp == "BUZZ") buzzerFunctions(getSplit(message, '-', 1));  
}

String getSplit(String data, char separator, int index){
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
