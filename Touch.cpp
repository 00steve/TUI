#include "Touch.h"


Int2 Touch::raw = Int2(0,0);
int Touch::rxplate = 0;
Int2 Touch::screenSize = Int2(SCREEN_SIZE_X,SCREEN_SIZE_Y);
Int2 Touch::screenMax = Int2(3782,3484);
Int2 Touch::screenMin = Int2(230,397);

float Touch::pressure = 0;
Int2 Touch::position = Int2(0,0);
Int2 Touch::smoothPosition = Int2(0,0);

int Touch::minPressure = 50;
unsigned char Touch::rotation = 0;

void Touch::SetRotation(unsigned char newRotation){
    if(newRotation < 0 || newRotation > 3) return;
    rotation = newRotation;
}

bool Touch::Setup(){
    return true;
}

void Touch::readPressureFromScreen(){
    // Set X+ to ground
    pinMode(touchXPPin, OUTPUT);
    digitalWrite(touchXPPin, LOW);

    // Set Y- to VCC
    pinMode(touchYMPin, OUTPUT);
    digitalWrite(touchYMPin, HIGH);

    // Hi-Z X- and Y+
    digitalWrite(touchXMPin, LOW);
    pinMode(touchXMPin, INPUT);
    digitalWrite(touchYPPin, LOW);
    pinMode(touchYPPin, INPUT);

    int z1 = analogRead(touchXMPin);
    int z2 = analogRead(touchYPPin);

    if (rxplate != 0) {
    // now read the x
        float rtouch;
        rtouch = z2;
        rtouch /= z1;
        rtouch -= 1;
        readXFromScreen();
        rtouch *= raw.x;
        rtouch *= rxplate;
        rtouch /= 4096;
        pressure = rtouch;
    } else {
        pressure = (4095-(z2-z1));
    }
    /*Serial.print("analog screen pressure : ");
    Serial.print(z1);
    Serial.print(" , ");
    Serial.print(z2);
    Serial.print(" pressure : " );
    Serial.println(pressure);*/
}

void Touch::readYFromScreen(){
    //set negitive pins to input mode
    pinMode(touchYMPin,INPUT);
    pinMode(touchYPPin,INPUT);

    //set positive pins to output mode
    pinMode(touchXMPin,OUTPUT);
    digitalWrite(touchXMPin,HIGH); //set -y to GND connection

    pinMode(touchXPPin,OUTPUT);
    digitalWrite(touchXPPin,LOW);

    raw.y = analogRead(touchYPPin);
}

void Touch::readXFromScreen(){
    //set negitive pins to input mode
    pinMode(touchXPPin,INPUT);
    pinMode(touchXMPin,INPUT);

    //set positive pins to output mode
    pinMode(touchYMPin,OUTPUT);
    digitalWrite(touchYMPin,LOW); //set -y to GND connection

    pinMode(touchYPPin,OUTPUT);
    digitalWrite(touchYPPin,HIGH);

    raw.x = analogRead(touchXPPin);
}


void Touch::translatePosition(){
    switch(rotation){
        case 0:
            position.x = 0;//(float)(raw.x-screenMin.x) / (float)(screenMax.x - screenMin.x) * screenSize.x;
            position.y = 0;//(float)(raw.y-screenMin.y) / (float)(screenMax.y - screenMin.y) * screenSize.y;
            break;
        case 1:
            position.y = 0;//(float)(raw.x-screenMin.x) / (float)(screenMax.x - screenMin.x) * -screenSize.x;
            position.x = 0;//(float)(raw.y-screenMin.y) / (float)(screenMax.y - screenMin.y) * -screenSize.y;
            break;
        case 2:
            position.x = 0;//(float)(raw.x-screenMin.x) / (float)(screenMax.x - screenMin.x) * screenSize.x;
            position.y = 0;//screenMin.y - ((float)(raw.y-screenMin.y) / (float)(screenMax.y - screenMin.y) * screenSize.y);
            break;
        case 3:
            position.x = (float)(raw.x-screenMin.x) / (float)(screenMax.x - screenMin.x) * screenSize.x;
            position.y = (float)(raw.y-screenMin.y) / (float)(screenMax.y - screenMin.y) * screenSize.y;
            break;
        
    }
}




String Touch::StatusString(){
    return "touch : " + String(position.x) + "," + String(position.y) + " Pressure : " + String(pressure)+"\n";
}
void Touch::Update(){
    readPressureFromScreen();
    readXFromScreen();
    readYFromScreen();
    translatePosition();
}


String Touch::Label(){
    return "Touchscreen";
}


float Touch::Pressure(){
    return pressure;
}

Int2 Touch::Position(){
    return position;
}

Int2 Touch::SmoothPosition(){
    smoothPosition = (smoothPosition*9 + position) / 10;
    return smoothPosition;
}

bool Touch::Pressing(){
    return pressure > minPressure;
}

void Touch::ResetSmoothPosition(){
    smoothPosition = position;
}


