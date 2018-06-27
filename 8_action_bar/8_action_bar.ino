//Code by milstrike
#include <UTFT.h> 
#include <URTouch.h>

UTFT    myGLCD(SSD1289,38,39,40,41);

extern uint8_t BigFont[];
extern uint8_t SmallFont[];

void setup() {
  myGLCD.InitLCD(0); //0: Portrait 1: Landscape
  myGLCD.clrScr();
  drawScreen(0);
  appPage(0);
}

void loop() {
  
}

void drawScreen(int a){
  myGLCD.fillScr(255,255,255);
  if(a == 0){
    myGLCD.setColor(33,150,243);
    myGLCD.fillRect (0, 0, 239, 35);
  }
  if(a == 1){
    myGLCD.setColor(33,150,243);
    myGLCD.fillRect (0, 0, 319, 35);
  }
//Title
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setBackColor(33,150,243); // Set font color
  myGLCD.setFont(BigFont); // Set font size
  myGLCD.print("MyApp", 10, 10); //Print String
}

void appPage(int page){
  if(page == 0){
    myGLCD.setColor(0,0,0); // Set font color
    myGLCD.setBackColor(255,255,255); // Set font color
    myGLCD.setFont(SmallFont); // Set font size
    myGLCD.print("Hello World", 10, 50); //Print String
  }
}

