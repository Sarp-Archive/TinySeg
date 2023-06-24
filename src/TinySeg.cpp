#include "Arduino.h"
#include "TinySeg.h"

TinySeg::TinySeg() { 

}
TinySeg::TinySeg(int c[5], int s[8]) {
    for (int i = 0; i < 5; i++) {
        charPins[i] = c[i];
    }

    for (int i = 0; i < 8; i++) {
        segmentPins[i] = s[i];
    }

    InitPins();
}
void TinySeg::InitPins() {
    for (int p : charPins) {
        pinMode(p, OUTPUT);
    }

    for (int p : segmentPins) {
        pinMode(p, OUTPUT);
    }
}


int* TinySeg::GetArray(char character) {
    int val = (int)character;
    if(val >= 0 && val <= 127)
        return asciiMap[val];

    return asciiMap[0];
}
int* TinySeg::GetArray(int num) {
    int val = num;
    if(val >= 0 && val <= 9)
        return asciiMap[val + 48];

    return asciiMap[0];
}
int* TinySeg::GetEmpty(){
    return asciiMap[0];
}



void TinySeg::SetDigit(int index, int num){
    memcpy(states[index], GetArray(num), sizeof(states[index]));
}
void TinySeg::SetDigit(int index, char character){
    memcpy(states[index], GetArray(character), sizeof(states[index]));
}
void TinySeg::SetDigit(int index, int* array) {
    memcpy(states[index], array, sizeof(states[index]));
}



String TinySeg::FormatString(String text) {
    int length = text.length();
    
    if (length >= 5) {
        return text.substring(0, 5);
    } else {
        String spaces(5 - length, ' ');
        return spaces + text;
    }
}



void TinySeg::Write(int num) {
    int index = 0;
    for (int i = 10'000; i >= 1; i /= 10) {
        int digit = (num / i) % 10;
        SetDigit(index, digit);
        index++;
    }
}
void TinySeg::Write(String text) {
    int i = 0;
    for(char c : FormatString(text)){
        SetDigit(i++, c);
    }
}



void TinySeg::FillDisplay(bool state) {
    for (int c : charPins) {
        digitalWrite(c, state?LOW:HIGH);
    }

    for (int l : segmentPins) {
        digitalWrite(l, state?HIGH:LOW);
    }
}
void TinySeg::ApplyValues() {
    for (int c = 0; c < 5; c++) {
        for (int l = 0; l < 8; l++) {
            int gnd = charPins[c];
            int vcc = segmentPins[l];

            if (states[c][l]) {
                digitalWrite(gnd, LOW);
                digitalWrite(vcc, HIGH);
                delayMicroseconds(10);
            }

            digitalWrite(gnd, HIGH);
            digitalWrite(vcc, LOW);
        }
    }
}