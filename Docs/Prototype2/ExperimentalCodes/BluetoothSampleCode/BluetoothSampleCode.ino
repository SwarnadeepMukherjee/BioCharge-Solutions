//YouTube | Tech at Home

#include<SoftwareSerial.h>
#include "DHT.h"

SoftwareSerial B(10,11);    //10-RX,  11-TX

#define DHTPIN 2  
#define DHTTYPE DHT11      // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
B.begin(9600);
dht.begin();
}

void loop() 
{
  delay(2000);

  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  B.print("HELLO");
  B.print(",");
  B.print(t);
  B.print(" C");
  B.print(",");
  B.print(f);
  B.print(" F");
  B.print(";");
  delay(20); 
}
