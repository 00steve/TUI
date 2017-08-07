
#include "UI.h"
#include "UILabel.h"

void setup() {
    analogReadAveraging(32);
    analogReadResolution(ANALOG_INPUT_BITS);
    Serial.begin(9600);
    Wire.begin();

  
    
    Touch::Setup();
    Screen::Setup();
    Screen::SetRotation(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  Touch::Update();
  Int2 pos = Touch::Position();
  Serial.print(pos.x);
  Serial.print(" ");
  Serial.println(pos.y);
  delay(10);

  UILabel widg = UILabel("stuff",UIP,Int2(pos.x,pos.y),Int2(200,140));
  widg.Draw();
  
}
