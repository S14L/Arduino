const int soundSensorPin = A0;
const int BUFFER_SIZE = 100;
int buffer[BUFFER_SIZE];
#define LED_PIN1 6
#define LED_PIN2 7
#define LED_PIN3 8
int index = 0;
int sum = 0;
int count = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 0;
  }
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue);

  // Subtract the oldest value from the sum
  sum -= buffer[index];

  // Update the buffer with the new value
  buffer[index] = soundValue;

  // Add the new value to the sum
  sum += soundValue;

  // Move to the next position in the buffer
  index = (index + 1) % BUFFER_SIZE;

  // Keep track of the number of valid readings
  if (count < BUFFER_SIZE) {
    count++;
  }
  // Calculate the average
  int average = sum / count;

  Serial.print("The average is: ");
  Serial.println(average);

  int threshold = 10;
  if (average > threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(average <= 10 ){
    digitalWrite(LED_PIN1, HIGH);
  }else{
    digitalWrite(LED_PIN1, LOW);
  }
  if(average <= 20 && average > 10){
      digitalWrite(LED_PIN2, HIGH);
    }else{
      digitalWrite(LED_PIN2, LOW);}
    if(average >21){
      digitalWrite(LED_PIN3, HIGH);
    }else{digitalWrite(LED_PIN3, LOW);}


}