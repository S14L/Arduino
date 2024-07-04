#include <Servo.h>

Servo myservo;
int joyX = A0;
int joyY = A1;
int joySW = 2;
int servoPin = 8;

int valX;
int valY;
int buttonState = 0;

void setup() {
  myservo.attach(servoPin);
  pinMode(joySW, INPUT_PULLUP);
}

void loop() {
  valX = analogRead(joyX);
  valY = analogRead(joyY);
  buttonState = digitalRead(joySW);

  valX = map(valX, 0, 1023, 0, 180);
  myservo.write(valX);

  if (buttonState == LOW) {
    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);
  }

  delay(15);
}
