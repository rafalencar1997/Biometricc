#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// PulseOximeter is the higher level interface to the sensor
// it offers:
//  * beat detection reporting
//  * heart rate calculation
//  * SpO2 (oxidation level) calculation
PulseOximeter pox;
float BPM, SpO2;
uint32_t tsLastReport = 0;

#define REPORTING_PERIOD_MS     1000

// Callback (registered below) fired when a pulse is detected
void onBeatDetected(){
    Serial.println("Beat Detected!");
}

void max30100_setup(){
    if (!pox.begin()){
         Serial.println("FAILED");
         for(;;);
    }
    else{
         Serial.println("SUCCESS");
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}


void max30100(){
    pox.update();
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS){
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" bpm / SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");
        tsLastReport = millis();
    }    
}
