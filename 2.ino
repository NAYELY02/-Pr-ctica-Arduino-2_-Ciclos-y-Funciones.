const int buttonLeftPin = 2; 
const int buttonRightPin = 3; 
const int ledPins[] = {7, 6, 5, 4, 8}; 
const int numLeds = 5;

int currentLed = 2; 
int buttonLeftState = 0;
int buttonRightState = 0;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonLeftPin, INPUT);
  pinMode(buttonRightPin, INPUT);

  digitalWrite(ledPins[currentLed], HIGH); 
}

void loop() {
  buttonLeftState = digitalRead(buttonLeftPin);
  buttonRightState = digitalRead(buttonRightPin);

  
  if (buttonLeftState == HIGH) {
    delay(50); 

    if (buttonLeftState == HIGH) {
      moveLeft();
      blinkAndStay();
    }
  }

  
  if (buttonRightState == HIGH) {
    delay(50); 

    if (buttonRightState == HIGH) {
      moveRight();
      blinkAndStay();
    }
  }
}

void moveLeft() {
  digitalWrite(ledPins[currentLed], LOW); 


  currentLed = (currentLed - 1 + numLeds) % numLeds;

  digitalWrite(ledPins[currentLed], HIGH); 
}

void moveRight() {
  digitalWrite(ledPins[currentLed], LOW); 

  currentLed = (currentLed + 1) % numLeds;

  digitalWrite(ledPins[currentLed], HIGH); 
}

void blinkAndStay() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < numLeds; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(500);
    for (int j = 0; j < numLeds; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(500);
  }
  digitalWrite(ledPins[currentLed], HIGH); 
}