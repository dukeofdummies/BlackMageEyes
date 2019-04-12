#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

//number of pixels in LED chain
const int pixelsum = 62;
//digital pin that's sending data to the eyes (Din on the strip)
const int eyepin = 13;

//This is the constructor for the neopixels
Adafruit_NeoPixel EyesArray = Adafruit_NeoPixel(pixelsum, eyepin);

//These are just a few colors.
uint32_t white = EyesArray.Color(2, 2, 2);
uint32_t yellow = EyesArray.Color(4, 2, 0);
uint32_t blue = EyesArray.Color(0, 0, 6);
uint32_t red = EyesArray.Color(6, 0, 0);
uint32_t black = EyesArray.Color(0, 0, 0);

//variable we use to verify the expression has already been pushed, see summary
int expression = -1;
/*
 * SUMMARY
 * 
 * This current eye pattern is one strand in this orientation
 *                 
 *                  56 49 42         19 12 5 
 *               61 55 48 41 35   26 20 13 6  0
 *               60 54 47 40 34   27 21 14 7  1
 *               59 53 46 39 33   28 22 15 8  2
 *               58 52 45 38 32   29 23 16 9  3
 *               57 51 44 37 31   30 24 17 10 4
 *                  50 43 36         25 18 11
 *                  
 * all patterns are going to start with a blast of black or yellow, followed by 
 * targeted changes to pixels, and thenb a final push to show the result result.
 * 
 * every expression also has a positive number associated with it in the "expression" variable. 
 * If we're already expressing the expression, the code shouldn't do anything. 
 * (this saves on quite a bit of power) Each expression is associated with a number.
 * 
 * 
 * if (expression != 4)
 * //Name of pattern
 * expression = 4;
 * Blast(black)
 * EyesArray.setPixelColor(pixelyouwant, coloryouwant); 
 * [repeat the previous line for as many times as needed]
 * EyesArray.show();
 * 
*/


//these are which "pins" the button is wired to on the controller, up is pin 2, while down is pin 3 etc.

const int uppin = 5;
const int downpin = 6;
const int rightpin = 4;
const int leftpin = 3;

const int toppin = 10;
const int botpin = 9;

//basically bins for up/down/left/right
int up = 0;
int down = 0;
int left = 0;
int right = 0;

int top = 0;
int bot = 0;


void setup() {
  //Dpad pins
  pinMode(uppin, INPUT);
  digitalWrite(uppin, HIGH);
  pinMode(downpin, INPUT);
  digitalWrite(downpin, HIGH);
  pinMode(leftpin, INPUT);
  digitalWrite(leftpin, HIGH);
  pinMode(rightpin, INPUT);
  digitalWrite(rightpin, HIGH);
  //5th/6th button pin
  pinMode(toppin, INPUT);
  digitalWrite(toppin, HIGH);  
  pinMode(botpin, INPUT);
  digitalWrite(botpin, HIGH);  

    
  // put your setup code here, to run once:
  EyesArray.begin();
  Blast(white);
  EyesArray.show(); // Initialize all pixels to 'on'
}

