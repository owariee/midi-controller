#include "BankC.hpp"

#include "Settings.hpp"
#include "Midi.hpp"

#include <stdio.h>

#define BANK_NUMBER 128

BankC::BankC(Mappings* map) {
    BankC::offset = 0;
    BankC::offsetMax = BANK_NUMBER/BankC::map->getButtonBankNumber();
    BankC::bankId = new uint8_t[BankC::offsetMax]();
    BankC::bank = new Bank*[BANK_NUMBER];
    BankC::map = map;

    for(uint8_t i = 0; i < BANK_NUMBER; i++) {
        BankC::bank[i] = new Bank(BankC::map->getButtonEffectNumber());
    }

    BankC::setActiveBank(0);
}

BankC::~BankC() {
    delete[] BankC::bankId;
    delete[] BankC::bank;
}

uint8_t BankC::getBankNumber() {
    return BankC::offset * BankC::map->getButtonBankNumber() + BankC::bankId[BankC::offset];
}

void BankC::setActiveBank(uint8_t index) {
    BankC::bankId[BankC::offset] = index;
    uint8_t bankNumber = BankC::getBankNumber();

    // disable all other bank leds and enable the active bank led 
    for(uint8_t i = 0; i < BankC::map->getLedBankNumber(); i++) {
        BankC::map->getLedBank(i)->set(i == index);
    }

    // restore effects led 
    for(uint8_t i = 0; i < BankC::map->getLedEffectNumber(); i++) {
        bool state = BankC::bank[bankNumber]->getEffect(i);
        BankC::map->getLedEffect(i)->set(state);
    }

    midiChangeBank(bankNumber);
    BankC::drawLCD();
}

void BankC::toggleEffect(uint8_t index) {
    uint8_t bankNumber = BankC::getBankNumber();
    bool state = !BankC::bank[bankNumber]->getEffect(index);
    BankC::bank[bankNumber]->setEffect(index, state);
    midiToggleEffect(index);
    BankC::map->getLedEffect(index)->set(state);
}

void BankC::drawLCD() {
    char* line1 = new char[16];
    char* line2 = new char[16];
    sprintf(line1, "Bank %i Prg %i", BankC::bankId[BankC::offset], BankC::getBankNumber());
    sprintf(line2, "Offset %i Ch %i", BankC::offset, MIDI_CHANNEL);
    BankC::map->getLCD()->draw(line1, line2, 1, 1);
}

void BankC::changeOffset(int8_t offset) {
    BankC::offset += offset;
    BankC::setActiveBank(BankC::bankId[BankC::offset]);
}

void BankC::update() {
    for(uint8_t i = 0; i < BankC::map->getButtonBankNumber(); i++) {
        if(BankC::map->getButtonBank(i)->onPress()) {
            BankC::setActiveBank(i);
        }
    }
    for(uint8_t i = 0; i < BankC::map->getButtonEffectNumber(); i++) {
        if(BankC::map->getButtonEffect(i)->onPress()) {
            BankC::toggleEffect(i);
        }
    }
    if(BankC::map->getButtonOffset(0)->onPress() && BankC::offset < BankC::offsetMax-1) {
        BankC::changeOffset(1);
    }
    if(BankC::map->getButtonOffset(1)->onPress() && BankC::offset > 0) {
        BankC::changeOffset(-1);
    }
    Potentiometer* pot = BankC::map->getPotentiometer();
    if(pot->isValueChanged()) {
        uint8_t potValue = pot->getValue();
        bool state = potValue != 0;
        BankC::map->getLedPotentiometer()->set(state);
        if(state) midiChangePotentiometer(potValue);
    }
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
