
#ifndef GPIO_H
#define GPIO_H

#define but1 2
#define but2 3
#define but3 4
#define but4 5

#define digiPot1_CS 21 //change
#define digiPot2_CS 22 //change
#define digiPot3_CS 9
#define digiPot4_CS 9
#define digiPot5_CS 8
#define digiPot6_CS 8
#define digiPot7_CS 7
#define digiPot8_CS 7


#define digiPot9_CS 13
#define ledStrip_dataPin 6

#define mux_S0 28
#define mux_S1 29
#define mux_S2 30
#define mux_S3 32

#define mux1_SIG 10
#define mux2_SIG 11

#define ADC_MAX 255
#define BUTTON_MAX 4
#define POT_MAX 16
#define DIGIPOT_MAX 9
#define PRESET_MAX 4
#define LED_MAX 8
#define LONGPRESS 2000

int const pot_channels[16] = {6,7,5,4,11,10,9,8,3,14,13,12,12,9,18,15};
int const pot_muxes[16] = {mux2_SIG,mux2_SIG,mux2_SIG,mux2_SIG,
                         mux2_SIG,mux2_SIG,mux2_SIG,mux2_SIG,
                         mux1_SIG,mux2_SIG,mux2_SIG,mux2_SIG,
                         mux1_SIG,mux1_SIG,mux1_SIG,mux2_SIG};

#endif
