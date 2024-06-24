#ifndef MIDI_HPP
#define MIDI_HPP

#include "cstdint.hpp"

void midiChangeBank(uint8_t bank);
void midiToggleEffect(uint8_t effect);
void midiChangePotentiometer(uint8_t level);

#endif//MIDI_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
