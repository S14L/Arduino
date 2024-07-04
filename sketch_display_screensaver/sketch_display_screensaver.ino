#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 

#define OLED_RESET     4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUM_STARS      10
#define METEORITE_FREQ 50
#define STAR_SPEED     1
#define METEORITE_SPEED 2

#define STAR_WIDTH     2
#define STAR_HEIGHT    2

#define METEORITE_WIDTH  4
#define METEORITE_HEIGHT 4

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.display();

  setupStars();
}

void loop() {
  animateStars();
  delay(50);
}

int stars[NUM_STARS][3];
bool meteoriteActive = false;
int meteorite[3];

void setupStars() {
  for (int i = 0; i < NUM_STARS; i++) {
    stars[i][0] = random(display.width());
    stars[i][1] = random(-display.height(), 0);
    stars[i][2] = STAR_SPEED;
  }
}

void animateStars() {
  display.clearDisplay();

  for (int i = 0; i < NUM_STARS; i++) {
    display.fillRect(stars[i][0], stars[i][1], STAR_WIDTH, STAR_HEIGHT, SSD1306_WHITE);
    stars[i][1] += stars[i][2];
    if (stars[i][1] >= display.height()) {
      stars[i][0] = random(display.width());
      stars[i][1] = random(-display.height(), 0);
      stars[i][2] = STAR_SPEED;
    }
  }

  if (meteoriteActive) {
    display.fillRect(meteorite[0], meteorite[1], METEORITE_WIDTH, METEORITE_HEIGHT, SSD1306_WHITE);
    meteorite[1] += meteorite[2];
    if (meteorite[1] >= display.height()) {
      meteoriteActive = false;
    }
  } else if (random(0, METEORITE_FREQ) == 0) {
    meteorite[0] = random(display.width());
    meteorite[1] = random(-METEORITE_HEIGHT, 0);
    meteorite[2] = METEORITE_SPEED;
    meteoriteActive = true;
  }

  display.display();
}
