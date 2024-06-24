#include "Potentiometer.hpp"

#include "Settings.hpp"

#include <Arduino.h>

Potentiometer::Potentiometer(uint8_t pin) {
    Potentiometer::pin = pin;
    Potentiometer::value = 0;
    Potentiometer::valueChanged = false;
    Potentiometer::lastDebounce = millis();
}

uint8_t Potentiometer::update() {
    if((millis() - Potentiometer::lastDebounce) > POTENTIOMETER_DEBOUNCE) {
        uint32_t read = analogRead(Potentiometer::pin);
        uint8_t newValue = map(read, 1, 1024, 0, 128);
        if(newValue != Potentiometer::value) {
            Potentiometer::valueChanged = true;
            Potentiometer::value = newValue;
        }
        Potentiometer::lastDebounce = millis();
    }
}

bool Potentiometer::isValueChanged() {
    if(!Potentiometer::valueChanged) return false;
    Potentiometer::valueChanged = false;
    return true;
}

uint8_t Potentiometer::getValue() {
    return Potentiometer::value;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
