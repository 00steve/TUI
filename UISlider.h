#ifndef UISLIDER_H
#define UISLIDER_H

#include "UIWidget.h"

template <class T>
class UISlider : public UIWidget {

public:
    UISlider(T &value, T minValue, T maxValue, Int2 topLeft, Int2 bottomRight);

  
};


#endif
