#ifndef UISLIDER_H
#define UISLIDER_H

#include "UIWidget.h"
#include "Style.h"

template <class T>
class UISlider : public UIWidget {
private:
    T *value;
    T minValue;
    T maxValue;
    bool vertical;
    Int2 sliderPosition;
    int oldPosition;
    int sliderRadius;
    bool pressing;

    void translateToScreen(){
        double p = (*value-minValue) / (maxValue-minValue);
        if(vertical){
            sliderPosition.x = left + width * .5;
            sliderPosition.y = top + style.padding + (double)(height-style.padding*2) * p;
            sliderRadius = width *.499 - 2;
        } else {
            sliderPosition.x = left + style.padding + (double)(width-style.padding*2) * p;
            sliderPosition.y = top + height * .5;
            sliderRadius = height *.499 - 2;
        }
        
    }
    void translateToValue(){
        double v;
        if(vertical){
            v = (double)(sliderPosition.y - style.padding - sliderRadius - top) / (double)( height-style.padding*2 - sliderRadius*2);
        } else {
            v = ((double)(left + width - style.padding - sliderPosition.x) / (double)width-style.padding*2);
        }
        
        *value = minValue + (double)(maxValue-minValue)*v;
        
        Serial.println(v);
        if(*value < minValue){
            *value = minValue;
            translateToScreen();
        } else if(*value > maxValue){
            *value = maxValue;
            translateToScreen();
        }
        
    }

public:
    UISlider(T &value, T minValue, T maxValue, Style newStyle, Int2 topLeft, Int2 bottomRight) : 
        UIWidget(topLeft,bottomRight,newStyle),
        value(&value),
        minValue(minValue),
        maxValue(maxValue),
        pressing(false)
            {
        vertical = height > width;//the orientation of the slider.
        translateToScreen();
    }
    ~UISlider(){
        if(value){
            delete value;
        }
    }

    void Draw(){
        if(pressing){
            Screen::tft.drawRoundRect(left,top,width,height,style.radius,style.backgroundColorActive);
            Screen::tft.fillCircle(sliderPosition.x,sliderPosition.y,sliderRadius,style.backgroundColorActive);
        } else {
            Screen::tft.drawRoundRect(left,top,width,height,style.radius,style.backgroundColor);
            Screen::tft.fillCircle(sliderPosition.x,sliderPosition.y,sliderRadius,style.backgroundColor);
        }
    }

    bool OnDown(Int2 position){
        if(sliderPosition.x - sliderRadius > position.x || sliderPosition.x + sliderRadius < position.x 
        || sliderPosition.y - sliderRadius > position.y || sliderPosition.y + sliderRadius < position.y) return false;
        pressing = true;
        Draw();
        return true;
    };

    bool OnUp(){
        if(!pressing) return false;
        pressing = false;
        Draw();
        return true;
    };

    bool WhilePressing(Int2 position){
        if(vertical){
            if(sliderPosition.y != position.y){
                oldPosition = sliderPosition.y;
                sliderPosition.y = position.y;
                translateToValue();
                Draw();
            }
        } else {
            if(sliderPosition.x != position.x){
                Serial.println(position.x);
                //Screen::tft.fillCircle(sliderPosition.x,sliderPosition.y,sliderRadius,style.clearColor);
                oldPosition = sliderPosition.x;
                sliderPosition.x = position.x;
                translateToValue();
                Draw();
            }
        }
        return true;
    }
  
};


#endif
