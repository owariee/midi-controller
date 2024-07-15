#include "Midi.hpp"

#include "Settings.hpp"

#include <Arduino.h>

void midiMessage2(int8_t status, int8_t data) {
    Serial.write(status);
    Serial.write(data);
}

void midiMessage3(int8_t status, int8_t data, int8_t data2) {
    Serial.write(status);
    Serial.write(data);
    Serial.write(data2);
}

void midiChangeBank(uint8_t bank) {
    if(bank > 127) {
        return;
    }
    midiMessage2(192+MIDI_CHANNEL, bank);
}

void midiToggleEffect(uint8_t effect) {
    if(effect > 127) {
        return;
    }
    midiMessage3(176+MIDI_CHANNEL, effect, 64);
}

void midiChangePotentiometer(uint8_t level) {
    if(level > 127) {
        return;
    }
    midiMessage3(176+MIDI_CHANNEL, 112, level);
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
