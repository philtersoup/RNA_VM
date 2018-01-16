
#ifndef Potentiometer_H
#define Potentiometer_H

#include "Arduino.h"
#include "GPIO.h"


class Potentiometer {
	public:
		Potentiometer(uint8_t _channel, uint8_t _mux){
			channel = _channel;
			mux = _mux;
		};
		uint8_t channel, mux;
		uint8_t value;

};

#endif
