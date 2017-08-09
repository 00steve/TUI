
#include "UI.h"
#include "UILabel.h"
#include "UIButton.h"
#include "UISlider.h"

#define SCREEN_ROTATION 3

UI ui;

double sliderValue = 10;
double sliderValue2 = 10;
double sliderValue3 = 50;
double sliderValue4 = 74.51;
String labelValue = "things";

void setup() {
    analogReadAveraging(32);
    analogReadResolution(ANALOG_INPUT_BITS);
    Serial.begin(9600);
    Wire.begin();

  
    
    Touch::Setup();
    Touch::SetRotation(SCREEN_ROTATION);
    Screen::Setup();
    Screen::SetRotation(SCREEN_ROTATION);

    

    ui.AddWidget(new UILabel<String>(labelValue,Style::H1(),Int2(10,10),Int2(200,80)));

    
    ui.AddWidget(new UIButton("click me",Style::Button(),Int2(210,10),Int2(400,100)));
    
    ui.AddWidget(new UISlider<double>(sliderValue,0,100,Style::Button(),Int2(90,110),Int2(470,160)));
    ui.AddWidget(new UILabel<double>(sliderValue,Style::P(),Int2(10,110),Int2(80,160)));
    
    ui.AddWidget(new UISlider<double>(sliderValue2,0,10,Style::Button(),Int2(90,170),Int2(140,310)));
    ui.AddWidget(new UILabel<double>(sliderValue2,Style::P(),Int2(10,175),Int2(80,200)));
    
    ui.AddWidget(new UISlider<double>(sliderValue3,0,50,Style::Button(),Int2(150,170),Int2(200,310)));
    ui.AddWidget(new UILabel<double>(sliderValue3,Style::P(),Int2(10,205),Int2(80,230)));
    
    ui.AddWidget(new UISlider<double>(sliderValue4,0,140,Style::Button(),Int2(210,170),Int2(260,310)));
    ui.AddWidget(new UILabel<double>(sliderValue4,Style::P(),Int2(10,235),Int2(80,260)));
    
    ui.Draw();
}

void loop() {
    // put your main code here, to run repeatedly:
    Touch::Update();
    ui.Update();

    if(sliderValue > 50){
        labelValue = "stuff";
    } else {
        labelValue = "things";
    }

    
    
}
