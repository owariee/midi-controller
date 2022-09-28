#ifndef MAPPINGS_HPP
#define MAPPINGS_HPP

#include "cstdint.hpp"
#include "Button.hpp"
#include "LCD.hpp"
#include "LED.hpp"
#include "Potentiometer.hpp"

class Mappings { // Harware Mappings and Instantiation
private:
    Button** buttons;
    LCD* lcd;
    LED** leds;
    Potentiometer* potentiometer;
    uint8_t ledNumber;
    uint8_t buttonNumber;

public:
    Mappings();
    ~Mappings();

    void update();
    Button* getButton(uint8_t index);
    LCD* getLCD();
    LED* getLED(uint8_t index);
    Potentiometer* getPotentiometer();
};

#endif//MAPPINGS_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
