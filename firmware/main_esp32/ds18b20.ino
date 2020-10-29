void ds18b20_setup() {
  sensors.begin();
}

float ds18b20() {
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0);
}
