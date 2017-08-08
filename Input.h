#ifndef INPUT_H
#define INPUT_H

#include <WProgram.h>
#include <WString.h>
#include "Double3.h"


#define ANALOG_INPUT_BITS 12


class Input{
private:

    static short maxAnalogVoltageInt;

protected:


    bool enabled;
    bool ignoreAlert;
    bool record;
    /*store the offset of where the input stores its setting information
    in the eeprom.*/
    int eepromOffset;

    bool newData;


    virtual void SetTilt(Double3 tilt);

public:

    Input() : newData(false){
    };

    /*purely abstract functions that must be implemented by any input types
    that want to be treated as an input.*/
    virtual void Setup() = 0;
    virtual void Update() = 0;
    virtual String Label() = 0;
    virtual String Units();
    virtual String* UnitsRef();

    virtual String StatusString();

    virtual bool StoreSettingDefaults(int startEepromOffset);
    virtual bool StoreSettings(int startingEepromOffset);
    virtual bool StoreSettings();
    virtual bool LoadSettings(int startingEepromOffset);

    static short MaxAnalogVoltageInt();

    float MinimumVoltage();
    float MaximumVoltage();
    bool Enabled();
    void Enable();
    void Disable();
    int EepromOffset();

    bool NewData();

    bool Record();


};



#endif
