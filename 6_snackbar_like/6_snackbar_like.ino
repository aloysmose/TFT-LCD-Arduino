//Code by milstrike
#include <UTFT.h> 
#include <URTouch.h>

UTFT    myGLCD(SSD1289,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);

extern uint8_t BigFont[];
extern uint8_t SmallFont[];
int x, y;

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  
  drawScreen();
}

void loop() {
   if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); 
      y=myTouch.getY();
      myGLCD.setColor(255, 0, 0);       
      if ((x>=40) && (x<=285) && (y>=90) && (y<=130)) {
        myGLCD.drawRoundRect (40, 90, 285, 130);
        delay(250);
        drawNotifications("1"); 
      }
      if ((x>=40) && (x<=285) && (y>=140) && (y<=180)) {
        myGLCD.drawRoundRect (40, 140, 285, 180);
        delay(250);
        drawNotifications("2"); 
      }
      if ((x>=40) && (x<=160) && (y>=190) && (y<=230)) {
        myGLCD.drawRoundRect (40, 190, 160, 230);
        delay(250);
        drawNotifications("3"); 
      }
      if ((x>=170) && (x<=285) && (y>=190) && (y<=230)) {
        myGLCD.drawRoundRect (170, 190, 285, 230);
        delay(250);
        drawNotifications("4");
      }
  }
}

void drawNotifications(String a){
  myGLCD.setColor(0,0,0); 
  for(int z = 239; z>210; z--){
    myGLCD.drawLine(0,z,319,z); 
    delay(5);
  }
  delay(250);
  myGLCD.setColor(255,255,255); 
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Snackbar Example Button " + a, 10, 223);
  myGLCD.setColor(247,255,0); 
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.print("DISMISS", 245, 223);
  delay(3000);
  myGLCD.clrScr();
  drawScreen();
}

void drawScreen(){
  myGLCD.fillScr(255,255,255); 
//Title
  myGLCD.setColor(35, 29, 225); // Set font color
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.setFont(BigFont); // Set font size
  myGLCD.print("SNACKBARLIKE EXAMPLE", CENTER, 10); //Print String
  
//SubTitle
  myGLCD.setColor(35, 29, 225); // Set font color
  myGLCD.setBackColor(255, 255, 255);
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
  myGLCD.print("MESSAGE 1", CENTER, 102); // Display text

// Button 2
  myGLCD.setColor(110, 113, 219); // Set green color for button
  myGLCD.fillRoundRect (40, 140, 285, 180); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (40, 140, 285, 180); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(110, 113, 219); // Set highlight color
  myGLCD.print("MESSAGE 2", CENTER, 152); // Display text

// Button 3
  myGLCD.setColor(255, 0, 34); // Set green color for button
  myGLCD.fillRoundRect (40, 190, 160, 230); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (40, 190, 160, 230); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(255, 0, 34); // Set highlight color
  myGLCD.print("MSG 3", 62, 202); // Display text

// Button 4
  myGLCD.setColor(255, 0, 34); // Set green color for button
  myGLCD.fillRoundRect (170, 190, 285, 230); // Draws rounded rectangle with color
  myGLCD.setColor(255, 255, 255); // Set text color to white
  myGLCD.drawRoundRect (170, 190, 285, 230); // Draw rounded rectangle for frame
  myGLCD.setFont(BigFont); // Set the font to size
  myGLCD.setBackColor(255, 0, 34); // Set highlight color
  myGLCD.print("MSG 4", 190, 202); // Display text
}

