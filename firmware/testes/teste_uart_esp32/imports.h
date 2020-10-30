// Bibliotecas
#include "WiFi.h"
#include "esp_wps.h"
#include "MAX30100_PulseOximeter.h"
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <BlynkSimpleEsp32.h>

// Constantes 
#define BLYNK_PRINT Serial

#define ESP_WPS_MODE      WPS_TYPE_PBC
#define ESP_MANUFACTURER  "ESPRESSIF"
#define ESP_MODEL_NUMBER  "ESP32"
#define ESP_MODEL_NAME    "ESPRESSIF IOT"
#define ESP_DEVICE_NAME   "ESP STATION"

// Tempos
#define TIMEOUT_WIFI 6000
#define REPORTING_PERIOD_MS 1000
#define MAX_REPORTING_PERIOD_MS 60000
#define TIME_BEFORE_MEASURE 5000

// Mensagens
#define BUZZ_0 "BUZZ-0" 
#define BUZZ_1 "BUZZ-1"
#define BUZZ_2 "BUZZ-2"
#define BUZZ_3 "BUZZ-3"
#define DISP_0 "DISP-0:x"
#define DISP_1 "DISP-1:"
#define DISP_2 "DISP-2:"
#define DISP_3 "DISP-3:x"

// Portas
#define GPIO_4 4
#define LED_INSIDE 2
#define BUTTON 5

#define AUTH "ZAzXQpO9XMwdB4tUMgWGusw7kNIISFTp"
