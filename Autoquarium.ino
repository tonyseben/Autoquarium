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
  setupRTC();
  setupBuzzer();
  setupLedStrip();
}


void loop() {
  EVERY_N_SECONDS( 1 ) {
    dPrintln((String)"Loop...Mem: " + availableMemory() + " ............");
  }

  TIME_NOW = getTimeFromRTC();
  if (TIME_NOW == NULL) {
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
