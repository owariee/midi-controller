#ifndef BANKC_HPP
#define BANKC_HPP

#include "Bank.hpp"
#include "Mappings.hpp"

class BankC { // Bank Controller
private:
    uint8_t offset;
    uint8_t offsetMax;
    uint8_t* bankId;
    Bank** bank;
    Mappings* map;

    void drawLCD();
    void setActiveBank(uint8_t index);
    void toggleEffect(uint8_t index);
    void changeOffset(int8_t offset);
    uint8_t getBankNumber();

public:
    BankC(Mappings* map);
    ~BankC();

    void update();
};

#endif//BANKC_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
