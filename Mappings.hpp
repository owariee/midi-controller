#ifndef MAPPINGS_HPP
#define MAPPINGS_HPP

#include "cstdint.hpp"
#include "Button.hpp"
#include "LCD.hpp"
#include "LED.hpp"

#define BANK_0_BUTTON 0
#define BANK_1_BUTTON 1
#define BANK_2_BUTTON 2
#define BANK_3_BUTTON 3
#define EFFECT_0_BUTTON 4
#define EFFECT_1_BUTTON 5
#define EFFECT_2_BUTTON 6
#define EFFECT_3_BUTTON 7
#define OFFSET_0_BUTTON 8
#define OFFSET_1_BUTTON 9 

#define BANK_0_LED 0
#define BANK_1_LED 1
#define BANK_2_LED 2
#define BANK_3_LED 3
#define EFFECT_0_LED 4
#define EFFECT_1_LED 5
#define EFFECT_2_LED 6
#define EFFECT_3_LED 7
#define POWER_LED 8
#define POTENTIOMETER_LED 9 

class Mappings { // Harware Mappings and Instantiation
private:
    uint8_t buttonNumber;
    Button** buttons;

    LCD* lcd;

    uint8_t ledNumber;
    LED** leds;

public:
    Mappings();
    ~Mappings();

    void update();
    Button* getButton(uint8_t index);
    LCD* getLCD();
    LED* getLED(uint8_t index);
};

#endif//MAPPINGS_HPP
