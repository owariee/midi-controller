#ifndef BANK_HPP
#define BANK_HPP

#include "cstdint.hpp"

class Bank {
private:
    bool* effects;
    uint8_t effectNumber;

public:
    Bank(uint8_t effectNumber);
    ~Bank();

    uint8_t getEffectNumber();
    bool getEffect(uint8_t index);
    void setEffect(uint8_t index, bool state);
};

#endif//BANK_HPP
