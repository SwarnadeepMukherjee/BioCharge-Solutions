const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const int ldrPin = A0;
int ldrValue = 0;

const int irSensorPin = 7;
const int ledPinOut = 6;
int val = 0; 

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(ledPinOut, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  ldrValue = analogRead(ldrPin);
  int sensorValue = digitalRead(irSensorPin);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if ((distance < 15) and (ldrValue>50)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }


  if (sensorValue == LOW and ldrValue>50) {
    digitalWrite(ledPinOut, HIGH);
  } 
  if (sensorValue == HIGH) {
    analogWrite(ledPinOut, LOW);
  }

  Serial.println(sensorValue);

  delay(1000);
}
