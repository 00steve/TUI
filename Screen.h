#ifndef SCREEN_H
#define SCREEN_H


#include "SPI.h"
#include "ILI9341_t3.h"
#include "Int2.h"


#include "font_LiberationSans.h"
//#include "font_AwesomeF000.h"

// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10

class Screen {
public:
    static ILI9341_t3 tft;
    static unsigned char rotation;
    
public:
    static void Clear();
    static Int2 GetTextDrawSize(String text);
    static ILI9341_t3 &Hardware();
    static bool SetRotation(unsigned short newRotation);
    static bool Setup();
    
};






#endif


