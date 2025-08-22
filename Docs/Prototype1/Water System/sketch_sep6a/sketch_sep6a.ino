const int detectorPin = A0;
const int pump1 = 11;
const int buzzer = 8;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pump1, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  Serial.println(val);

  val = analogRead(detectorPin);

  if (val >= 1000) {
    digitalWrite(pump1, 0);
    delay(1000);
    digitalWrite(buzzer, HIGH);

  }
  else{
    digitalWrite(pump1, 255);
    digitalWrite(buzzer, LOW);
  }
}