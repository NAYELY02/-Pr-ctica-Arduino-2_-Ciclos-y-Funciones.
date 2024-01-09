const int potPin = A0;   
const int ledPin1 = 2;   
const int ledPin2 = 3;   
const int ledPin3 = 4;   

int potValue;            

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);

  
  if (potValue >= 0 && potValue <= 500) {
    digitalWrite(ledPin1, HIGH);
    delay(1000);
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin3, HIGH);
    delay(1000);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  
  else if (potValue > 500 && potValue <= 1000) {
    digitalWrite(ledPin3, HIGH);
    delay(1000);
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin1, HIGH);
    delay(1000);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
  }
}