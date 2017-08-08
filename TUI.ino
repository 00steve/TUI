
#include "UI.h"
#include "UILabel.h"
#include "UIButton.h"
#include "UISlider.h"

#define SCREEN_ROTATION 3

UI ui;

double sliderValue = 10;

void setup() {
    analogReadAveraging(32);
    analogReadResolution(ANALOG_INPUT_BITS);
    Serial.begin(9600);
    Wire.begin();

  
    
    Touch::Setup();
    Touch::SetRotation(SCREEN_ROTATION);
    Screen::Setup();
    Screen::SetRotation(SCREEN_ROTATION);

    

    ui.AddWidget(new UILabel("stuff",Style::P(),Int2(10,10),Int2(200,80)));
    ui.AddWidget(new UIButton("click me",Style::Button(),Int2(210,10),Int2(400,100)));
    
    ui.AddWidget(new UISlider<double>(sliderValue,0,100,Style::Button(),Int2(10,110),Int2(470,140)));
    ui.Draw();
}

void loop() {
    // put your main code here, to run repeatedly:
    Touch::Update();
    ui.Update();
}
