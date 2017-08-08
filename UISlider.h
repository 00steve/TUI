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

    int translateToScreen(T value,T minValue,T maxValue){
        double p = (value-minValue) / (maxValue-minValue);
        if(vertical){
            
        } else {
            return left + (double)width * p;
        }
        return 0;
        
    }

public:
    UISlider(T &value, T minValue, T maxValue, Style newStyle, Int2 topLeft, Int2 bottomRight) : 
        UIWidget(topLeft,bottomRight,newStyle),
        value(&value),
        minValue(minValue),
        maxValue(maxValue)
            {
        vertical = height > width;//the orientation of the slider.
    }

    void Draw(){
        Screen::tft.drawRoundRect(left,top,width,height,style.radius,style.backgroundColor);
        
        Screen::tft.fillCircle(0,0,10,style.backgroundColor);
        //*value = 60;
    }
  
};


#endif
