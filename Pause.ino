boolean IS_PAUSED = false;
int pauseStartTimeStamp = -1;

void handlePause() {
  int nowTimestamp = TIME_NOW.unixtime();

  if (digitalRead(PIN_PAUSE)) {
    // Pause button pressed

    if (!IS_PAUSED) {
      // Pause ON
      pauseStartTimeStamp = nowTimestamp;
      IS_PAUSED = true;
      buzzPauseOn();
      Serial.println("PAUSE: ON");
    }
    else if (nowTimestamp > pauseStartTimeStamp + 3) {
      // Pause OFF
      reset();
      Serial.println("PAUSE: OFF");
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

        Serial.println("PAUSE: Starting ..");
      }
      Serial.println((String)"PAUSE: In progress " + (nowTimestamp - pauseStartTimeStamp));
    }
    else {
      // After pause timeout
      reset();
      Serial.println("PAUSE: TIMEOUT");
    }
  }
}

void reset() {
  pauseStartTimeStamp = -1;
  IS_PAUSED = false;

  buzzPauseOff();
  digitalWrite(PIN_PAUSE_INDICATOR, LOW);
}
