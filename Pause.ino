
int pauseStartTimeStamp = -1;

void handlePause() {
  EVERY_N_SECONDS( 1 ) {
    dPrintln((String)"PAUSE: BTN:" + digitalRead(PIN_PAUSE) +", LED:"+digitalRead(PIN_PAUSE_INDICATOR));

    int nowTimestamp = TIME_NOW.unixtime();

    if (digitalRead(PIN_PAUSE) == HIGH) {
      // Pause button pressed

      if (!IS_PAUSED) {
        // Pause ON
        pauseStartTimeStamp = nowTimestamp;
        IS_PAUSED = true;
        buzzPauseOn();
        dPrintln("PAUSE: ON");
      }
      else if (nowTimestamp > pauseStartTimeStamp + 3) {
        // Pause OFF
        reset();
        dPrintln("PAUSE: OFF");
      }
    }

    else if (IS_PAUSED) {
      // In Paused state

      if (nowTimestamp <= pauseStartTimeStamp + PAUSE_DURATION_SECONDS) {
        // Before pause timeout
        int previousStatus = digitalRead(PIN_PAUSE_INDICATOR);
        if (previousStatus == LOW) {
          digitalWrite(PIN_PAUSE_INDICATOR, HIGH);
          playPauseStartMelody();

          dPrintln("PAUSE: Start");
        }
        dPrintln((String)"PAUSE: " + (nowTimestamp - pauseStartTimeStamp));
      }
      else {
        // After pause timeout
        reset();
        dPrintln("PAUSE: TIMEOUT");
      }
    }
  }
}

void reset() {
  pauseStartTimeStamp = -1;
  IS_PAUSED = false;

  buzzPauseOff();
  digitalWrite(PIN_PAUSE_INDICATOR, LOW);
}
