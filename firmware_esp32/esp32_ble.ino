/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use ESP32 BLE
  to connect your project to Blynk.

  Warning: Bluetooth support is in beta!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define BLYNK_USE_DIRECT_CONNECT

#define LED_INSIDE 2

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

//#include <HCSR04.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ZAzXQpO9XMwdB4tUMgWGusw7kNIISFTp";

void setup()
{
  // Debug console
  
  Serial.begin(9600);

  Serial.println("Waiting for connections...");
  
  Blynk.setDeviceName("Biometricc");
  
  Blynk.begin(auth);
  
  pinMode(LED_INSIDE, OUTPUT);            
  digitalWrite(LED_INSIDE, HIGH);
}

BLYNK_WRITE(V10) {
  Serial.println(param.asStr());
}


void loop()
{
  Blynk.run();
  delay(5000);
  Blynk.virtualWrite(V21, 24);
  delay(5000);
  Blynk.virtualWrite(V21, 12);
}
