#ifndef POTENTIOMETER_HPP
#define POTENTIOMETER_HPP

#include "cstdint.hpp"

class Potentiometer {
private:
    uint8_t pin;
    bool valueChanged;
    uint8_t value;

public:
    Potentiometer(uint8_t pin);
    ~Potentiometer();

    uint8_t update();
    bool isValueChanged();
    uint8_t getValue();
};

#endif//POTENTIOMETER_HPP
