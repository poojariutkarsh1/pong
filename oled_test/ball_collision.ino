#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int x = 0;
int speed = 1;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

  x += speed;

  if (x >= 127) {
    speed = -1;
  }

  if (x <= 0) {
    speed = 1;
  }

  display.clearDisplay();
  display.drawCircle(x, 32, 10, WHITE);
  display.display();

  delay(5);
}
