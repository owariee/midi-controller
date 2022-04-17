#include "MidiS.hpp"

void MidiS::message(byte status, byte data) {
    Serial.write(status);
    Serial.write(data);
}

void MidiS::message(byte status, byte data, byte data2) {
    Serial.write(status);
    Serial.write(data);
    Serial.write(data2);
}

MidiS::MidiS() {
    MidiS::channel = 0;
    MidiS::bank = 0;
}

MidiS::~MidiS() {

}

void MidiS::changeBank(uint8_t bank) {
    MidiS::channel = bank/128;
    if(channel > 16) {
        return;
    }
    MidiS::bank = bank - (128*MidiS::channel);

    // send program change
    MidiS::message(192+MidiS::channel, MidiS::bank);
}

void MidiS::toggleEffect(uint8_t effect) {
    uint8_t effectIndex = (((MidiS::channel*128)+MidiS::bank)*4) + effect;
    uint8_t effectChannel = effectIndex/128;
    effectIndex = effectIndex - (effectChannel*128);
    // send control change
    MidiS::message(176+effectChannel, effectIndex, 64);
}

void MidiS::changePotentiometer(uint8_t level) {
    MidiS::message(176, 112, level);
}

uint8_t MidiS::getChannel() {
    return MidiS::channel;
}

uint8_t MidiS::getBank() {
    return MidiS::bank;
}
