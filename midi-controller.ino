#include "BankC.hpp"
#include "Mappings.hpp"

Mappings mappings;
BankC* bankc;

void setup() { 
    // init lcd pins
    LCD* lcd = mappings.getLCD();
    lcd->banner("MIDI Controller", "Firmware v0.1");
    lcd->banner("Source code at", "git.sabatini.xyz");

    // init serial
    Serial.begin(115200);

    // init bank controller
    bankc = new BankC(&mappings);
}

void loop() {
    mappings.update();
    bankc->update();
}