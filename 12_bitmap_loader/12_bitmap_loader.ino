#include <UTFT.h> 

UTFT myGLCD(SSD1289,38,39,40,41);

extern uint8_t BigFont[];
extern unsigned int milsystem[0x2A8A];

void setup() {
  myGLCD.InitLCD(1); //0: Portrait 1: Landscape
  myGLCD.clrScr();
  drawScreen();
}

void loop() {
}

void drawScreen(){
  myGLCD.drawBitmap (38,97, 242, 45, milsystem);
}

