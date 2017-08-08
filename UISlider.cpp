#include "UISlider.h"

template<class T>
UISlider<T>::UISlider(T &value, T minValue, T maxValue, Int2 topLeft, Int2 bottomRight){
    top = topLeft.y;
    left = topLeft.x;
    width = bottomRight.x - topLeft.x;
    height = bottomRight.y - topLeft.y;

    
};

