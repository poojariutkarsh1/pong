#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void drawFace(int x)
{
    display.fillCircle(x - 20,20,3,WHITE);
    display.fillCircle(x + 20,20,3,WHITE);
    display.drawLine(x - 20,45,x + 20,45,WHITE);
}
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

 
}

void loop()
{
   display.clearDisplay();

  drawFace(30);
  drawFace(90);
  
  



  display.display();
  
}
