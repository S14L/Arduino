int redPin= 8;
int greenPin = 9;
int  bluePin = 10;
int val;
const int photoResistor = A0;
void setup() {
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void startrgb(){
  setColor(255, 0, 0);
  delay(100);
  setColor(0,  255, 0);
  delay(100);
  setColor(0, 0, 255);
  delay(100);
  setColor(255, 255, 255);
  delay(100);
  setColor(170, 0, 255);
  delay(100);
  setColor(127, 127,  127);
  delay(100);
}
void stoprgb(){
  setColor(255, 255, 255);
}
void  loop() {
    val = analogRead(photoResistor);
    if(val>600){
      startrgb();
    }else{
      stoprgb();
    }
  

}
void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}
