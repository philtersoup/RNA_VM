#include "DigiPot.h"
#include <SPI.h>

DigiPot::DigiPot(uint8_t _CS, uint8_t _addr) {
  CS = _CS;
  addr = _addr;
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
}

void DigiPot::write(uint8_t _value) {
  digitalWrite(CS, LOW);
  SPI.transfer(addr);
  SPI.transfer(_value);
  digitalWrite(CS, HIGH);
}
