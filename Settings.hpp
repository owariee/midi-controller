#ifndef SETTINGS_HPP
#define SETTINGS_HPP

// Bank Buttons
#define BANK_0_BUTTON_PIN 22
#define BANK_1_BUTTON_PIN 24
#define BANK_2_BUTTON_PIN 26
#define BANK_3_BUTTON_PIN 28
#define BANK_BUTTON_ARRAY BANK_0_BUTTON_PIN, \
                          BANK_1_BUTTON_PIN, \
                          BANK_2_BUTTON_PIN, \
                          BANK_3_BUTTON_PIN

// Bank LEDs
#define BANK_0_LED_PIN 23
#define BANK_1_LED_PIN 25
#define BANK_2_LED_PIN 27
#define BANK_3_LED_PIN 29
#define BANK_LED_ARRAY BANK_0_LED_PIN, \
                       BANK_1_LED_PIN, \
                       BANK_2_LED_PIN, \
                       BANK_3_LED_PIN

// Effect Buttons
#define EFFECT_0_BUTTON_PIN 30
#define EFFECT_1_BUTTON_PIN 32
#define EFFECT_2_BUTTON_PIN 34
#define EFFECT_3_BUTTON_PIN 36
#define EFFECT_BUTTON_ARRAY EFFECT_0_BUTTON_PIN, \
                            EFFECT_1_BUTTON_PIN, \
                            EFFECT_2_BUTTON_PIN, \
                            EFFECT_3_BUTTON_PIN

// Effect LEDs
#define EFFECT_0_LED_PIN 31
#define EFFECT_1_LED_PIN 33
#define EFFECT_2_LED_PIN 35
#define EFFECT_3_LED_PIN 37
#define EFFECT_LED_ARRAY EFFECT_0_LED_PIN, \
                         EFFECT_1_LED_PIN, \
                         EFFECT_2_LED_PIN, \
                         EFFECT_3_LED_PIN

// Offset Buttons
#define OFFSET_0_BUTTON_PIN 38
#define OFFSET_1_BUTTON_PIN 40

// Power LED
#define POWER_LED_PIN 39

// Potentiometer
#define POTENTIOMETER_PIN 03
#define POTENTIOMETER_LED_PIN 41

// LCD Ports
#define LCD_0_RS_PIN 48
#define LCD_0_ENABLE_PIN 49
#define LCD_0_D4_PIN 50
#define LCD_0_D5_PIN 51
#define LCD_0_D6_PIN 52
#define LCD_0_D7_PIN 53
#define LCD_0_PINS LCD_0_RS_PIN, LCD_0_ENABLE_PIN, \
                   LCD_0_D4_PIN, LCD_0_D5_PIN, \
                   LCD_0_D6_PIN, LCD_0_D7_PIN

// General
#define MIDI_CHANNEL 00
#define BUTTON_DEBOUNCE 160
#define POTENTIOMETER_DEBOUNCE 100
#define BAUD_RATE 115200

#endif//SETTINGS_HPP

// vim:tabstop=4:shiftwidth=4:expandtab:textwidth=100
