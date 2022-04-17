#include "BankC.hpp"

#include <stdio.h>

void BankC::drawLCD() {
    MidiS* midiSerial = BankC::mappings->getMidiSerial();
    sprintf(BankC::offsetText, "Offset %i Ch %i", BankC::offset, midiSerial->getChannel());
    sprintf(BankC::bankText, "Bank %i (%i)", BankC::bankIndexRelative, midiSerial->getBank());

    BankC::mappings->getLCD()->draw(offsetText, bankText);
}

void BankC::setActiveBank(uint8_t index) {
    // update indexes
    BankC::bankIndexRelative = index;
    BankC::bankIndex = index + BankC::offset * 4;

    // disable all other bank leds and enable the active bank led 
    for(uint8_t i = BANK_0_LED; i < BANK_3_LED+1; i++) {
        LED* ledBuffer = BankC::mappings->getLED(i);
        if(i-BANK_0_LED == index) {
            ledBuffer->on();
        } else {
            ledBuffer->off();
        }
    }

    // restore effects led 
    for(uint8_t i = EFFECT_0_LED; i < EFFECT_3_LED+1; i++) {
        LED* ledBuffer = BankC::mappings->getLED(i);
        bool active = BankC::banks[BankC::bankIndex]->getEffect(i-EFFECT_0_LED);
        if(active) {
            ledBuffer->on();
        } else {
            ledBuffer->off();
        }
    }

    // send midi signal
    BankC::mappings->getMidiSerial()->changeBank(BankC::bankIndex);

    // update lcd
    BankC::drawLCD();
}

void BankC::toggleEffect(uint8_t index) {
    bool actualState = !BankC::banks[BankC::bankIndex]->getEffect(index);
    BankC::banks[BankC::bankIndex]->setEffect(index, actualState);

    // send midi signal
    BankC::mappings->getMidiSerial()->toggleEffect(index);

    if(actualState) {
        BankC::mappings->getLED(index+EFFECT_0_LED)->on();
    } else {
        BankC::mappings->getLED(index+EFFECT_0_LED)->off();
    }
}

BankC::BankC(Mappings* mappings) {
    BankC::bankIndex = 0;
    BankC::bankIndexRelative = 0;
    BankC::offset = 0;
    BankC::offsetDatatypeLimit = 6;
    BankC::offsetActiveBankIndex = new uint8_t[BankC::offsetDatatypeLimit];
    BankC::bankNumber = (BankC::offsetDatatypeLimit+1) * 4;
    BankC::mappings = mappings;
    BankC::banks = new Bank*[BankC::bankNumber];
    BankC::bankText = new char[16];
    BankC::offsetText = new char[16];

    // init per offset bankIndexRelative
    for(uint8_t i = 0; i < BankC::offsetDatatypeLimit+1; i++) {
        BankC::offsetActiveBankIndex[i] = 0;
    }

    // init banks
    for(uint16_t i = 0; i < BankC::bankNumber; i++) {
        BankC::banks[i] = new Bank(4);
    }

    BankC::setActiveBank(0);
}

BankC::~BankC() {
    delete[] BankC::banks;
    delete BankC::bankText;
    delete BankC::offsetText;
    delete BankC::offsetActiveBankIndex;
}

void BankC::update() {
        for(uint8_t i = BANK_0_BUTTON; i < BANK_3_BUTTON+1; i++) {
        if(BankC::mappings->getButton(i)->isPressed()) {
            BankC::setActiveBank(i-BANK_0_BUTTON);
        }
    }
    for(uint8_t i = EFFECT_0_BUTTON; i < EFFECT_3_BUTTON+1; i++) {
        if(BankC::mappings->getButton(i)->isPressed()) {
            BankC::toggleEffect(i-EFFECT_0_BUTTON);
        }
    }
    if(BankC::mappings->getButton(OFFSET_0_BUTTON)->isPressed() && BankC::offset < BankC::offsetDatatypeLimit) {
        BankC::offsetActiveBankIndex[BankC::offset] = BankC::bankIndexRelative;
        BankC::offset++;
        BankC::setActiveBank(BankC::offsetActiveBankIndex[BankC::offset]);
    }
    if(BankC::mappings->getButton(OFFSET_1_BUTTON)->isPressed() && BankC::offset > 0) {
        BankC::offsetActiveBankIndex[BankC::offset] = BankC::bankIndexRelative;
        BankC::offset--;
        BankC::setActiveBank(BankC::offsetActiveBankIndex[BankC::offset]);
    }
}
