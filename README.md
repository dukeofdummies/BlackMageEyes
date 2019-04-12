# BlackMageEyes
For the code behind the eyes here https://www.youtube.com/watch?v=K9V43iSXRQA

The main gyst of this code is to read button pushes (contact closures) from a controller to change patterns in Adafruit's Neopixel Array.

For details on the Hardware behind it see here
https://www.deviantart.com/dukeofdummies

This current eye pattern is one strand in this orientation
                
                 56 49 42         19 12 5 
              61 55 48 41 35   26 20 13 6  0
              60 54 47 40 34   27 21 14 7  1
              59 53 46 39 33   28 22 15 8  2
              58 52 45 38 32   29 23 16 9  3
              57 51 44 37 31   30 24 17 10 4
                 50 43 36         25 18 11
                 
all patterns are going to start with a blast of black or yellow, followed by 
targeted changes to pixels, and thenb a final push to show the result.

every expression also has a positive number associated with it in the "expression" variable. 
If we're already expressing the expression, the code shouldn't do anything. 
(this saves on quite a bit of power) Each expression is associated with a number.

The general pattern will look like this

if (expression != 4)
//Name of pattern
expression = 4;
Blast(black)
EyesArray.setPixelColor(pixelyouwant, coloryouwant); 
[repeat the previous line for as many times as needed]
EyesArray.show();
