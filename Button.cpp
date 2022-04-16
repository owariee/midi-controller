#include "Button.hpp"

#include <Arduino.h>

Button::Button(uint8_t pin) {
    Button::pin = pin;
    Button::state = false;
    Button::pressed = false;
    Button::lastDebounce = millis();
    Button::debounceDelay = 160;
    Button::lastState = false;

    pinMode(Button::pin, INPUT_PULLUP);
}

Button::~Button() {

}

bool Button::isPressed() {
    return Button::pressed;
}

void Button::update() {
    bool newRead = digitalRead(Button::pin) == LOW;

    if(newRead != Button::lastState) {
        Button::lastDebounce = millis();
    }

    if((millis() - Button::lastDebounce) > Button::debounceDelay) {
        bool oldRead = Button::state;
        Button::pressed = !oldRead && newRead;
        Button::state = newRead;
    }

    Button::lastState = newRead;
}
