#ifndef LED_HPP
#define LED_HPP

#include "cstdint.hpp"

class LED {
private:
    uint8_t pin;

public:
    LED(uint8_t pin);

    void set(bool state);
};

#endif//LED_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
