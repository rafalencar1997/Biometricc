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

// Configuração Inicial
void setup() {
  Serial.begin(115200);

  pinMode(BUTTON, INPUT); 
  pinMode(LED_INSIDE, OUTPUT);            
  digitalWrite(LED_INSIDE, HIGH);

  // Configuração do WiFi e Blynk 
  WiFi_setup();
  // Configuração dos sensor de temperatura
  ds18b20_setup();
  // Configuração dos sensor oxímetro
  max30100_setup();

  // Mensagem serial para o display  
  Serial.println("display-welcome");
}

// Loop do Código
void loop() { 
  Blynk.run();
  pox.update();
  if(OXIM_ON){
    max30100();
  }
  if(digitalRead(BUTTON) == LOW && 
     !OXIM_ON && millis()-timeLastMeasure > TIME_BEFORE_MEASURE){
     TEMP_ON = true;
    ds18b20();
  }
}
