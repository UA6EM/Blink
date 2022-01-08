/*
  Blink.h - Library for flashing LED.
  Created by  UA6EM, Victor, 07.01.2022
  Released into the public domain.
*/

#pragma once
#include <Arduino.h>

// описание класса
class Blink {   // Blink
  public:
    Blink(uint8_t led_pin, uint16_t led_on, uint16_t led_off, uint16_t count, bool inverse=false);
    void start();
    void myrun();
  private:
    uint32_t _mymillis;
    uint8_t _led_pin;
    uint16_t _led_on;
    uint16_t _led_off;
    uint16_t _count;
    bool _flag;
    bool _ends;
    bool _inverse;
};
