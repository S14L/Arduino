
const int LED1 = 6;
const int LED2 = 5;
const int LED3 = 4;
const int photoResistor = A0;
int val;

void runleds(){
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED3, LOW);
}

void stopleds(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(photoResistor, INPUT);
}

void loop() {
  val = analogRead(photoResistor);
  Serial.println(val);
  if (val>600){
    runleds();
  }else{
    stopleds();
  }
}
