int ledPin = 9;      // LED connected to digital pin 9
    int analogPin = A0;   // potentiometer connected to analog pin 3
    int val = 0;         // variable to store the read value

    void setup() {
      Serial.begin(9600);
      pinMode(ledPin, OUTPUT);  // sets the pin as output
    }

    void loop() {
      val = analogRead(analogPin);
      Serial.println(val);
      
      analogWrite(ledPin, (255/1024)*val);

      if (val <= 1000) {
        analogWrite(ledPin, 255);
      }
      else if (val <= 1013) {
        analogWrite(ledPin, 150);
      }
      else if (val <= 1018) {
        analogWrite(ledPin, 75);
      }
      else if (val <= 1023) {
        analogWrite(ledPin, 0);
      }
      else{
        analogWrite(ledPin, 0);
      }


      delay(200);
    }
