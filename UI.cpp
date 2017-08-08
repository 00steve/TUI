#include "UI.h"

UI::UI() : 
    widgetSize(64),
    widgetCount(0),
    widget(new UIWidget*[widgetSize]),
    pressState(0)
        {
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
            Serial.println("press");
            pressState = 5;
            pressPosition = Touch::Position();
            Serial.print(pressPosition.x);
            Serial.print(",");
            Serial.println(pressPosition.y);
            i = widgetCount;
            while(i-->0){
                if(!widget[i]->OnDown(pressPosition)) continue;
                break;
            }
        }
        break;
    case 5: //while pressing
    
            if(!Touch::Pressing()){
                pressState = 10;
            } else {
                pressPosition = Touch::Position();
                i = widgetCount;
                while(i-->0){
                    widget[i]->WhilePressing(pressPosition);
                }
            }

        break;
    case 10: //done pressing
        Serial.println("up");
        i = widgetCount;
        while(i-->0){
            widget[i]->OnUp();
        }
        pressState = 0;
        break;
    }
    return true;
}

