boolean IS_PAUSED = false;
int pauseEndTimeStamp = -1;

void handlePause() {
  int nowTimestamp = TIME_NOW.unixtime();

  if (digitalRead(PIN_PAUSE) && !IS_PAUSED) {
    pauseEndTimeStamp = nowTimestamp + PAUSE_DURATION_SECONDS;
    IS_PAUSED = true;
    buzzPauseOn();
    Serial.println("PAUSE: Start");
  }

  else if (!digitalRead(PIN_PAUSE)
           && IS_PAUSED
           && nowTimestamp <= pauseEndTimeStamp) {

    int previousStatus = digitalRead(PIN_PAUSE_INDICATOR);
    digitalWrite(PIN_PAUSE_INDICATOR, HIGH);
    if (previousStatus == LOW) {
      playPauseStartMelody();
    }
    Serial.println((String)"PAUSE: In progress " + (pauseEndTimeStamp - nowTimestamp));
  }

  else if (IS_PAUSED) {
    pauseEndTimeStamp = -1;
    IS_PAUSED = false;

    buzzPauseOff();
    digitalWrite(PIN_PAUSE_INDICATOR, LOW);
  }
}
