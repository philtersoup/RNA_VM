#ifndef MULTIPLEXER_H
#define  MULTIPLEXER_H

#include "Arduino.h"
#include "GPIO.h"
class Multiplexer{
public:
  Multiplexer();


  uint16_t pots[POT_MAX];

  uint8_t controlPin[4] = {28, 29, 30, 32};
  uint8_t muxChannel[16][4] = {
    {0, 0, 0, 0}, //channel 0
    {1, 0, 0, 0}, //channel 1
    {0, 1, 0, 0}, //channel 2
    {1, 1, 0, 0}, //channel 3
    {0, 0, 1, 0}, //channel 4
    {1, 0, 1, 0}, //channel 5
    {0, 1, 1, 0}, //channel 6
    {1, 1, 1, 0}, //channel 7
    {0, 0, 0, 1}, //channel 8
    {1, 0, 0, 1}, //channel 9
    {0, 1, 0, 1}, //channel 10
    {1, 1, 0, 1}, //channel 11
    {0, 0, 1, 1}, //channel 12
    {1, 0, 1, 1}, //channel 13
    {0, 1, 1, 1}, //channel 14
    {1, 1, 1, 1} //channel 15
  };

  void init();
  void update();
  void log();
  
  int readMux(int channel, int mux);
  int getPot(int idx);


};
#endif
