// Define the pin numbers
const int ledPin = 12;     // Pin for the LED
const int irSensorPin = 2; // Pin for the IR sensor module (usually digital)

int sensorState = 0; // Variable to store the state of the IR sensor
int lastSensorState = 0; // Previous state of the sensor to detect changes

const int ldrPin = A0;
int ldrValue = 0;

#include<SoftwareSerial.h>

SoftwareSerial B(10,11);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin);

  sensorState = digitalRead(irSensorPin);

  if (ldrValue>50) {
    digitalWrite(ledPin, LOW);
  }
  else {
  
    if (sensorState != lastSensorState) {
      if (sensorState == LOW) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        delay(200);
      }
    }
  }

  lastSensorState = sensorState;
  Serial.println(ldrValue);
}
