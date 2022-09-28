#include "LED.hpp"

#include <Arduino.h>

LED::LED(uint8_t pin) {
    LED::pin = pin;
    pinMode(LED::pin, OUTPUT);
}

void LED::set(bool state) {
    if(state) {
        digitalWrite(LED::pin, HIGH);
        return;
    }
    digitalWrite(LED::pin, LOW);
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
