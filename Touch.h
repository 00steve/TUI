#ifndef TOUCH_H
#define TOUCH_H

#include "Int2.h"
#include <Wire.h>
#include "Input.h"

#ifndef SCREEN_SIZE_X
    #define SCREEN_SIZE_X 480
#endif // SCREEN_SIZE_X
#ifndef SCREEN_SIZE_Y
    #define SCREEN_SIZE_Y 320
#endif // SCREEN_SIZE_Y

#define touchYPPin A1
#define touchXPPin A0
#define touchYMPin A20
#define touchXMPin A19


class Touch{

private:

    static int pressureRaw;
    static Int2 raw;
    static int rxplate;

    static Int2 screenSize;
    static Int2 screenMin;
    static Int2 screenMax;

    static void readPressureFromScreen();
    static void readYFromScreen();
    static void readXFromScreen();
    static void translatePosition();

    static float pressure;
    static float smoothPressure;
    static Int2 position;
    static Int2 smoothPosition;
    static int minPressure;
    static unsigned char rotation;
    
protected:


public:
    static bool Setup();
    virtual String StatusString();
    static void Update();
    virtual String Label();

    static float Pressure();
    static Int2 Position();
    static Int2 SmoothPosition();
    static bool Pressing();
    static void ResetSmoothPosition();
    static void SetRotation(unsigned char newRotation);
};






#endif
