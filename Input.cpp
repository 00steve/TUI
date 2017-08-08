#include "Input.h"


short Input::maxAnalogVoltageInt = pow(2,ANALOG_INPUT_BITS);



String Input::Units(){ return ""; }
String* Input::UnitsRef(){ return NULL; }


short Input::MaxAnalogVoltageInt(){
    return maxAnalogVoltageInt;
}


bool Input::StoreSettingDefaults(int startEepromOffset){
    Serial.println("store setting defaults not implemented for this input type");
    return false;
}

bool Input::StoreSettings(int startingEepromOffset){
    Serial.println("store settings not implemented for this input type");
    return false;
}
bool Input::StoreSettings(){
    return false;
}

bool Input::LoadSettings(int startingEepromOffset){
    Serial.println("load settings not implemented for this input type");
    return false;
}

bool Input::Enabled(){
    return enabled;
}

void Input::Enable(){ enabled = true; }
void Input::Disable(){ enabled = false; }

int Input::EepromOffset(){return eepromOffset;}


bool Input::NewData(){ return newData ? !(newData=false) : false; }

bool Input::Record(){ return record; }
