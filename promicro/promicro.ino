#include "BankC.hpp"
#include "Mappings.hpp"
#include "Settings.hpp"

// Arduino MIDI functions MIDIUSB Library
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

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
