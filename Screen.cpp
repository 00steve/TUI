#include "Screen.h"



ILI9341_t3 Screen::tft = ILI9341_t3(TFT_CS, TFT_DC);
unsigned char Screen::rotation = 1;

void Screen::Clear(){
    tft.fillScreen(ILI9341_BLACK);
}

Int2 Screen::GetTextDrawSize(String text){
    int16_t  x1, y1;
    uint16_t w, h;
    //tft.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
    return Int2(w,h);
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




