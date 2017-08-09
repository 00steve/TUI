#ifndef UICHECKBOX_H
#define UICHECKBOX_H

#include "UIWidget.h"

class UICheckbox : public UIWidget{
private:
    bool *value;
    bool knownValue;

public:
    UICheckbox(bool &value,Style style,Int2 topLeft,Int2 bottomRight);

    virtual void Draw();

    virtual bool OnDown(Int2 position);
    virtual bool OnUp();
    
    virtual void Redraw();
    virtual void Update();


  
};



#endif
