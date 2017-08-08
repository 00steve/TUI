#include "UILabel.h"

UILabel::UILabel(String newValue,Style newStyle,Int2 topLeft, Int2 bottomRight) : 
    UIWidget(topLeft,bottomRight,newStyle),
    value(newValue)
        {
  
};
UILabel::~UILabel(){
    
}


void UILabel::Draw(){
    Screen::tft.setFont(style.fontStyle);
    Screen::tft.setTextColor(style.fontColor);
    Screen::tft.setCursor(top,left);
    Screen::tft.print(value);
};

