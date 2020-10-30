void ds18b20_setup() {
  sensors.begin();
}

void ds18b20(){
  
  float epsilon = 0.05;
  float delta = epsilon+1;
  
  float temp[5];
  float tempMax = -1000;
  float tempMin = 1000;

  uint32_t firstReport = millis();
  uint32_t lastReport = firstReport;
  while(delta > epsilon || tempMax > thresholdTEMPhigh || tempMin < thresholdTEMPlow){
    //  Tempo limite para fazer medição do temperatura
    if(lastReport-firstReport > MAX_REPORTING_PERIOD_MS){
      Serial.println(DISP_3);
      Serial.println(BUZZ_1);
      Serial.println(DISP_0);
      TEMP_ON = false;
      timeLastMeasure = millis();
      return;
    }  
    int i = 0;
    tempMax = -1000;
    tempMin = 1000;
    while(i < 5){
      sensors.requestTemperatures(); 
      if (millis()-lastReport > REPORTING_PERIOD_MS) {
        temp[i]= round(sensors.getTempCByIndex(0)*100)/100;
        if(temp[i] > tempMax) tempMax = temp[i];
        if(temp[i] < tempMin) tempMin = temp[i];
        Serial.println(DISP_1+(String)temp[i]);
        Blynk.virtualWrite(V3, temp[i]);
        lastReport = millis();
        i++;
      }
    }
    delta = abs(tempMax-tempMin);  
  }

  delay(1000);
  TEMP_ON = false;
  timeLastMeasure = millis();
  Serial.println(BUZZ_2);
  Serial.println(DISP_0);
}
