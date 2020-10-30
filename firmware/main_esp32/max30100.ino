// Callback (registered below) fired when a pulse is detected
void onBeatDetected(){
//  Serial.println("Beat detected"); 
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
  
  float epsilon1 = 5;
  float epsilon2 = 1;
  float delta1 = epsilon1;
  float delta2 = epsilon2;
  
  float bpm[5];
  float bpmMax = 0;
  float bpmMin = 1000;

  float spo2[5];
  float spo2Max = 0;
  float spo2Min = 1000;

  uint32_t firstReport = millis();
  uint32_t lastReport = firstReport;
  do{
    //  Tempo limite para fazer medição do oxímetro
    if(lastReport-firstReport > MAX_REPORTING_PERIOD_MS){
      Serial1.println(DISP_5);
      Serial.println(BUZZ_1);
      Serial.println(DISP_0);
      OXIM_ON = false;
      timeLastMeasure = millis();
      return;
    } 
    int i = 0;
    bpmMax = 0;
    bpmMin = 1000;
    spo2Max = 0;
    spo2Min = 1000;
    while(i < 5){
      pox.update();
      if (millis()-lastReport > REPORTING_PERIOD_MS) {
        bpm[i] = round(pox.getHeartRate()*100)/100;
        spo2[i] = round(pox.getSpO2()*100)/100;
        if(bpm[i] > bpmMax) bpmMax = bpm[i];
        if(bpm[i] < bpmMin) bpmMin = bpm[i];
        if(spo2[i] > spo2Max) spo2Max = spo2[i];
        if(spo2[i] < spo2Min) spo2Min = spo2[i];
        Serial.println(DISP_4+(String)bpm[i]+"/"+(String)spo2[i]);
        Blynk.virtualWrite(V4, bpm[i]);
        Blynk.virtualWrite(V5, spo2[i]);
        lastReport = millis();
        i++;
      }
    }
    delta1 = abs(bpmMax-bpmMin);
    delta2 = abs(spo2Max-spo2Min);       
  }
  while(delta1 > epsilon1 || delta2 > epsilon2 || 
        spo2Max > thresholdO2high  || spo2Min < thresholdO2low ||
        bpmMax  > thresholdBPMhigh || bpmMin  < thresholdBPMlow);
  Serial.println(BUZZ_2);
  Serial.println(DISP_0);
  OXIM_ON = false;
  timeLastMeasure = millis();
}
