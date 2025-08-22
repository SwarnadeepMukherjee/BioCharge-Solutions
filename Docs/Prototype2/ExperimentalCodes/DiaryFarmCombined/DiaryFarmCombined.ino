const int trigPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int ledPin = 13; // LED Pin
const int ldrPin = A0;
int ldrValue = 0;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize Serial communication
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  ldrValue = analogRead(ldrPin);

  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (back and forth)

  // Check the distance and control the LED
  if ((distance < 10) and (ldrValue>50)) { // If the object is within 10 cm
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    digitalWrite(ledPin, LOW); // Turn LED off
  }

  // Print the distance on Serial Monitor
  Serial.println(ldrValue);

  delay(500); // Wait for 500 milliseconds
}
