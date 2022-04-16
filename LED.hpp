#ifndef LED_HPP
#define LED_HPP

#include "cstdint.hpp"

class LED {
private:
    uint8_t pin;

public:
    LED(uint8_t pin);
    ~LED();

    void on();
    void off();
};

#endif//LED_HPP
