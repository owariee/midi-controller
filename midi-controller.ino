#include "BankC.hpp"
#include "Mappings.hpp"
#include "Settings.hpp"

Mappings mapp;
BankC* bankc;

void setup() { 
    mapp.getLCD()->banner("MIDI Controller", "Firmware v0.3!", 0, 1);
    mapp.getLCD()->banner("Source code at", "git.sabatini.xyz", 1);
    mapp.getLedPower()->set(true);
    Serial.begin(BAUD_RATE);
    bankc = new BankC(&mapp);
}

void loop() {
    mapp.update();
    bankc->update();
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
