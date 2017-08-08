#ifndef UILABEL_H
#define UILABEL_H

#include "UIWidget.h"

class UILabel : public UIWidget {
private:
    String *value;
    String knownValue;
    
public:
    UILabel(String &value,Style newStyle,Int2 topLeft,Int2 bottomRight);
    ~UILabel();

    virtual void Draw();
    virtual void Redraw();
    virtual void Update();
};


#endif
