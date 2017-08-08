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

     uint16_t backgroundColor;
     
public:
    UIWidget(Int2 topLeft,Int2 bottomRight,Style style);
    ~UIWidget();
    
    virtual void Draw() = 0;
    
    virtual bool OnDown(Int2 position);
    virtual bool OnUp();

    virtual void Redraw() = 0;
    virtual void Update() = 0;
    virtual bool WhilePressing(Int2 position);
  
};



#endif
