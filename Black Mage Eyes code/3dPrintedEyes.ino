#include <Adafruit_NeoPixel.h>

//pins in use

int leftpin = 3;
int uppin = 4;
int downpin = 5;
int rightpin= 6;
int toppin = 8;
int botpin =7;

//neopixel data pin and length
int pixelPin = 14;
int pixelLength = 114;


//first pixel in left eye
int lefteye = 1;
//first pixel in right eye
int righteye = 61;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(pixelLength, pixelPin, NEO_GRB + NEO_KHZ800);


//colors
uint32_t eyecolor = pixels.Color(2,1,0);
uint32_t angercolor = pixels.Color(3,0,0);
uint32_t tearcolor = pixels.Color(0,0,3);
uint32_t blushcolor = pixels.Color(5,1,1);
uint32_t off = pixels.Color(0,0,0);

//eye patterns
//Since these arrays are created before compile time (thanks C++ -_-) we need to spell out exactly how many pixels we're going to change
int normaleye[]={31,10,11,12,13,14,25,24,23,22,21,20,19,33,32,31,30,29,28,27,37,38,39,40,41,42,43,50,49,48,47,46};

int closedeye[]={5,48,40,30,22,12};

int happyeye[]={5,48,39,31,21,12};

int blushingeye[] = {18,14,13,12,19,20,21,22,33,32,31,30,37,38,39,40,50,49,48};

int eyeblush[] = {5,44,43,26,9,8};

int hearteye[] = {26,2,3,4,15,14,13,12,11,20,21,22,23,24,32,31,30,29,28,37,38,39,40,41,50,49,48};

int sleepyeye[]={23,49,48,47,46,39,40,41,42,43,31,30,29,28,27,21,22,23,24,25,13,12,11,10};

int surprisedeye[] ={24,1,2,3,4,5,6,9,25,27,43,46,47,48,49,50,51,36,34,18,16,31,21,30,22};
 
int slanteye[] = {31,0,1,2,3,4,5,6,9,10,11,12,13,14,15,20,21,22,23,24,25,31,30,29,28,27,40,41,42,43,47,46};

int teareye[] = {13,46,43,27,25,9,6,47,42,28,24,10,5,44};

int suspiciouseye[] = {14,14,13,12,20,21,22,32,31,30,38,39,40,49,48};

int raisedeye[] = {36,51,36,34,18,15,10,11,12,13,14,25,24,23,22,21,20,19,33,32,31,30,29,28,27,37,38,39,40,41,42,43,50,49,48,47,46};

int realangryeye[] = {29,0,1,2,3,4,5,6,15,14,13,12,11,10,9,20,21,22,23,24,25,31,30,29,28,27,40,41,42,47};

int squinteye[] = {7,19,32,39,48,41,28,25};

int deadeye[] = {9,37,32,21,14,1,41,30,12,5};

void blackout(){
    for(int i=0;i<pixelLength;i++){
      pixels.setPixelColor(i, 0,0,0);
    }
}

void draw(int eye, uint32_t color, int locations[]){
  int listsize = locations[0];
  for (int i = 1; i < listsize+1; i++) {
     pixels.setPixelColor(locations[i]+eye, color);
  }
}

void invdraw(int eye, uint32_t color, int locations[]){
  int listsize = locations[0];
  for (int i = 1; i < listsize+1; i++) {
     pixels.setPixelColor(abs(locations[i]-52)+eye, color);
  }
}

//these are all the expressions, basically we wanna make sure that we don't spam the same expression over and over (really drains battery life) we wanna set it and then leave it static

//current expression to avoid spam
int currentexpression = 0;

int neutral = 0;
int left00 = 1;int left10 = 2; int left01 = 3; int left11 = 4;
int up00 = 5; int up10 = 6; int up01 = 7; int up11 = 8;
int right00 = 9;int right10=10;int right01 = 11;int right11 = 12;
int down00=13;int down10 =14;int down01=15;int down11 = 16;


void setup() {
  pinMode(pixelPin, OUTPUT);
  
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
  
  pixels.begin();
  blackout();
 
    draw(lefteye,eyecolor, normaleye);
    invdraw(righteye,eyecolor, normaleye);
  pixels.show();
}


