#ifndef BUTTON_H
#define BUTTON_H
#include "UIWidget.h"


class UIButton : public UIWidget{
private:
    String value;
    Int2 valueSize;
    bool pressing;

public:
    UIButton(String newValue,Style newStyle,Int2 topLeft,Int2 bottomRight);

    virtual bool Dirty();
    virtual void Draw();

    virtual bool OnDown(Int2 position);
    virtual bool OnUp();
};



#endif
