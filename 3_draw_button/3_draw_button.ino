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
  myGLCD.print("DRAW BUTTON!", CENTER, 10); //Print String
  
//SubTitle
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setFont(SmallFont); // Set font size
  myGLCD.print("by: milstrike", CENTER, 30); // Print String

//---------------------------------------------------------
// Button 1
  myGLCD.setColor(16, 167, 103); // Set green color for button
  myGLCD.fillRoundRect (40, 90, 285, 130); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (40, 90, 285, 130); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(16, 167, 103); // Set highlight color
  myGLCD.print("BUTTON 1", CENTER, 102); // Display text

// Button 2
  myGLCD.setColor(110, 113, 219); // Set green color for button
  myGLCD.fillRoundRect (40, 140, 285, 180); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (40, 140, 285, 180); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(110, 113, 219); // Set highlight color
  myGLCD.print("BUTTON 2", CENTER, 152); // Display text

// Button 3
  myGLCD.setColor(255, 0, 34); // Set green color for button
  myGLCD.fillRoundRect (40, 190, 160, 230); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (40, 190, 160, 230); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(255, 0, 34); // Set highlight color
  myGLCD.print("BTN 3", 62, 202); // Display text

// Button 4
  myGLCD.setColor(255, 0, 34); // Set green color for button
  myGLCD.fillRoundRect (170, 190, 285, 230); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (170, 190, 285, 230); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(255, 0, 34); // Set highlight color
  myGLCD.print("BTN 4", 190, 202); // Display text
}

