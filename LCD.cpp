#include "LCD.hpp"

#include <Arduino.h>

LCD::LCD(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) {
    LCD::lcd = new LiquidCrystal(rs, enable, d4, d5, d6, d7);
    LCD::lcd->begin(16,2);
    LCD::lcd->clear();
    LCD::lcd->setCursor(0,0);
}

LCD::~LCD() {
    delete LCD::lcd;
}

void LCD::draw(const char* msg, const char* msg1, uint8_t offset, uint8_t offset1) {
    LCD::lcd->clear();
    LCD::lcd->setCursor(offset,0);
    LCD::lcd->write(msg);
    LCD::lcd->setCursor(offset1,1);
    LCD::lcd->write(msg1);
}

void LCD::banner(const char* msg, const char* msg1, uint8_t offset, uint8_t offset1, uint16_t delayMs) {
    LCD::draw(msg, msg1, offset, offset1);
    delay(delayMs);
}

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
