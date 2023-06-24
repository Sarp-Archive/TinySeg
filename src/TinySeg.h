#include "Arduino.h"

class TinySeg {
  public:

    uint8_t charPins[5];
    uint8_t segmentPins[8];

    TinySeg();
    TinySeg(uint8_t c[5], uint8_t s[8]);
    void InitPins();


    bool* GetArray(char character);
    bool* GetArray(uint8_t num);
    bool* GetEmpty();


    void SetDigit(uint8_t index, uint8_t num);
    void SetDigit(uint8_t index, char character);
    void SetDigit(uint8_t index, bool* array);


    void Write(int num);
    // void Write(char* text);
    void Write(char text[5]);


    void FillDisplay(bool state);
    void ApplyValues();


  private:
    bool states[5][8] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    bool asciiMap[128][8] = {
        {0,0,0,0,0,0,0,0}, // 000 [NULL]
        {0,0,0,0,0,0,0,0}, // 001 [NULL]
        {0,0,0,0,0,0,0,0}, // 002 [NULL]
        {0,0,0,0,0,0,0,0}, // 003 [NULL]
        {0,0,0,0,0,0,0,0}, // 004 [NULL]
        {0,0,0,0,0,0,0,0}, // 005 [NULL]
        {0,0,0,0,0,0,0,0}, // 006 [NULL]
        {0,0,0,0,0,0,0,0}, // 007 [NULL]
        {0,0,0,0,0,0,0,0}, // 008 [NULL]
        {0,0,0,0,0,0,0,0}, // 009 [NULL]
        {0,0,0,0,0,0,0,0}, // 010 [NULL]
        {0,0,0,0,0,0,0,0}, // 011 [NULL]
        {0,0,0,0,0,0,0,0}, // 012 [NULL]
        {0,0,0,0,0,0,0,0}, // 013 [NULL]
        {0,0,0,0,0,0,0,0}, // 014 [NULL]
        {0,0,0,0,0,0,0,0}, // 015 [NULL]
        {0,0,0,0,0,0,0,0}, // 016 [NULL]
        {0,0,0,0,0,0,0,0}, // 017 [NULL]
        {0,0,0,0,0,0,0,0}, // 018 [NULL]
        {0,0,0,0,0,0,0,0}, // 019 [NULL]
        {0,0,0,0,0,0,0,0}, // 020 [NULL]
        {0,0,0,0,0,0,0,0}, // 021 [NULL]
        {0,0,0,0,0,0,0,0}, // 022 [NULL]
        {0,0,0,0,0,0,0,0}, // 023 [NULL]
        {0,0,0,0,0,0,0,0}, // 024 [NULL]
        {0,0,0,0,0,0,0,0}, // 025 [NULL]
        {0,0,0,0,0,0,0,0}, // 026 [NULL]
        {0,0,0,0,0,0,0,0}, // 027 [NULL]
        {0,0,0,0,0,0,0,0}, // 028 [NULL]
        {0,0,0,0,0,0,0,0}, // 029 [NULL]
        {0,0,0,0,0,0,0,0}, // 030 [NULL]
        {0,0,0,0,0,0,0,0}, // 031 [NULL]

        {0,0,0,0,0,0,0,0}, // 032 [SPACE]
        {0,0,0,0,0,0,0,0}, // 033 !
        {0,0,0,0,0,0,0,0}, // 034 "
        {0,0,0,0,0,0,0,0}, // 035 #
        {0,0,0,0,0,0,0,0}, // 036 $
        {0,0,0,0,0,0,0,0}, // 037 %
        {0,0,0,0,0,0,0,0}, // 038 &
        {0,0,0,0,0,0,0,0}, // 039 '
        {0,0,0,0,0,0,0,0}, // 040 (
        {0,0,0,0,0,0,0,0}, // 041 )
        {0,0,0,0,0,0,0,0}, // 042 *
        {0,0,0,0,0,0,0,0}, // 043 +
        {0,0,0,0,0,0,0,0}, // 044 ,
        {0,0,0,0,0,0,0,0}, // 045 -
        {0,0,0,0,0,0,0,0}, // 046 .
        {0,0,0,0,0,0,0,0}, // 047 /

        {1,1,1,0,1,1,0,1}, // 048 0
        {0,1,0,0,0,1,0,0}, // 049 1
        {1,1,0,1,1,0,0,1}, // 050 2
        {1,1,0,1,0,1,0,1}, // 051 3
        {0,1,1,1,0,1,0,0}, // 052 4
        {1,0,1,1,0,1,0,1}, // 053 5
        {1,0,1,1,1,1,0,1}, // 054 6
        {1,1,0,0,0,1,0,0}, // 055 7
        {1,1,1,1,1,1,0,1}, // 056 8
        {1,1,1,1,0,1,0,1}, // 057 9

        {0,0,0,0,0,0,0,0}, // 058 :
        {0,0,0,0,0,0,0,0}, // 059 ;
        {0,0,0,0,0,0,0,0}, // 060 <
        {0,0,0,0,0,0,0,0}, // 061 =
        {0,0,0,0,0,0,0,0}, // 062 >
        {0,0,0,0,0,0,0,0}, // 063 ?
        {0,0,0,0,0,0,0,0}, // 064 @

        {1,1,1,1,1,1,0,0}, // 065 A
        {1,1,1,1,1,1,0,1}, // 066 B
        {1,0,1,0,1,0,0,1}, // 067 C
        {1,1,1,0,1,1,0,1}, // 068 D
        {1,0,1,1,1,0,0,1}, // 069 E
        {1,0,1,1,1,0,0,0}, // 070 F
        {1,0,1,1,1,1,0,1}, // 071 G
        {0,1,1,1,1,1,0,0}, // 072 H
        {0,1,0,0,0,1,0,0}, // 073 I
        {1,1,0,0,1,1,0,1}, // 074 J
        {0,1,1,1,1,1,0,0}, // 075 K
        {0,0,1,0,1,0,0,1}, // 076 L
        {1,1,1,0,1,1,0,0}, // 077 M
        {1,1,1,0,1,1,0,0}, // 078 N
        {1,1,1,0,1,1,0,1}, // 079 O
        {1,1,1,1,1,0,0,0}, // 080 P
        {1,1,1,1,0,1,0,0}, // 081 Q
        {1,1,1,1,1,1,0,0}, // 082 R
        {1,0,1,1,0,1,0,1}, // 083 S
        {0,0,1,1,1,0,0,1}, // 084 T
        {0,1,1,0,1,1,0,1}, // 085 U
        {0,1,1,0,1,1,0,1}, // 086 V
        {0,1,1,0,1,1,0,1}, // 087 W
        {0,1,1,1,1,1,0,0}, // 088 X
        {0,1,1,1,0,1,0,1}, // 089 Y
        {1,1,0,1,1,0,0,1}, // 090 Z

        {0,0,0,0,0,0,0,0}, // 091 [
        {0,0,0,0,0,0,0,0}, // 092 BACKSLASH
        {0,0,0,0,0,0,0,0}, // 093 ]
        {0,0,0,0,0,0,0,0}, // 094 ^
        {0,0,0,0,0,0,0,0}, // 095 _
        {0,0,0,0,0,0,0,0}, // 096 `

        {0,0,0,1,1,1,0,1}, // 097 a
        {0,0,1,1,1,1,0,1}, // 098 b
        {0,0,0,1,1,0,0,1}, // 099 c
        {0,1,0,1,1,1,0,1}, // 100 d
        {1,0,1,1,1,0,0,1}, // 101 e
        {1,0,1,1,1,0,0,0}, // 102 f
        {1,1,1,1,0,1,0,1}, // 103 g
        {0,0,1,1,1,1,0,0}, // 104 h
        {0,0,0,0,0,1,0,0}, // 105 i
        {0,1,0,0,1,1,0,1}, // 106 j
        {0,1,1,1,1,1,0,0}, // 107 k
        {0,0,1,0,1,0,0,0}, // 108 l
        {0,0,0,1,1,1,0,0}, // 109 m
        {0,0,0,1,1,1,0,0}, // 110 n
        {0,0,0,1,1,1,0,1}, // 111 o
        {1,1,1,1,1,0,0,0}, // 112 p
        {1,1,1,1,0,1,0,0}, // 113 q
        {0,0,0,1,1,0,0,0}, // 114 r
        {1,0,1,1,0,1,0,1}, // 115 s
        {0,0,1,1,1,0,0,1}, // 116 t
        {0,0,0,0,1,1,0,1}, // 117 u
        {0,0,0,0,1,1,0,1}, // 118 v
        {0,0,0,0,1,1,0,1}, // 119 w
        {0,1,1,1,1,1,0,0}, // 120 x
        {0,1,1,1,0,1,0,1}, // 121 y
        {1,1,0,1,1,0,0,1}, // 122 z

        {0,0,0,0,0,0,0,0}, // 123 {
        {0,0,0,0,0,0,0,0}, // 124 |
        {0,0,0,0,0,0,0,0}, // 125 }
        {0,0,0,0,0,0,0,0}, // 126 ~
        {0,0,0,0,0,0,0,0}  // 127 [DEL]

    };
};
