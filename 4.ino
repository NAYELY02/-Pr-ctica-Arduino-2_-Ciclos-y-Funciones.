const int buttonPin = 2;      
const int potPin = A0;       
const int ledPins[] = {3, 5, 6, 9, 10};  
const int numLeds = 5;

int buttonState = 0;
int lastButtonState = 0;
int ledCount = 1; 
int potValue = 0;
int ledToShow = 0;
int speed = 1000; 

void setup() {
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  potValue = analogRead(potPin);

  
  if (millis() % 1000 == 0) {
    randomSeed(millis()); 
    ledToShow = random(numLeds);
    showSingleLed(ledToShow);
  }

  
  if (buttonState == HIGH && lastButtonState == LOW) {
    ledCount = random(1, numLeds + 1);
    showRandomLeds(ledCount);
  }

  
  speed = map(potValue, 0, 1023, 500, 2000);

  lastButtonState = buttonState;
}

void showSingleLed(int index) {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(ledPins[index], HIGH);
}

void showRandomLeds(int count) {
  for (int i = 0; i < count; i++) {
    ledToShow = random(numLeds);
    digitalWrite(ledPins[ledToShow], HIGH);
  }

  delay(speed);

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}