// Define the pin numbers
const int ledPin = 12;  
const int ledPin2 = 11;
const int irSensorPin = 2; // Pin for the IR sensor module (usually digital)

int sensorState = 0; // Variable to store the state of the IR sensor
int lastSensorState = 0; // Previous state of the sensor to detect changes

void setup() {
  Serial.begin(9600);
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // Initialize the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
}

void loop() {
  // Read the current state of the IR sensor
  sensorState = digitalRead(irSensorPin);
  
  // Check if the sensor state has changed
  if (sensorState != lastSensorState) {
    // If an object is detected (assuming LOW signal from IR sensor when object is detected)
    if (sensorState == LOW) {
      // Toggle the LED state
      digitalWrite(ledPin, !digitalRead(ledPin));
      delay(200); // Delay to debounce the sensor, avoid multiple triggers
    }
  }

  // Save the current state of the sensor for comparison in the next loop
  lastSensorState = sensorState;
  Serial.println(lastSensorState);
}