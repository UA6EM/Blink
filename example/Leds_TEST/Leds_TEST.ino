// BLINK для ATtiny85
#include "Blink.h"

uint8_t led01_pin = 13;
uint8_t led02_pin = 11;
uint8_t led03_pin = 10;

uint16_t work_01_time = 1000;  // включено (время включенного состояния мс) LED1
uint16_t pause_01 = 10000;     // выключено (время выключенного состояния мс) LED1
uint16_t impuls_01 = 270;      // число импульсов LED1
bool inverse_01 = true;

uint16_t work_02_time = 250;   // включено (время включенного состояния мс) LED2
uint16_t pause_02 = 300;       // выключено(время выключенного состояния мс) LED2
uint16_t impuls_02 = 27;       // число импульсов LED2
bool inverse_02 = false;

uint16_t work_03_time = 10;    // включено (время включенного состояния мс) LED3
uint16_t pause_03 = 10;        // выключено(время выключенного состояния мс) LED3
uint16_t impuls_03 = 5000;     // число импульсов LED3
bool inverse_03 = false;

Blink leds_01(led01_pin, work_01_time, pause_01, impuls_01, inverse_01);
Blink leds_02(led02_pin, work_02_time, pause_02, impuls_02, inverse_02);
Blink leds_03(led03_pin, work_03_time, pause_03, impuls_03, inverse_03);

void setup() {
  leds_01.start();
  leds_02.start();
  leds_03.start();
}

void loop()
{
  leds_01.myrun();
  leds_02.myrun();
  leds_03.myrun();
}
