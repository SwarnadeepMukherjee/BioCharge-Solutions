const int irSensorPin = 7;
const int ledPin = 9;
const int photoSensorPin = A1;
int val = 0; 

const int b1 = 1000;
const int b2 = 1010;
const int b3 = 1020;
const int b4 = 1023;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == HIGH) {
    digitalWrite(ledPin, LOW);
  } 
  else {
    analogWrite(ledPin, LOW);
  }

  delay(250);
}
