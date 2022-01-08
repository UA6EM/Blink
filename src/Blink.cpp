/*
  Blink.h - Library for flashing LED.
  Created by  UA6EM, Victor, 07.01.2022
  Released into the public domain.
*/

#include "Blink.h"

// реализация методов
Blink::Blink(uint8_t led_pin, uint16_t led_on=500, uint16_t led_off=500, uint16_t count=200,bool inverse=false)
{
  pinMode(led_pin, OUTPUT);
  _led_pin = led_pin;
  _led_on = led_on;
  _led_off = led_off;
  _count = count * 2 - 1;
  _inverse = inverse;
  _ends = false;
}

void Blink::start()
{
  _mymillis = millis();
  _ends = false;
  _flag = !(_inverse);
  digitalWrite(_led_pin, _flag);
}

void Blink::myrun()
{
  if (!_ends && millis() - _mymillis >= (_flag ? _led_on : _led_off)) {
    _mymillis = millis();
    _flag = !_flag;
    digitalWrite(_led_pin, _flag);
    _count--;
    if (_count == 0 && !_flag) _ends = true;
  }
}

