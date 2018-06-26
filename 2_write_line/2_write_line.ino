//Code by milstrike
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
  
}

void drawScreen(){
//Title
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(BigFont); // Set font size
  myGLCD.print("WRITE LINES!", CENTER, 10); //Print String
  
//SubTitle
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print("by: milstrike", CENTER, 30); // Print String

//---------------------------------------------------------
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print(" Long Line", LEFT, 65); // Print String

//Write Long Line
  myGLCD.setColor(255, 255, 255); // Set line color
  myGLCD.drawLine(0,80,319,80); // write line
//---------------------------------------------------------
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print(" Dashed Line", LEFT, 100); // Print String

//Write dashed line
  myGLCD.setColor(255, 255, 255); // Set line color
  for(int a = 0; a<=319; a++){
    myGLCD.drawLine(a,120,a+10,120); // write line
  a = a+20;
  }
//---------------------------------------------------------
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print(" Dotted Line", LEFT, 140); // Print String

//Write dotted line
  myGLCD.setColor(255, 255, 255); // Set line color
  for(int a = 0; a<=319; a++){
    myGLCD.drawLine(a,160,a+1,160); // write line
    a = a+2;
  }
//---------------------------------------------------------
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print(" Saw Line", LEFT, 180); // Print String

//Write saw line
  myGLCD.setColor(255, 255, 255); // Set line color
  int z = 0;
  for(int a = 0; a<=319; a++){
    if(z == 0){
      myGLCD.drawLine(a,220,a+10,200); // write line
      a = a+10;
      z = 1;
    }
    if(z == 1){
      myGLCD.drawLine(a,200,a+10,220); // write line
      a = a+10;
      z = 0;
    }
  }
  
}

