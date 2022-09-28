#include "Mappings.hpp"

#include "Settings.hpp"

Mappings::Mappings() {
    Mappings::lcd = new LCD(LCD_0_RS_PIN, LCD_0_ENABLE_PIN, LCD_0_D4_PIN, LCD_0_D5_PIN,
                            LCD_0_D6_PIN, LCD_0_D7_PIN);

    uint8_t buttonPins[] = { BANK_0_BUTTON_PIN, BANK_1_BUTTON_PIN, BANK_2_BUTTON_PIN, 
                             BANK_3_BUTTON_PIN, EFFECT_0_BUTTON_PIN, EFFECT_1_BUTTON_PIN,
                             EFFECT_2_BUTTON_PIN, EFFECT_3_BUTTON_PIN, OFFSET_0_BUTTON_PIN,
                             OFFSET_1_BUTTON_PIN };
    Mappings::buttonNumber = 10;
    Mappings::buttons = new Button*[Mappings::buttonNumber];
    for(uint8_t i = 0; i < Mappings::buttonNumber; i++) {
        Mappings::buttons[i] = new Button(buttonPins[i]);
    }

    uint8_t ledPins[] = { BANK_0_LED_PIN, BANK_1_LED_PIN, BANK_2_LED_PIN, BANK_3_LED_PIN,
                          EFFECT_0_LED_PIN, EFFECT_1_LED_PIN, EFFECT_2_LED_PIN, EFFECT_3_LED_PIN,
                          POWER_LED_PIN, POTENTIOMETER_LED_PIN };
    Mappings::ledNumber = 10;
    Mappings::leds = new LED*[Mappings::ledNumber];
    for(uint8_t i = 0; i < Mappings::ledNumber; i++) {
        Mappings::leds[i] = new LED(ledPins[i]);
    }

    Mappings::potentiometer = new Potentiometer(POTENTIOMETER_PIN);
}

Mappings::~Mappings() {
    delete[] Mappings::buttons;
    delete Mappings::lcd;
    delete[] Mappings::leds;
    delete Mappings::potentiometer;
}

void Mappings::update() {
    for(uint8_t i = 0; i < Mappings::buttonNumber; i++) {
        Mappings::buttons[i]->update();
    }
    Mappings::potentiometer->update();
}

Button* Mappings::getButton(uint8_t index) {
    return Mappings::buttons[index];
}

LCD* Mappings::getLCD() {
    return Mappings::lcd;
}

LED* Mappings::getLED(uint8_t index) {
    return Mappings::leds[index];
}

Potentiometer* Mappings::getPotentiometer() {
    return Mappings::potentiometer;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
