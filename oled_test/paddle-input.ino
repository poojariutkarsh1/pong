#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_UP 2
#define BTN_DOWN 3

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int paddleY = 20;

void setup() {

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

  // Move paddle up
  if (digitalRead(BTN_UP) == LOW) {
    paddleY--;
  }

  // Move paddle down
  if (digitalRead(BTN_DOWN) == LOW) {
    paddleY++;
  }

  // Prevent paddle leaving screen
  if (paddleY < 0) {
    paddleY = 0;
  }

  if (paddleY > SCREEN_HEIGHT - 20) {
    paddleY = SCREEN_HEIGHT - 20;
  }

  display.clearDisplay();

  // Paddle
  display.fillRect(5, paddleY, 4, 20, WHITE);

  display.display();

  delay(5);
}
