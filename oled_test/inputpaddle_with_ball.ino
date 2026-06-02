// there is no cpu in this, it is just to test the ball collision with the paddle
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_UP 2
#define BTN_DOWN 3

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Paddle
int paddleY = 20;
const int paddleX = 5;
const int paddleWidth = 4;
const int paddleHeight = 20;

// Ball
int ballX = 64;
int ballY = 32;

int speedX = -1;
int speedY = 1;

const int radius = 2;

void setup() {

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

  //INPUT

  if (digitalRead(BTN_UP) == LOW) {
    paddleY -= 2;
  }

  if (digitalRead(BTN_DOWN) == LOW) {
    paddleY += 2;
  }

  // Paddle limits
  if (paddleY < 0) {
    paddleY = 0;
  }

  if (paddleY > SCREEN_HEIGHT - paddleHeight) {
    paddleY = SCREEN_HEIGHT - paddleHeight;
  }

  // BALL MOVEMENT

  ballX += speedX;
  ballY += speedY;

  // Top wall
  if (ballY <= radius) {
    ballY = radius;
    speedY = -speedY;
  }

  // Bottom wall
  if (ballY >= SCREEN_HEIGHT - radius) {
    ballY = SCREEN_HEIGHT - radius;
    speedY = -speedY;
  }

  // Right wall
  if (ballX >= SCREEN_WIDTH - radius) {
    ballX = SCREEN_WIDTH - radius;
    speedX = -speedX;
  }

  //PADDLE COLLISION

  if (
      ballX >= paddleX &&
      ballX <= paddleX + paddleWidth &&
      ballY >= paddleY &&
      ballY <= paddleY + paddleHeight
     )
  {
    speedX = -speedX;
  }

 //DRAW

  display.clearDisplay();

  display.fillRect(
    paddleX,
    paddleY,
    paddleWidth,
    paddleHeight,
    WHITE
  );

  display.fillCircle(
    ballX,
    ballY,
    radius,
    WHITE
  );

  display.display();

  delay(15);
}
