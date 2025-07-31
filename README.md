# BlackMageEyes
For the code behind the eyes here https://www.youtube.com/watch?v=K9V43iSXRQA

The main gyst of this code is to read button pushes (contact closures) from a controller to change patterns in Adafruit's Neopixel Array.

For details on the Hardware behind it see here
https://www.deviantart.com/dukeofdummies

This current eye pattern is one strand in this orientation zig zagging up and down, many LEDs aren't actually used
```
0   18    36    54 55 56 57 58 59 60   78    96
 1 17 19 35 37 53                  61 77 79 95 97  113
 2 16 20 34 38 52                  62 76 80 94 98  112
 3 15 21 33 39 51                  63 75 81 93 99  111
 4 14 22 32 40 50                  64 74 82 92 100 110
 5 13 23 31 41 49                  65 73 83 91 101 109
 6 12 24 30 42 48                  66 72 84 90 102 108
 7 11 25 29 43 47                  67 71 85 89 103 107
 8 10 26 28 44 46                  68 70 86 88 104 106
  9    27    45                     69    87     105
```
                 

every expression also has a positive number associated with it in the "expression" variable. 
If we're already expressing the expression, the code shouldn't do anything. 
(this saves on quite a bit of power) Each expression is associated with a number.

The general pattern will look like this
