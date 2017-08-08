#include "UI.h"

UI::UI() : 
    widgetSize(64),
    widgetCount(0),
    widget(new UIWidget*[widgetSize]),
    pressState(0),
    activeWidget(NULL)
        {
}

UI::~UI(){
    i = widgetCount;
    while(i-->0){
        delete widget[i];
    }
    delete widget;
    if(activeWidget){
        delete activeWidget;
    }
}

bool UI::AddWidget(UIWidget *newWidget){
    if(widgetCount == 64) return false;
    widget[widgetCount++] = newWidget;
    return true;
}

void UI::Draw(){
    i = widgetCount;
    while(i-->0){
        widget[i]->Draw();
    }
}

bool UI::Update(){
    switch(pressState){
    case 0: //not pressing
        if(Touch::Pressing()){
            pressPosition = Touch::Position();
            i = widgetCount;
            while(i-->0){
                if(!widget[i]->OnDown(pressPosition)) continue;
                activeWidget = widget[i];
                pressState = 5;
                break;
            }
        }
        break;
    case 5: //while pressing
        if(!Touch::Pressing()){
            pressState = 10;
        } else {
            pressPosition = Touch::Position();
            activeWidget->WhilePressing(pressPosition);
        }
        break;
    case 10: //done pressing
        activeWidget->OnUp();
        activeWidget = NULL;
        pressState = 0;
        break;
    }
    return true;
}

