#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int x = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

  display.clearDisplay();

  display.drawCircle(x, 32,10, WHITE);

  display.display();

  x++;
  if(x ==128){
    x = 0;
    x++;
  }

  delay(50);
}
