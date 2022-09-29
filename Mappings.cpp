#include "Mappings.hpp"

#include "Settings.hpp"

#define length(_Array) (sizeof(_Array) / sizeof(_Array[0]))

Mappings::Mappings() {
    Mappings::lcd = new LCD(LCD_0_PINS);

    uint8_t bankBtnPins[] = {BANK_BUTTON_ARRAY};
    Mappings::bankBtnNumber = length(bankBtnPins);
    Mappings::bankBtn = new Button*[Mappings::bankBtnNumber];
    for(uint8_t i = 0; i < Mappings::bankBtnNumber; i++) {
        Mappings::bankBtn[i] = new Button(bankBtnPins[i]);
    }

    uint8_t effectBtnPins[] = {EFFECT_BUTTON_ARRAY};
    Mappings::effectBtnNumber = length(effectBtnPins);
    Mappings::effectBtn = new Button*[Mappings::effectBtnNumber];
    for(uint8_t i = 0; i < Mappings::effectBtnNumber; i++) {
        Mappings::effectBtn[i] = new Button(effectBtnPins[i]);
    }

    uint8_t offsetBtnPins[] = {OFFSET_0_BUTTON_PIN, OFFSET_1_BUTTON_PIN};
    Mappings::offsetBtnNumber = length(offsetBtnPins);
    Mappings::offsetBtn = new Button*[Mappings::offsetBtnNumber];
    for(uint8_t i = 0; i < Mappings::offsetBtnNumber; i++) {
        Mappings::offsetBtn[i] = new Button(offsetBtnPins[i]);
    }

    uint8_t bankLedPins[] = {BANK_LED_ARRAY};
    Mappings::bankLedNumber = length(bankLedPins);
    Mappings::bankLED = new LED*[Mappings::bankLedNumber];
    for(uint8_t i = 0; i < Mappings::bankLedNumber; i++) {
        Mappings::bankLED[i] = new LED(bankLedPins[i]);
    }
    
    uint8_t effectLedPins[] = {EFFECT_LED_ARRAY};
    Mappings::effectLedNumber = length(effectLedPins);
    Mappings::effectLED = new LED*[Mappings::effectLedNumber];
    for(uint8_t i = 0; i < Mappings::effectLedNumber; i++) {
        Mappings::effectLED[i] = new LED(effectLedPins[i]);
    }

    Mappings::powerLED = new LED(POWER_LED_PIN);
    Mappings::potentiometerLED = new LED(POTENTIOMETER_LED_PIN);

    Mappings::potentiometer = new Potentiometer(POTENTIOMETER_PIN);
}

Mappings::~Mappings() {
    delete[] Mappings::bankBtn;
    delete[] Mappings::effectBtn;
    delete[] Mappings::offsetBtn;
    delete[] Mappings::bankLED;
    delete[] Mappings::effectLED;
    delete Mappings::powerLED;
    delete Mappings::potentiometerLED;
    delete Mappings::lcd;
    delete Mappings::potentiometer;
}

void Mappings::update() {
    Mappings::updateButton(Mappings::bankBtn, Mappings::bankBtnNumber);
    Mappings::updateButton(Mappings::effectBtn, Mappings::effectBtnNumber);
    Mappings::updateButton(Mappings::offsetBtn, Mappings::offsetBtnNumber);
    Mappings::potentiometer->update();
}

Button* Mappings::getButtonBank(uint8_t index) {
    return Mappings::bankBtn[index];
}

Button* Mappings::getButtonEffect(uint8_t index) {
    return Mappings::effectBtn[index];
}

Button* Mappings::getButtonOffset(uint8_t index) {
    return Mappings::offsetBtn[index];
}

uint8_t Mappings::getButtonBankNumber() {
    return Mappings::bankBtnNumber;
}

uint8_t Mappings::getButtonEffectNumber() {
    return Mappings::effectBtnNumber;
}

uint8_t Mappings::getButtonOffsetNumber() {
    return Mappings::offsetBtnNumber;
}

LCD* Mappings::getLCD() {
    return Mappings::lcd;
}

LED* Mappings::getLedBank(uint8_t index) {
    return Mappings::bankLED[index];
}

LED* Mappings::getLedEffect(uint8_t index) {
    return Mappings::effectLED[index];
}

uint8_t Mappings::getLedBankNumber() {
    return Mappings::bankLedNumber;
}

uint8_t Mappings::getLedEffectNumber() {
    return Mappings::effectLedNumber;
}

LED* Mappings::getLedPower() {
    return Mappings::powerLED;
}

LED* Mappings::getLedPotentiometer() {
    return Mappings::potentiometerLED;
}

Potentiometer* Mappings::getPotentiometer() {
    return Mappings::potentiometer;
}

void Mappings::updateButton(Button** arrayBtn, uint8_t size) {
    for(uint8_t i = 0; i < size; i++) {
        arrayBtn[i]->update();
    }
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
