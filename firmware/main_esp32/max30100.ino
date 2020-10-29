// Callback (registered below) fired when a pulse is detected
void onBeatDetected(){
  Serial.println("Beat detected"); 
  if(!TEMP_ON && millis()-timeLastMeasure > TIME_BEFORE_MEASURE){
    OXIM_ON = true;
  }
}

void max30100_setup(){
  if (!pox.begin()) Serial.println("Falha na conexão com MAX30100");
  else{
    Serial.println("Conexão com MAX30100 sucedida");
    pox.setOnBeatDetectedCallback(onBeatDetected);
  }
  // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}

void max30100(){
  
  double epsilon = 5;
  double delta1 = epsilon;
  double delta2 = epsilon;
  
  double bpm[5];

  double spo2[5];

  uint32_t firstReport = millis();
  uint32_t lastReport = 0;
  do{
    int i = 0;
    double bpmMax = 0;
    double bpmMin = 1000;
    double spo2Max = 0;
    double spo2Min = 1000;
    while(i < 5){
      pox.update();
      if (millis()-lastReport > REPORTING_PERIOD_MS) {
        bpm[i] = pox.getHeartRate();
        spo2[i] = pox.getSpO2();
        if(bpm[i] > bpmMax) bpmMax = bpm[i];
        if(bpm[i] < bpmMin) bpmMin = bpm[i];
        if(spo2[i] > spo2Max) spo2Max = spo2[i];
        if(spo2[i] < spo2Min) spo2Min = spo2[i];
        Serial.print("BPM: ");
        Serial.println(bpm[i]);
        Serial.print("SPO2: ");
        Serial.println(spo2[i]);
        Blynk.virtualWrite(V4, bpm[i]);
        Blynk.virtualWrite(V5, spo2[i]);
        lastReport = millis();
        i++;
      }
    }
    delta1 = abs(bpmMax-bpmMin);
    delta2 = abs(spo2Max-spo2Min);
    Serial.print("Delta1: ");
    Serial.println(delta1);
    Serial.print("Delta2: ");
    Serial.println(delta2);
    //  Tempo limite para fazer medição do oxímetro
    if(lastReport-firstReport > MAX_REPORTING_PERIOD_MS){
      Serial.println("buzzer-falha");
      Serial.println("display-Falha na medição");
      OXIM_ON = false;
      timeLastMeasure = millis();
      return;
    }        
  }
  while(delta1 > epsilon || delta2 > epsilon);
  Serial.println("buzzer-sucesso");
  Serial.println("display-medição concluida");
  OXIM_ON = false;
  timeLastMeasure = millis();
}
