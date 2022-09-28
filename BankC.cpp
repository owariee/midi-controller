#include "BankC.hpp"

#include "Settings.hpp"
#include "Components.hpp"
#include "Midi.hpp"

#include <stdio.h>

#define BANK_NUMBER 128
#define OFFSET_MAX (BANK_NUMBER/MIDI_BANKS)

BankC::BankC(Mappings* map) {
    BankC::offset = 0;
    BankC::bankId = new uint8_t[OFFSET_MAX]();
    BankC::bank = new Bank[BANK_NUMBER]();
    BankC::map = map;
    BankC::setActiveBank(0);
}

BankC::~BankC() {
    delete[] BankC::bankId;
    delete[] BankC::bank;
}

uint8_t BankC::getBankNumber() {
    return BankC::offset * MIDI_BANKS + BankC::bankId[BankC::offset];
}

void BankC::setActiveBank(uint8_t index) {
    BankC::bankId[BankC::offset] = index;
    uint8_t bankNumber = BankC::getBankNumber();

    // disable all other bank leds and enable the active bank led 
    for(uint8_t i = BANK_0_LED; i < BANK_3_LED+1; i++) {
        BankC::map->getLED(i)->set(i-BANK_0_LED == index);
    }

    // restore effects led 
    for(uint8_t i = EFFECT_0_LED; i < EFFECT_3_LED+1; i++) {
        bool state = BankC::bank[bankNumber].getEffect(i-EFFECT_0_LED);
        BankC::map->getLED(i)->set(state);
    }

    midiChangeBank(bankNumber);
    BankC::drawLCD();
}

void BankC::toggleEffect(uint8_t index) {
    uint8_t bankNumber = BankC::getBankNumber();
    bool state = !BankC::bank[bankNumber].getEffect(index);
    BankC::bank[bankNumber].setEffect(index, state);
    midiToggleEffect(index);
    BankC::map->getLED(EFFECT_0_LED+index)->set(state);
}

void BankC::drawLCD() {
    char* line1 = new char[16];
    char* line2 = new char[16];
    sprintf(line1, "Offset %i C%i", BankC::offset, MIDI_CHANNEL);
    sprintf(line2, "Bank %i (%i)", BankC::bankId[BankC::offset], BankC::getBankNumber());
    BankC::map->getLCD()->draw(line1, line2);
}

void BankC::changeOffset(int8_t offset) {
    BankC::offset += offset;
    BankC::setActiveBank(BankC::bankId[BankC::offset]);
}

void BankC::update() {
    for(uint8_t i = BANK_0_BUTTON; i < BANK_3_BUTTON+1; i++) {
        if(BankC::map->getButton(i)->onPress()) {
            BankC::setActiveBank(i-BANK_0_BUTTON);
        }
    }
    for(uint8_t i = EFFECT_0_BUTTON; i < EFFECT_3_BUTTON+1; i++) {
        if(BankC::map->getButton(i)->onPress()) {
            BankC::toggleEffect(i-EFFECT_0_BUTTON);
        }
    }
    if(BankC::map->getButton(OFFSET_0_BUTTON)->onPress() && BankC::offset < OFFSET_MAX-1) {
        BankC::changeOffset(1);
    }
    if(BankC::map->getButton(OFFSET_1_BUTTON)->onPress() && BankC::offset > 0) {
        BankC::changeOffset(-1);
    }
    Potentiometer* pot = BankC::map->getPotentiometer();
    if(pot->isValueChanged()) {
        uint8_t potValue = pot->getValue();
        bool state = potValue != 0;
        BankC::map->getLED(POTENTIOMETER_LED)->set(state);
        if(state) midiChangePotentiometer(potValue);
    }
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
