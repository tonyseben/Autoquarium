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
  //delay(2000);
}


void loop() {
  EVERY_N_SECONDS( 1 ) {
    dPrintln((String)"Loop...Mem: " + availableMemory() + " ............");
  }

  TIME_NOW = getTimeFromRTC();
  if (TIME_NOW == NULL) {
    return;
  }

  loopRelays();
  loopLedStrip();
  handlePause();
  //delay(1000);
}


int availableMemory()
{
  int size = 8192;
  byte *buf;
  while ((buf = (byte *) malloc(--size)) == NULL);
  free(buf);
  return size;
}