void loop() {
  int up = digitalRead(uppin);
  int down = digitalRead(downpin);
  int left = digitalRead(leftpin);
  int right = digitalRead(rightpin);
  int top = digitalRead(toppin);
  int bot = digitalRead(botpin);

  if (left == LOW){
    if(top == HIGH && bot == LOW){
       if (currentexpression != left10){
        currentexpression = left10;
        blackout();
        draw(lefteye,eyecolor, blushingeye);
        invdraw(righteye,eyecolor, blushingeye);
        pixels.show();
       }
    }
    else if(top == LOW && bot == HIGH){
       if (currentexpression != left01){
        currentexpression = left01;
        blackout();
        draw(lefteye,eyecolor, happyeye);
        invdraw(righteye,eyecolor, normaleye);
        pixels.show();
       }
    }
    else if(top == LOW && bot == LOW){
       if (currentexpression != left11){
        currentexpression = left11;
        blackout();
        draw(lefteye,eyecolor, hearteye);
        invdraw(righteye,eyecolor, hearteye);
        pixels.show();
       }
    }
    else{
      if (currentexpression != left00){
      currentexpression = left00;
      blackout();
      draw(lefteye,eyecolor, happyeye);
      invdraw(righteye,eyecolor, happyeye);
      pixels.show();
      }
    }
  }

  
  else if (right == LOW){
   if(top == LOW && bot == HIGH){
       if (currentexpression != right10){
        currentexpression = right10;
        blackout();
      invdraw(lefteye,eyecolor, slanteye);
      draw(righteye,eyecolor, slanteye);
      invdraw(lefteye,tearcolor, teareye);
      draw(righteye,tearcolor, teareye);
      pixels.show();
       }
    }
    else if(top == HIGH && bot == LOW){
       if (currentexpression != right01){
        currentexpression = right01;
        blackout();
        draw(lefteye,eyecolor, closedeye);
        invdraw(righteye,eyecolor, closedeye);
        pixels.show();
       }
    }
    else if(top == LOW && bot == LOW){
       if (currentexpression != right11){
        currentexpression = right11;
        blackout();
        draw(lefteye,eyecolor, sleepyeye);
        invdraw(righteye,eyecolor, sleepyeye);
        pixels.show();
       }
    }
    else{
      if (currentexpression != right00){
      currentexpression = right00;
      blackout();
      invdraw(lefteye,eyecolor, slanteye);
      draw(righteye,eyecolor, slanteye);
      pixels.show();
      }
    }
  }

  
  else if (up == LOW){
   if(top == LOW && bot == HIGH){
       if (currentexpression != up10){
        currentexpression = up10;
        blackout();
      draw(lefteye,eyecolor, suspiciouseye);
      invdraw(righteye,eyecolor, suspiciouseye);
      pixels.show();
       }
    }
    else if(top == HIGH && bot == LOW){
       if (currentexpression != up01){
        currentexpression = up01;
        blackout();
        draw(lefteye,angercolor, realangryeye);
        invdraw(righteye,angercolor, realangryeye);
        pixels.show();
       }
    }
    else if(top == LOW && bot == LOW){
       if (currentexpression != up11){
        currentexpression = up11;
        blackout();
        draw(lefteye,eyecolor, slanteye);
        invdraw(righteye,eyecolor, slanteye);
        pixels.show();
       }
    }
    else{
      if (currentexpression != up00){
      currentexpression = up00;
      blackout();
      draw(lefteye,eyecolor, sleepyeye);
      invdraw(righteye,eyecolor, raisedeye);
      pixels.show();
      }
    }
  }

  
  else if (down == LOW){
   if(top == LOW && bot == HIGH){
       if (currentexpression != down10){
        currentexpression = down10;
        blackout();
      draw(lefteye,eyecolor, squinteye);
      invdraw(righteye,eyecolor, squinteye);
      pixels.show();
       }
    }
    else if(top == HIGH && bot == LOW){
       if (currentexpression != down01){
        currentexpression = down01;
        blackout();
        pixels.show();
       }
    }
    else if(top == LOW && bot == LOW){
       if (currentexpression != down11){
        currentexpression = down11;
        blackout();
        draw(lefteye,eyecolor, deadeye);
        invdraw(righteye,eyecolor, deadeye);
        pixels.show();
       }
    }
    else{
      if (currentexpression != down00){
      currentexpression = down00;
      blackout();
      draw(lefteye,eyecolor, surprisedeye);
      draw(righteye,eyecolor, surprisedeye);
      pixels.show();
      }
    }
  }
  else{
   if (currentexpression != neutral){
    currentexpression = neutral;
    blackout();
    draw(lefteye,eyecolor, normaleye);
    invdraw(righteye,eyecolor, normaleye);
    pixels.show();
   }

  }
}
