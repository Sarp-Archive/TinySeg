# TinySeg

![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/Segilmez06/TinySeg/build-examples.yml?branch=development&color=blue&label=Build%20examples%20%28Uno%29&logo=github&logoColor=white)
![GitHub Workflow Status (with branch)](https://img.shields.io/github/actions/workflow/status/Segilmez06/TinySeg/check-linting.yml?branch=development&color=blue&label=Linting%20Check&logo=github&logoColor=white)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/Segilmez06/TinySeg?display_name=tag&label=Latest%20Release&color=blue&logo=Github&logoColor=white&style=flat)
![GitHub repo size](https://img.shields.io/github/repo-size/Segilmez06/TinySeg?color=yellow&label=Repo%20Size&logo=github&logoColor=white)
![GitHub all releases](https://img.shields.io/github/downloads/Segilmez06/TinySeg/total?color=yellow&label=Downloads&logo=Github&logoColor=white)
[![arduino-library-badge](https://www.ardu-badge.com/badge/TinySeg.svg?)](https://www.ardu-badge.com/TinySeg)

A simple library for bit-sized HP 7 segment display which was staying in my component box. I found this at 3AM and had urge to use this cute thing and I wrote this library to make controlling easier. Display has matrix connections so it can pretty much run without any libraries. But this library allows you to print string and int values easily.

I tested this with RP2040 but lib doesn't contains any platform-spesific code. It's compatible with all AVR and ESP boards. If you want to use it with other boards, just make your own pin connections.

Also I found an article about using this display with Arduino after a quick search: [Hewlett-Packard 5082-7415 LED Display from 1976](https://tronixstuff.com/2012/04/07/hewlett-packard-5082-7415-led-display-from-1976/)

You can open new issues and pull request to contribute. New example sketches will be appreciated.

## Installation

### With Arduino Library Manager

1. Open the Arduino IDE
2. Go to `Sketch > Include Library > Manage Libraries...`
3. Search for `TinySeg`
4. Click on the library and click `Install`

### With Zip file

1. Download the library from the [Releases page](https://github.com/Segilmez06/TinySeg/releases).
2. Open the Arduino IDE
3. Go to `Sketch > Include Library > Add .ZIP Library...`
4. Select the downloaded file

### Manual Installation

1. Download the library from the [Releases page](https://github.com/Segilmez06/TinySeg/releases).
2. Unzip the file
3. Go to `Documents/Arduino/libraries`
4. Copy contents of the zip file to `Documents/Arduino/libraries`

## Usage

```c++
#include <TinySeg.h>

// Define the pins
int charPins[] = { 15, 16, 17, 18, 14 }; // GND
int segPins[] = { 22, 21, 20, 19, 13, 12, 11, 10 }; // VCC

// Init the display
TinySeg s(charPins, segPins);

void setup() {
    s.Write("HELLO");
}

void loop() {
    s.ApplyValues();
}
```

## Credits

Created and maintained by [Segilmez06](https://www.sarpegilmez.net/).
