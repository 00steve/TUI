#ifndef UI_H
#define UI_H

#include "Touch.h"
#include "Screen.h"
#include "UIWidget.h"

#define UIH1 1
#define UIH2 2
#define UIH3 3
#define UIH4 4
#define UIP  10

#define UI_COLOR_ERROR 0xF800
#define UI_COLOR_NORMAL 0x0000
#define UI_COLOR_SUCCESS 0x07E0

#define UIH1FONT Arial
#define UIH1SIZE 32
#define UIH1COLOR 0xffff



class UI {
private:
    unsigned char widgetSize;
    unsigned char widgetCount;
    UIWidget **widget;

    unsigned char pressState;
    Int2 pressPosition;

    unsigned int i;

public:
    UI();
    bool AddWidget(UIWidget *newWidget);
    void Draw();
    bool Update();
  
};



#endif
