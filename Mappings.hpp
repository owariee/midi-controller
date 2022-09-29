#ifndef MAPPINGS_HPP
#define MAPPINGS_HPP

#include "cstdint.hpp"
#include "Button.hpp"
#include "LCD.hpp"
#include "LED.hpp"
#include "Potentiometer.hpp"

class Mappings { // Harware Mappings and Instantiation
private:
    LCD* lcd;
    Potentiometer* potentiometer;

    LED** bankLED;
    LED** effectLED;
    LED* powerLED;
    LED* potentiometerLED;

    Button** bankBtn;
    Button** effectBtn;
    Button** offsetBtn;

    uint8_t bankBtnNumber;
    uint8_t effectBtnNumber;
    uint8_t offsetBtnNumber;

    uint8_t bankLedNumber;
    uint8_t effectLedNumber;

    void updateButton(Button** arrayBtn, uint8_t size);

public:
    Mappings();
    ~Mappings();

    void update();

    LCD* getLCD();
    Potentiometer* getPotentiometer();

    LED* getLedBank(uint8_t index);
    LED* getLedEffect(uint8_t index);
    LED* getLedPower();
    LED* getLedPotentiometer();

    Button* getButtonBank(uint8_t index);
    Button* getButtonEffect(uint8_t index);
    Button* getButtonOffset(uint8_t index);

    uint8_t getButtonBankNumber();
    uint8_t getButtonEffectNumber();
    uint8_t getButtonOffsetNumber();

    uint8_t getLedBankNumber();
    uint8_t getLedEffectNumber();
};

#endif//MAPPINGS_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
