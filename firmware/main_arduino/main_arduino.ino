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

void setup() {
  Serial.begin(9600);
  displaySetup();
}

void loop() {
  String msg = getMessage();
  displayFunctions(msg);
  buzzerFunctions(msg);
}
