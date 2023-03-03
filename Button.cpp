#include "Button.hpp"

#include "Settings.hpp"

#include <Arduino.h>

Button::Button(uint8_t pin) {
    Button::pin = pin;
    Button::press = false;
    Button::pressed = false;
    Button::release = false;
    Button::state = false;
    Button::lastState = false;
    Button::lastDebounce = millis();
    pinMode(Button::pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return Button::pressed;
}

bool Button::onPress() {
    return Button::press;
}

bool Button::onRelease() {
    return Button::release;
}

void Button::update() {
    bool newRead = digitalRead(Button::pin) == LOW;

    if(newRead != Button::lastState) {
        Button::lastDebounce = millis();
    }

    if((millis() - Button::lastDebounce) > BUTTON_DEBOUNCE) {
        bool oldRead = Button::state;
        Button::press = !oldRead && newRead;
        Button::pressed = oldRead && newRead;
        Button::release = oldRead && !newRead;
        Button::state = newRead;
    }

    Button::lastState = newRead;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
