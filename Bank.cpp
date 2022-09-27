#include "Bank.hpp"

Bank::Bank(uint8_t effectNumber) {
    Bank::effectNumber = effectNumber;
    Bank::effects = new bool[Bank::effectNumber];

    for(uint8_t i = 0; i < Bank::effectNumber; i++) {
        Bank::effects[i] = false;
    }
}

Bank::~Bank() {
    delete[] Bank::effects;
}

uint8_t Bank::getEffectNumber() {
    return Bank::effectNumber;
}

bool Bank::getEffect(uint8_t index) {
    return Bank::effects[index];
}

void Bank::setEffect(uint8_t index, bool state) {
    if(index < Bank::effectNumber && index > -1) {
        Bank::effects[index] = state;
    }
}
