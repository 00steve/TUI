#ifndef UILABEL_H
#define UILABEL_H

#include "UIWidget.h"

class UILabel : public UIWidget {
private:
    String value;
    
public:
    UILabel(String newValue,Style newStyle,Int2 topLeft,Int2 bottomRight);

    virtual void Draw();

  
};


#endif
