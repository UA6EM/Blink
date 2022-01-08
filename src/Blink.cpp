#include "Blink.h"

// реализация методов
Blink::Blink(uint8_t led_pin, uint16_t led_on, uint16_t led_off, uint16_t count,bool inverse)
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
  _flag = false;
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

