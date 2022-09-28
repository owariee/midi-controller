#include "BankC.hpp"
#include "Mappings.hpp"
#include "Components.hpp"

// midi-controller.ino Put baud rate intro settings, move start code to BankC
// Midi            change byte to uint8_t/int8_t
// Mappings        make new hardware instantiation easy

Mappings mappings;
BankC* bankc;

void setup() { 
    // init lcd 
    LCD* lcd = mappings.getLCD();
    lcd->banner("MIDI Controller", "Firmware v0.1");
    lcd->banner("Source code at", "git.sabatini.xyz");

    // init power led
    mappings.getLED(POWER_LED)->set(true);

    // init serial
    Serial.begin(115200);

    // init bank controller
    bankc = new BankC(&mappings);
}

void loop() {
    mappings.update();
    bankc->update();
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
