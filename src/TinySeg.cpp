#include "Arduino.h"
#include "TinySeg.h"

TinySeg::TinySeg() { 

}
TinySeg::TinySeg(uint8_t c[5], uint8_t s[8]) {
    for (uint8_t i = 0; i < 5; i++) {
        charPins[i] = c[i];
    }

    for (uint8_t i = 0; i < 8; i++) {
        segmentPins[i] = s[i];
    }

    InitPins();
}
void TinySeg::InitPins() {
    for (uint8_t p : charPins) {
        pinMode(p, OUTPUT);
    }

    for (uint8_t p : segmentPins) {
        pinMode(p, OUTPUT);
    }
}


bool* TinySeg::GetArray(char character) {
    uint8_t val = (uint8_t)character;
    if(val >= 0 && val <= 127)
        return asciiMap[val];

    return asciiMap[0];
}
bool* TinySeg::GetArray(uint8_t num) {
    if(num >= 0 && num <= 9)
        return asciiMap[num + 48];

    return asciiMap[0];
}
bool* TinySeg::GetEmpty(){
    return asciiMap[0];
}



void TinySeg::SetDigit(uint8_t index, uint8_t num){
    memcpy(states[index], GetArray(num), sizeof(states[index]));
}
void TinySeg::SetDigit(uint8_t index, char character){
    memcpy(states[index], GetArray(character), sizeof(states[index]));
}
void TinySeg::SetDigit(uint8_t index, bool* array) {
    memcpy(states[index], array, sizeof(states[index]));
}



void TinySeg::Write(int num) {
    uint8_t index = 0;
    for (int i = 10000; i >= 1; i /= 10) {
        uint8_t digit = (num / i) % 10;
        SetDigit(index, digit);
        index++;
    }
}
void TinySeg::Write(char text[5]) {
    for(uint8_t i = 0; i < 5; i++){
        SetDigit(i, text[i]);
    }
}



void TinySeg::FillDisplay(bool state) {
    for (uint8_t c : charPins) {
        digitalWrite(c, state?LOW:HIGH);
    }

    for (uint8_t l : segmentPins) {
        digitalWrite(l, state?HIGH:LOW);
    }
}
void TinySeg::ApplyValues() {
    for (uint8_t c = 0; c < 5; c++) {
        for (uint8_t l = 0; l < 8; l++) {
            uint8_t gnd = charPins[c];
            uint8_t vcc = segmentPins[l];

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