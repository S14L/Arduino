const int buttonPin = 4;
const int fanPin = 8;
int buttonState;
bool stateRun = false;

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(50);

  if (stateRun){
    digitalWrite(fanPin, HIGH);    
  }else{
    digitalWrite(fanPin, LOW);
  }
  
  if (buttonState == HIGH) {
    stateRun = true;
  } else {
    stateRun = false;
  }
}
