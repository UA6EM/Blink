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
    Blink(uint8_t led_pin, uint16_t led_on, uint16_t led_off, uint16_t count, bool inverse);
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


// реализация методов
Blink::Blink(uint8_t led_pin, uint16_t led_on, uint16_t led_off, uint16_t count,bool inverse)
{
  pinMode(led_pin, OUTPUT);
  _led_pin = led_pin;
  _led_on = led_on;
  _led_off = led_off;
  _count = count * 2 - 1;
  _inverse = inverse;
  if(_inverse){
    _flag = false; 
  }else{
  _flag = true;
  }
  _ends = false;
}

void Blink::start()
{
  _mymillis = millis();
  _ends = false;
  _flag = true;
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
