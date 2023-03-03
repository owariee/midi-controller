#ifndef LED_HPP
#define LED_HPP

#include "cstdint.hpp"

class LED {
private:
    bool state;
    uint8_t pin;

public:
    LED(uint8_t pin);

    void set(bool state);
    bool get();
};

#endif//LED_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
