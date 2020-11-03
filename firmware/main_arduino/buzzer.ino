int melody[] = {
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };
 int melody2[] = {
  NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_AS3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, 
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_G4, 0, 0, 0,
  NOTE_C4, NOTE_AS3, NOTE_A3, NOTE_F3,
  NOTE_G3, 0, NOTE_G3,
  NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_A3,
  0, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_AS3, NOTE_A3,
  NOTE_G3, 0, NOTE_G3,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_G3, 0, NOTE_G3, 
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_G3, 0, NOTE_G3, 
  NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_A3,
  0, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_AS3, NOTE_A3,
  NOTE_G3, 0, NOTE_G3,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_G3, 0, NOTE_G3, 
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4,
  NOTE_G3, 0, NOTE_G3 
 };

void buzzerFunctions(String msg){
  int code = msg.toInt();
  switch(code) {
    // Som de falha
    case 1:
      for (int j = 0; j < 3; j++) {
          tone(BUZZER, NOTE_G4);  
          delay(1000); 
          noTone(BUZZER);
          delay(250);
      }
      break;
    // Som de fim de medição  
    case 2:
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          tone(BUZZER, NOTE_A5);  
          delay(50); 
          noTone(BUZZER);
          delay(50);
        }
        delay(500);
      }
      break; 
    case 3:
      for (int thisNote = 0; thisNote < 91; thisNote++) {
        int noteDuration = 188;
        tone(BUZZER, melody2[thisNote], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(BUZZER);
      }    
      break; 
    default : 
      break;
  }
}
