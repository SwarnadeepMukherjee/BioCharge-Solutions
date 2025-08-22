const int input1 = 10;

void setup() {
  pinMode(input1, OUTPUT);
}

void loop() {
  digitalWrite(input1, HIGH);
  delay(15000);
  digitalWrite(input1, LOW);
  delay(20000);
}
