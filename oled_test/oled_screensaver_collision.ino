#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ballX = 64;
int ballY = 32;

int speedX = 1;
int speedY = 1;

const int radius = 2;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

  // Move ball
  ballX += speedX;
  ballY += speedY;

  // Left and right walls
  if (ballX >= SCREEN_WIDTH - 1 - radius) {
    ballX = SCREEN_WIDTH - 1 - radius;
    speedX = -speedX;
  }

  if (ballX <= radius) {
    ballX = radius;
    speedX = -speedX;
  }

  // Top and bottom walls
  if (ballY >= SCREEN_HEIGHT - 1 - radius) {
    ballY = SCREEN_HEIGHT - 1 - radius;
    speedY = -speedY;
  }

  if (ballY <= radius) {
    ballY = radius;
    speedY = -speedY;
  }

  display.clearDisplay();

  display.fillCircle(ballX, ballY, radius, WHITE);

  display.display();

  delay(15);
}
