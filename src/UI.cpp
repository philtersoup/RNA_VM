#include "UI.h"
#include "Arduino.h"

void UI::Init() {

  ticks = lastTick = 0;
  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);

  delay(25);

  ledStrip.begin();//Initialise LED Strip
  ledStrip.show(); // Initialize all pixels to 'off'

  delay(25);
  SPI.setSCK(14);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.begin();

  memLoc = 0;
  presetMode = 0;

  delay(25);
  for(uint8_t j = 0; j < PRESET_MAX; j++){
    for(uint8_t i = 0; i < DIGIPOT_MAX; i++){
        presets[j][i] = EEPROM.read(j*PRESET_MAX + i);
    }
  }

  for(uint8_t i = 0; i<LED_MAX; i++){
    ledStrip.setPixelColor(i,0,255,0);
    ledStrip.show();
    delay(25);
  }
  ledStripFlush();

  ledStrip.setPixelColor(memLoc,0,255,0);
  ledStrip.show();

}

void UI::Update(Multiplexer* _mux) {
  ++ticks;
  if(ticks % 150 == 0){

  }

  // Serial.println(_mux->getPot(2));


  for (uint8_t i = 0; i < BUTTON_MAX; i++) {
    buttons[i].button->update();
    if(buttons[i].button->fallingEdge()){
      buttons[i].timer = millis();
      switch (i) {
        case 0:
          if(presetMode == 0){
            presetMode = 1;
          }
          else if(presetMode == 1){
            presetMode = 0;
          }
          break;

        case 3:
          if(presetMode == 0){
            for (uint8_t i = 0; i < POT_MAX; i++) {
              presets[memLoc][i] = _mux->getPot(i);
            }
            for(uint8_t i = 0; i < LED_MAX; i++){
              ledStrip.setPixelColor(i,255,69,0);
              ledStrip.show();
            }
            break;
          }
          else if(presetMode == 1) break;

        default:
          break;
      }

    }
    else if (buttons[i].button->risingEdge()){
      // if(millis() - buttons[i].timer > LONGPRESS){
        switch(i){
          case 1:
            if(presetMode == 1){
              memLoc = memLoc == 0 ? PRESET_MAX-1 : memLoc - 1;
              OutputPreset();
            }
            else if(presetMode == 0){
              memLoc = memLoc == 0 ? PRESET_MAX-1 : memLoc - 1;
            }
            break;

          case 2:
            if(presetMode == 1){
              memLoc = memLoc < PRESET_MAX - 1 ? memLoc + 1 : 0;
              OutputPreset();
            }
            else if(presetMode == 0){
              memLoc = memLoc < PRESET_MAX - 1 ? memLoc + 1 : 0;
            }
            break;

          case 3:
          if(presetMode == 1){
            EEPROMSave();
          }
        }
        handleLEDs();
        buttons[i].timer = 0;
        // Serial.println(memLoc);
      // }
    }
  }
}

bool UI::GetMode(){
  return presetMode;
}

void UI::OutputPreset(){

  for(uint8_t i = 0; i < DIGIPOT_MAX; i++){
    digipots[i].write(presets[memLoc][i]);
    delay(10);
  }
}
void UI::HandleButtonPress(int _i, bool _falling) {
  if (_falling) {
    //

  }
  else if (!_falling) {
  //
  }
}

void UI::EEPROMSave(){
  for(uint8_t j = 0; j < PRESET_MAX; j++){
    for(uint8_t i = 0; i < DIGIPOT_MAX; i++){
      EEPROM.write((PRESET_MAX*j)+i, presets[j][i]);
    }
  }
  for(uint8_t i = 0; i<LED_MAX; i++){
    ledStrip.setPixelColor(i,255,0,0);
    ledStrip.show();
  }
  ledStripFlush();

  eepromSaved = true;

  Serial.println("SAVED TO EEPROM");
  Serial.println("Reading back...");
  for(uint8_t j = 0; j < PRESET_MAX; j++){
    Serial.println();
    Serial.print(j);
    Serial.print('\t');
    for(uint8_t i = 0; i < DIGIPOT_MAX; i++){
        byte value = EEPROM.read((j*PRESET_MAX)+i);
        Serial.print(value);
        Serial.print('\t');
    }
  }
}

void UI::ledStripFlush(){
  for(uint8_t i = 0; i < LED_MAX; i++){
    ledStrip.setPixelColor(i,0,0,0);
    ledStrip.show();
  }
}

void UI::handleLEDs(){
  ledStripFlush();
  if(presetMode == 0){
    ledStrip.setPixelColor(memLoc,0,255,0);
  }
  else if(presetMode == 1){
    ledStrip.setPixelColor(memLoc,0,0,255);
  }
  ledStrip.show();
}
