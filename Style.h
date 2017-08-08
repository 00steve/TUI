#ifndef STYLE_H
#define STYLE_H

#include "ILI9341_t3.h"
#include "font_LiberationSans.h"

struct Style{
    
    uint16_t backgroundColor;
    ILI9341_t3_font_t fontStyle;
    uint16_t fontColor;
    uint16_t backgroundColorActive;
    ILI9341_t3_font_t fontStyleActive;
    uint16_t fontColorActive;

    static Style P();
    static Style Button();
  
};



#endif
