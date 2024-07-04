int led = 13;
int reelSwitch = 2;
int switchState;

void setup() 
{
  pinMode (led, OUTPUT);
  pinMode (reelSwitch, INPUT);
}

void loop()
{
  switchState = digitalRead(reelSwitch);
  
  if (switchState == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else 
  {
    digitalWrite(led, LOW);
  }
}