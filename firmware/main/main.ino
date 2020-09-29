/*
  Example Code To Get ESP32 To Connect To A Router Using WPS
  ===========================================================
  This example code provides both Push Button method and Pin
  based WPS entry to get your ESP connected to your WiFi router.

  Hardware Requirements
  ========================
  ESP32 and a Router having atleast one WPS functionality

  This code is under Public Domain License.

  Author:
  Pranav Cherukupalli <cherukupallip@gmail.com>
*/

unsigned long previousMillisWiFi = 0; // Memorizza l'ultimo volta che l'evento è stato aggiornato
long intervalWiFi = 6000; // Variabile per l'intervallo di tempo tra un tentativo di connessione e l'altro.


#include "WiFi.h"
#include "esp_wps.h"
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial
/*
  Change the defin dition of the WPS mode
  from WPS_TYPE_PBC to WPS_TYPE_PIN in
  the case that you are using pin type
  WPS
*/
#define ESP_WPS_MODE      WPS_TYPE_PBC
#define ESP_MANUFACTURER  "ESPRESSIF"
#define ESP_MODEL_NUMBER  "ESP32"
#define ESP_MODEL_NAME    "ESPRESSIF IOT"
#define ESP_DEVICE_NAME   "ESP STATION"
#define LED_INSIDE 2

char auth[] = "ZAzXQpO9XMwdB4tUMgWGusw7kNIISFTp";

static esp_wps_config_t config;

void wpsInitConfig() {
  config.crypto_funcs = &g_wifi_default_wps_crypto_funcs;
  config.wps_type = ESP_WPS_MODE;
  strcpy(config.factory_info.manufacturer, ESP_MANUFACTURER);
  strcpy(config.factory_info.model_number, ESP_MODEL_NUMBER);
  strcpy(config.factory_info.model_name, ESP_MODEL_NAME);
  strcpy(config.factory_info.device_name, ESP_DEVICE_NAME);
}

String wpspin2string(uint8_t a[]) {
  char wps_pin[9];
  for (int i = 0; i < 8; i++) {
    wps_pin[i] = a[i];
  }
  wps_pin[8] = '\0';
  return (String)wps_pin;
}

void WiFiEvent(WiFiEvent_t event, system_event_info_t info) {
  switch (event) {
    case SYSTEM_EVENT_STA_START:
      Serial.println("Station Mode Started");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.println("Connected to :" + String(WiFi.SSID()));
      Serial.print("Got IP: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("Disconnected from station, attempting reconnection");
      WiFi.reconnect();
      break;
    case SYSTEM_EVENT_STA_WPS_ER_SUCCESS:
      Serial.println("WPS Successfull, stopping WPS and connecting to: " + String(WiFi.SSID()));
      esp_wifi_wps_disable();
      delay(10);
      WiFi.begin();
      break;
    case SYSTEM_EVENT_STA_WPS_ER_FAILED:
      Serial.println("WPS Failed, retrying");
      esp_wifi_wps_disable();
      esp_wifi_wps_enable(&config);
      esp_wifi_wps_start(0);
      break;
    case SYSTEM_EVENT_STA_WPS_ER_TIMEOUT:
      Serial.println("WPS Timedout, retrying");
      esp_wifi_wps_disable();
      esp_wifi_wps_enable(&config);
      esp_wifi_wps_start(0);
      break;
    case SYSTEM_EVENT_STA_WPS_ER_PIN:
      Serial.println("WPS_PIN = " + wpspin2string(info.sta_er_pin.pin_code));
      break;
    default:
      break;
  }
}

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
    Serial.print("Connesso a: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    
    Blynk.config(auth);
    bool success = Blynk.connect();
    if(!success){
        Serial.println("Connection failed");
        return;
    }
    Serial.println("Connection succeded");
  }
}

void loop() {
  Blynk.run();
  delay(5000);
  Blynk.virtualWrite(V21, 24);
  delay(5000);
  Blynk.virtualWrite(V21, 12);
}
