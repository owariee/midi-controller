#include "midiMessage.h"
#include "bankController.h"

uint8_t bankPins[] = {
// BUTTON, LED
}; // Max 128 banks

uint8_t bankNumber = 0;
uint8_t hiddenBank = 0;
uint8_t bank = 0;
uint8_t oldBank = 0;
uint8_t i = 0;

uint8_t getButtonPin(uint8_t index) {
  return bankPins[index*2];
}

uint8_t getLedPin(uint8_t index) {
  return bankPins[index*2+1];
}

uint8_t bankControllerGetBank() {
  return bank;
}

void bankControllerSetup() {
  // setup variables
  bankNumber = (sizeof(bankPins)/sizeof(bankPins[0]))/2;
  hiddenBank = bankNumber+1;
  bank = hiddenBank;
  oldBank = bank;

  // setup buttons and led pins for each bank
  for(i = 0; i < bankNumber; i++) {
    pinMode(getButtonPin(i), INPUT_PULLUP);
    pinMode(getLedPin(i), OUTPUT);
  }
}

void bankControllerLogic() {
  // set bank to actual pressed button
  for(i = 0; i < bankNumber; i++) {
    if(digitalRead(getButtonPin(i)) == LOW) {
      bank = i;
    }
  }

  // verify if the active bank has changed and
  // reflect this on the leds and midi interface
  if(oldBank != bank) {
    for(i = 0; i < bankNumber; i++) {
      digitalWrite(getLedPin(i), LOW);
    }
    digitalWrite(getLedPin(bank), HIGH);
    if(oldBank != hiddenBank) {
      midiMessage(127, oldBank, 127); // Channel 1 Note off
    }
    midiMessage(144, bank, 127); // Channel 1 Note on
    oldBank = bank;
  }
}

