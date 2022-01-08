// ATMEL                                ATtiny 25/45/85
//                                           +-\/-+
//             !RESET PCINT5 5/A0 (D 5) PB5 1|    |8  Vcc
//  XTAL1 CLKI !OC1B  PCINT3 3/A3 (D 3) PB3 2|    |7  PB2 (D 2) 2/A1 PCINT2 USCK SCK T0   INT0 SCL  
//  XTAL2 CLKO  OC1B  PCINT4 4/A2 {D 4) PB4 3|    |6  PB1 (D 1) pwm1 PCINT1 MISO DO  OC0B AIN1
//                                      GND 4|    |5  PB0 (D 0) pwm0 PCINT0 MOSI DI  OC0A AIN0 SDA AREF
//                                           +----+

// BLINK для ATtiny85
#include "Blink.h"

uint8_t led01_pin = 0;
uint8_t led02_pin = 1; //(LED_BUILTIN)
uint8_t led03_pin = 2;

uint16_t work_01_time = 2000;  // включено (время включенного состояния мс) LED1
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
Blink leds_02(led02_pin, work_02_time, pause_02, impuls_02);
Blink leds_03(led03_pin);

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
