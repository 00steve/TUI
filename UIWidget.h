#ifndef UIWIDGET_H
#define UIWIDGET_H

#include "Int2.h"
#include "Screen.h"
#include "Style.h"

class UIWidget {

private:

protected:
    unsigned short top,left,width,height;
    Int2 dimensions;//xy width and height of widget
    String value;
    Style style;


public:
    UIWidget(Int2 topLeft,Int2 bottomRight,Style style);
    virtual void Draw() = 0;
    
    virtual bool OnDown(Int2 position);
    virtual bool OnUp();
    virtual bool WhilePressing(Int2 position);
  
};



#endif
