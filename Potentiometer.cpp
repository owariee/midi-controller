#include "Potentiometer.hpp"

#include <Arduino.h>

Potentiometer::Potentiometer(uint8_t pin) {
    Potentiometer::pin = pin;
    Potentiometer::valueChanged = false;
    Potentiometer::value = 0;
}

Potentiometer::~Potentiometer() {

}

uint8_t Potentiometer::update() {
    uint32_t read = analogRead(Potentiometer::pin);
    uint8_t newValue = map(read, 1, 1024, 0, 128);

    if(newValue != Potentiometer::value) {
        Potentiometer::valueChanged = true;
        Potentiometer::value = newValue;
    }

    // implement debounce
}

bool Potentiometer::isValueChanged() {
    if(Potentiometer::valueChanged) {
        Potentiometer::valueChanged = false;
        return true;
    }
    return false; 
}

uint8_t Potentiometer::getValue() {
    return Potentiometer::value;
}
