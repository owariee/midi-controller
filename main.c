#include "midiMessage.h"

#define BANKNUMBER 10 // Max 128
#define PINNUMBER BANKNUMBER*2
#define HIDDENBANK BANKNUMBER+1

uint8_t bankPins[PINNUMBER] = {
//BUTTONX, LEDX
};

uint8_t bank = HIDDENBANK;
uint8_t oldBank = bank;
uint8_t i;

uint8_t getButtonPin(uint8_t index) {
  return bankPins[index * 2];
}

uint8_t getLedPin(uint8_t index) {
  return bankPins[index*2+1];
}

void setup() {
  // setup buttons and led pins
  for(i = 0; i < BANKNUMBER; i++) {
    pinMode(getButtonPin(i), INPUT_PULLUP);
    pinMode(getLedPin(i), OUTPUT);
  }
}

void loop() {
  // set bank to actual pressed button
  for(i = 0; i < BANKNUMBER; i++) {
    if(digitalRead(getButtonPin(i)) == LOW) {
      bank = i;
    }
  }

  // verify if the active bank has changed and
  // reflect this on the leds and midi interface
  if(oldBank != bank) {
    for(i = 0; i < BANKNUMBER; i++) {
      digitalWrite(getLedPin(i), LOW);
    }
    digitalWrite(getLedPin(bank), HIGH);
    if(oldBank != HIDDENBANK) {
      midiMessage(127, oldBank, 127); // Channel 1 Note off
    }
    midiMessage(144, bank, 127); // Channel 1 Note on
    oldBank = bank;
  }
}
