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
  myGLCD.setColor(250, 250, 250); 
  myGLCD.fillRoundRect (20, 40, 300, 200); 
  myGLCD.setColor(255, 255, 255); 
  myGLCD.drawRoundRect (20, 40, 300, 200); 
  myGLCD.setColor(107, 93, 233); 
  myGLCD.fillRect (20, 40, 300, 80); 
  myGLCD.setColor(255, 255, 255); 
  myGLCD.setFont(BigFont); 
  myGLCD.setBackColor(107, 93, 233);
  myGLCD.print("Notifications", CENTER, 55);

  myGLCD.setColor(0,0,0); 
  myGLCD.setFont(SmallFont); 
  myGLCD.setBackColor(250, 250, 250);
  myGLCD.print("You just hit button number " + a, CENTER, 100);
  for(int i = 3; i > 0; i--){
      myGLCD.print("Please wait... (" + String(i) + ") second(s)", CENTER, 115);  
      delay(1000);
  }
  myGLCD.clrScr();
  drawScreen();
}

void drawScreen(){
//Title
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont); // Set font size
  myGLCD.print("MESSAGE!", CENTER, 10); //Print String
  
//SubTitle
  myGLCD.setColor(255, 255, 255); // Set font color
  myGLCD.setBackColor(0, 0, 0);
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

