#include "Screen.h"



ILI9341_t3 Screen::tft = ILI9341_t3(TFT_CS, TFT_DC);
unsigned char Screen::rotation = 1;

void Screen::Clear(){
    tft.fillScreen(ILI9341_BLACK);
}


    
bool Screen::SetRotation(unsigned short newRotation){
    if(newRotation <0 || newRotation > 3) return false;
    rotation = (unsigned char)newRotation;
    tft.setRotation(rotation);
    return true;
}

bool Screen::Setup(){
    tft.begin();
    
    delayMicroseconds(2);//required to avoid white screens
    tft.fillScreen(ILI9341_BLACK);
    tft.setRotation(rotation);
    
    return true;
}




