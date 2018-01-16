#ifndef DIGIPOT_H
#define DIGIPOT_H

#include "Arduino.h"
#include "GPIO.h"

class DigiPot {
  public:

    DigiPot(uint8_t _CS, byte _addr);


    // void init();
    void write(uint8_t value);


  private:
    uint8_t CS;
    uint8_t addr;
};

#endif
