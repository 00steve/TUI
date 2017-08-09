#ifndef UILABEL_H
#define UILABEL_H

#include "UIWidget.h"

template <class T>
class UILabel : public UIWidget {
private:
    T *value;
    T knownValue;
    
public:
    UILabel(T &value,Style newStyle,Int2 topLeft, Int2 bottomRight) : 
        UIWidget(topLeft,bottomRight,newStyle),
        value(&value),
        knownValue(value)
            {
      
    };
    
    ~UILabel(){
        delete value;
    }
    
    
    virtual void Draw(){
        Screen::tft.fillRect(left,top,width,height,style.backgroundColor);
        Screen::tft.setFont(style.fontStyle);
        Screen::tft.setTextColor(style.fontColor);
        Screen::tft.setCursor(left+style.padding,top+style.padding);
        Screen::tft.print(*value);
    };
    
    
    virtual void Redraw(){
        Draw();
    }
    
    virtual void Update(){
        if(knownValue != *value){
            knownValue = *value;
            Draw();
        }
    };

};


#endif
