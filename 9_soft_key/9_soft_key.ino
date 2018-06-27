//Code by milstrike
#include <UTFT.h> 
#include <URTouch.h>

UTFT    myGLCD(SSD1289,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);

extern uint8_t BigFont[];
extern uint8_t SmallFont[];
int x, y;

void setup() {
  myGLCD.InitLCD(0); //0: Portrait 1: Landscape
  myGLCD.clrScr();
  myTouch.InitTouch(0); //0: Portrait 1: Landscape
  myTouch.setPrecision(PREC_MEDIUM);
  drawScreen(0);
}

void loop() {
  if (myTouch.dataAvailable()) {
      myTouch.read();
      x=myTouch.getX(); 
      y=myTouch.getY();      
      if ((x>=115) && (x<=130) && (y>=297) && (y<=312)) {
        delay(250);
        drawNotifications("Home"); 
      }
      if ((x>=50) && (x<=65) && (y>=297) && (y<=311)) {
        delay(250);
        drawNotifications("Back"); 
      }
      if ((x>=178) && (x<=191) && (y>=297) && (y<=311)) {
        delay(250);
        drawNotifications("Task"); 
      }
  }
}

void drawNotifications(String a){
  myGLCD.setColor(0,0,0); 
  myGLCD.print("You just hit " + a + " button", 10, 50);
  for(int i = 3; i > 0; i--){
      myGLCD.print("Please wait... (" + String(i) + ") second(s)", 10, 75);  
      delay(1000);
  }
    renderPage();
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

  renderPage();  
}

void renderPage(){
  appPage(0);
  softKey();
}

void appPage(int page){

  myGLCD.setColor(255,255,255);
  myGLCD.fillRect(0,36,239,317);
  
  if(page == 0){
    myGLCD.setColor(0,0,0); // Set font color
    myGLCD.setBackColor(255,255,255); // Set font color
    myGLCD.setFont(SmallFont); // Set font size
    myGLCD.print("Hello World", 10, 50); //Print String
  }
}

void softKey(){
  myGLCD.setColor(192,192,192);
  myGLCD.drawLine(0,289,239,289); // write line
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(0,290,239,319);

  myGLCD.setColor(0,0,0);
  myGLCD.drawRect(115,297,130,312);
  myGLCD.drawRect(50,297,65,311);
  myGLCD.drawRect(178,297,191,311);
  
  myGLCD.setColor(255,255,255);
  myGLCD.fillCircle(122,304,8);
  myGLCD.fillRect(178,297,191,311);

  myGLCD.drawLine(64,297,65,297);
  myGLCD.drawLine(62,298,65,298);
  myGLCD.drawLine(60,299,65,299);
  myGLCD.drawLine(58,300,65,300);
  myGLCD.drawLine(56,301,65,301);
  myGLCD.drawLine(54,302,65,302);
  myGLCD.drawLine(52,303,65,303);
  myGLCD.drawLine(50,304,65,304);
  myGLCD.drawLine(52,305,65,305);
  myGLCD.drawLine(54,306,65,306);
  myGLCD.drawLine(56,307,65,307);
  myGLCD.drawLine(58,308,65,308);
  myGLCD.drawLine(60,309,65,309);
  myGLCD.drawLine(62,310,65,310);
  myGLCD.drawLine(64,311,65,311);
}
