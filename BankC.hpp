#ifndef BANKC_HPP
#define BANKC_HPP

#include "Bank.hpp"
#include "Mappings.hpp"

class BankC { // Bank Controller
private:
    uint8_t offsetDatatypeLimit;
    uint8_t offset;
    uint8_t* offsetActiveBankIndex;
    uint8_t bankIndexRelative;
    uint16_t bankIndex;
    uint16_t bankNumber;
    char* bankText;
    char* offsetText;
    Bank** banks;

    Mappings* mappings;

    void drawLCD();
    void setActiveBank(uint8_t index);
    void toggleEffect(uint8_t index);

public:
    BankC(Mappings* mappings);
    ~BankC();
    void update();
};

#endif//BANKC_HPP
