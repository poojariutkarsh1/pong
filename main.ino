#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define buzzer 8

#define BTN_UP 2
#define BTN_DOWN 3

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//boolean for restarting game and variables
bool gameOver = false;
bool playerWon = false;

//player and cpu score
int playerScore = 0;
int cpuScore = 0;

//Player paddle

int paddleY = 20;
const int paddleX = 5;
const int paddleWidth = 4;
const int paddleHeight = 20;

//Cpu paddle

int cpuY = 20;
const int cpuX = 119;

//Ball

int ballX = 64;
int ballY = 32;

int speedX = -1;
int speedY = 1;

const int radius = 2;

void winnersound()
{
  tone(buzzer, 523,400);
  delay(400);

  tone(buzzer, 659,400);
  delay(400);

  tone(buzzer, 784, 800);
  delay(800);
}

void losersound()
{
  tone(buzzer, 500, 400);
  delay(400);

  tone(buzzer, 400, 400);
  delay(400);

  tone(buzzer, 250, 800);
  delay(800);
}
void resetBall(){
  ballX = SCREEN_WIDTH/2;
  ballY = SCREEN_HEIGHT /2;
  speedX = -speedX;
}

void playerScores()
{
  playerScore++;
  tone(buzzer, 600, 100);

  resetBall();
}

void cpuScores()
{
  cpuScore++;
  tone(buzzer, 300, 100);

  resetBall();
}

void restartGame()
{
  playerScore = 0;
  cpuScore = 0;

  paddleY = 20;
  cpuY = 20;

  ballX = 64;
  ballY = 32;

  speedX = -1;
  speedY = 1;

  gameOver = false;
  playerWon = false;
}

void drawScore()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(55,0);

  display.print(playerScore);

  display.print(":");

  display.print(cpuScore);
}

/* void WinScreen(char* winner)
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(10,25);

  display.print(winner);

  display.display();
} */

void setup() {

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

    if(gameOver)
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  if(playerWon)
  {
    display.setCursor(35,20);
    display.print("YOU WIN");
  }
  else
  {
    display.setCursor(30,20);
    display.print("CPU WINS");
  }

  display.setCursor(15,45);
  display.print("Press UP");

  display.display();

  if(digitalRead(BTN_UP) == LOW)
  {
    restartGame();
  }

  delay(100);

  return;
}

  // player input

  if (digitalRead(BTN_UP) == LOW) {
    paddleY -= 2;
  }

  if (digitalRead(BTN_DOWN) == LOW) {
    paddleY += 2;
  }

  // Player boundaries

  if (paddleY < 0) {
    paddleY = 0;
  }

  if (paddleY > SCREEN_HEIGHT - paddleHeight) {
    paddleY = SCREEN_HEIGHT - paddleHeight;
  }

  //cpu ai

  int cpuCenter = cpuY + paddleHeight / 2;
  int targetY = ballY + random(-15,15);

  if (targetY > cpuCenter) {
    cpuY++;
  }

  if (targetY < cpuCenter) {
    cpuY--;
  }

  // CPU boundaries

  if (cpuY < 0) {
    cpuY = 0;
  }

  if (cpuY > SCREEN_HEIGHT - paddleHeight) {
    cpuY = SCREEN_HEIGHT - paddleHeight;
  }

       //Ball movement

  ballX += speedX;
  ballY += speedY;

  // Top wall

  if (ballY <= radius) {
    ballY = radius;
    speedY = -speedY;
    tone(buzzer, 550, 100);
  }

  // Bottom wall

  if (ballY >= SCREEN_HEIGHT - radius) {
    ballY = SCREEN_HEIGHT - radius;
    speedY = -speedY;
    tone(buzzer, 550, 100);
  }

  if (ballX < 0)
{
  cpuScores();
}

if (ballX > SCREEN_WIDTH)
{
  playerScores();
}

  //player paddle collision

  if (
      ballX >= paddleX &&
      ballX <= paddleX + paddleWidth &&
      ballY >= paddleY &&
      ballY <= paddleY + paddleHeight
     )
  {
    speedX = -speedX;
    tone(buzzer, 1000, 100);
  }

  //Cpu paddle collision

  if (
      ballX >= cpuX &&
      ballX <= cpuX + paddleWidth &&
      ballY >= cpuY &&
      ballY <= cpuY + paddleHeight
     )
  {
    speedX = -speedX;
    tone(buzzer, 1000, 100);
  }

if(playerScore >= 3)
{
  winnersound();
  

  gameOver = true;
  playerWon = true;
}

if(cpuScore >= 3)
{
  losersound();
  

  gameOver = true;
  playerWon = false;
}

  //Drawing the things

  display.clearDisplay();

  // Player paddle
  display.fillRect(
    paddleX,
    paddleY,
    paddleWidth,
    paddleHeight,
    WHITE
  );

  // CPU paddle
  display.fillRect(
    cpuX,
    cpuY,
    paddleWidth,
    paddleHeight,
    WHITE
  );

  // Ball
  display.fillCircle(
    ballX,
    ballY,
    radius,
    WHITE
  );

drawScore();

  display.display();

  delay(5);
}
