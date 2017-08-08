#include "UILabel.h"

UILabel::UILabel(String &value,Style newStyle,Int2 topLeft, Int2 bottomRight) : 
    UIWidget(topLeft,bottomRight,newStyle),
    value(&value)
        {
  
};
UILabel::~UILabel(){
    
}


void UILabel::Draw(){
    Screen::tft.fillRect(left,top,width,height,style.backgroundColor);
    Screen::tft.setFont(style.fontStyle);
    Screen::tft.setTextColor(style.fontColor);
    Screen::tft.setCursor(top,left);
    Screen::tft.print(*value);
};


void UILabel::Redraw(){
    Draw();
}

void UILabel::Update(){
    if(knownValue != *value){
        knownValue = *value;
        Draw();
    }
};


