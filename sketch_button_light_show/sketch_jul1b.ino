const int buttonPin = 4;
const int redPin = 8;
const int greenPin = 9;
const int bluePin = 10;

int buttonState = 0;
int lastButtonState = 0;
bool isRedOn = false;

void setup() {
  pinMode(buttonPin, INPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    if (isRedOn) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    } else {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }

    isRedOn = !isRedOn;
  }
  
  lastButtonState = buttonState;
  
  delay(50);
}
