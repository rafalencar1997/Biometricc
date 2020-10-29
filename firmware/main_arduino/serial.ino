String getMessage(){
  String message = "";
  char character;
  while(Serial.available() > 0){
    character = Serial.read();
    message = message + character;
    if(character == '\n'){
      return message;
    }
  }
}
