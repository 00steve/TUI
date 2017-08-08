#ifndef STYLE_H
#define STYLE_H

#include "ILI9341_t3.h"
#include "font_LiberationSans.h"

struct Style{
    
    uint16_t backgroundColor;
    uint16_t backgroundColorActive;
    uint16_t clearColor;
    
    ILI9341_t3_font_t fontStyle;
    ILI9341_t3_font_t fontStyleActive;
    
    uint16_t fontColor;
    uint16_t fontColorActive;

    /*padding is the amount of room given from the border of any widgets 
    to the inner components. For example, in a slider, the border would determine
    how far the slider can move (length - padding*2), and how large the actual 
    slider is on the track (width - padding*2), etc. It should be used like a boss,
    or else the man's gonna have a word with your dumb asses.*/
    unsigned char padding;

    /*just like the css property, mo-fo's!*/
    unsigned char radius;

    static Style P();
    static Style Button();
  
};



#endif
