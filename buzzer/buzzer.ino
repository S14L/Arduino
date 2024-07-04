  int buzzerPin = 2;
  int buttonPin = 4;
  int buttonState;

  void setup() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
  }


void loop(){
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    digitalWrite(buzzerPin, HIGH);
  }else{
    digitalWrite(buzzerPin, LOW);
  }
}
