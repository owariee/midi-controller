#ifndef BANK_HPP
#define BANK_HPP

#include "cstdint.hpp"

class Bank {
private:
    uint8_t effectsNumber;
    bool* effects;

public:
    Bank(uint8_t effects);
    ~Bank();

    bool getEffect(uint8_t index);
    void setEffect(uint8_t index, bool state);
};

#endif//BANK_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
