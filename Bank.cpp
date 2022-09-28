#include "Bank.hpp"

#include "Settings.hpp"

Bank::Bank() {
    Bank::effects = new bool[MIDI_EFFECTS]();
}

Bank::~Bank() {
    delete[] Bank::effects;
}

bool Bank::getEffect(uint8_t index) {
    if(index >= MIDI_EFFECTS) return false;
    return Bank::effects[index];
}

void Bank::setEffect(uint8_t index, bool state) {
    if(index >= MIDI_EFFECTS) return;
    Bank::effects[index] = state;
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
