#include <stddef.h>
#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
#include "FastLED.h"
#include "Constants.h"

DateTime TIME_NOW;

void setup() {
  setupUtils();
  dPrintln("Setup");
  if (DEBUG) {
    optimiseConstantsForDebug();
  }

  setupPin();
  digitalWrite(PIN_PAUSE_INDICATOR, HIGH);
  setupBuzzer();
  setupRTC();
  setupLedStrip();
  digitalWrite(PIN_PAUSE_INDICATOR, LOW);
}


void loop() {
  EVERY_N_SECONDS( 1 ) {
    dPrintln((String)"Loop...Mem: " + availableMemory() + " ............");
  }
  getTimeFromRTC();

  TIME_NOW = getTimeFromRTC();
  if (TIME_NOW.year() < 2020 || TIME_NOW.year() > 2030) {
    return;
  }

  handlePause();
  loopRelays();
  loopLedStrip();
}


int availableMemory()
{
  int size = 8192;
  byte *buf;
  while ((buf = (byte *) malloc(--size)) == NULL);
  free(buf);
  return size;
}
