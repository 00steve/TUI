#include "Style.h"

Style Style::P(){
    Style n;
    n.backgroundColor = 0x0000;
    n.fontStyle = LiberationSans_16;
    n.fontColor = 0xFFFF;

    return n;
}

Style Style::Button(){
    Style n;
    n.backgroundColor = 0xFFFF;
    n.fontStyle = LiberationSans_16;
    n.fontColor = 0x0000;
    n.clearColor = 0x0000;

    n.backgroundColorActive = 0x006F;
    n.fontStyleActive = LiberationSans_16;
    n.fontColorActive = 0xFFFF;

    n.padding = 10;
    n.radius = 10;
    return n;
}
