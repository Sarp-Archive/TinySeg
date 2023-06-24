/*
    23 June 2023
    Created by Segilmez06.

    Scrolling text demo for bit-sized HP display.

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
#include <TinySeg.h>

// Define the pins
int charPins[] = { 15, 16, 17, 18, 14 }; // GND
int segPins[] = { 22, 21, 20, 19, 13, 12, 11, 10 }; // VCC

// Init the display
TinySeg s(charPins, segPins);

// Vars for scrolling loop
long previousMillis = 0;
const int period = 450;

// Put space before and after the text to make it more smooth
const char* text = "     tinyseg hp 5082 7415     ";
int last = 0;

// Nothing to see here...
void setup() {

}

void loop() {

    // Use millis() to wait until next period
    if (millis() - previousMillis >= period) {
        previousMillis = millis();

        for (int i = 0; i < 5; i++){
            s.SetDigit(i, text[last+i]);
        }
        last++;

    }

    if (last > strlen(text) - 5) last = 0;

    // Show the status on the display
    s.ApplyValues();
}
