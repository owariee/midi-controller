#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "cstdint.hpp"

class Button {
private:
    uint8_t pin;
    bool state;
    bool pressed;
    bool lastState;
    uint32_t lastDebounce;
    uint32_t debounceDelay;
    
public:
    Button(uint8_t pin);
    ~Button();

    bool isPressed();
    void update();
};

#endif//BUTTON_HPP
