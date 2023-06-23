/*
    23 June 2023
    Created by Segilmez06.

    Wave demo for bit-sized HP display.

    Connectins for RP2040:

      TYPE:   PICO PIN:   DISP PIN:   DESC:

      VCC     GPIO10      6           Bottom Horizontal
      VCC     GPIO11      5           Dot
      VCC     GPIO12      3           Bottom Right Vertical
      VCC     GPIO13      2           Bottom Left Vertical
      GND     GPIO14      7           Char 5
      GND     GPIO15      1           Char 1

      GND     GPIO16      13          Char 2
      GND     GPIO17      11          Char 3
      GND     GPIO18      9           Char 4
      VCC     GPIO19      8           Middle Horizontal
      VCC     GPIO20      10          Top Left Vertical
      VCC     GPIO21      12          Top Right Vertical
      VCC     GPIO22      14          Top Horizontal

    Both pin 4 and pin 11 is used for GND of char 3 (middle) digit. You can
    connect pin 4 instead of pin 11.

    To use with other platforms (AVR, ESP...) just change the pin array contents.

    Display's diagram:

      14 13 12 11 10  9  8
    ┌──┴──┴──┴──┴──┴──┴──┴──┐
    │ 8.   8.   8.   8.   8.│
    └──┬──┬──┬──┬──┬──┬──┬──┘
       1  2  3  4  5  6  7

*/

// Include the lib
#include <Segment.h>

// Define the pins
int charPins[] = { 15, 16, 17, 18, 14 }; // GND
int segPins[] = { 22, 21, 20, 19, 13, 12, 11, 10 }; // VCC

// Init the display
Segment s(charPins, segPins);

// Vars for waving loop
long previousMillis = 0;
const long period = 100;
long counter = 0;

// Spinner animation keyframes
int spinner[6][8] = {
    {1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1},
    {0,0,0,0,1,0,0,0},
    {0,0,1,0,0,0,0,0}
};

// Nothing to see here...
void setup() {

}

void loop() {

    // Use millis() to wait until next period
    long currentMillis = millis();
    if (currentMillis - previousMillis >= period) {
        previousMillis = currentMillis;

        for(int i = 0; i < 5; i++){
            if(++counter > 5) counter = 0;
            s.SetDigit(i, spinner[counter]);
        }

    }

    // Show the status on the display
    s.ApplyValues();
}
