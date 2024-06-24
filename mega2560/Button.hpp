#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "cstdint.hpp"

class Button {
private:
    uint8_t pin;
    bool state;
    bool press;
    bool pressed;
    bool release;
    bool lastState;
    uint32_t lastDebounce;
    
public:
    Button(uint8_t pin);

    bool isPressed();
    bool onPress();
    bool onRelease();
    void update();
};

#endif//BUTTON_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
