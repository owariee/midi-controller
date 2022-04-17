#ifndef MIDIS_HPP
#define MIDIS_HPP

#include "cstdint.hpp"

#include <Arduino.h>

class MidiS { // Midi through serial
private:
    uint8_t channel;
    uint8_t bank;
    void message(byte status, byte data);
    void message(byte status, byte data, byte data2);

public:
    MidiS();
    ~MidiS();

    void changeBank(uint8_t bank);
    void toggleEffect(uint8_t effect);
    void changePotentiometer(uint8_t level);

    uint8_t getChannel();
    uint8_t getBank();
};

#endif//MIDIS_HPP
