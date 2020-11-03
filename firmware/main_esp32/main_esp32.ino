#include "imports.h"

// Objetos de Globais
static esp_wps_config_t config;
PulseOximeter pox;
OneWire oneWire(GPIO_4);
DallasTemperature sensors(&oneWire);

int const thresholdO2low = 50;
int const thresholdO2high = 100;
int const thresholdBPMlow = 60;
int const thresholdBPMhigh = 190;
int const thresholdTEMPhigh = 50;
int const thresholdTEMPlow = 30;

// Semáforos
boolean TEMP_ON = false;
boolean OXIM_ON = false;
uint32_t timeLastMeasure = 0;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON, INPUT); 
  pinMode(LED_INSIDE, OUTPUT);            
  digitalWrite(LED_INSIDE, HIGH);

  // Configuração do WiFi e Blynk 
  WiFi_setup();
  // Configuração dos sensor de temperatura
  ds18b20_setup();
  // Configuração dos sensor oxímetro
  max30100_setup();

  Serial.println(DISP_0);
//  Serial.println(BUZZ_3);
//  delay(30000);
  digitalWrite(LED_INSIDE, LOW);
}

void loop() {
  Blynk.run();
  pox.update();
  if(OXIM_ON){
    digitalWrite(LED_INSIDE, HIGH);
    max30100();
    max30100_setup();
    digitalWrite(LED_INSIDE, LOW);
  }
  if(digitalRead(BUTTON) == LOW && 
     !OXIM_ON && millis()-timeLastMeasure > TIME_BEFORE_MEASURE){
    TEMP_ON = true;
    digitalWrite(LED_INSIDE, HIGH);
    ds18b20();
    digitalWrite(LED_INSIDE, LOW);
  }
}
