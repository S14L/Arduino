#include "DHT.h"
#define sensorDigital 2
#define DHTPIN 3
#define DHTTYPE DHT11
#define LEDPIN 8
#define sensorAnalog A1
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(sensorDigital, INPUT);
  pinMode(LEDPIN, OUTPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  
  delay(3000);
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);
  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("  ");
  Serial.print("Digital value :");
  Serial.println(digital);
  digitalWrite(LEDPIN, HIGH);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } 

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  digitalWrite(LEDPIN, LOW);
}
