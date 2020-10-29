#include "imports.h"

// Objetos de Globais
static esp_wps_config_t config;
PulseOximeter pox;
OneWire oneWire(GPIO_4);
DallasTemperature sensors(&oneWire);

int const thresholdO2 = 50;
int const thresholdBPMlow = 60;
int const thresholdBPMhigh = 190;

// Semáforos
boolean TEMP_ON = false;
boolean OXIM_ON = false;
uint32_t timeLastMeasure = 0;

// Configuração Inicial
void setup() {
  Serial.begin(115200);
  
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
  //  Temperartura
  //  float temp = float(ds18b20(),1);
  //  Blynk.virtualWrite(V3, temp);

}
