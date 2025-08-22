// Define the pins for the IR sensor and LED
const int irSensorPin = 7; // IR sensor output pin
const int ledPin = 13;      // LED pin

void setup() {
  // Initialize the IR sensor pin as input
  pinMode(irSensorPin, INPUT);
  // Initialize the LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the value from the IR sensor
  int sensorValue = digitalRead(irSensorPin);

  // If the sensor detects an object, turn on the LED
  if (sensorValue == HIGH) {
    digitalWrite(ledPin, LOW);
  } 
  // If no object is detected, turn off the LED
  else {
    digitalWrite(ledPin, HIGH);
  }
}
