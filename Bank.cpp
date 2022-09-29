#include "Bank.hpp"

Bank::Bank(uint8_t effectsNumber) {
    Bank::effectsNumber = effectsNumber;
    Bank::effects = new bool[Bank::effectsNumber]();
}

Bank::~Bank() {
    delete[] Bank::effects;
}

bool Bank::getEffect(uint8_t index) {
    if(index >= Bank::effectsNumber) return false;
    return Bank::effects[index];
}

void Bank::setEffect(uint8_t index, bool state) {
    if(index >= Bank::effectsNumber) return;
    Bank::effects[index] = state;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
