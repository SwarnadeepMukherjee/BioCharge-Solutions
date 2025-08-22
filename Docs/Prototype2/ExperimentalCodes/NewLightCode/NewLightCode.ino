const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const float ldrPin = A0;
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

  if ((distance < 15) and (ldrValue>600) and (ldrValue<1000)) {
    digitalWrite(ledPin, LOW);
  } 
  if  ((distance < 15) and (ldrValue>50) and (ldrValue<400)) {
    digitalWrite(ledPin, 100);
  }
  if  ((distance < 15) and (ldrValue>0) and (ldrValue<50)) {
    digitalWrite(ledPin, HIGH);
  }


  if ((sensorValue == HIGH) and (ldrValue>600) and (ldrValue<1000)) {
    digitalWrite(ledPinOut, LOW);
  }
  if ((sensorValue == HIGH) and (ldrValue>50) and (ldrValue<400)) {
    analogWrite(ledPinOut, 100);
  }
  if ((sensorValue == HIGH) and (ldrValue>0) and (ldrValue<50)) {
    digitalWrite(ledPinOut, HIGH);
  } 
  

  Serial.println(ldrValue);

  delay(1000);

}
