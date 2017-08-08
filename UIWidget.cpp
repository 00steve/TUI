#include "UIWidget.h"


UIWidget::UIWidget(Int2 topLeft,Int2 bottomRight,Style style) : 
    top(topLeft.y),
    left(topLeft.x),
    width(bottomRight.x - topLeft.x),
    height(bottomRight.y - topLeft.y),
    isDirty(false),
    style(style)
        {
};

UIWidget::~UIWidget(){
};

bool UIWidget::IsDirty(){
    if(isDirty){
        isDirty = false;
        return true;
    }
    return false;
}

bool UIWidget::OnDown(Int2 position){
    return false;
};

bool UIWidget::OnUp(){
    return false;
};

bool UIWidget::WhilePressing(Int2 position){
    return false;
};