void loop() {
  up = digitalRead(uppin);
  down = digitalRead(downpin);
  left = digitalRead(leftpin);
  right = digitalRead(rightpin);
  top = digitalRead(toppin);
  bot = digitalRead(botpin);
  
 if (up == LOW){
  
  if (top == LOW && bot == LOW){
    if (expression != 4)
      //angry
      expression = 4;
      Blast(yellow);
      
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(41, black);
      EyesArray.setPixelColor(35, black);
      EyesArray.setPixelColor(34, black);
      
      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(26, black);
      EyesArray.setPixelColor(20, black);
      EyesArray.setPixelColor(27, black);
      EyesArray.show();
    }  
  else if (top == LOW){
    if (expression != 3){
      //suspicious
      expression = 3;
      Blast(black);
      EyesArray.setPixelColor(1, yellow);
      EyesArray.setPixelColor(7, yellow);
      EyesArray.setPixelColor(14, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(2, yellow);
      EyesArray.setPixelColor(8, yellow);
      EyesArray.setPixelColor(15, yellow);
      EyesArray.setPixelColor(22, yellow);
      EyesArray.setPixelColor(28, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(3, yellow);
      EyesArray.setPixelColor(9, yellow);
      EyesArray.setPixelColor(16, yellow);
      EyesArray.setPixelColor(23, yellow);
      EyesArray.setPixelColor(29, yellow);
  
      EyesArray.setPixelColor(60, yellow);
      EyesArray.setPixelColor(54, yellow);
      EyesArray.setPixelColor(47, yellow);
      EyesArray.setPixelColor(40, yellow);
      EyesArray.setPixelColor(59, yellow);
      EyesArray.setPixelColor(53, yellow);
      EyesArray.setPixelColor(46, yellow);
      EyesArray.setPixelColor(39, yellow);
      EyesArray.setPixelColor(33, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(58, yellow);
      EyesArray.setPixelColor(52, yellow);
      EyesArray.setPixelColor(45, yellow);
      EyesArray.setPixelColor(38, yellow);
      EyesArray.setPixelColor(32, yellow);
      EyesArray.show();
    }
    
  }
  else if (bot == LOW){
    if (expression != 2){
      //really angry
      expression = 2;
      Blast(red);
      
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(41, black);
      EyesArray.setPixelColor(35, black);
      EyesArray.setPixelColor(34, black);
  
      EyesArray.setPixelColor(57, black);
      EyesArray.setPixelColor(50, black);
      
      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(26, black);
      EyesArray.setPixelColor(20, black);
      EyesArray.setPixelColor(27, black);
  
      EyesArray.setPixelColor(11, black);
      EyesArray.setPixelColor(4, black);
      EyesArray.show();
    }
  }
  else{
    if (expression != 1){
      //skeptical
      expression = 1;
      Blast(yellow);
      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(5, black);
      EyesArray.setPixelColor(26, black);
      EyesArray.setPixelColor(20, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(6, black);
      EyesArray.setPixelColor(0, black);
      EyesArray.show();
    }

  }
 }
 else if (down == LOW){
if (top == LOW && bot == LOW){
    if (expression != 8)
      //X X Expression
      expression = 8;
      Blast(black);
      EyesArray.setPixelColor(61, yellow);
      EyesArray.setPixelColor(54, yellow);
      EyesArray.setPixelColor(46, yellow);
      EyesArray.setPixelColor(38, yellow);
      EyesArray.setPixelColor(31, yellow);
      EyesArray.setPixelColor(35, yellow);
      EyesArray.setPixelColor(40, yellow);     
      EyesArray.setPixelColor(52, yellow);
      EyesArray.setPixelColor(57, yellow);

      EyesArray.setPixelColor(26, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(15, yellow);
      EyesArray.setPixelColor(9, yellow);
      EyesArray.setPixelColor(4, yellow);
      EyesArray.setPixelColor(30, yellow);
      EyesArray.setPixelColor(23, yellow);     
      EyesArray.setPixelColor(7, yellow);
      EyesArray.setPixelColor(0, yellow);
      EyesArray.show();
    }  
  else if (top == LOW){
    if (expression != 7){
      // > < expression
      expression = 7;
      Blast(black);
      EyesArray.setPixelColor(56, yellow);
      EyesArray.setPixelColor(48, yellow);
      EyesArray.setPixelColor(40, yellow);
      EyesArray.setPixelColor(33, yellow);
      EyesArray.setPixelColor(38, yellow);
      EyesArray.setPixelColor(44, yellow);
      EyesArray.setPixelColor(50, yellow);
      
      EyesArray.setPixelColor(5, yellow);
      EyesArray.setPixelColor(13, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(28, yellow);
      EyesArray.setPixelColor(23, yellow);
      EyesArray.setPixelColor(17, yellow);
      EyesArray.setPixelColor(11, yellow);
      EyesArray.show();
    }
    
  }
  else if (bot == LOW){
    if (expression != 6){
      //blank
      expression = 6;
      Blast(black);

      EyesArray.show();
    }
  }
  else{
    if (expression != 5){
      //surprise
      expression = 5;
      Blast(yellow);
      EyesArray.setPixelColor(55, black);
      EyesArray.setPixelColor(48, black);
      EyesArray.setPixelColor(41, black);
      EyesArray.setPixelColor(40, black);
      EyesArray.setPixelColor(39, black);
      EyesArray.setPixelColor(38, black);
      EyesArray.setPixelColor(37, black);
      EyesArray.setPixelColor(44, black);
      EyesArray.setPixelColor(51, black);
      EyesArray.setPixelColor(52, black);
      EyesArray.setPixelColor(53, black);
      EyesArray.setPixelColor(54, black);

      EyesArray.setPixelColor(20, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(6, black);
      EyesArray.setPixelColor(7, black);
      EyesArray.setPixelColor(8, black);
      EyesArray.setPixelColor(9, black);
      EyesArray.setPixelColor(10, black);
      EyesArray.setPixelColor(17, black);
      EyesArray.setPixelColor(24, black);
      EyesArray.setPixelColor(23, black);
      EyesArray.setPixelColor(22, black);
      EyesArray.setPixelColor(21, black);

      EyesArray.show();
    }

  }
  
 }
 else if (left == LOW){
  if (top == LOW && bot == LOW){
    if (expression != 12)
      //hearts
      expression = 12;
      Blast(yellow);
      EyesArray.setPixelColor(56, black);
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(61, black);
      EyesArray.setPixelColor(48, black);
      EyesArray.setPixelColor(35, black);
      EyesArray.setPixelColor(58, black);
      EyesArray.setPixelColor(32, black);
      EyesArray.setPixelColor(57, black);
      EyesArray.setPixelColor(51, black);
      EyesArray.setPixelColor(37, black);
      EyesArray.setPixelColor(31, black);
      EyesArray.setPixelColor(50, black);
      EyesArray.setPixelColor(43, black);
      EyesArray.setPixelColor(36, black);

      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(5, black);
      EyesArray.setPixelColor(26, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(0, black);
      EyesArray.setPixelColor(29, black);
      EyesArray.setPixelColor(3, black);
      EyesArray.setPixelColor(30, black);
      EyesArray.setPixelColor(24, black);
      EyesArray.setPixelColor(10, black);
      EyesArray.setPixelColor(4, black);
      EyesArray.setPixelColor(25, black);
      EyesArray.setPixelColor(18, black);
      EyesArray.setPixelColor(11, black);
      
      EyesArray.show();
    }  
  else if (top == LOW){
    if (expression != 11){
      // wink
      expression =11;
      Blast(black);

      EyesArray.setPixelColor(59, yellow);
      EyesArray.setPixelColor(54, yellow);
      EyesArray.setPixelColor(47, yellow);
      EyesArray.setPixelColor(40, yellow);
      EyesArray.setPixelColor(33, yellow);

    for (int i =0; i < 31; i++){
      EyesArray.setPixelColor(i, yellow);
    }
      EyesArray.show();
    }
    
  }
  else if (bot == LOW){
    if (expression != 10){
      //happy2
      expression = 10;
      Blast(yellow);
      EyesArray.setPixelColor(50, black);
      EyesArray.setPixelColor(43, black);
      EyesArray.setPixelColor(36, black);
      EyesArray.setPixelColor(57, black);
      EyesArray.setPixelColor(51, black);
      EyesArray.setPixelColor(44, black);
      EyesArray.setPixelColor(37, black);
      EyesArray.setPixelColor(31, black);
      EyesArray.setPixelColor(58, black);
      EyesArray.setPixelColor(52, black);
      EyesArray.setPixelColor(45, black);
      EyesArray.setPixelColor(38, black);
      EyesArray.setPixelColor(32, black);

      EyesArray.setPixelColor(25, black);
      EyesArray.setPixelColor(18, black);
      EyesArray.setPixelColor(11, black);
      EyesArray.setPixelColor(30, black);
      EyesArray.setPixelColor(24, black);
      EyesArray.setPixelColor(17, black);
      EyesArray.setPixelColor(10, black);
      EyesArray.setPixelColor(4, black);
      EyesArray.setPixelColor(29, black);
      EyesArray.setPixelColor(23, black);
      EyesArray.setPixelColor(16, black);
      EyesArray.setPixelColor(9, black);
      EyesArray.setPixelColor(3, black);
      EyesArray.show();
    }
  }
  else{
    if (expression != 9){
      //happy
      expression = 9;
      Blast(black);
      EyesArray.setPixelColor(59, yellow);
      EyesArray.setPixelColor(54, yellow);
      EyesArray.setPixelColor(47, yellow);
      EyesArray.setPixelColor(40, yellow);
      EyesArray.setPixelColor(33, yellow);

      EyesArray.setPixelColor(28, yellow);
      EyesArray.setPixelColor(21, yellow);
      EyesArray.setPixelColor(14, yellow);
      EyesArray.setPixelColor(7, yellow);
      EyesArray.setPixelColor(2, yellow);
      EyesArray.show();
    }

  }
  
 }
  else if (right == LOW){
  if (top == LOW && bot == LOW){
    if (expression != 16)
      //really?
      expression = 16;
      Blast(yellow);
      EyesArray.setPixelColor(56, black);
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(61, black);
      EyesArray.setPixelColor(55, black);
      EyesArray.setPixelColor(48, black);
      EyesArray.setPixelColor(41, black);
      EyesArray.setPixelColor(35, black);
      EyesArray.setPixelColor(60, black);
      EyesArray.setPixelColor(54, black);
      EyesArray.setPixelColor(47, black);
      EyesArray.setPixelColor(40, black);
      EyesArray.setPixelColor(34, black);

      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(5, black);
      EyesArray.setPixelColor(26, black);
      EyesArray.setPixelColor(20, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(6, black);
      EyesArray.setPixelColor(0, black);
      EyesArray.setPixelColor(27, black);
      EyesArray.setPixelColor(21, black);
      EyesArray.setPixelColor(14, black);
      EyesArray.setPixelColor(7, black);
      EyesArray.setPixelColor(1, black);
      
      EyesArray.show();
    }  
  else if (top == LOW){
    if (expression != 15){
      // super sad
      expression =15;
      Blast(yellow);
      EyesArray.setPixelColor(5, black);
      EyesArray.setPixelColor(0, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(6, black);
      EyesArray.setPixelColor(1, black);
      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(7, black);
      EyesArray.setPixelColor(2, black);

      EyesArray.setPixelColor(56, black);
      EyesArray.setPixelColor(61, black);
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(55, black);
      EyesArray.setPixelColor(60, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(48, black);
      EyesArray.setPixelColor(54, black);
      EyesArray.setPixelColor(59, black);

      EyesArray.setPixelColor(57, blue);
      EyesArray.setPixelColor(51, blue);
      EyesArray.setPixelColor(50, blue);
      EyesArray.setPixelColor(43, blue);
      EyesArray.setPixelColor(36, blue);
      EyesArray.setPixelColor(37, blue);
      EyesArray.setPixelColor(31, blue);

      EyesArray.setPixelColor(30, blue);
      EyesArray.setPixelColor(24, blue);
      EyesArray.setPixelColor(25, blue);
      EyesArray.setPixelColor(18, blue);
      EyesArray.setPixelColor(11, blue);
      EyesArray.setPixelColor(10, blue);
      EyesArray.setPixelColor(4, blue);
      
      EyesArray.show();
    }
    
  }
  else if (bot == LOW){
    if (expression != 14){
      //blink
      expression = 14;
      Blast(black);
      EyesArray.setPixelColor(59, yellow);
      EyesArray.setPixelColor(53, yellow);
      EyesArray.setPixelColor(46, yellow);
      EyesArray.setPixelColor(39, yellow);
      EyesArray.setPixelColor(33, yellow);

      EyesArray.setPixelColor(28, yellow);
      EyesArray.setPixelColor(22, yellow);
      EyesArray.setPixelColor(15, yellow);
      EyesArray.setPixelColor(8, yellow);
      EyesArray.setPixelColor(2, yellow);
      
      EyesArray.show();
    }
  }
  else{
    if (expression != 13){
      //sad
      expression = 13;
      Blast(yellow);
      EyesArray.setPixelColor(5, black);
      EyesArray.setPixelColor(0, black);
      EyesArray.setPixelColor(12, black);
      EyesArray.setPixelColor(6, black);
      EyesArray.setPixelColor(1, black);
      EyesArray.setPixelColor(19, black);
      EyesArray.setPixelColor(13, black);
      EyesArray.setPixelColor(7, black);
      EyesArray.setPixelColor(2, black);

      EyesArray.setPixelColor(56, black);
      EyesArray.setPixelColor(61, black);
      EyesArray.setPixelColor(49, black);
      EyesArray.setPixelColor(55, black);
      EyesArray.setPixelColor(60, black);
      EyesArray.setPixelColor(42, black);
      EyesArray.setPixelColor(48, black);
      EyesArray.setPixelColor(54, black);
      EyesArray.setPixelColor(59, black);

      EyesArray.show();
    }

  }
  
 }
 
  else{
    if (expression != 0){
      //normal eyes
      expression = 0;
      Blast(yellow);
      EyesArray.show();
    }
  }
 
}

//blast will blast all the pixels into the array to one color THIS DOES NOT PUSH CHANGES
void Blast(uint32_t color) {
  for (int i =0; i < pixelsum; i++){
    EyesArray.setPixelColor(i, color);
    }
}
