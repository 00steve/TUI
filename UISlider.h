#ifndef UISLIDER_H
#define UISLIDER_H

#include "UIWidget.h"
#include "Style.h"

template <class T>
class UISlider : public UIWidget {
private:
    T *value;
    T knownValue;
    T minValue;
    T maxValue;
    bool vertical;
    Int2 sliderPosition;
    int oldPosition;
    int touchOffset;
    int sliderRadius;
    bool pressing;
    bool oldPressing;

    void translateToScreen(){
        double p = (*value-minValue) / (maxValue-minValue);
        if(vertical){
            sliderPosition.x = left + width * .5;
            sliderPosition.y = top + style.padding + sliderRadius + (double)(height-style.padding*2-sliderRadius*2) * p;
            //sliderRadius = width *.499 - 2;
        } else {
            sliderPosition.x = left + style.padding + sliderRadius + (double)(width-style.padding*2-sliderRadius*2) * p;
            sliderPosition.y = top + height * .5;
            //sliderRadius = height *.499 - 2;
        }
        
    }
    void translateToValue(){
        double v;
        if(vertical){
            v = (double)(sliderPosition.y - style.padding - sliderRadius - top) / (double)( height-style.padding*2 - sliderRadius*2);
        } else {
            v = (double)(sliderPosition.x - style.padding - sliderRadius - left) / (double)(width-style.padding*2 - sliderRadius*2);
            //v = ((double)(left + width - style.padding - sliderPosition.x) / (double)width-style.padding*2);
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
        knownValue(value),
        minValue(minValue),
        maxValue(maxValue),
        pressing(false),
        oldPressing(true)
            {
        vertical = height > width;//the orientation of the slider.
        sliderRadius = (vertical ? width : height ) *.5 - style.padding;
        translateToScreen();
        Redraw();
    }
    ~UISlider(){
        if(value){
            delete value;
        }
    }

    void Redraw(){
        Draw();
        Screen::tft.drawRect(left,top,width,height,style.backgroundColor);
    }
    
    void Draw(){
      
        backgroundColor = pressing ? style.backgroundColorActive : style.backgroundColor;

        if(vertical){
            if(oldPosition < sliderPosition.y) {
                Screen::tft.fillRect(sliderPosition.x-sliderRadius,oldPosition-sliderRadius,sliderRadius*2,sliderPosition.y-oldPosition,0x0000);
                Screen::tft.fillRect(sliderPosition.x-sliderRadius,oldPosition+sliderRadius,sliderRadius*2,sliderPosition.y-oldPosition,backgroundColor);
            } else if(oldPosition > sliderPosition.y) {
                Screen::tft.fillRect(sliderPosition.x-sliderRadius,sliderPosition.y+sliderRadius,sliderRadius*2,oldPosition-sliderPosition.y,0x0000);
                Screen::tft.fillRect(sliderPosition.x-sliderRadius,sliderPosition.y-sliderRadius,sliderRadius*2,oldPosition-sliderPosition.y,backgroundColor);
            }
        } else {
            if(oldPosition < sliderPosition.x) {
                Screen::tft.fillRect(oldPosition-sliderRadius,sliderPosition.y-sliderRadius,sliderPosition.x-oldPosition,sliderRadius*2,0x0000);
                Screen::tft.fillRect(oldPosition+sliderRadius,sliderPosition.y-sliderRadius,sliderPosition.x-oldPosition,sliderRadius*2,backgroundColor);
            } else if(oldPosition > sliderPosition.x) {
                Screen::tft.fillRect(sliderPosition.x+sliderRadius,sliderPosition.y-sliderRadius,oldPosition-sliderPosition.x,sliderRadius*2,0x0000);
                Screen::tft.fillRect(sliderPosition.x-sliderRadius,sliderPosition.y-sliderRadius,oldPosition-sliderPosition.x,sliderRadius*2,backgroundColor);
            }
        }
        if(pressing != oldPressing){
            oldPressing = pressing;
            Screen::tft.fillRect(sliderPosition.x-sliderRadius,sliderPosition.y-sliderRadius,sliderRadius*2,sliderRadius*2,backgroundColor);
        }

    }

    bool OnDown(Int2 position){
        if(sliderPosition.x - sliderRadius - style.padding > position.x || sliderPosition.x + sliderRadius + style.padding < position.x 
        || sliderPosition.y - sliderRadius - style.padding > position.y || sliderPosition.y + sliderRadius + style.padding < position.y) return false;
        pressing = true;
        touchOffset = vertical ? position.y - sliderPosition.y : position.x - sliderPosition.x;
        Draw();
        return true;
    };

    bool OnUp(){
        if(!pressing) return false;
        pressing = false;
        Draw();
        return true;
    };

    void Update(){
        if(knownValue != *value){
            knownValue = *value;
            translateToScreen();
            Draw();
        }
    };

    bool WhilePressing(Int2 position){
        if(vertical){
            if(sliderPosition.y != position.y){
                oldPosition = sliderPosition.y;
                sliderPosition.y = position.y;//-touchOffset;
                translateToValue();
                Draw();
            }
        } else {
            if(sliderPosition.x != position.x){
                Serial.println(position.x);
                //Screen::tft.fillCircle(sliderPosition.x,sliderPosition.y,sliderRadius,style.clearColor);
                oldPosition = sliderPosition.x;
                sliderPosition.x = position.x;//-touchOffset;
                translateToValue();
                Draw();
            }
        }
        return true;
    }
  
};


#endif
