const int analogPin = A2;
const int solarPin = A1;
const int batteryPin = A0;

float voltage = 0.0;
float solarVolts = 0.0;
float batteryVolts = 0.0;

#include<SoftwareSerial.h>
#include "DHT.h"

SoftwareSerial B(10,11);

#define DHTPIN 2  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  B.begin(9600);
  dht.begin();
}

void loop() {

    int sensorValue = analogRead(analogPin);
    int solarValue = analogRead(solarPin);
    int batteryValue = analogRead(batteryPin);
    voltage = sensorValue * (5.0 / 1023.0);
    float eff = (voltage/4.5)*100;

    solarVolts = solarValue * (5.0 / 1023.0);
    batteryVolts = batteryValue * (5.0 / 1023.0);
    eachMFC = voltage/9;


    B.print(voltage);
    B.print("V");
    B.print(",");
    B.print(eachMFC);
    B.print("V");
    B.print(",");
    B.print(eff);
    B.print("%");
    B.print(",");
    B.print(solarVolts);
    B.print("V");
    B.print(",");
    B.print(batteryVolts);
    B.print("V");
    B.print(";");
    delay(2000);
}
