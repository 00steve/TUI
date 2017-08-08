#include "UIButton.h"


UIButton::UIButton(String newValue,Style newStyle,Int2 topLeft, Int2 bottomRight) : 
    UIWidget(topLeft,bottomRight,newStyle),
    value(newValue)
        {
    Screen::tft.setFont(style.fontStyle);
    valueSize = Screen::GetTextDrawSize(value);
};

bool UIButton::Dirty(){
    return isDirty;
}


void UIButton::Draw(){
    if(pressing){
        Screen::tft.setFont(style.fontStyleActive);
        Screen::tft.setTextColor(style.fontColorActive);
        Screen::tft.fillRect(left,top,width,height,style.backgroundColorActive);   
    } else {
        Screen::tft.setFont(style.fontStyle);
        Screen::tft.setTextColor(style.fontColor);
        Screen::tft.fillRect(left,top,width,height,style.backgroundColor);
    }

    Screen::tft.setCursor(left,top);
    Screen::tft.print(value);
    Serial.println("draw");
};


bool UIButton::OnDown(Int2 position){
    if(position.x < left || position.x > left+width || position.y < top || position.y > top+height) return false;
    pressing = true;
    Draw();
    return true;
}

bool UIButton::OnUp(){
    if(!pressing) return false;
    pressing = false;
    Draw();
    return true;
}


