#include "UI.h"
#include "Multiplexer.h"
#include <SPI.h>


static constexpr uint32_t CORE_ISR_FREQ = 16666U;
static constexpr uint32_t CORE_TIMER_RATE = (1000000UL / CORE_ISR_FREQ);
static constexpr uint32_t UI_TIMER_RATE   = 1000UL;


static constexpr int CORE_TIMER_PRIO = 80;
static constexpr int UI_TIMER_PRIO   = 100;

//UI ISR
IntervalTimer UI_timer;
UI ui;


Multiplexer* mux = new Multiplexer();

void FASTRUN UI_timer_ISR() {
	//
	 ui.Update(mux);
}

IntervalTimer Sys_timer;
int count = 0;

void FASTRUN Sys_timer_ISR(){

}

void setup() {

  ui.Init();
  mux->init();

	//Flash LED for init
	delay(50);
	digitalWrite(13, HIGH);
	delay(50);
	digitalWrite(13, LOW);

	//Begin UI Timer
	// ui.combinedMux->update();

	 UI_timer.begin(UI_timer_ISR, UI_TIMER_RATE);
	 UI_timer.priority(UI_TIMER_PRIO);

   // Sys_timer.begin(Sys_timer_ISR, CORE_TIMER_RATE);
   // Sys_timer.priority(CORE_TIMER_PRIO);
}

uint32_t then = 0, now;

void loop() {
now = millis();
if(now - then > 30){
  mux->update();
  mux->log();
	then = 0;
}
//	if (now - then > 10) {
//		if (ui.GetMode() == 0) {
//			for (uint8_t i = 0 ; i < DIGIPOT_MAX; i++) {
//
//				// ui.digipots[i].write(ui.combinedMux->getPot(i));
//
//				// ui.ledStrip.setPixelColor(i
//
//				// ui.ledStrip.show();
//				delay(5);
//				}
//			}
//			then = now;
//		}
}
