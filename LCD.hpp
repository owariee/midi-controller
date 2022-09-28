#ifndef LCD_HPP
#define LCD_HPP

#include "cstdint.hpp"

#include <LiquidCrystal.h>

class LCD {
private:
    LiquidCrystal* lcd;

public:
    LCD(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    ~LCD();

    void draw(const char* msg, const char* msg1 = "", uint8_t offset = 0, uint8_t offset1 = 0);
    void banner(const char* msg, const char* msg1 = "", uint8_t offset = 0, uint8_t offset1 = 0, uint16_t delayMs = 2000);
};

#endif//LCD_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
