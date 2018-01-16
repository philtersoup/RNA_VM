#ifndef UI_H
#define UI_H

#include "Arduino.h"
#include "GPIO.h"
#include "Potentiometer.h"
#include "DigiPot.h"
#include "Button.h"
#include "Multiplexer.h"

#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <EEPROM.h>


class UI {
  public:
    UI(){};
    //All pin states are read from GPIO.h

    Button buttons[4] = {Button(but1, 5), Button(but2, 5), Button(but3, 5),
                         Button(but4, 5)
                        };


    DigiPot digipots[9] = {DigiPot(digiPot1_CS, 0x00), DigiPot(digiPot2_CS, 0x10),
                           DigiPot(digiPot3_CS, 0x00), DigiPot(digiPot4_CS, 0x10),
                           DigiPot(digiPot5_CS, 0x00), DigiPot(digiPot6_CS, 0x10),
                           DigiPot(digiPot7_CS, 0x00), DigiPot(digiPot8_CS, 0x10),
                           DigiPot(digiPot9_CS, 0x00)
                          };



    uint8_t presets[POT_MAX][PRESET_MAX];

    Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(LED_MAX, ledStrip_dataPin, NEO_GRB + NEO_KHZ800);

    uint32_t colours[4] = {ledStrip.Color(0, 135, 68), ledStrip.Color(0, 87, 231), ledStrip.Color(213, 45, 32),
                           ledStrip.Color(255, 167, 0)
                          };
    bool presetMode, eepromSaved;


    void Init();
    void Update(Multiplexer* _mux);


    bool GetMode();
    void HandleButtonPress(int _i, bool _falling);

  private:
    uint16_t ticks;
    uint16_t lastTick;
    uint16_t memLoc;
    void OutputPreset();
    void ledStripFlush();
    void handleLEDs();
    void EEPROMSave();

};

#endif
