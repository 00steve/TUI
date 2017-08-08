#include "UIWidget.h"


UIWidget::UIWidget(Int2 topLeft,Int2 bottomRight,Style style) : 
    top(topLeft.y),
    left(topLeft.x),
    width(bottomRight.x - topLeft.x),
    height(bottomRight.y - topLeft.y),
    isDirty(true),
    style(style)
        {
}
/*
void UIWidget::Draw(){
    Screen::Hardware().drawRect(left,top,width,height,0xffff);
    Screen::Hardware().drawLine(left,top,left+width-1,top+height-1,0xffff);
    Screen::Hardware().drawLine(left+width-1,top,left,top+height-1,0xffff);
};*/


bool UIWidget::OnDown(Int2 position){
    return false;
};

bool UIWidget::OnUp(){
    return false;
};

bool UIWidget::WhilePressing(Int2 position){
    return false;
};

