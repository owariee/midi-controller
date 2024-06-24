#include "Bank.hpp"

#include <avr/eeprom.h>
#include <EEPROM.h>

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

void Bank::EEPROMwrite(uint8_t bankIndex) {
    uint16_t position = bankIndex * Bank::effectsNumber;
    for(uint8_t i = 0; i < Bank::effectsNumber; i++) {
        EEPROM.write(position+i, Bank::effects[i]);
    }
}

void Bank::EEPROMread(uint8_t bankIndex) {
    uint16_t position = bankIndex * Bank::effectsNumber;
    for(uint8_t i = 0; i < Bank::effectsNumber; i++) {
        Bank::effects[i] = EEPROM.read(position+i);
    }
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
