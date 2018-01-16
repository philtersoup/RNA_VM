#include "Multiplexer.h"


Multiplexer::Multiplexer() {
  // for (uint8_t i = 0; i < POT_MAX; i++) {
  //   pots[i] = new Potentiometer(pot_channels[i], pot_muxes[i]);
  // }
  // Serial.print("Initialised");


}

void Multiplexer::init() {
  //

  pinMode(mux_S0, OUTPUT);
  pinMode(mux_S1, OUTPUT);
  pinMode(mux_S2, OUTPUT);
  pinMode(mux_S3, OUTPUT);



  digitalWrite(mux_S0, LOW);
  digitalWrite(mux_S1, LOW);
  digitalWrite(mux_S2, LOW);
  digitalWrite(mux_S3, LOW);

}

void Multiplexer::update() {
  for (uint8_t i = 0; i < POT_MAX; i++) {
    pots[i]= readMux(pot_channels[i], pot_muxes[i]);
  }
}

int Multiplexer::readMux(int channel, int mux) {
  for (int i = 0; i < 4; i ++) {  //loop through the 4 sig
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  int val = analogRead(mux);
  //read the value at the SIG pin
  return val;                     //return the value
}


int Multiplexer::getPot(int idx) {
  return pots[idx];
}

void Multiplexer::log(){
  Serial.println();
  for(uint8_t i = 0; i < POT_MAX; i++){
    if(i % 4 == 0 ) Serial.println();
    Serial.print(pots[i]);
    Serial.print("\t");
  }
}
