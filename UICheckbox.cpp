#include "UICheckbox.h"


UICheckbox::UICheckbox(bool &value,Style style,Int2 topLeft,Int2 bottomRight):
    UIWidget(topLeft,bottomRight,style),
    value(&value),
    knownValue(value)
        {
        
};

void UICheckbox::Draw(){
    Screen::tft.fillRect(left+style.padding,top+style.padding,width-style.padding*2,height-style.padding*2,(*value ? style.backgroundColor : 0x0000));
};

bool UICheckbox::OnDown(Int2 position){
    if(position.x < left || position.x > left+width || position.y < top || position.y > top + height) return false;
    *value = !*value;
    isDirty = true;
    Draw();
    return true;
}

bool UICheckbox::OnUp(){
    return false;
};

void UICheckbox::Redraw(){
    Draw();
    Screen::tft.drawRect(left,top,width,height,style.backgroundColor);
};

void UICheckbox::Update(){
    if(knownValue != *value){
        knownValue = *value;
        Draw();
    }
};

