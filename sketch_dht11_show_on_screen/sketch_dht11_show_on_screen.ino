#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define MQ7_PIN A0
#define MQ8_PIN A1

#define NUM_READINGS 10

float humidityReadings[NUM_READINGS];
float temperatureReadings[NUM_READINGS];
int mq7Readings[NUM_READINGS];
int mq8Readings[NUM_READINGS];

int readIndex = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.display();

  pinMode(MQ7_PIN, INPUT);
  pinMode(MQ8_PIN, INPUT);

  for (int i = 0; i < NUM_READINGS; i++) {
    humidityReadings[i] = 0;
    temperatureReadings[i] = 0;
    mq7Readings[i] = 0;
    mq8Readings[i] = 0;
  }
}

void loop() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();

  int mq7Value = analogRead(MQ7_PIN);
  int mq8Value = analogRead(MQ8_PIN);

  humidityReadings[readIndex] = humidity;
  temperatureReadings[readIndex] = temperatureC;
  mq7Readings[readIndex] = mq7Value;
  mq8Readings[readIndex] = mq8Value;

  readIndex = (readIndex + 1) % NUM_READINGS;

  float avgHumidity = 0;
  float avgTemperature = 0;
  float avgMq7 = 0;
  float avgMq8 = 0;

  for (int i = 0; i < NUM_READINGS; i++) {
    avgHumidity += humidityReadings[i];
    avgTemperature += temperatureReadings[i];
    avgMq7 += mq7Readings[i];
    avgMq8 += mq8Readings[i];
  }

  avgHumidity /= NUM_READINGS;
  avgTemperature /= NUM_READINGS;
  avgMq7 /= NUM_READINGS;
  avgMq8 /= NUM_READINGS;

  float mq7Concentration = (avgMq7 / 1023.0) * 100;
  float mq8Concentration = (avgMq8 / 1023.0) * 100;

  Serial.print(F("Avg Humidity: "));
  Serial.print(avgHumidity);
  Serial.print(F("%  Avg Temperature: "));
  Serial.print(avgTemperature);
  Serial.print(F("°C "));
  Serial.print(F("  Avg MQ-7 CO Concentration: "));
  Serial.print(mq7Concentration);
  Serial.println(F(" ppm"));
  Serial.print(F("Avg MQ-8 H2 Concentration: "));
  Serial.print(mq8Concentration);
  Serial.println(F(" ppm"));

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print(F("Avg Hum: "));
  display.print(avgHumidity);

  display.setCursor(0, 8);
  display.print(F("Avg Temp: "));
  display.print(avgTemperature);
  display.print(F("C "));

  display.setCursor(0, 16);
  display.print(F("Avg MQ-7 CO: "));
  display.print(mq7Concentration);
  display.println(F(" ppm"));

  display.setCursor(0, 24);
  display.print(F("Avg MQ-8 H2: "));
  display.print(mq8Concentration);
  display.println(F(" ppm"));

  display.display();

  delay(1000);
}
