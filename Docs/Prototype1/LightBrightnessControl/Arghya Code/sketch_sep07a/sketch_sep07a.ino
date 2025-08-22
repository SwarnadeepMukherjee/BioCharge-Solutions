// Define pin connections
const int photoSensorPin = A0;  // Pin for the photoresistor
const int ledPin = 9;           // Pin for the LED

// Variable to store the sensor value
int sensorValue = 0;
int outval = 0;
int ledBrightness = 0;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  pinMode(photoSensorPin, INPUT);
  // Start serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Read the value from the photoresistor (0 to 1023)
  sensorValue = analogRead(photoSensorPin);
  
  // Map the sensor value (light intensity) to the LED brightness (0 to 255)
  // Higher light -> lower brightness
  ledBrightness = map(sensorValue, 0, 1023, 255, 0);
  // ledBrightness = 255 - ((sensorValue/1023)* 255);
  int lightval = constrain(outval, 0,255);

  // Set the LED brightness (0 to 255)
  analogWrite(ledPin, ledBrightness);

  // Print sensor value and LED brightness for debugging
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(ledBrightness);

  // Small delay to stabilize readings
  delay(200);
}
