#include <UTFT.h> 
#include <URTouch.h>

UTFT    myGLCD(SSD1289,38,39,40,41);

extern uint8_t BigFont[];
extern uint8_t SmallFont[];

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  drawScreen();
}

void loop() {
  drawScreen();
}

void drawScreen(){
//Title
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(BigFont); // Set font size
  myGLCD.print("HELLO WORLD!", LEFT, 10); //Print String

//SubTitle
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print("by: milstrike", LEFT, 41); // Print String
}

