unsigned long previousMillisWiFi = 0; // Memorizza l'ultimo volta che l'evento è stato aggiornato
long intervalWiFi = 6000; // Variabile per l'intervallo di tempo tra un tentativo di connessione e l'altro.

#include "WiFi.h"
#include "esp_wps.h"
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial

#define ESP_WPS_MODE      WPS_TYPE_PBC
#define ESP_MANUFACTURER  "ESPRESSIF"
#define ESP_MODEL_NUMBER  "ESP32"
#define ESP_MODEL_NAME    "ESPRESSIF IOT"
#define ESP_DEVICE_NAME   "ESP STATION"
#define LED_INSIDE 2

char auth[] = "ZAzXQpO9XMwdB4tUMgWGusw7kNIISFTp";

static esp_wps_config_t config;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode(LED_INSIDE, OUTPUT);            
  digitalWrite(LED_INSIDE, HIGH);

  Serial.println();
  Serial.println("Avvio la WiFi");

  WiFi.begin();

  Serial.print("Connessione all'ultimo AP");

  while (WiFi.status() != WL_CONNECTED) {
    if (previousMillisWiFi < intervalWiFi){
      previousMillisWiFi = millis();
      Serial.print(".");
      delay(500);
    }
    else break;
  }

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.onEvent(WiFiEvent);
    WiFi.mode(WIFI_MODE_STA);
    Serial.println("Starting WPS");
    wpsInitConfig();
    esp_wifi_wps_enable(&config);
    esp_wifi_wps_start(0);
  }
  else {
    Serial.println();
    Serial.print("Conectado a: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    
    Blynk.config(auth);
    bool success = Blynk.connect();
    if(!success){
        Serial.println("Falha na conexão com o Blynk");
        return;
    }
    Serial.println("Sucesso na conexão com o Blynk");
  }

  ds18b20_setup();

//  max30100_setup();
  
}

void loop() {
  Blynk.run();
  delay(2000);
  float x = ds18b20();
  // BPM
  Blynk.virtualWrite(V3, x);
  // Oxigenação
  delay(2000);
}
