
int nowTimestamp = -1;
int pauseStartTimeStamp = -1;

void handlePause() {
  EVERY_N_SECONDS( 1 ) {
    dPrintln((String)"PAUSE: BTN:" + digitalRead(PIN_PAUSE) + ", LED:" + digitalRead(PIN_PAUSE_INDICATOR));
    nowTimestamp = TIME_NOW.unixtime();

    // Pause button pressed
    if (digitalRead(PIN_PAUSE) == HIGH) {
      if (!IS_PAUSED) {
        pauseOn();
      }
      else if (nowTimestamp > pauseStartTimeStamp + 3) {
        pauseOff();
      }
    }

    // While in Paused state, after pause timeout
    if (IS_PAUSED
        && nowTimestamp > pauseStartTimeStamp + PAUSE_DURATION_SECONDS) {
      dPrintln("PAUSE: TIMEOUT");
      pauseOff();
    }
  }
}


void pauseOn() {
  pauseStartTimeStamp = nowTimestamp;
  IS_PAUSED = true;

  digitalWrite(PIN_PAUSE_INDICATOR, HIGH);
  playPauseStartMelody();
  dPrintln("PAUSE: ON");
}


void pauseOff() {
  pauseStartTimeStamp = -1;
  IS_PAUSED = false;

  digitalWrite(PIN_PAUSE_INDICATOR, LOW);
  buzzPauseOff();
  dPrintln("PAUSE: OFF");
}
