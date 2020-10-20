#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 4;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void ds18b20_setup() {
  sensors.begin();
}

float ds18b20() {
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0);
}
