#include "LED.hpp"

#include <Arduino.h>

LED::LED(uint8_t pin) {
    LED::pin = pin;
    LED::state = false;
    pinMode(LED::pin, OUTPUT);
}

void LED::set(bool state) {
    LED::state = state;
    if(state) {
        digitalWrite(LED::pin, HIGH);
        return;
    }
    digitalWrite(LED::pin, LOW);
}

bool LED::get() {
    return LED::state;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
