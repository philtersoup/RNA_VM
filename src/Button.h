#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"
#include <Bounce.h>

class Button{

public:
  Bounce* button;
  uint16_t timer;
  Button(uint8_t _pin, unsigned long _debounce){
    button = new Bounce(_pin, _debounce);
  }


};

#endif
